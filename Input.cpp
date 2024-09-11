//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Input.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInputForm *InputForm;
//---------------------------------------------------------------------------
__fastcall TInputForm::TInputForm(TComponent* Owner)
    : TForm(Owner), Value(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TInputForm::RMaskEditKeyPress(TObject *Sender, char &Key)
{
    //фильтруем ненужные цифры
    if (Key >= '2' && Key <= '9')
        Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TInputForm::RMaskEditChange(TObject *Sender)
{
    //форматируем текст
    AnsiString str = RMaskEdit->Text;
    for (int i = 1; i <= str.Length(); i++)
        if (str[i] == ' ' && i % 5 != 0)
            str[i] = '0';
    if (str != RMaskEdit->Text) {
        int pos = RMaskEdit->SelStart;
        RMaskEdit->Text = str;
        RMaskEdit->SelStart = pos;
    }
    //переводим в десятичную систему счисления
    Value = 0;
    for (int i = 1, num = 1; i <= 19; i++)
        if (i % 5) {
            Value += str[i] == '1' ? 1 << 16 - num : 0;
            num++;
        }
    RDecMaskEdit->Text = AnsiString().sprintf("%05d", Value);
}
//---------------------------------------------------------------------------

void __fastcall TInputForm::RDecMaskEditChange(TObject *Sender)
{
    //получаем и форматируем значение поля
    AnsiString str = RDecMaskEdit->Text;
    for (int i = 1; i <= str.Length(); i++)
        if (str[i] == ' ')
            str[i] = '0';
    Value = StrToInt(str);
    if (Value > 65535) {
        Value = 65535;
        str = "65535";
    }
    if (str != RDecMaskEdit->Text)
    {
        int pos = RDecMaskEdit->SelStart;
        RDecMaskEdit->Text = str;
        RDecMaskEdit->SelStart = pos;
    }
    //отображаем его в двоичном виде на флажках и в поле ввода
    str = "";
    for (int i = 15; i >= 0; i--) {
        TCheckBox *CheckBox = dynamic_cast<TCheckBox *>(FindComponent("CheckBox" + IntToStr(i)));
        CheckBox->OnClick = NULL;
        CheckBox->Checked = Value & 1 << i;
        CheckBox->OnClick = CheckBoxClick;
        str += Value & 1 << i ? '1' : '0';
        if (i % 4 == 0 && i != 0)
            str += ' ';
    }
    RMaskEdit->OnChange = NULL;
    RMaskEdit->Text = str;
    RMaskEdit->OnChange = RMaskEditChange;
}
//---------------------------------------------------------------------------

void __fastcall TInputForm::CheckBoxClick(TObject *Sender)
{
    //переводим в десятичную систему счисления
    Value = 0;
    for (int i = 0; i < 16; i++)
        Value += dynamic_cast<TCheckBox *>(FindComponent("CheckBox" + IntToStr(i)))->Checked ? 1 << i : 0;
    RDecMaskEdit->Text = AnsiString().sprintf("%05d", Value);
}
//---------------------------------------------------------------------------
