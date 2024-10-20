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
#pragma hdrstop

#include "FileExport.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

TExportThread::TExportThread(bool CreateSuspended)
: TThread(CreateSuspended)
{
}

void __fastcall TExportThread::Execute()
{
    X584Form->WordItem->Enabled = false;
    X584Form->WordToolButton->Enabled = false;
    //соединяемся с сервером автоматизации
    CoInitialize(NULL);
    X584Form->WordApplication->Connect();
    //создаем новый документ и отключаем проверку орфографии
    X584Form->WordApplication->Documents->Add(EmptyParam(), EmptyParam(), EmptyParam(), EmptyParam());
    X584Form->WordDocument->ConnectTo(X584Form->WordApplication->ActiveDocument);
    X584Form->WordApplication->Options->CheckSpellingAsYouType = False;
    X584Form->WordApplication->Options->CheckGrammarAsYouType = False;
    //записываем заголовок
    X584Form->WordApplication->Selection->Font->Size = 14;
    X584Form->WordApplication->Selection->Font->Bold = true;
    X584Form->WordApplication->Selection->ParagraphFormat->Alignment = WdParagraphAlignment::wdAlignParagraphCenter;
    X584Form->WordApplication->Selection->TypeText(StringToOleStr(X584Form->Caption + L"\n"));
    //записываем дату и время создания
    TDateTime dt = Now();
    X584Form->WordApplication->Selection->Font->Size = 12;
    X584Form->WordApplication->Selection->Font->Bold = false;
    X584Form->WordApplication->Selection->Font->Italic = true;
    X584Form->WordApplication->Selection->ParagraphFormat->Alignment = WdParagraphAlignment::wdAlignParagraphLeft;
    X584Form->WordApplication->Selection->TypeText(StringToOleStr(L"\nДата создания: " + DateToStr(dt) + L"\n"));
    X584Form->WordApplication->Selection->TypeText(StringToOleStr(L"Время создания: " + TimeToStr(dt) + L"\n\n"));
    //определяем количество используемых строк
    int count = MAX_ADDR - 1;
    while (count >= 0 && X584Form->Code[count] == NOP && X584Form->CodeListView->Items->Item[count]->SubItems->Strings[2] == L"")
        count--;
    count++;
    //создаем и настраиваем таблицу
    X584Form->WordApplication->Selection->Font->Size = 12;
    X584Form->WordApplication->Selection->Font->Italic = false;
    TVariant start = X584Form->WordApplication->Selection->Start;
    X584Form->WordDocument->Tables->Add(X584Form->WordDocument->Range(start, EmptyParam()),
        count + 1, 4, EmptyParam(), EmptyParam());
    Table *table = X584Form->WordDocument->Tables->Item(1);
    table->Borders->set_Enable(true);
    table->Columns->Item(1)->Width = 50;
    table->Columns->Item(2)->Width = 150;
    table->Columns->Item(3)->Width = 150;
    //заполняем заголовок
    UnicodeString Head[4] = {L"Адрес", L"Микроинструкция", L"Управляющий оператор", L"Комментарий"};
    for (int i = 0; i < 4; i++) {
        WordRange *range;
        table->Cell(1, i + 1)->get_Range(&range);
        range->ParagraphFormat->Alignment = WdParagraphAlignment::wdAlignParagraphCenter;
        range->Font->set_Bold(true);
        range->InsertAfter(StringToOleStr(Head[i]));
    }
    //заполняем поля таблицы
    for (int i = 0; i < count; i++)
        for (int j = 0; j < 4; j++) {
            WordRange *range;
            table->Cell(i + 2, j + 1)->get_Range(&range);
            range->ParagraphFormat->Alignment = j ? WdParagraphAlignment::wdAlignParagraphLeft : WdParagraphAlignment::wdAlignParagraphCenter;
            range->InsertAfter(StringToOleStr(X584Form->CodeListView->Items->Item[i]->SubItems->Strings[j]));
        }
    //показываем документ и завершаем работу
    X584Form->WordApplication->set_Visible(true);
    X584Form->WordDocument->Disconnect();
    X584Form->WordApplication->Disconnect();
    X584Form->WordItem->Enabled = true;
    X584Form->WordToolButton->Enabled = true;
    CoUninitialize();
}
