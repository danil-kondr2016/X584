//---------------------------------------------------------------------------

#ifndef InputH
#define InputH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include "Main.h"
//---------------------------------------------------------------------------
class TInputForm : public TForm
{
__published:	// IDE-managed Components
    TButton *OKButton;
    TButton *CancelButton;
    TGroupBox *GroupBox1;
    TMaskEdit *RMaskEdit;
    TCheckBox *CheckBox0;
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox3;
    TCheckBox *CheckBox4;
    TCheckBox *CheckBox5;
    TCheckBox *CheckBox6;
    TCheckBox *CheckBox7;
    TCheckBox *CheckBox8;
    TCheckBox *CheckBox9;
    TCheckBox *CheckBox10;
    TCheckBox *CheckBox11;
    TCheckBox *CheckBox12;
    TCheckBox *CheckBox13;
    TCheckBox *CheckBox14;
    TCheckBox *CheckBox15;
    TMaskEdit *RDecMaskEdit;    
    void __fastcall RMaskEditKeyPress(TObject *Sender, char &Key);
    void __fastcall RMaskEditChange(TObject *Sender);
    void __fastcall RDecMaskEditChange(TObject *Sender);
    void __fastcall CheckBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    int Value;      //введенное значение
    __fastcall TInputForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInputForm *InputForm;
//---------------------------------------------------------------------------
#endif
