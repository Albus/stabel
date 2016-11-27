#include <vcl.h>
#pragma hdrstop

#include "form.h"
#include "ping.h"

#include "soap.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxStatusBar"
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "PgAccess"
#pragma resource "*.dfm"
TForm2 *Form2;
ping *PingTread = new ping(true);
_di_selftabelPortType *SOAP;
INT64 AllowedAction;

System::UnicodeString DayMessage = "Вы работаете в\nДНЕВНУЮ смену";

System::UnicodeString NightMessage = "Вы работаете в\nНОЧНУЮ смену";

UnicodeString ConfigNotExistMessage =
	"НЕ МОГУ НАЙТИ ФАЙЛ КОНФИГУРАЦИИ.\n\n(для выхода нажмите ESCAPE)";

UnicodeString ConfigCanNotFindDBSectionMessage =
	"НЕ МОГУ НАЙТИ СЕКЦИЮ [DB] В ФАЙЛЕ КОНФИГУРАЦИИ.\n\n(для выхода нажмите ESCAPE)";

UnicodeString PgCanNotConnect =
	"НЕ МОГУ ПОДКЛЮЧИТЬСЯ К БАЗЕ ДАННЫХ\n\n(для выхода нажмите ESCAPE)";

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {

}
// ---------------------------------------------------------------------------

void __fastcall TForm2::FormCloseQuery(TObject *Sender, bool &CanClose) {
	PingTread->Terminate();
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::FatalError(UnicodeString Message) {
	this->Enabled = false;
	Label1->Font->Color = clRed;
	Label1->Caption = Message;
}

void __fastcall TForm2::SpeedButton1Click(TObject *Sender) {
	Label1->Caption = !SpeedButton1->Down ? DayMessage : NightMessage;
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::ButtonCloseClick(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::ShtrihChange(TObject *Sender) {
	if (Shtrih->GetTextLen() == 13) {
		Shtrih->Enabled = false;
		Shtrih->Repaint();
		if (dxStatusBar1->Panels->Items[3]->Text.Length() > 0) {
			_di_selftabelPortType SOAP =
				GetselftabelPortType(false,
				"http://" + dxStatusBar1->Panels->Items[3]->Text +
				"/jex/ws/selftabel.1cws", NULL);
			AllowedAction =
				SOAP->GetAllowedAction
				(dxStatusBar1->Panels->Items[2]->Text.ToInt(), Shtrih->Text);
			switch (AllowedAction) {
			case 0:
				LabelResult->Caption =
					"Вы не можете открыть или закрыть смену\nСервер не принял ваш штрих-код";
				ButtonGo->Caption = "";
				ButtonGo->Enabled = false;
				break;
			case 1:
				LabelResult->Caption = "Вы можете открыть смену";
				ButtonGo->Caption = "ОТКРЫТЬ СМЕНУ";
				ButtonGo->Enabled = true;
				break;
			case 2:
				LabelResult->Caption = "Вы можете закрыть смену";
				ButtonGo->Caption = "ЗАКРЫТЬ СМЕНУ";
				ButtonGo->Enabled = true;
				break;
			case 3:
				LabelResult->Caption = "Сервер выдал не верный результат №3";
				ButtonGo->Caption = "";
				ButtonGo->Enabled = false;
				break;
			}
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender) {
	PingTread->FreeOnTerminate = true;

	TIniFile *lIni = NULL;
	UnicodeString lIniFileName = ExtractFilePath(Application->ExeName) +
		"\\cfg\\aptrtlwh.cfg";
	if (!FileExists(lIniFileName, true)) {
		FatalError(ConfigNotExistMessage);
		return;
	}
	else
		lIni = new TIniFile(lIniFileName);
	if (!lIni->SectionExists("DB")) {
		FatalError(ConfigCanNotFindDBSectionMessage);
		return;
	}
	Connection->Server = lIni->ReadString("DB", "server", "1.1.1.1");
	Connection->Port = lIni->ReadInteger("DB", "port", 5432);
	Connection->Database = lIni->ReadString("DB", "database", "blabla");
	Connection->Username = lIni->ReadString("DB", "username", "blabla");
	Connection->Password = lIni->ReadString("DB", "password", "blabla");
	lIni->FreeInstance();

connect:
	try {
		Connection->Connect();
	}
	catch (...) {
		FatalError(PgCanNotConnect);
		return;
	}
	if (Connection->Connected) // Сервер аптеки достуен
	{
		PgQuery->SQL->Add("select id_dep from conf.const limit 1;");
		PgQuery->Open();
		UnicodeString AptNum = PgQuery->FieldByName("id_dep")->AsString;
		try {
			StrToInt(AptNum);
			dxStatusBar1->Panels->Items[2]->PanelStyle->Font->Color = clGreen;
			dxStatusBar1->Panels->Items[2]->Text = AptNum;
		}
		catch (...) {
			dxStatusBar1->Panels->Items[2]->PanelStyle->Font->Color = clRed;
		}

		PgQuery->Close();
		Connection->Disconnect();
	}
	else
		goto connect;

	PingTread->Start();
	Label1->Caption = DayMessage;
	SpeedButton1->Down = false;

}
