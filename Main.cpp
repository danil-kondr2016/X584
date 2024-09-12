//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include <stdio.h>
#include "Input.h"
#include "About.h"
#include "FileExport.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Word_2K_SRVR"
#pragma resource "*.dfm"
TX584Form *X584Form;
//---------------------------------------------------------------------------
__fastcall TX584Form::TX584Form(TComponent* Owner)
    : TForm(Owner), CPU(16), OpFilter(0), ResFilter(-1), ResButton(NULL), SelCount(0), ClipboardSize(0)
{
}
//---------------------------------------------------------------------------

#define PRJSTR1 "Проект Микропрограммы Процессора К-584"
#define PRJSTR2 "Код РОН П Л/Аоп.           Коментарии"
#define X584 0x34383558
#define NONAME_X584 "Безымянный.x584"

//Таблица перекодировки для совместимости с предыдущим эмулятором
unsigned ReCode[54] = {
    0, 11, 14, 20,                                                              //РОН
    1, 12, 9, 40, 38, 43, 42, 41, 41, 39, 39, 23, 23, 3, 4, 17,                 //РР
    46, 44, 44, 44, 37, 35, 36, 34, 49, 48, 47, 47, 31, 29, 30, 28, 45, 45,     //РР, РРР
    22, 8, 13, 10, 25, 5, 6, 15, 18,                                            //РРР
    21, 19, 26, 26, 2, 7, 16                                                    //ШИНвых
};

void TX584Form::LoadFile(AnsiString FileName)
{
    TFileStream *Stream;
    try {
        Stream = new TFileStream(FileName, fmOpenRead);
        AnsiString ext = AnsiUpperCase(ExtractFileExt(FileName));
        char buf[256];
        if (ext == ".X584") {
            //родной формат
            unsigned Sign;
            Stream->Read(&Sign, 4);
            if (Sign != X584)
                throw EConvertError("");
            for (int i = 0; i < MAX_ADDR; i++) {
                //загружаем код микроинструкции
                Stream->Read(&Code[i], 2);
                //форматируем его
                CPU.Format(Code[i], buf);
                CodeListView->Items->Item[i]->SubItems->Strings[1] = buf;
                //загружаем комментарий
                unsigned char len;
                Stream->Read(&len, 1);
                Stream->Read(buf, len);
                buf[len] = 0;
                CodeListView->Items->Item[i]->SubItems->Strings[2] = buf;
            }
        } else {
            //текстовый формат *.Prj
            TStringList *List = new TStringList();
            List->LoadFromStream(Stream);
            //проверяем заголовок
            if (List->Count < 2 || List->Strings[0] != PRJSTR1 || List->Strings[1] != PRJSTR2)
                throw EConvertError("");
            //читаем все оставшиеся строки
            for (int i = 0; i < List->Count - 2; i++) {
                //читаем поля микроинструкции
                AnsiString str = List->Strings[i + 2];
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
                CodeListView->Items->Item[i]->SubItems->Strings[2] = str.SubString(15, str.Length() - 14);
            }
            //очищаем остальные строки
            for (int i = List->Count - 2; i < MAX_ADDR; i++) {
                Code[i] = NOP;
                CodeListView->Items->Item[i]->SubItems->Strings[1] = NOP_TEXT;
                CodeListView->Items->Item[i]->SubItems->Strings[2] = "";
            }
            delete List;
        }
        SetModifyFlag(false);
        ResetItemClick(this);
        Caption = AnsiString("X584 - ") + ExtractFileName(OpenDialog->FileName);
    }
    catch (EConvertError &e) {
        MessageBox(Handle, ("Неверный формат файла " + OpenDialog->FileName).c_str(),
            "Ошибка", MB_OK | MB_ICONERROR | MB_DEFBUTTON1 | MB_APPLMODAL);
    }
    catch (Exception &e) {
        MessageBox(Handle, ("Ошибка открытия файла " + FileName).c_str(),
            "Ошибка", MB_OK | MB_ICONERROR | MB_DEFBUTTON1 | MB_APPLMODAL);
    }
    delete Stream;
}
//---------------------------------------------------------------------------

void TX584Form::SaveFile(AnsiString FileName)
{
    TFileStream *Stream;
    try  {
        Stream = new TFileStream(FileName, fmCreate);
        //сохраняем в родном формате
        unsigned Sign = X584;
        Stream->Write(&Sign, 4);
        for (int i = 0; i < MAX_ADDR; i++) {
            //сохраняем инструкцию
            Stream->Write(&Code[i], 2);
            //сохраняем комментарий
            AnsiString str = CodeListView->Items->Item[i]->SubItems->Strings[2];
            unsigned char len = str.Length();
            Stream->Write(&len, 1);
            Stream->Write(str.c_str(), len);
        }
        SetModifyFlag(false);
    }
    catch (Exception &e) {
        MessageBox(Handle, ("Ошибка сохранения файла " + FileName).c_str(),
            "Ошибка", MB_OK | MB_ICONERROR | MB_DEFBUTTON1 | MB_APPLMODAL);
    }
    delete Stream;
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
    StepItem->Enabled = Flag;
    RunToCursorItem->Enabled = Flag;
    Caption = AnsiString("X584 - ") + ExtractFileName(OpenDialog->FileName) + (Flag ? "" : " [Running]");
}
//---------------------------------------------------------------------------

void TX584Form::BuildTree(int OpFilter, int ResFilter)
{
    //создаем древовидный список инструкций
    char str[64];
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

AnsiString NextWord(AnsiString str, int &pos)
{
    //пропускаем ведущие пробелы
    while (pos <= str.Length() && str[pos] == ' ')
        pos++;
    int org = pos;
    //ищем конец слова
    while (pos <= str.Length() && str[pos] != ' ')
        pos++;
    //выделяем слово
    return AnsiUpperCase(str.SubString(org, pos - org));
}

const AnsiString FlagNames[12] = {"ПАЛУ3", "!СДЛ1", "!СДП1", "!СДЛ2", "!СДП2",
    "РРР0", "РРР3", "A15", "B15", "ПАЛУ0", "ПАЛУ1", "ПАЛУ2"};
const AnsiString AltFlagNames[12] = {"П", "!СДЛ1", "!СДП1", "!СДЛ2", "!СДП2",
    "РРР0", "РРР3", "А15", "В15", "П0", "П1", "П2"};

bool TX584Form::ParseComment(AnsiString str, int &Instruction)
{
    int pos = 1;
    AnsiString token = NextWord(str, pos);
    if (token == "IF" || token == "ЕСЛИ") {
        //проверяем логическое условие
        token = NextWord(str, pos);
        int flag = 0;
        for (int i = 0; i < 12; i++)
            if (token == FlagNames[i] || token == AltFlagNames[i]) {
                flag = F_CO << i;
                break;
            }
        //не нашли корректное логическое условие - выходим
        if (!flag)
            return false;
        token = NextWord(str, pos);
        if (token != "THEN" && token != "ТО")
            return false;
        //читаем адрес перехода в случае истинности условия
        int TrueAddr;
        if (!TryStrToInt(NextWord(str, pos), TrueAddr) || TrueAddr < 0 || TrueAddr >= MAX_ADDR)
            return false;
        //проверяем необязательную ветвь else
        token = NextWord(str, pos);
        int FalseAddr;
        if (token == "")
            //ветвь отсутствует - берем адрес следующей инструкции
            FalseAddr = Instruction + 1;
        else if (token == "ELSE" || token == "ИНАЧЕ") {
            //читаем адрес перехода в случае ложности условия
            if (!TryStrToInt(NextWord(str, pos), FalseAddr) || FalseAddr < 0 || FalseAddr >= MAX_ADDR)
                return false;
            //проверяем, что больше нет других лексем
            if (NextWord(str, pos) != "")
                return false;
        } else
            return false;
        //выполняем ветвление
        Instruction = OutFlags & flag ? TrueAddr : FalseAddr;
        return true;
    // Товарищи, это так не работает - Д.А.К.
    //} else if (token == "GOTO" || "ИДИ_НА") { // ;-)
    } else if (token == "GOTO" || token == "ИДИ_НА") { // вот так правильно
        //читаем адрес перехода и проверяем, что больше нет других лексем
        int Addr;
        if (!TryStrToInt(NextWord(str, pos), Addr) || Addr < 0 || Addr >= MAX_ADDR || NextWord(str, pos) != "")
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
        AnsiString str = "";
        unsigned bit = 1 << 15;
        for (int j = 1; j <= 19; j++)
            if (j % 5) {
                str += Regs[i] & bit ? '1' : '0';
                bit >>= 1;
            } else
                str += ' ';
        //выводим строку, выделяя цветом при изменении
        TMaskEdit *Edit = dynamic_cast<TMaskEdit *>(FindComponent("RMaskEdit" + IntToStr(i)));
        Edit->Font->Color = Edit->Text == str ? clWindowText : clRed;
        Edit->Text = str;
    }
    //отображаем флаги
    for (int i = 0; i < 12; i++)
        dynamic_cast<TCheckBox *>(FindComponent("OutFlags" + IntToStr(i)))->Checked = OutFlags & 1 << i;
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
        AnsiString str = dynamic_cast<TMaskEdit *>(FindComponent("RMaskEdit" + IntToStr(i)))->Text;
        Regs[i] = 0;
        unsigned bit = 1 << 15;
        for (int j = 1; j <= 19; j++)
            if (j % 5) {
                Regs[i] |= str[j] == '1' ? bit : 0;
                bit >>= 1;
            }
    }
    //считываем флаги
    InFlags = 0;
    for (int i = 1; i <= 4; i++)
        InFlags |= dynamic_cast<TCheckBox *>(FindComponent("InFlags" + IntToStr(i)))->Checked ? 1 << i : 0;
    for (int i = 0; i < 12; i++)
        OutFlags |= dynamic_cast<TCheckBox *>(FindComponent("OutFlags" + IntToStr(i)))->Checked ? 1 << i : 0;
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
                    InputForm->RMaskEdit->Text = "0000 0000 0000 0000";
                    InputForm->RMaskEditChange(this);
                    if (InputForm->ShowModal() == mrOk)
                        DI = InputForm->Value;
                    else
                        //останавливаем выполнение
                        goto Stop;
                    }
                break;
            }
        //нашли инструкцию - выполняем
        if (find) {
            //указываем перенос
            InFlags = InFlags & ~F_CI | (Code[Instruction] & ATTR_CARRY ? F_CI : 0);
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
    } while (!Terminated && (Mode < 0 && Instruction != -Mode || Mode >= 0 && Mode < count));

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
        Item->Caption = "";
        //добавляем колонки
        Item->SubItems->Add(AnsiString().sprintf("%03d.", i));
        Item->SubItems->Add("");
        Item->SubItems->Add("");
    }
    NewItemClick(this);
    //создаем дерево микроинструкций
    BuildTree(OpFilter, ResFilter);
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
        switch (MessageBox(Handle, ("Файл " + OpenDialog->FileName + " был изменен. Сохранить изменения?").c_str(),
            "Сохранение файла", MB_YESNOCANCEL | MB_ICONWARNING | MB_DEFBUTTON1 | MB_APPLMODAL)) {
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
    StatusBar->Panels->Items[1]->Text = GetKeyState(VK_CAPITAL) & 1 ? "CAP" : "";
    StatusBar->Panels->Items[2]->Text = GetKeyState(VK_NUMLOCK) & 1 ? "NUM" : "";
    StatusBar->Panels->Items[3]->Text = GetKeyState(VK_SCROLL) & 1 ? "SCRL" : "";
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
    //прекращаем редактирование
    InputEditExit(this);
    TRect Rect = Item->DisplayRect(drBounds);
    //рисуем часть корешка
    LeftImageList->Draw(CodeListView->Canvas, Rect.Left, Rect.Top, Item->Index == Instruction ?
        (Code[Item->Index] & ATTR_BREAKPOINT ? 3 : 2) : (Code[Item->Index] & ATTR_BREAKPOINT ? 1 : 0), true);
    //рисуем фон
    Rect.Left += LeftImageList->Width;
    if (SelCount > 0 && Item->Index >= CodeListView->ItemFocused->Index &&
                        Item->Index < CodeListView->ItemFocused->Index + SelCount ||
        SelCount < 0 && Item->Index >= CodeListView->ItemFocused->Index + SelCount &&
                        Item->Index <= CodeListView->ItemFocused->Index) {
        //выделяем стандартным цветом
        CodeListView->Canvas->Brush->Color = SEL_COLOR;
        CodeListView->Canvas->FillRect(Rect);
    } else {
        //нечетные строки - цветные, четные - белые
        CodeListView->Canvas->Brush->Color = Item->Index & 0x01 ? ROW_COLOR : clWhite;
        CodeListView->Canvas->FillRect(Rect);
    }
    //отображаем флажки
    if (Code[Item->Index] & ATTR_CUSED)
        CheckImageList->Draw(CodeListView->Canvas, Rect.Left + (CodeListView->Columns->Items[0]->Width -
            LeftImageList->Width - CheckImageList->Width) / 2, Rect.Top + (LeftImageList->Height -
            CheckImageList->Height) / 2, Code[Item->Index] & ATTR_CARRY ? 1 : 0, true);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeListViewMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    //определяем выделенный ряд
    int Row = CodeListView->TopItem->Index + (Y - CodeListView->TopItem->Position.y) / LeftImageList->Height;
    if (Row >= MAX_ADDR)
        Row = MAX_ADDR - 1;
    bool WasSelected = CodeListView->ItemFocused->Index == Row;
    TListItem *Item = CodeListView->Items->Item[Row];
    //проверяем, не зажата ли клавиша Shift
    if (Shift.Contains(ssShift)) {
        //выделяем элементы до предыдущего выделения
        SelCount = Row - CodeListView->ItemFocused->Index;
        if (SelCount >= 0)
            SelCount++;
        CodeListView->Repaint();
        return;
    }
    if (SelCount != 1) {
        SelCount = 1;
        CodeListView->Repaint();
    }
    CodeListView->ItemIndex = Row;
    CodeListView->ItemFocused = Item;
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
            char str[64];
            CPU.Format(Code[Row], str);
            Item->SubItems->Strings[1] = str;
            CheckImageList->Draw(CodeListView->Canvas, Rect.Left, Rect.Top,
                Code[Row] & ATTR_CARRY ? 1 : 0, true);
            SetModifyFlag(true);
        }
    } else {
        Rect.Left += CodeListView->Columns->Items[0]->Width + CodeListView->Columns->Items[1]->Width +
            CodeListView->Columns->Items[2]->Width;
        if (WasSelected && X > Rect.Left) {
            //щелкнули в области колонки комментариев - запускаем таймер редактирования
            EditRow = Row;
            EditPoint.x = CodeListView->Left + Rect.Left + 8;
            EditPoint.y = CodeListView->Top + Rect.Top + 2;
            //перезапускаем таймер
            ClickTimer->Enabled = false;
            ClickTimer->Enabled = true;
        }
    }
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
    case VK_UP:
        if (GetKeyState(VK_SHIFT) & 0x8000) {
            int index = CodeListView->ItemFocused->Index + (SelCount < 0 ? SelCount : SelCount - 1);
            //перерисовываем элемент
            if (index)
                if (--SelCount >= 1)
                    DrawItem(index);
                else {
                    if (SelCount == 0)
                        SelCount = -1;
                    DrawItem(index - 1);
                }
            Key = 0;    
        } else
            if (SelCount != 1) {
                SelCount = 1;
                CodeListView->Repaint();
            }
        break;
    case VK_DOWN:
        if (GetKeyState(VK_SHIFT) & 0x8000) {
            int index = CodeListView->ItemFocused->Index + (SelCount < 0 ? SelCount : SelCount - 1);
            if (index != MAX_ADDR - 1)
                if (++SelCount > 1)
                    DrawItem(index + 1);
                else {
                    if (SelCount == 0)
                        SelCount = 1;
                    DrawItem(index);
                }
            Key = 0;
        } else
            if (SelCount != 1) {
                SelCount = 1;
                CodeListView->Repaint();
            }
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
        InputEdit->Left = EditPoint.x;
        InputEdit->Top = EditPoint.y + (LeftImageList->Height - InputEdit->Height) / 2;
        int w1 = CodeListView->Canvas->TextWidth(CodeListView->Items->Item[EditRow]->SubItems->Strings[2]) + 8;
        if (w1 < 64)
            w1 = 64;
        int w2 = CodeListView->Left + CodeListView->Width - GetSystemMetrics(SM_CXVSCROLL) - InputEdit->Left - 2;
        if (w2 < InputEdit->Constraints->MinWidth)
            return;
        InputEdit->Width = w1 < w2 ? w1 : w2;
        InputEdit->Text = CodeListView->Items->Item[EditRow]->SubItems->Strings[2];
        InputEdit->Visible = true;
        InputEdit->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::InputEditExit(TObject *Sender)
{
    //завершаем редактирование и перерисовываем строку
    if (InputEdit->Visible) {
        CodeListView->Items->Item[EditRow]->SubItems->Strings[2] = InputEdit->Text;
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
            int Row = CodeListView->TopItem->Index + (Y - CodeListView->TopItem->Position.y) / LeftImageList->Height;
            if (Row >= MAX_ADDR)
                Row = MAX_ADDR - 1;
            if (SelCount != 1) {
                SelCount = 1;
                CodeListView->Repaint();
            }
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
//                     *** ДЕРЕВО МИКРОИНСТРУКЦИЙ ***
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeTreeViewChange(TObject *Sender,
      TTreeNode *Node)
{
    //выводим код микроинструкции
    unsigned val = (unsigned)Node->Data & ~ATTR_CUSED;
    DescMemo->Lines->Clear();
    if (!Node->Count) {
        AnsiString str = "Код микроинструкции: ";
        for (int i = 8; i >= 0; i--)
            str += val & 1 << i ? '1' : '0';
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
    DescMemo->Lines->Add("Информация по текущей микроинструкции отсутствует");
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CodeTreeViewDblClick(TObject *Sender)
{
    TTreeNode *Node = CodeTreeView->Selected;
    if (!Node->Count) {
        int pos = CodeListView->ItemIndex;
        if (InsertItem->Checked)
            //сдвигаем весь код на одну позицию вправо
            for (int i = MAX_ADDR - 1; i > pos; i--) {
                Code[i] = Code[i - 1];
                CodeListView->Items->Item[i]->SubItems->Strings[1] =
                    CodeListView->Items->Item[i - 1]->SubItems->Strings[1];
                CodeListView->Items->Item[i]->SubItems->Strings[2] =
                    CodeListView->Items->Item[i - 1]->SubItems->Strings[2];
            }
        //форматируем и добавляем инструкцию
        Code[pos] = (unsigned)Node->Data;
        char str[64];
        CPU.Format(Code[pos], str);
        CodeListView->Items->Item[pos]->SubItems->Strings[1] = str;
        CodeListView->Items->Item[pos]->SubItems->Strings[2] = "";
        if (++pos >= MAX_ADDR)
            pos = MAX_ADDR - 1;
        CodeListView->ItemIndex = pos;
        CodeListView->ItemFocused = CodeListView->Items->Item[pos];
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
    //фильтруем ненужные цифры
    if (Key >= '2' && Key <= '9')
        Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::RegMaskEditChange(TObject *Sender)
{
    //форматируем текст
    TMaskEdit *MaskEdit = dynamic_cast<TMaskEdit *>(Sender);
    AnsiString str = MaskEdit->Text;
    for (int i = 1; i <= str.Length(); i++)
        if (str[i] == ' ' && i % 5 != 0)
            str[i] = '0';
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
        switch (MessageBox(Handle, ("Файл " + OpenDialog->FileName + " был изменен. Сохранить изменения?").c_str(),
            "Сохранение файла", MB_YESNOCANCEL | MB_ICONWARNING | MB_DEFBUTTON1 | MB_APPLMODAL)) {
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
        CodeListView->Items->Item[i]->SubItems->Strings[2] = "";
    }
    //сбрасываем состояние регистров
    ResetItemClick(this);
    //создаем новый файл
    OpenDialog->FileName = NONAME_X584;
    Caption = "X584 - " + ExtractFileName(OpenDialog->FileName);
    SetModifyFlag(false);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::OpenItemClick(TObject *Sender)
{
    InputEditExit(this);
    //сохраняем предыдущий файл
    if (Modified)
        switch (MessageBox(Handle, ("Файл " + OpenDialog->FileName + " был изменен. Сохранить изменения?").c_str(),
            "Открытие файла", MB_YESNOCANCEL | MB_ICONWARNING | MB_DEFBUTTON1 | MB_APPLMODAL)) {
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
        Caption = AnsiString("X584 - ") + ExtractFileName(OpenDialog->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::WordItemClick(TObject *Sender)
{
    try {
        TExportThread *Export = new TExportThread(false);
        Export->FreeOnTerminate = true;
        Export->Resume();
    }
    catch (Exception &e) {
        MessageBox(Handle, "Ошибка экспортирования данных в Microsoft Word.",
            "Ошибка", MB_OK | MB_ICONERROR | MB_DEFBUTTON1 | MB_APPLMODAL);
        WordItem->Enabled = true;
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
    if (ActiveControl == CodeListView && !InputEdit->Visible) {
        CopyItemClick(this);
        DeleteItemClick(this);
    } else
        PostMessage(ActiveControl->Handle, WM_CUT, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::CopyItemClick(TObject *Sender)
{
    if (ActiveControl == CodeListView && !InputEdit->Visible) {
        //сохраняем инструкции в буфере обмена
        int index = CodeListView->ItemFocused->Index;
        if (SelCount > 0) {
            ClipboardSize = SelCount;
            for (int i = 0; i < ClipboardSize; i++) {
                MIClipboard[i] = Code[index + i];
                CMClipboard[i] = CodeListView->Items->Item[index + i]->SubItems->Strings[2];
            }
        } else {
            ClipboardSize = 1 - SelCount;
            for (int i = 0; i < ClipboardSize; i++) {
                MIClipboard[i] = Code[index + SelCount + i];
                CMClipboard[i] = CodeListView->Items->Item[index + SelCount + i]->SubItems->Strings[2];
            }
        }
    } else
        PostMessage(ActiveControl->Handle, WM_COPY, 0, 0);
    PasteItem->Enabled = true;
    PasteToolButton->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::PasteItemClick(TObject *Sender)
{
    if (ActiveControl == CodeListView && !InputEdit->Visible) {
        int index = CodeListView->ItemFocused->Index;
        if (InsertItem->Checked)
            //сдвигаем все инструкции на ClipboardSize позиций вправо
            for (int i = MAX_ADDR - 1; i >= index + ClipboardSize; i--) {
                Code[i] = Code[i - ClipboardSize];
                CodeListView->Items->Item[i]->SubItems->Strings[1] =
                    CodeListView->Items->Item[i - ClipboardSize]->SubItems->Strings[1];
                CodeListView->Items->Item[i]->SubItems->Strings[2] =
                    CodeListView->Items->Item[i - ClipboardSize]->SubItems->Strings[2];
            }
        //на освободившееся место помещаем инструкции из буфера обмена
        for (int i = 0; i < ClipboardSize; i++)
            if (index + i < MAX_ADDR) {
                Code[index + i] = MIClipboard[i];
                char str[64];
                CPU.Format(Code[index + i], str);
                CodeListView->Items->Item[index + i]->SubItems->Strings[1] = str;
                CodeListView->Items->Item[index + i]->SubItems->Strings[2] = CMClipboard[i];
            }
        SelCount = ClipboardSize;
        if (index + SelCount > MAX_ADDR)
            SelCount = MAX_ADDR - index;
        CodeListView->Repaint();
        SetModifyFlag(true);
    } else
        PostMessage(ActiveControl->Handle, WM_PASTE, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::DeleteItemClick(TObject *Sender)
{
    if (ActiveControl == CodeListView && !InputEdit->Visible) {
        if (InsertItem->Checked) {
            //сдвигаем все инструкции на SelCount позиций влево
            for (int i = CodeListView->ItemIndex; i < MAX_ADDR; i++)
                if (i + SelCount < MAX_ADDR) {
                    Code[i] = Code[i + SelCount];
                    CodeListView->Items->Item[i]->SubItems->Strings[1] =
                        CodeListView->Items->Item[i + SelCount]->SubItems->Strings[1];
                    CodeListView->Items->Item[i]->SubItems->Strings[2] =
                        CodeListView->Items->Item[i + SelCount]->SubItems->Strings[2];
                } else {
                    //очищаем инструкции
                    Code[i] = NOP;
                    CodeListView->Items->Item[i]->SubItems->Strings[1] = NOP_TEXT;
                    CodeListView->Items->Item[i]->SubItems->Strings[2] = "";
                }
            //снимаем выделение
            SelCount = 1;
        } else
            //очищаем выделенные инструкции
            for (int i = CodeListView->ItemIndex; i < CodeListView->ItemIndex + SelCount; i++) {
                Code[i] = NOP;
                CodeListView->Items->Item[i]->SubItems->Strings[1] = NOP_TEXT;
                CodeListView->Items->Item[i]->SubItems->Strings[2] = "";
            }
        CodeListView->Repaint();
        SetModifyFlag(true);
    }
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::InsertItemClick(TObject *Sender)
{
    InsertItem->Checked = !InsertItem->Checked;
    StatusBar->Panels->Items[4]->Text = InsertItem->Checked ? "INS" : "";
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
        TMaskEdit *MaskEdit = dynamic_cast<TMaskEdit *>(FindComponent("RMaskEdit" + IntToStr(i)));
        MaskEdit->Text = "0000 0000 0000 0000";
        MaskEdit->Font->Color = clBlack;
    }
    //сбрасываем флаги
    InFlags1->Checked = true; InFlags2->Checked = true; InFlags3->Checked = false; InFlags4->Checked = false;
    for (int i = 0; i < 12; i++)
        dynamic_cast<TCheckBox *>(FindComponent("OutFlags" + IntToStr(i)))->Checked = i >= 1 && i <= 4;
    //перерисовываем редактор кода
    Instruction = 0;
    CodeListView->ItemIndex = 0;
    SelCount = 1;
    CodeListView->ItemFocused = CodeListView->Items->Item[0];
    CodeListView->Repaint();
    Terminated = true;
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::HelpItemClick(TObject *Sender)
{
    ShellExecute(NULL, NULL, "X584.doc", NULL, NULL, 0);
}
//---------------------------------------------------------------------------

void __fastcall TX584Form::AboutItemClick(TObject *Sender)
{
    AboutForm->ShowModal();
}
//---------------------------------------------------------------------------


