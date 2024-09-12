//---------------------------------------------------------------------------

#ifndef AboutH
#define AboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TAboutForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *HeaderPanel;
    TImage *InfoImage;
    TLabel *AboutLabel;
    TImage *IconImage;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TImage *WinXPImage;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *MailLabel2;
    TPanel *Panel1;
    TLabel *MemCaptionLabel;
    TButton *OKButton;
    TLabel *MemLabel;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall MailLabelClick(TObject *Sender);
    void __fastcall LinkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TAboutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
//---------------------------------------------------------------------------
#endif
