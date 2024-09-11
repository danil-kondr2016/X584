//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ToolWin.hpp>
#include <AppEvnts.hpp>
#include <ExtCtrls.hpp>
#include "K584core.h"
#include "Word_2K_SRVR.h"
#include <OleServer.hpp>
//---------------------------------------------------------------------------

#define MAX_ADDR        1024

class TX584Form : public TForm
{
__published:	// IDE-managed Components
    TListView *CodeListView;
    TImageList *LeftImageList;
    TImageList *CheckImageList;
    TImageList *EmptyImageList;
    TImageList *ButtonsImageList;
    TImageList *TreeImageList;
    TTreeView *CodeTreeView;
    TGroupBox *RegGroupBox;
    TGroupBox *BusGroupBox;
    TLabel *RLabel0;
    TLabel *RLabel1;
    TLabel *RLabel2;
    TLabel *RLabel3;
    TLabel *RLabel4;
    TLabel *RLabel5;
    TLabel *RLabel6;
    TLabel *RLabel7;
    TLabel *WRLabel;
    TLabel *XWRLabel;
    TMaskEdit *RMaskEdit0;
    TMaskEdit *RMaskEdit1;
    TMaskEdit *RMaskEdit2;
    TMaskEdit *RMaskEdit3;
    TMaskEdit *RMaskEdit4;
    TMaskEdit *RMaskEdit5;
    TMaskEdit *RMaskEdit6;
    TMaskEdit *RMaskEdit7;
    TMaskEdit *RMaskEdit8;
    TMaskEdit *RMaskEdit9;
    TMaskEdit *RMaskEdit10;
    TMaskEdit *RMaskEdit11;
    TLabel *OutLabel;
    TLabel *AddrLabel;
    TGroupBox *InGroupBox;
    TCheckBox *InFlags1;
    TCheckBox *InFlags2;
    TCheckBox *InFlags3;
    TCheckBox *InFlags4;
    TGroupBox *OutGroupBox;
    TCheckBox *OutFlags0;
    TCheckBox *OutFlags1;
    TCheckBox *OutFlags2;
    TCheckBox *OutFlags3;
    TCheckBox *OutFlags4;
    TCheckBox *OutFlags5;
    TCheckBox *OutFlags6;
    TCheckBox *OutFlags7;
    TCheckBox *OutFlags8;
    TCheckBox *OutFlags9;
    TCheckBox *OutFlags10;
    TCheckBox *OutFlags11;
    TGroupBox *FilterOpGroupBox;
    TButton *FilterOpRegButton;
    TButton *FilterOpWRButton;
    TButton *FilterOpXWRButton;
    TButton *FilterOpInButton;
    TButton *FilterOpCarryButton;
    TButton *FilterResRegButton;
    TButton *FilterResWRButton;
    TButton *FilterResXWRButton;
    TButton *FilterResOutButton;
    TButton *FilterResWRXWRButton;
    TGroupBox *DescGroupBox;
    TMemo *DescMemo;
    TMainMenu *MainMenu;
    TMenuItem *FileMenu;
    TMenuItem *NewItem;
    TMenuItem *OpenItem;
    TMenuItem *SaveItem;
    TMenuItem *SaveAsItem;
    TMenuItem *Item1;
    TMenuItem *ExportItem;
    TMenuItem *WordItem;
    TMenuItem *Item2;
    TMenuItem *ExitItem;
    TMenuItem *EditMenu;
    TMenuItem *CutItem;
    TMenuItem *CopyItem;
    TMenuItem *PasteItem;
    TMenuItem *DeleteItem;
    TMenuItem *Item3;
    TMenuItem *InsertItem;
    TMenuItem *DebugMenu;
    TMenuItem *RunItem;
    TMenuItem *StepItem;
    TMenuItem *RunToCursorItem;
    TMenuItem *Item4;
    TMenuItem *BreakItem;
    TMenuItem *ResetItem;
    TMenuItem *HelpMenu;
    TMenuItem *HelpItem;
    TMenuItem *Item5;
    TMenuItem *AboutItem;
    TOpenDialog *OpenDialog;
    TSaveDialog *SaveDialog;
    TToolBar *ToolBar;
    TToolButton *NewToolButton;
    TToolButton *OpenToolButton;
    TToolButton *SaveToolButton;
    TToolButton *WordToolButton;
    TToolButton *ExitToolButton;
    TToolButton *Separator1;
    TToolButton *CutToolButton;
    TToolButton *CopyToolButton;
    TToolButton *PasteToolButton;
    TToolButton *DeleteToolButton;
    TToolButton *Separator2;
    TToolButton *RunToolButton;
    TToolButton *StepToolButton;
    TToolButton *RunToCursorToolButton;
    TToolButton *Separator3;
    TToolButton *BreakToolButton;
    TToolButton *ResetToolButton;
    TToolButton *Separator4;
    TToolButton *HelpToolButton;
    TToolButton *AboutToolButton;
    TStatusBar *StatusBar;
    TApplicationEvents *ApplicationEvents;
    TEdit *InputEdit;
    TTimer *ClickTimer;
    TWordApplication *WordApplication;
    TWordDocument *WordDocument;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall ApplicationEventsHint(TObject *Sender);
    void __fastcall ApplicationEventsIdle(TObject *Sender, bool &Done);
    void __fastcall CodeListViewCustomDrawItem(TCustomListView *Sender,
          TListItem *Item, TCustomDrawState State, bool &DefaultDraw);
    void __fastcall CodeListViewMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall CodeListViewDblClick(TObject *Sender);
    void __fastcall CodeListViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ClickTimerTimer(TObject *Sender);
    void __fastcall InputEditExit(TObject *Sender);
    void __fastcall InputEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ControlsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CodeListViewDragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
    void __fastcall CodeListViewDragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
    void __fastcall CodeTreeViewChange(TObject *Sender, TTreeNode *Node);          
    void __fastcall CodeTreeViewDblClick(TObject *Sender);
    void __fastcall CodeTreeViewExpanded(TObject *Sender, TTreeNode *Node);
    void __fastcall CodeTreeViewCollapsed(TObject *Sender,
          TTreeNode *Node);
    void __fastcall FilterOpButtonClick(TObject *Sender);
    void __fastcall FilterResButtonClick(TObject *Sender);
    void __fastcall RegMaskEditKeyPress(TObject *Sender, char &Key);
    void __fastcall RegMaskEditChange(TObject *Sender);
    void __fastcall RegMaskEditDblClick(TObject *Sender);
    void __fastcall NewItemClick(TObject *Sender);
    void __fastcall OpenItemClick(TObject *Sender);
    void __fastcall SaveItemClick(TObject *Sender);
    void __fastcall SaveAsItemClick(TObject *Sender);
    void __fastcall WordItemClick(TObject *Sender);
    void __fastcall ExitItemClick(TObject *Sender);
    void __fastcall CutItemClick(TObject *Sender);
    void __fastcall CopyItemClick(TObject *Sender);
    void __fastcall PasteItemClick(TObject *Sender);
    void __fastcall DeleteItemClick(TObject *Sender);
    void __fastcall InsertItemClick(TObject *Sender);
    void __fastcall RunItemClick(TObject *Sender);
    void __fastcall StepItemClick(TObject *Sender);
    void __fastcall RunToCursorItemClick(TObject *Sender);
    void __fastcall BreakItemClick(TObject *Sender);
    void __fastcall ResetItemClick(TObject *Sender);
    void __fastcall HelpItemClick(TObject *Sender);
    void __fastcall AboutItemClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    K584 CPU;                           //объект процессора
    unsigned Code[MAX_ADDR];            //массив инструкций
    int Instruction;                    //индекс текущей инструкции
    int OpFilter;                       //текущий фильтр операндов
    int ResFilter;                      //текущий фильтр результата
    TButton *ResButton;                 //предыдущая выделенная кнопка фильтра результатов
    unsigned Regs[12];                  //регистры и шины
    unsigned InFlags, OutFlags;         //входные и выходные флаги
    int SelCount;                       //количество выделенных строк
    unsigned MIClipboard[MAX_ADDR];     //буфер обмена для микроинструкций
    AnsiString CMClipboard[MAX_ADDR];   //буфер обмена для комментариев
    int ClipboardSize;                  //размер буфера обмена
    bool Modified;                      //флаг изменений
    int EditRow;                        //строка редактирования
    TPoint EditPoint;                   //точка редактирования
    bool Terminated;                    //флаг завершения выполнения
    int OldInstruction;                 //прежняя выполняемая инструкция
    void LoadFile(AnsiString FileName);
    void SaveFile(AnsiString FileName);
    void SetModifyFlag(bool Flag);
    void EnableRunControls(bool Flag);
    void BuildTree(int OpFilter, int ResFilter);
    void DrawItem(int Index);
    bool ParseComment(AnsiString str, int &Instruction);
    void ShowState();
    void Run(int Mode);
    __fastcall TX584Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TX584Form *X584Form;
//---------------------------------------------------------------------------
#endif
