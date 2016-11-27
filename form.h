//---------------------------------------------------------------------------

#ifndef formH
#define formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxStatusBar.hpp"
#include <IdAntiFreeze.hpp>
#include <IdAntiFreezeBase.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "PgAccess.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TdxStatusBar *dxStatusBar1;
	TEdit *Shtrih;
	TSpeedButton *SpeedButton1;
	TLabel *Label1;
	TButton *ButtonGo;
	TButton *ButtonClose;
	TPgConnection *Connection;
	TPgQuery *PgQuery;
	TLabel *LabelResult;
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall ShtrihChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
	UnicodeString __fastcall GetAppVer();
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	UnicodeString lIniFileName;
	void __fastcall FatalError(System::UnicodeString Message = "FATAL ERROR\npress ESCAPE");
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
