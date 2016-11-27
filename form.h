// ---------------------------------------------------------------------------

#ifndef formH
#define formH
// ---------------------------------------------------------------------------
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
#include "soap.h"

// ---------------------------------------------------------------------------
class TSelfTabel : public TForm {
__published: // IDE-managed Components

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
	void __fastcall ButtonGoClick(TObject *Sender);

private: // User declarations
	UnicodeString __fastcall GetAppVer();
	_di_selftabelPortType _fastcall SOAP();

public: // User declarations
	__fastcall TSelfTabel(TComponent* Owner);

	UnicodeString lIniFileName;

	void __fastcall FatalError(System::UnicodeString Message =
		"FATAL ERROR\npress ESCAPE");
	void __fastcall Status(UnicodeString text = "");
};

// ---------------------------------------------------------------------------
extern PACKAGE TSelfTabel *SelfTabel;
// ---------------------------------------------------------------------------

#define VPN dxStatusBar1->Panels->Items[0]
#define WWW dxStatusBar1->Panels->Items[1]
#define aNum dxStatusBar1->Panels->Items[2]
#define AP dxStatusBar1->Panels->Items[3]

#define ColorVPN VPN->PanelStyle->Font->Color
#define ColorWWW WWW->PanelStyle->Font->Color
#define ColorANum aNum->PanelStyle->Font->Color
#define ColorAP WWW->PanelStyle->Font->Color

#endif
