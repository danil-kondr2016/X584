/*
 * Copyright (C) 2005-2024 X584 developers
 *
 * This file is part of X584.
 *
 * X584 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * X584 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with X584. If not, see <https://www.gnu.org/licenses/>.
 */

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include <stdio.h>
#include "Input.h"
#include "About.h"
#include "FileExport.h"
#include <Vcl.Clipbrd.hpp>
#include <System.StrUtils.hpp>
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Word_2K_SRVR"
#pragma resource "*.dfm"
TX584Form *X584Form;
//---------------------------------------------------------------------------
#define NONAME_X584 L"Безымянный.x584"
__fastcall TX584Form::TX584Form(TComponent* Owner)
    : TForm(Owner), CPU(16), OpFilter(0), ResFilter(-1), ResButton(NULL), ClipboardSize(0), PreviousSelected(0)
{
    ClipboardFormat = RegisterClipboardFormatW(L"X584 v2 Code");
}
//---------------------------------------------------------------------------

#define PRJSTR1 L"Проект Микропрограммы Процессора К-584"
#define PRJSTR2 L"Код РОН П Л/Аоп.           Коментарии"
#define X584 0x34383558
#define V2P0 0x302E3256

//Таблица перекодировки для совместимости с предыдущим эмулятором
unsigned ReCode[54] = {
    0, 11, 14, 20,                                                              //РОН
    1, 12, 9, 40, 38, 43, 42, 41, 41, 39, 39, 23, 23, 3, 4, 17,                 //РР
    46, 44, 44, 44, 37, 35, 36, 34, 49, 48, 47, 47, 31, 29, 30, 28, 45, 45,     //РР, РРР
    22, 8, 13, 10, 25, 5, 6, 15, 18,                                            //РРР
    21, 19, 26, 26, 2, 7, 16                                                    //ШИНвых
};

void TX584Form::LoadFile(UnicodeString FileName)
{
    try {
        std::unique_ptr<TFileStream> Stream(new TFileStream(FileName, fmOpenRead));
        UnicodeString ext = UpperCase(ExtractFileExt(FileName));

        if (ext == L".X584") {
            //родной формат
            LoadX584(Stream.get());
        } else {
            //текстовый формат *.Prj
            LoadPRJ(Stream.get());
        }
        SetModifyFlag(false);
        ResetItemClick(this);
        OpenDialog->FileName = FileName;
        Caption = UnicodeString(L"X584 - ") + ExtractFileName(FileName);
    }
    catch (EConvertError &e) {
        MessageBoxW(Handle, (L"Неверный формат файла " + FileName).c_str(),
            L"Ошибка", MB_OK | MB_ICONERROR | MB_DEFBUTTON1 | MB_APPLMODAL);
    }
    catch (Exception &e) {
        MessageBoxW(Handle, (L"Ошибка открытия файла " + FileName).c_str(),
            L"Ошибка", MB_OK | MB_ICONERROR | MB_DEFBUTTON1 | MB_APPLMODAL);
    }
}

void TX584Form::LoadX584(TFileStream *Stream)
{
    std::unique_ptr<TBinaryReader> Reader(new TBinaryReader(Stream, TEncoding::UTF8, false));
    wchar_t buf[256];
    unsigned Sign;
    Sign = Reader->ReadUInt32();
    if (Sign != X584)
        throw EConvertError(L"Неверный формат");
    for (int i = 0; i < MAX_ADDR; i++) {
        //загружаем код микроинструкции
        Code[i] = Reader->ReadUInt16();
        //форматируем его
        CPU.Format(Code[i], buf);
        CodeListView->Items->Item[i]->SubItems->Strings[1] = buf;
        //загружаем комментарий
        unsigned char len;
        len = Reader->ReadByte();

        TBytes comment = Reader->ReadBytes(len);

        int Dummy;
        UnicodeString commentStr = TEncoding::GetEncoding(1251)->GetString(comment);
        if (ParseComment(commentStr, Dummy)) {
            CodeListView->Items->Item[i]->SubItems->Strings[2] = commentStr;
            CodeListView->Items->Item[i]->SubItems->Strings[3] = L"";
        } else {
            CodeListView->Items->Item[i]->SubItems->Strings[3] = commentStr;
            CodeListView->Items->Item[i]->SubItems->Strings[2] = L"";
        }
    }

    if (Reader->PeekChar() != -1) {
        Sign = Reader->ReadUInt32();
        // скорее всего, есть дополнительные данные
        if (Sign != V2P0)
            throw EConvertError(L"Неверный формат");

        for (int i = 0; i < MAX_ADDR; i++) {
            CodeListView->Items->Item[i]->SubItems->Strings[2] = Reader->ReadString();
            CodeListView->Items->Item[i]->SubItems->Strings[3] = Reader->ReadString();
        }
    }
}

void TX584Form::LoadPRJ(TFileStream *Stream)
{
    wchar_t buf[256];
    std::unique_ptr<TStringList> List(new TStringList());
    List->LoadFromStream(Stream, TEncoding::GetEncoding(1251));
    //проверяем заголовок
    if (List->Count < 2 || List->Strings[0] != PRJSTR1 || List->Strings[1] != PRJSTR2)
        throw EConvertError(L"");
    //читаем все оставшиеся строки
    for (int i = 0; i < List->Count - 2; i++) {
        //читаем поля микроинструкции
        UnicodeString str = List->Strings[i + 2];
        unsigned code = StrToInt(str.SubString(1, 3)),
                 reg = StrToInt(str.SubString(5, 3)),
                 carry = StrToInt(str.SubString(9, 1)),
                 op = StrToInt(str.SubString(11, 3));
        //формируем код микроинструкции
        unsigned opcode = code < 54 ? iSet[ReCode[code]].BitValue : NOP;
        if (reg != 0xFF)
            opcode |= reg;
        opcode |= carry ? ATTR_CARRY : 0;
        if (op != 0xFF)
            opcode |= op << 5;
        //определяем, используется ли перенос в данной инструкции
        if (code < 54)
            opcode |= CPU.FindOperand(ReCode[code], OP_CARRY, opcode) ? ATTR_CUSED : 0;
        //записываем микроинструкцию в редактор кода
        Code[i] = opcode;
        CPU.Format(opcode, buf);
        CodeListView->Items->Item[i]->SubItems->Strings[1] = buf;

        UnicodeString comment = str.SubString(15, str.Length() - 14);
        int Dummy;
        if (ParseComment(comment, Dummy)) {
            CodeListView->Items->Item[i]->SubItems->Strings[2] = comment;
            CodeListView->Items->Item[i]->SubItems->Strings[3] = L"";
        } else {
            CodeListView->Items->Item[i]->SubItems->Strings[3] = comment;
            CodeListView->Items->Item[i]->SubItems->Strings[2] = L"";
        }
    }
    //очищаем остальные строки
    for (int i = List->Count - 2; i < MAX_ADDR; i++) {
        Code[i] = NOP;
        CodeListView->Items->Item[i]->SubItems->Strings[1] = NOP_TEXT;
        CodeListView->Items->Item[i]->SubItems->Strings[2] = L"";
        CodeListView->Items->Item[i]->SubItems->Strings[3] = L"";
    }
}
//---------------------------------------------------------------------------

// Для обратной совместимости
UnicodeString CorrectControlComment(UnicodeString cmt);

void TX584Form::SaveFile(UnicodeString FileName)
{
    try {
        std::unique_ptr<TFileStream> Stream(new TFileStream(FileName, fmCreate));
        std::unique_ptr<TBinaryWriter> Writer(new TBinaryWriter(Stream.get(), TEncoding::UTF8, false));

        //сохраняем в родном формате
        unsigned int Sign = X584;
        Writer->Write(Sign);
        for (int i = 0; i < MAX_ADDR; i++) {
            //сохраняем инструкцию
            Writer->Write(static_cast<unsigned short>(Code[i]));
            //сохраняем комментарий
            int Dummy;
            UnicodeString control = CodeListView->Items->Item[i]->SubItems->Strings[2];
            UnicodeString comment = CodeListView->Items->Item[i]->SubItems->Strings[3];
            UnicodeString str = (control.Length() > 0 && !ParseInput(control, Dummy)) ? control : comment;

            if (str.Length() > 255)
                str.SetLength(255);

            unsigned char len = str.Length();
            Writer->Write(len);

            TBytes encodedStr = TEncoding::GetEncoding(1251)->GetBytes(str);
            Writer->Write(encodedStr);
        }

        //сохраняем новые данные
        Sign = V2P0;
        Writer->Write(Sign);

        for (int i = 0; i < MAX_ADDR; i++) {
            Writer->Write(CodeListView->Items->Item[i]->SubItems->Strings[2]);
            Writer->Write(CodeListView->Items->Item[i]->SubItems->Strings[3]);
        }

        SetModifyFlag(false);
        OpenDialog->FileName = FileName;
    }
    catch (Exception &e) {
        MessageBoxW(Handle, (L"Ошибка сохранения файла " + FileName).c_str(),
            L"Ошибка", MB_OK | MB_ICONERROR | MB_DEFBUTTON1 | MB_APPLMODAL);
    }
}
//---------------------------------------------------------------------------

void TX584Form::SetModifyFlag(bool Flag)
{
    Modified = Flag;
    SaveItem->Enabled = Flag;
    SaveToolButton->Enabled = Flag;
}
//---------------------------------------------------------------------------

void TX584Form::EnableRunControls(bool Flag)
{
    RunItem->Enabled = Flag;
    RunToolButton->Enabled = Flag;
    StepItem->Enabled = Flag;
    StepToolButton->Enabled = Flag;
    RunToCursorItem->Enabled = Flag;
    RunToCursorToolButton->Enabled = Flag;
    Caption = UnicodeString(L"X584 - ") + ExtractFileName(OpenDialog->FileName) + (Flag ? L"" : L" [Running]");
}
//---------------------------------------------------------------------------

void TX584Form::BuildTree(int OpFilter, int ResFilter)
{
    //создаем древовидный список инструкций
    wchar_t str[64];
    CodeTreeView->Items->Clear();
    for (int i = 0; i < INSTR_COUNT; i++) {
        //фильтруем по результату операции
        if (ResFilter != -1 && iSet[i].Result != ResFilter)
            continue;
        //фильтруем по списку операндов
        bool filter = false;
        for (int j = OP_WR; j <= OP_ONE; j++)
            if (OpFilter & 1 << j)
                if (j != OP_XWR || iSet[i].Result != OP_WRXWR) {
                    //ищем нужный операнд в списке
                    filter = true;
                    for (int k = 0; k < iSet[i].OpCount; k++)
                        if ((iSet[i].Operands[k] & F_MMASK) == j) {
                            filter = false;
                            break;
                        }
                    //не нашли - выходим
                    if (filter)
                        break;
                }
        if (filter)
            continue;
        //добавляем узел в корень дерева
        unsigned op = iSet[i].BitValue;
        CPU.Format(op, str, false, false, false);
        //исключаем дубликаты
        bool dup = false;
        if (CodeTreeView->Items->Count) {
            //получаем первый корневой элемент и перебираем его соседей
            TTreeNode *Node = CodeTreeView->Items->GetFirstNode();
            do {
                if (Node->Text == str) {
                    dup = true;
                    break;
                }
                Node = Node->getNextSibling();
            } while (Node);
        }
        if (dup)
            continue;
        //создаем корневой узел
        TTreeNode *Node = CodeTreeView->Items->Add(NULL, str);
        op |= CPU.FindOperand(i, OP_CARRY, op) ? ATTR_CUSED : 0;
        Node->Data = (void *)op;
        if (iSet[i].Type == TYPE_ALU) {
            Node->ImageIndex = 0;
            Node->SelectedIndex = 0;
            for (int j = 0; j < 16; j++) {
                //операция АЛУ - перебираем все 16 операций
                op = iSet[i].BitValue | j << 5;
                op |= CPU.FindOperand(i, OP_CARRY, op) ? ATTR_CUSED : 0;
                CPU.Format(op, str, true, false, false);
                TTreeNode *Child = CodeTreeView->Items->AddChild(Node, str);
                Child->Data = (void *)op;
                Child->ImageIndex = 0;
                Child->SelectedIndex = 0;
                //если среди операндов - РОНы, продолжаем детализацию
                if (CPU.FindOperand(i, OP_REG, iSet[i].BitValue | j << 5) || iSet[i].Result == OP_REG) {
                    Child->ImageIndex = 0;
                    Child->SelectedIndex = 0;
                    for (int k = 0; k < 8; k++) {
                        op = iSet[i].BitValue | j << 5 | k;
                        op |= CPU.FindOperand(i, OP_CARRY, op) ? ATTR_CUSED : 0;
                        CPU.Format(op, str, true, true, false);
                        TTreeNode *Item = CodeTreeView->Items->AddChild(Child, str);
                        Item->Data = (void *)op;
                        Item->ImageIndex = 2;
                        Item->SelectedIndex = 2;
                    }
                } else {
                    Child->ImageIndex = 2;
                    Child->SelectedIndex = 2;
                }
            }
        } else
            //детализируем инструкцию, если в списке операндов есть РОНы
            if (CPU.FindOperand(i, OP_REG, iSet[i].BitValue) || iSet[i].Result == OP_REG)
                for (int j = 0; j < 8; j++) {
                    op = iSet[i].BitValue | j;
                    op |= CPU.FindOperand(i, OP_CARRY, op) ? ATTR_CUSED : 0;
                    CPU.Format(op, str, true, true, false);
                    TTreeNode *Item = CodeTreeView->Items->AddChild(Node, str);
                    Item->Data = (void *)op;
                    Item->ImageIndex = 2;
                    Item->SelectedIndex = 2;
                }
            else {
                Node->ImageIndex = 2;
                Node->SelectedIndex = 2;
            }
    }
}
//---------------------------------------------------------------------------

void TX584Form::DrawItem(int Index)
{
    TRect Rect = CodeListView->Items->Item[Index]->DisplayRect(drBounds);
    InvalidateRect(CodeListView->Handle, &Rect, false);
    CodeListView->Update();
}
//---------------------------------------------------------------------------

UnicodeString NextWord(UnicodeString str, int &pos)
{
    //пропускаем ведущие пробелы
    while (pos <= str.Length() && str[pos] == L' ')
        pos++;
    int org = pos;
    //ищем конец слова
    while (pos <= str.Length() && str[pos] != L' ')
        pos++;
    //выделяем слово
    return AnsiUpperCase(str.SubString(org, pos - org));
}

const UnicodeString FlagNames[12] = {L"ПАЛУ3", L"!СДЛ1", L"!СДП1", L"!СДЛ2", L"!СДП2",
    L"РРР0", L"РРР3", L"A15", L"B15", L"ПАЛУ0", L"ПАЛУ1", L"ПАЛУ2"};
const UnicodeString AltFlagNames[12] = {L"П", L"!СДЛ1", L"!СДП1", L"!СДЛ2", L"!СДП2",
    L"РРР0", L"РРР3", L"А15", L"В15", L"П0", L"П1", L"П2"};
const UnicodeString EngFlagNames[12] = {L"ALUCOUT3", L"!WRLFT", L"!WRRT", L"!XWRLFT", L"!XWRRT",
    L"XWR0", L"XWR3", L"A15", L"B15", L"ALUCOUT0", L"ALUCOUT1", L"ALUCOUT2"};
const UnicodeString EngAltFlagNames[12] =  {L"C", L"!WRLFT", L"!WRRT", L"!XWRLFT", L"!XWRRT",
    L"XWR0", L"XWR3", L"A15", L"B15", L"C0", L"C1", L"C2"};

UnicodeString CorrectControlComment(UnicodeString cmt)
{
    TReplaceFlags flags = TReplaceFlags() << rfReplaceAll << rfIgnoreCase;
    UnicodeString result = cmt;

    for (int i = 0; i < 12; i++) {
        result = StringReplace(result, L" " + EngFlagNames[i] + L" ", L" " + FlagNames[i] + L" ", flags);
        if (EngAltFlagNames[i] != L"A15" && EngAltFlagNames[i] != L"B15") {
            result = StringReplace(result, L" " + EngAltFlagNames[i] + L" ", L" " + AltFlagNames[i] + L" ", flags);
        }
    }

    return result;
}

bool TX584Form::ParseInput(UnicodeString str, unsigned &Number)
{
    int pos = 1;
    UnicodeString token = NextWord(str, pos);
    if (token != L"INPUT" && token != L"ВВОД") {
        return false;
    }

    UnicodeString NumberString = str.SubString(pos, str.Length()-pos+1);
    UnicodeString WithoutSpaces = AnsiLowerCase(ReplaceStr(NumberString.Trim(), L" ", L""));

    Number = 0;
    if (WithoutSpaces.Length() >= 16) {
        // скорее всего, двоичные коды
        int count = 0;
        for (int i = 1; i <= NumberString.Length() && count < 16; i++) {
            if (NumberString[i] == L' ') {
                pos++;
                continue;
            }
            if (NumberString[i] != L'0' && NumberString[i] != L'1')
                return false;
            Number = (Number << 1) | (NumberString[i] - L'0');
            count++;
            pos++;
        }
    }
    else {
        NumberString = LowerCase(NextWord(str, pos));
        int SignedNumber;
        if (!TryStrToInt(NumberString, SignedNumber))
                return false;
        if (SignedNumber < -32768 || SignedNumber > 65535) {
            Number = 65535;
        }
        else if (SignedNumber < 0) {
            Number = SignedNumber + 65536; // преобразовать в дополнительный код
        }
        else {
            Number = SignedNumber;
        }
    }

    return NextWord(str, pos) == L"";
}

bool TX584Form::ParseComment(UnicodeString str, int &Instruction)
{
    int pos = 1;
    UnicodeString token = NextWord(str, pos);
    if (token == L"IF" || token == L"ЕСЛИ") {
        //проверяем логическое условие
        token = NextWord(str, pos);
        int flag = 0;
        for (int i = 0; i < 12; i++)
            if (token == FlagNames[i] || token == AltFlagNames[i] || token == EngFlagNames[i] || token == EngAltFlagNames[i]) {
                flag = F_CO << i;
                break;
            }
        //не нашли корректное логическое условие - выходим
        if (!flag)
            return false;
        token = NextWord(str, pos);
        if (token != L"THEN" && token != L"ТО")
            return false;
        //читаем адрес перехода в случае истинности условия
        int TrueAddr;
        if (!TryStrToInt(NextWord(str, pos), TrueAddr) || TrueAddr < 0 || TrueAddr >= MAX_ADDR)
            return false;
        //проверяем необязательную ветвь else
        token = NextWord(str, pos);
        int FalseAddr;
        if (token == L"")
            //ветвь отсутствует - берем адрес следующей инструкции
            FalseAddr = Instruction + 1;
        else if (token == L"ELSE" || token == L"ИНАЧЕ") {
            //читаем адрес перехода в случае ложности условия
            if (!TryStrToInt(NextWord(str, pos), FalseAddr) || FalseAddr < 0 || FalseAddr >= MAX_ADDR)
                return false;
            //проверяем, что больше нет других лексем
            if (NextWord(str, pos) != L"")
                return false;
        } else
            return false;
        //выполняем ветвление
        Instruction = OutFlags & flag ? TrueAddr : FalseAddr;
        return true;
    } else if (token == L"GOTO" || token == L"ИДИ_НА") {
        //читаем адрес перехода и проверяем, что больше нет других лексем
        int Addr;
        if (!TryStrToInt(NextWord(str, pos), Addr) || Addr < 0 || Addr >= MAX_ADDR || NextWord(str, pos) != L"")
            return false;
        //выполняем безусловный переход
        Instruction = Addr;
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------

void TX584Form::ShowState()
{
    //считываем состояние процессора
    for (int i = 0; i < 8; i++)
        Regs[i] = CPU.Reg[i];
    Regs[8] = CPU.WR;
    Regs[9] = CPU.XWR;
    //преобразуем число в строку с учетом разделяющих пробелов
    for (int i = 0; i < 12; i++) {
        UnicodeString str = L"";
        unsigned bit = 1 << 15;
        for (int j = 1; j <= 19; j++)
            if (j % 5) {
                str += Regs[i] & bit ? L'1' : L'0';
                bit >>= 1;
            } else
                str += L' ';
        //выводим строку, выделяя цветом при изменении
        TMaskEdit *Edit = dynamic_cast<TMaskEdit *>(FindComponent(L"RMaskEdit" + IntToStr(i)));
        Edit->Font->Color = Edit->Text == str ? clWindowText : clRed;
        Edit->Text = str;
    }
    //отображаем флаги
    for (int i = 0; i < 12; i++)
        dynamic_cast<TCheckBox *>(FindComponent(L"OutFlags" + IntToStr(i)))->Checked = OutFlags & 1 << i;
    //если курсор вышел за пределы экрана, прокручиваем редактор кода
    int topitem = -1;
    if (Instruction < CodeListView->TopItem->Index)
        topitem = Instruction;
    if (Instruction >= CodeListView->TopItem->Index + CodeListView->VisibleRowCount - 3)
        topitem = Instruction - CodeListView->VisibleRowCount + 3;
    if (topitem >= 0) {
        //прокручиваем редактор кода
        CodeListView->Scroll(0, CodeListView->Items->Item[topitem]->GetPosition().y -
            CodeListView->Items->Item[CodeListView->TopItem->Index]->GetPosition().y);
        CodeListView->Repaint();
    } else if (OldInstruction != Instruction) {
        //перерисовываем указатель текущей микроинструкции
        DrawItem(OldInstruction);
        DrawItem(Instruction);
    }
}
//---------------------------------------------------------------------------

void TX584Form::Run(int Mode)
{
    //вводим строку, пропуская разделяющие пробелы
    for (int i = 0; i < 12; i++) {
        UnicodeString str = dynamic_cast<TMaskEdit *>(FindComponent(L"RMaskEdit" + IntToStr(i)))->Text;
        Regs[i] = 0;
        unsigned bit = 1 << 15;
        for (int j = 1; j <= 19; j++)
            if (j % 5) {
                Regs[i] |= str[j] == L'1' ? bit : 0;
                bit >>= 1;
            }
    }
    //считываем флаги
    InFlags = 0;
    for (int i = 1; i <= 4; i++)
        InFlags |= dynamic_cast<TCheckBox *>(FindComponent(L"InFlags" + IntToStr(i)))->Checked ? 1 << i : 0;
    for (int i = 0; i < 12; i++)
        OutFlags |= dynamic_cast<TCheckBox *>(FindComponent(L"OutFlags" + IntToStr(i)))->Checked ? 1 << i : 0;
    //инициируем состояние процессора
    for (int i = 0; i < 8; i++)
        CPU.Reg[i] = Regs[i];
    CPU.WR = Regs[8];
    CPU.XWR = Regs[9];

    //выполняем инструкции в заданном режиме
    EnableRunControls(false);
    Terminated = false;
    OldInstruction = Instruction;
    int count = 0;
    do {
        //если инструкция требует входной шины, вводим ее значение
        unsigned DI = 0;
        bool find = false;
        for (int i = 0; i < INSTR_COUNT; i++)
            if ((Code[Instruction] & iSet[i].BitMask) == iSet[i].BitValue) {
                find = true;
                if (CPU.FindOperand(i, OP_IN, Code[Instruction])) {
                    ShowState();
                    if (!ParseInput(CodeListView->Items->Item[Instruction]->SubItems->Strings[2], DI)) {
                        InputForm->RMaskEdit->Text = L"0000 0000 0000 0000";
                        InputForm->RMaskEditChange(this);
                        if (InputForm->ShowModal() == mrOk)
                            DI = InputForm->Value;
                        else
                            //останавливаем выполнение
                            goto Stop;
                    }
                }
                break;
            }
        //нашли инструкцию - выполняем
        if (find) {
            //указываем перенос
            InFlags = (InFlags & ~F_CI) | (Code[Instruction] & ATTR_CARRY ? F_CI : 0);
            //выполняем инструкцию
            CPU.Execute(Code[Instruction], DI, Regs[10], Regs[11], InFlags, OutFlags);
        }
        //анализируем комментарий
        if (!ParseComment(CodeListView->Items->Item[Instruction]->SubItems->Strings[2], Instruction))
            //переходим к следующей инструкции
            if (++Instruction >= MAX_ADDR) {
                Instruction = 0;
                break;
            }
        count++;
        //останавливаемся на точке останова
        if (Code[Instruction] & ATTR_BREAKPOINT)
            break;
        //обрабатываем сообщения на случай зацикливания
        Application->ProcessMessages();
    } while (!Terminated && ((Mode < 0 && Instruction != -Mode) || (Mode >= 0 && Mode < count)));

Stop:
    EnableRunControls(true);
    ShowState();
}

//---------------------------------------------------------------------------
//                              *** ФОРМА ***
//---------------------------------------------------------------------------

void __fastcall TX584Form::FormCreate(TObject *Sender)
{
    //инициализируем окно редактора кода
    for (int i = 0; i < MAX_ADDR; i++) {
        TListItem *Item = CodeListView->Items->Add();
        Item->Caption = L"";
        //добавляем колонки
        Item->SubItems->Add(UnicodeString().sprintf(L"%03d.", i));
        Item->SubItems->Add(L"");
        Item->SubItems->Add(L"");
        Item->SubItems->Add(L"");
    }
    NewItemClick(this);
    //создаем дерево микроинструкций
    BuildTree(OpFilter, ResFilter);
    if (ParamCount() > 0) {
        LoadFile(ParamStr(1));
    }

    AddClipboardFormatListener(Handle);

    // проверяем буфер обмена при отображении формы
    TWMNoParams x = {WM_CLIPBOARDUPDATE};
    OnClipboardUpdate(x);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::FormDestroy(TObject *Sender)
{
    RemoveClipboardFormatListener(Handle);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::FormResize(TObject *Sender)
{
    StatusBar->Panels->Items[0]->Width = StatusBar->Width - 5 * StatusBar->Panels->Items[1]->Width;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    if (Modified)
        switch (MessageBoxW(Handle, (L"Файл " + OpenDialog->FileName + L" был изменен. Сохранить изменения?").c_str(),
            L"Сохранение файла", MB_YESNOCANCEL | MB_ICONWARNING | MB_DEFBUTTON1 | MB_APPLMODAL)) {
        case IDYES:
            SaveItemClick(this);
            break;
        case IDCANCEL:
            CanClose = false;
            break;
        }
    Terminated = true;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::ApplicationEventsHint(TObject *Sender)
{
    StatusBar->Panels->Items[0]->Text = Application->Hint;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::ApplicationEventsIdle(TObject *Sender,
      bool &Done)
{
    StatusBar->Panels->Items[1]->Text = GetKeyState(VK_CAPITAL) & 1 ? L"CAP" : L"";
    StatusBar->Panels->Items[2]->Text = GetKeyState(VK_NUMLOCK) & 1 ? L"NUM" : L"";
    StatusBar->Panels->Items[3]->Text = GetKeyState(VK_SCROLL) & 1 ? L"SCRL" : L"";

    // ХАК: прекращаем редактирование комментария при прокрутке редактора кода
    if (InputEdit->Visible &&
        (LastTopItem != CodeListView->TopItem || LastItemLeft != CodeListView->TopItem->Left))
    {
        InputEditExit(this);
    }

    Done = true;
}

//---------------------------------------------------------------------------
//                           *** РЕДАКТОР КОДА ***
//---------------------------------------------------------------------------

#define ROW_COLOR (TColor)0x00FFF6EE
#define SEL_COLOR (TColor)0x00EBB99D

void __fastcall TX584Form::CodeListViewCustomDrawItem(
      TCustomListView *Sender, TListItem *Item, TCustomDrawState State,
      bool &DefaultDraw)
{
    TRect Rect = Item->DisplayRect(drBounds);
    //рисуем часть корешка
    LeftImageList->Draw(CodeListView->Canvas, Rect.Left, Rect.Top, Item->Index == Instruction ?
        (Code[Item->Index] & ATTR_BREAKPOINT ? 3 : 2) : (Code[Item->Index] & ATTR_BREAKPOINT ? 1 : 0), true);
    //рисуем фон
    Rect.Left += LeftImageList->Width;
    if (!Item->Selected) {
        //нечетные строки - цветные, четные - белые
        CodeListView->Canvas->Brush->Color = Item->Index & 0x01 ? ROW_COLOR : clWhite;
        CodeListView->Canvas->FillRect(Rect);
    }
    else {
        CodeListView->Canvas->Brush->Color = SEL_COLOR;
        CodeListView->Canvas->FillRect(Rect);
    }
    //отображаем флажки
    if (Code[Item->Index] & ATTR_CUSED)
        CheckImageList->Draw(CodeListView->Canvas, Rect.Left + (CodeListView->Columns->Items[0]->Width -
            LeftImageList->Width - CheckImageList->Width) / 2, Rect.Top + (LeftImageList->Height -
            CheckImageList->Height) / 2, Code[Item->Index] & ATTR_CARRY ? 1 : 0, true);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeListViewAdvancedCustomDrawItem(TCustomListView *Sender,
          TListItem *Item, TCustomDrawState State, TCustomDrawStage Stage,
          bool &DefaultDraw)
{
    DefaultDraw = false;
    TRect Rectangle = Item->DisplayRect(drBounds);
    TRect TextRectangle;

    for (int i = 1; i < CodeListView->Columns->Count; i++) {
        TTextFormat format = TTextFormat();

        Rectangle.Left += CodeListView->Columns->Items[i-1]->Width;
        Rectangle.Right = Rectangle.Left + CodeListView->Columns->Items[i]->Width;
        TextRectangle = Rectangle;

        switch (CodeListView->Columns->Items[i]->Alignment) {
        case taLeftJustify:
            format = format << tfLeft;
            TextRectangle.Left += 7;
            TextRectangle.Right -= 7;
            break;
        case taRightJustify:
            format = format << tfRight;
            TextRectangle.Left += 7;
            TextRectangle.Right -= 7;
            break;
        case taCenter:
            format = format << tfCenter;
            break;
        }
        format = format << tfVerticalCenter;
        format = format << tfSingleLine;
        format = format << tfEndEllipsis;
        format = format << tfNoPrefix;

        UnicodeString str = Item->SubItems->Strings[i-1];
        CodeListView->Canvas->TextRect(TextRectangle, str, format);
    }
}
//---------------------------------------------------------------------------
void __fastcall TX584Form::CodeListViewMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    //определяем выделенный ряд
    int Row = CodeListView->ItemFocused->Index;
    TListItem *Item = CodeListView->ItemFocused;
    bool WasSelected = (PreviousSelected == Row);
    //проверяем, не зажата ли клавиша Shift или Ctrl
    if (Shift.Contains(ssShift)||Shift.Contains(ssCtrl)) {
        return;
    }

    CodeListView->ItemIndex = Row;
    TRect Rect = Item->DisplayRect(drBounds);
    //проверяем, не поставили ли точку останова
    if (X - Rect.Left < LeftImageList->Width) {
        //инвертируем состояние точки останова и перерисовываем корешок
        Code[Row] ^= ATTR_BREAKPOINT;
        LeftImageList->Draw(CodeListView->Canvas, Rect.Left, Rect.Top, Row == Instruction ?
            (Code[Row] & ATTR_BREAKPOINT ? 3 : 2) : (Code[Row] & ATTR_BREAKPOINT ? 1 : 0), true);
        SetModifyFlag(true);
    } else if (X - Rect.Left < CodeListView->Columns->Items[0]->Width) {
        //проверяем, не щелкнули ли по флажку
        Rect.Left += LeftImageList->Width + (CodeListView->Columns->Items[0]->Width -
            LeftImageList->Width - CheckImageList->Width) / 2;
        Rect.Top += (LeftImageList->Height - CheckImageList->Height) / 2;
        Rect.Right = Rect.Left + CheckImageList->Width;
        Rect.Bottom = Rect.Top + CheckImageList->Height;
        if ((Code[Row] & ATTR_CUSED) != 0 && PtInRect(Rect, Point(X, Y))) {
            //инвертируем состояние флажка и перерисовываем его
            Code[Row] ^= ATTR_CARRY;
            wchar_t str[64];
            CPU.Format(Code[Row], str);
            Item->SubItems->Strings[1] = str;
            CheckImageList->Draw(CodeListView->Canvas, Rect.Left, Rect.Top,
                Code[Row] & ATTR_CARRY ? 1 : 0, true);
            SetModifyFlag(true);
        }
    } else {
        Rect.Left += CodeListView->Columns->Items[0]->Width + CodeListView->Columns->Items[1]->Width +
            CodeListView->Columns->Items[2]->Width;
        Rect.Right = Rect.Left + CodeListView->Columns->Items[3]->Width;
        if (WasSelected && X >= Rect.Left && X <= Rect.Right) {
            //щелкнули в области колонки управляющих команд - запускаем таймер редактирования
            EditRow = Row;
            EditColumn = 2;
            EditPoint.x = CodeListView->Left + Rect.Left + 8;
            EditPoint.y = CodeListView->Top + Rect.Top + 2;
            //перезапускаем таймер
            ClickTimer->Enabled = false;
            ClickTimer->Enabled = true;
        }
        else {
            Rect.Left = Rect.Right;
            Rect.Right = Rect.Left + CodeListView->Columns->Items[4]->Width;
            if (WasSelected && X >= Rect.Left && X <= Rect.Right) {
                //щелкнули в области колонки комментариев - запускаем таймер редактирования
                EditRow = Row;
                EditColumn = 3;
                EditPoint.x = CodeListView->Left + Rect.Left + 8;
                EditPoint.y = CodeListView->Top + Rect.Top + 2;
                //перезапускаем таймер
                ClickTimer->Enabled = false;
                ClickTimer->Enabled = true;
            }
        }
    }
    PreviousSelected = Row;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeListViewDblClick(TObject *Sender)
{
    //получаем координаты двойного щелчка
    TPoint Point = CodeListView->ScreenToClient(Mouse->CursorPos);
    int X = Point.x - CodeListView->ItemFocused->DisplayRect(drBounds).Left;
    if (X > CodeListView->Columns->Items[0]->Width && X < CodeListView->Columns->Items[0]->Width +
        CodeListView->Columns->Items[1]->Width + CodeListView->Columns->Items[2]->Width) {
        //перемещаем указатель инструкции на текущую строчку
        int OldInstruction = Instruction;
        Instruction = CodeListView->ItemFocused->Index;
        //перерисовываем элементы
        if (OldInstruction != Instruction) {
            DrawItem(OldInstruction);
            DrawItem(Instruction);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeListViewKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    switch (Key) {
    case VK_DELETE:
        DeleteItemClick(this);
        Key = 0;
        break;
    case VK_INSERT:
        InsertItemClick(this);
        Key = 0;
        break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::ClickTimerTimer(TObject *Sender)
{
    ClickTimer->Enabled = false;
    //если мышь не покинула пределы строки после щелчка, начинаем редактирование
    TPoint Point = ScreenToClient(Mouse->CursorPos);
    if (Point.x >= EditPoint.x && Point.y >= EditPoint.y && Point.y < EditPoint.y + LeftImageList->Height) {
        LastTopItem = CodeListView->TopItem;
        LastItemLeft = CodeListView->TopItem->Left;
        InputEdit->Left = EditPoint.x;
        InputEdit->Top = EditPoint.y + (LeftImageList->Height - InputEdit->Height) / 2;
        int w1 = CodeListView->Canvas->TextWidth(CodeListView->Items->Item[EditRow]->SubItems->Strings[EditColumn]) + 8;
        if (w1 < 64)
            w1 = 64;
        int w2 = CodeListView->Left + CodeListView->Width - GetSystemMetrics(SM_CXVSCROLL) - InputEdit->Left - 2;
        if (w2 < InputEdit->Constraints->MinWidth)
            return;
        InputEdit->Width = w1 < w2 ? w1 : w2;
        InputEdit->Text = CodeListView->Items->Item[EditRow]->SubItems->Strings[EditColumn];
        InputEdit->Visible = true;
        InputEdit->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::InputEditExit(TObject *Sender)
{
    //завершаем редактирование и перерисовываем строку
    if (InputEdit->Visible) {
        int Dummy;
        if (EditColumn == 2 && InputEdit->Text.Length() && !ParseComment(InputEdit->Text, Dummy)) {
            CodeListView->Scroll(CodeListView->TopItem->Left-LastItemLeft, LastTopItem->Top - CodeListView->TopItem->Top);
            throw Exception(L"Неверный управляющий оператор");
        }
        CodeListView->Items->Item[EditRow]->SubItems->Strings[EditColumn] = InputEdit->Text;
        InputEdit->Visible = false;
        CodeListView->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::InputEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    switch (Key) {
    case VK_RETURN:
        //сохраняем комментарий и выходим
        InputEditExit(this);
        Key = 0;
        break;

    case VK_ESCAPE:
        //завершаем редактирование
        InputEdit->Visible = false;
        CodeListView->SetFocus();
        Key = 0;
        break;

    default:
        SetModifyFlag(true);
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::ControlsMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    InputEditExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeListViewDragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
    TTreeView *TreeView = dynamic_cast<TTreeView *>(Source);
    if (TreeView == CodeTreeView) {
        Accept = TreeView->Selected->Count == 0;
        if (Accept) {
            //выделяем элемент, над которым перемещается указатель мыши
            int RowHeight = CodeListView->TopItem->DisplayRect(drBounds).Height();
            int Row = CodeListView->TopItem->Index + (Y - CodeListView->TopItem->Position.y) / RowHeight;
            if (Row >= MAX_ADDR)
                Row = MAX_ADDR - 1;
            ClearSelection();

            CodeListView->ItemIndex = Row;
            TListItem *Item = CodeListView->Items->Item[Row];
            CodeListView->ItemFocused = Item;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeListViewDragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
    if (Source == CodeTreeView)
        CodeTreeViewDblClick(this);
}

//---------------------------------------------------------------------------
//                      *** ДЕРЕВО МИКРОИНСТРУКЦИЙ ***
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeTreeViewChange(TObject *Sender,
      TTreeNode *Node)
{
    //выводим код микроинструкции
    unsigned val = (unsigned)Node->Data & ~ATTR_CUSED;
    DescMemo->Lines->Clear();
    if (!Node->Count) {
        UnicodeString str = L"Код микроинструкции: ";
        for (int i = 8; i >= 0; i--)
            str += val & 1 << i ? L'1' : L'0';
        DescMemo->Lines->Add(str);
    }
    //получаем элемент верхнего уровня
    TTreeNode *Root = Node;
    for (int i = 0; i < Node->Level; i++)
        Root = Root->Parent;
    val = (unsigned)Root->Data & ~ATTR_CUSED;    
    //ищем сопоставленный раздел справки
    for (int i = 0; i < INSTR_COUNT; i++)
        if (val == iSet[i].BitValue) {
            DescMemo->Lines->Add(iSet[i].Help);
            return;
        }
    DescMemo->Lines->Add(L"Информация по текущей микроинструкции отсутствует");
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeTreeViewDblClick(TObject *Sender)
{
    TTreeNode *Node = CodeTreeView->Selected;
    if (!Node->Count) {
        int pos = CodeListView->ItemFocused->Index;
        if (InsertItem->Checked)
            //сдвигаем весь код на одну позицию вправо
            for (int i = MAX_ADDR - 1; i > pos; i--) {
                Code[i] = Code[i - 1];
                CodeListView->Items->Item[i]->SubItems->Strings[1] =
                    CodeListView->Items->Item[i - 1]->SubItems->Strings[1];
                CodeListView->Items->Item[i]->SubItems->Strings[2] =
                    CodeListView->Items->Item[i - 1]->SubItems->Strings[2];
                CodeListView->Items->Item[i]->SubItems->Strings[3] =
                    CodeListView->Items->Item[i - 1]->SubItems->Strings[3];
            }
        //форматируем и добавляем инструкцию
        Code[pos] = (unsigned)Node->Data;
        wchar_t str[64];
        CPU.Format(Code[pos], str);
        CodeListView->Items->Item[pos]->SubItems->Strings[1] = str;
        CodeListView->Items->Item[pos]->SubItems->Strings[2] = L"";
        CodeListView->Items->Item[pos]->SubItems->Strings[3] = L"";
        if (++pos >= MAX_ADDR)
            pos = MAX_ADDR - 1;
        ClearSelection();
        CodeListView->ItemFocused->Selected = false;
        CodeListView->ItemIndex = pos;
        CodeListView->ItemFocused = CodeListView->Items->Item[pos];
        CodeListView->Repaint();
        SetModifyFlag(true);
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeTreeViewExpanded(TObject *Sender,
      TTreeNode *Node)
{
    Node->ImageIndex = 1;
    Node->SelectedIndex = 1;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeTreeViewCollapsed(TObject *Sender,
      TTreeNode *Node)
{
    Node->ImageIndex = 0;
    Node->SelectedIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeTreeViewKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_RETURN) {
        CodeTreeViewDblClick(this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::FilterOpButtonClick(TObject *Sender)
{
    TButton *Button = dynamic_cast<TButton *>(Sender);
    int filter = 1 << Button->Tag;
    //инвертируем состояние кнопки
    OpFilter ^= filter;
    Button->Font->Style = OpFilter & filter ? Button->Font->Style << fsBold : Button->Font->Style >> fsBold;
    BuildTree(OpFilter, ResFilter);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::FilterResButtonClick(TObject *Sender)
{
    TButton *Button = dynamic_cast<TButton *>(Sender);
    if (ResFilter == Button->Tag) {
        //снимаем фильтр
        ResFilter = -1;
        Button->Font->Style = Button->Font->Style >> fsBold;
        BuildTree(OpFilter, ResFilter);
        ResButton = NULL;
    } else {
        //снимаем выделение с предыдущей кнопки
        if (ResButton)
            ResButton->Font->Style = ResButton->Font->Style >> fsBold;
        //и включаем фильтр
        ResFilter = Button->Tag;
        Button->Font->Style = Button->Font->Style << fsBold;
        BuildTree(OpFilter, ResFilter);
        ResButton = Button;
    }
}

//---------------------------------------------------------------------------
//                            *** РЕГИСТРЫ ***
//---------------------------------------------------------------------------

void __fastcall TX584Form::RegMaskEditKeyPress(TObject *Sender, char &Key)
{
    // обработка нажатия Enter
    if (Key == '\r') {
        Key = 0;
        RegMaskEditDblClick(Sender);
        return;
    }
    //фильтруем ненужные цифры
    if (Key >= '2' && Key <= '9')
        Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::RegMaskEditChange(TObject *Sender)
{
    //форматируем текст
    TMaskEdit *MaskEdit = dynamic_cast<TMaskEdit *>(Sender);
    UnicodeString str = MaskEdit->Text;
    for (int i = 1; i <= str.Length(); i++)
        if (str[i] == L' ' && i % 5 != 0)
            str[i] = L'0';
    if (str != MaskEdit->Text) {
        int pos = MaskEdit->SelStart;
        MaskEdit->Text = str;
        MaskEdit->SelStart = pos;
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::RegMaskEditDblClick(TObject *Sender)
{
    //показываем окно с содержимым поля ввода
    TMaskEdit *MaskEdit = dynamic_cast<TMaskEdit *>(Sender);
    InputForm->RMaskEdit->Text = MaskEdit->Text;
    InputForm->RMaskEditChange(this);
    if (InputForm->ShowModal() == mrOk)
        MaskEdit->Text = InputForm->RMaskEdit->Text;
}

//---------------------------------------------------------------------------
//                           *** ГЛАВНОЕ МЕНЮ ***
//---------------------------------------------------------------------------

void __fastcall TX584Form::NewItemClick(TObject *Sender)
{
    InputEditExit(this);
    //сохраняем предыдущий файл
    if (Modified)
        switch (MessageBoxW(Handle, (L"Файл " + OpenDialog->FileName + L" был изменен. Сохранить изменения?").c_str(),
            L"Сохранение файла", MB_YESNOCANCEL | MB_ICONWARNING | MB_DEFBUTTON1 | MB_APPLMODAL)) {
        case IDYES:
            SaveItemClick(this);
            break;
        case IDCANCEL:
            return;
        }
    //очищаем редактор кода
    for (int i = 0; i < MAX_ADDR; i++) {
        Code[i] = NOP;
        CodeListView->Items->Item[i]->SubItems->Strings[1] = NOP_TEXT;
        CodeListView->Items->Item[i]->SubItems->Strings[2] = L"";
        CodeListView->Items->Item[i]->SubItems->Strings[3] = L"";
    }
    //сбрасываем состояние регистров
    ResetItemClick(this);
    //создаем новый файл
    OpenDialog->FileName = NONAME_X584;
    Caption = L"X584 - " + ExtractFileName(OpenDialog->FileName);
    SetModifyFlag(false);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::OpenItemClick(TObject *Sender)
{
    InputEditExit(this);
    //сохраняем предыдущий файл
    if (Modified)
        switch (MessageBoxW(Handle, (L"Файл " + OpenDialog->FileName + L" был изменен. Сохранить изменения?").c_str(),
            L"Открытие файла", MB_YESNOCANCEL | MB_ICONWARNING | MB_DEFBUTTON1 | MB_APPLMODAL)) {
        case IDYES:
            SaveItemClick(this);
            break;
        case IDCANCEL:
            return;
        }
    //открываем новый
    if (OpenDialog->Execute())
        LoadFile(OpenDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::SaveItemClick(TObject *Sender)
{
    InputEditExit(this);
    if (OpenDialog->FileName == NONAME_X584)
        SaveAsItemClick(this);
    else if (Modified)
        SaveFile(OpenDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::SaveAsItemClick(TObject *Sender)
{
    InputEditExit(this);
    if (SaveDialog->Execute()) {
        SaveFile(SaveDialog->FileName);
        //меняем имя текущего файла
        OpenDialog->FileName = SaveDialog->FileName;
        Caption = UnicodeString(L"X584 - ") + ExtractFileName(OpenDialog->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::WordItemClick(TObject *Sender)
{
    try {
        TExportThread *Export = new TExportThread(true);
        Export->FreeOnTerminate = true;
        Export->Start();
    }
    catch (Exception &e) {
        MessageBoxW(Handle, L"Ошибка экспортирования данных в Microsoft Word.",
            L"Ошибка", MB_OK | MB_ICONERROR | MB_DEFBUTTON1 | MB_APPLMODAL);
        WordItem->Enabled = true;
        WordToolButton->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::ExitItemClick(TObject *Sender)
{
    InputEditExit(this);
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CutItemClick(TObject *Sender)
{
    if ((ActiveControl == CodeListView || ActiveControl == CodeTreeView) && !InputEdit->Visible) {
        CopyItemClick(this);
        DeleteItemClick(this);
    } else
        PostMessageW(ActiveControl->Handle, WM_CUT, 0, 0);
}
//---------------------------------------------------------------------------

std::vector<TListItem*> TX584Form::GetSelectedItems()
{
    std::vector<TListItem*> result;
    TItemStates selected = TItemStates() << isSelected;

    for (TListItem *Item = CodeListView->Selected; Item;
        Item = CodeListView->GetNextItem(Item, sdBelow, selected)) {
        result.push_back(Item);
    }

    return result;
}
//---------------------------------------------------------------------------

void TX584Form::CopySelectedItems()
{
    std::vector<TListItem *> Selected = GetSelectedItems();

    for (size_t i = 0; i < Selected.size(); i++) {
        TListItem *Item = Selected[i];
        int Index = Item->Index;
      
        MIClipboard[i] = Code[Index];
        CFClipboard[i] = Item->SubItems->Strings[2];
        CMClipboard[i] = Item->SubItems->Strings[3];
    }

    ClipboardSize = Selected.size();
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CopyItemClick(TObject *Sender)
{
    if ((ActiveControl == CodeListView || ActiveControl == CodeTreeView) && !InputEdit->Visible) {
        //сохраняем инструкции в буфере обмена
        CopySelectedItems();
        PutIntoClipboard();
    } else
        PostMessageW(ActiveControl->Handle, WM_COPY, 0, 0);
    PasteItem->Enabled = true;
    PasteToolButton->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::PasteItemClick(TObject *Sender)
{
    if ((ActiveControl == CodeListView || ActiveControl == CodeTreeView) && !InputEdit->Visible) {
        GetFromClipboard();
        int index = CodeListView->ItemFocused->Index;
        if (InsertItem->Checked)
            //сдвигаем все инструкции на ClipboardSize позиций вправо
            for (int i = MAX_ADDR - 1; i >= index + ClipboardSize; i--) {
                Code[i] = Code[i - ClipboardSize];
                CodeListView->Items->Item[i]->SubItems->Strings[1] =
                    CodeListView->Items->Item[i - ClipboardSize]->SubItems->Strings[1];
                CodeListView->Items->Item[i]->SubItems->Strings[2] =
                    CodeListView->Items->Item[i - ClipboardSize]->SubItems->Strings[2];
                CodeListView->Items->Item[i]->SubItems->Strings[3] =
                    CodeListView->Items->Item[i - ClipboardSize]->SubItems->Strings[3];
            }
        ClearSelection();
        //на освободившееся место помещаем инструкции из буфера обмена
        for (int i = 0; i < ClipboardSize; i++)
            if (index + i < MAX_ADDR) {
                Code[index + i] = MIClipboard[i];
                wchar_t str[64];
                CPU.Format(Code[index + i], str);
                CodeListView->Items->Item[index + i]->SubItems->Strings[1] = str;
                CodeListView->Items->Item[index + i]->SubItems->Strings[2] = CFClipboard[i];
                CodeListView->Items->Item[index + i]->SubItems->Strings[3] = CMClipboard[i];
                CodeListView->Items->Item[index + i]->Selected = true;
            }

        CodeListView->Repaint();
        SetModifyFlag(true);
    } else
        PostMessageW(ActiveControl->Handle, WM_PASTE, 0, 0);
}
//---------------------------------------------------------------------------

void TX584Form::ClearSelectedItems()
{
    std::vector<TListItem *> Selected = GetSelectedItems();

    for (size_t i = 0; i < Selected.size(); i++) {
        TListItem *Item = Selected[i];
        int Index = Item->Index;

        Code[Index] = NOP;
        Item->SubItems->Strings[1] = NOP_TEXT;
        Item->SubItems->Strings[2] = L"";
        Item->SubItems->Strings[3] = L"";
    }
}
//---------------------------------------------------------------------------

void TX584Form::RemoveSelectedItems()
{
    int OldIndex, NewIndex;

    for (OldIndex = 0, NewIndex = 0; OldIndex < MAX_ADDR; OldIndex++) {
        if (!CodeListView->Items->Item[OldIndex]->Selected) {
            Code[NewIndex] = Code[OldIndex];

            TListItem *OldItem = CodeListView->Items->Item[OldIndex];
            TListItem *NewItem = CodeListView->Items->Item[NewIndex];
            NewItem->SubItems->Strings[1] = OldItem->SubItems->Strings[1];
            NewItem->SubItems->Strings[2] = OldItem->SubItems->Strings[2];
            NewItem->SubItems->Strings[3] = OldItem->SubItems->Strings[3];
            NewIndex++;
        }
    }

    for (; NewIndex < MAX_ADDR; NewIndex++) {
        Code[NewIndex] = NOP;
        CodeListView->Items->Item[NewIndex]->SubItems->Strings[1] = NOP_TEXT;
        CodeListView->Items->Item[NewIndex]->SubItems->Strings[2] = L"";
        CodeListView->Items->Item[NewIndex]->SubItems->Strings[3] = L"";
    }
}
//---------------------------------------------------------------------------

void TX584Form::ClearSelection()
{
    TListItem *FocusedItem = CodeListView->ItemFocused;

    for (int i = 0; i < CodeListView->Items->Count; i++) {
        CodeListView->Items->Item[i]->Selected = false;
    }

    if (FocusedItem) {
        FocusedItem->Selected = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TX584Form::DeleteItemClick(TObject *Sender)
{
    if ((ActiveControl == CodeListView || ActiveControl == CodeTreeView) && !InputEdit->Visible) {
        if (InsertItem->Checked) {
            RemoveSelectedItems();
            //снимаем выделение
            ClearSelection();
        } else {
            ClearSelectedItems();
        }
        CodeListView->Repaint();
        SetModifyFlag(true);
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::InsertItemClick(TObject *Sender)
{
    InsertItem->Checked = !InsertItem->Checked;
    StatusBar->Panels->Items[4]->Text = InsertItem->Checked ? L"INS" : L"";
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::RunItemClick(TObject *Sender)
{
    InputEditExit(this);
    Run(0);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::StepItemClick(TObject *Sender)
{
    InputEditExit(this);
    Run(1);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::RunToCursorItemClick(TObject *Sender)
{
    InputEditExit(this);
    Run(-CodeListView->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::BreakItemClick(TObject *Sender)
{
    //выставляем флаг завершения
    InputEditExit(this);
    Terminated = true;
}
//---------------------------------------------------------------------------
void __fastcall TX584Form::ResetItemClick(TObject *Sender)
{
    InputEditExit(this);
    //очищаем регистры
    for (int i = 0; i < 12; i++) {
        TMaskEdit *MaskEdit = dynamic_cast<TMaskEdit *>(FindComponent(L"RMaskEdit" + IntToStr(i)));
        MaskEdit->Text = L"0000 0000 0000 0000";
        MaskEdit->Font->Color = clBlack;
    }
    //сбрасываем флаги
    InFlags1->Checked = true; InFlags2->Checked = true; InFlags3->Checked = false; InFlags4->Checked = false;
    for (int i = 0; i < 12; i++)
        dynamic_cast<TCheckBox *>(FindComponent(L"OutFlags" + IntToStr(i)))->Checked = i >= 1 && i <= 4;
    //перерисовываем редактор кода
    Instruction = 0;
    ClearSelection();
    CodeListView->ItemIndex = 0;
    CodeListView->ItemFocused = CodeListView->Items->Item[0];
    CodeListView->ItemFocused->Selected = true;
    CodeListView->Repaint();
    Terminated = true;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::HelpItemClick(TObject *Sender)
{
    UnicodeString HelpFilePath = ExtractFilePath(Application->ExeName) + L"X584.chm";
    ShellExecuteW(NULL, NULL, HelpFilePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::AboutItemClick(TObject *Sender)
{
    AboutForm->ShowModal();
}

//---------------------------------------------------------------------------
//                           *** БУФЕР ОБМЕНА ***
//---------------------------------------------------------------------------

void TX584Form::PutIntoClipboard()
{
    std::unique_ptr<TMemoryStream> Buffer(new TMemoryStream());
    std::unique_ptr<TBinaryWriter> Writer(new TBinaryWriter(Buffer.get(), TEncoding::UTF8, false));

    Writer->Write(ClipboardSize);
    for (int i = 0; i < ClipboardSize; i++) {
        Writer->Write(MIClipboard[i]);
        Writer->Write(CFClipboard[i]);
        Writer->Write(CMClipboard[i]);
    }

    Clipboard()->Open();

    Clipboard()->Clear();

    HGLOBAL hClipboardBuffer = GlobalAlloc(GMEM_MOVEABLE, Buffer->Size);
    void *ClipboardBuffer = GlobalLock(hClipboardBuffer);
    memcpy(ClipboardBuffer, Buffer->Memory, Buffer->Size);

    GlobalUnlock(hClipboardBuffer);
    Clipboard()->SetAsHandle(ClipboardFormat, reinterpret_cast<THandle>(hClipboardBuffer));

    Clipboard()->Close();
}
//---------------------------------------------------------------------------

void TX584Form::GetFromClipboard()
{
    if (!Clipboard()->HasFormat(ClipboardFormat)) {
        ClipboardSize = 0;
        return;
    }

    Clipboard()->Open();

    HGLOBAL hClipboardBuffer = reinterpret_cast<HGLOBAL>(Clipboard()->GetAsHandle(ClipboardFormat));
    void *ClipboardBuffer = GlobalLock(hClipboardBuffer);
    size_t ClipboardBufferSize = GlobalSize(hClipboardBuffer);

    std::unique_ptr<TMemoryStream> Buffer(new TMemoryStream());
    Buffer->Write(ClipboardBuffer, ClipboardBufferSize);
    Buffer->Seek(0ull, soBeginning);

    GlobalUnlock(hClipboardBuffer);

    Clipboard()->Close();

    std::unique_ptr<TBinaryReader> Reader(new TBinaryReader(Buffer.get(), TEncoding::UTF8, false));
    ClipboardSize = Reader->ReadInt32();
    for (int i = 0; i < ClipboardSize; i++) {
        MIClipboard[i] = Reader->ReadUInt32();
        CFClipboard[i] = Reader->ReadString();
        CMClipboard[i] = Reader->ReadString();
    }
}
//---------------------------------------------------------------------------

void TX584Form::OnClipboardUpdate(TWMNoParams &x)
{
    bool ClipboardHasData = Clipboard()->HasFormat(ClipboardFormat);
    PasteItem->Enabled = ClipboardHasData;
    PasteToolButton->Enabled = ClipboardHasData;
}
//---------------------------------------------------------------------------
