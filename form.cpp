﻿#include <vcl.h>
#pragma hdrstop

#include "form.h"
#include "ping.h"


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
#
HANDLE hFont;

const short ExitTimeOut = 30;

TSelfTabel *SelfTabel;
ping *PingTread = new ping(true);

INT64 AllowedAction;

UnicodeString DayMessage = "Вы работаете в ДНЕВНУЮ смену";

UnicodeString AllDayMessage = "Вы работаете в СУТОЧНУЮ смену";

UnicodeString NightMessage = "Вы работаете в НОЧНУЮ смену";

UnicodeString ConfigNotExistMessage =
	"НЕ МОГУ НАЙТИ ФАЙЛ КОНФИГУРАЦИИ.\n\n(для выхода нажмите ESCAPE)";

UnicodeString ConfigCanNotFindDBSectionMessage =
	"НЕ МОГУ НАЙТИ СЕКЦИЮ [DB] В ФАЙЛЕ КОНФИГУРАЦИИ.\n\n(для выхода нажмите ESCAPE)";

UnicodeString PgCanNotConnect =
	"НЕ МОГУ ПОДКЛЮЧИТЬСЯ К БАЗЕ ДАННЫХ\n\n(для выхода нажмите ESCAPE)";

TLastInputInfo lpi;

// ---------------------------------------------------------------------------
__fastcall TSelfTabel::TSelfTabel(TComponent* Owner) : TForm(Owner) {

}
// ---------------------------------------------------------------------------

void __fastcall TSelfTabel::FormCloseQuery(TObject *Sender, bool &CanClose) {
	PingTread->Terminate();
}

// ---------------------------------------------------------------------------
void __fastcall TSelfTabel::FatalError(UnicodeString Message) {
	this->Enabled = false;
	Label1->Font->Color = clRed;
	Label1->Caption = Message;
}

// ---------------------------------------------------------------------------

void __fastcall TSelfTabel::ButtonCloseClick(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TSelfTabel::Status(UnicodeString text) {
	StaText->Text = text;
	dxStatusBar1->Repaint();
}

_di_selftabelPortType _fastcall TSelfTabel::SOAP() {
	return (GetselftabelPortType(false,
		"http://" + AP->Text + "/jex/ws/selftabel.1cws", NULL));
}

void __fastcall TSelfTabel::GetAllowedActions() {
	if (AP->Text.Length() > 0) {
		Status("Выполняем запрос к серверу .....");
		AllowedAction = SOAP()->GetAllowedAction(aNum->Text.ToInt(),
			Shtrih->Text);
		Status("Запрос к серверу завершен");
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

void __fastcall TSelfTabel::ShtrihChange(TObject *Sender) {
	if (Shtrih->GetTextLen() == 13) {
		Label1->Caption = "НУЖНО ВЫБРАТЬ ТИП СМЕНЫ";
		grpOperationMode->Enabled = true;
		Shtrih->Enabled = false;
		SelfTabel->Repaint();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TSelfTabel::FormCreate(TObject *Sender) {

	Application->OnDeactivate = &AppDeactivate;
    lpi.cbSize = sizeof(lpi);
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
			ColorANum = clGreen;
			aNum->Text = AptNum;
		}
		catch (...) {
			ColorANum = clRed;
		}

		PgQuery->Close();
		Connection->Disconnect();
	}
	else
		goto connect;

	PingTread->Start();
   	Timer1000->FreeOnRelease();
	Shtrih->Font->Name = "Comfortaa";
	Shtrih->Font->Charset = RUSSIAN_CHARSET;

}

bool __fastcall TSelfTabel::DayOrNight() {
	return (btnDay->Down ? false : true);
}

void __fastcall TSelfTabel::ButtonGoClick(TObject *Sender) {
	switch (AllowedAction) {
	case 1: // открытие смены
		Status("Запрос к серверу на открытие смены .....");
		LabelResult->Caption = SOAP()->CheckIn(aNum->Text.ToInt(), Shtrih->Text,
			DayOrNight());
		Status("Запрос к серверу завершен");
		break; // конец: открытие смены
	case 2: // закрытие смены
		Status("Запрос к серверу на закрытие смены .....");
		LabelResult->Caption = SOAP()->CheckOut(aNum->Text.ToInt(),
			Shtrih->Text, DayOrNight());
		Status("Запрос к серверу завершен");
		break; // конец: закрытие смены
	}
}
// ---------------------------------------------------------------------------

void __fastcall TSelfTabel::FormResize(TObject *Sender) {
	int Width = (grpOperationMode->Width - grpOperationMode->Padding->Right -
		grpOperationMode->Padding->Left) / 3;
	btnDay->Width = Width;
	btnNight->Width = Width;
}

// ---------------------------------------------------------------------------
void __fastcall TSelfTabel::btnDayClick(TObject *Sender) {
	if (btnDay->Down) {
		Label1->Caption = DayMessage;
		GetAllowedActions();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TSelfTabel::btnAllDayClick(TObject *Sender) {
	if (btnAllDay->Down) {
		Label1->Caption = AllDayMessage;
		GetAllowedActions();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TSelfTabel::btnNightClick(TObject *Sender) {
	if (btnNight->Down) {
		Label1->Caption = NightMessage;
		GetAllowedActions();
	}
}

// ---------------------------------------------------------------------------

void __fastcall TSelfTabel::AppDeactivate(TObject *Sender) {
	Close();
}

void __fastcall TSelfTabel::Timer1000Timer(TObject *Sender)
{
	static short t = ExitTimeOut;
	static unsigned long LastTime = 0;
	if(t==0)Close();
	GetLastInputInfo(&lpi);
	unsigned long CurrTime = lpi.dwTime;
	if(LastTime==CurrTime)t--;
	else {
		t = ExitTimeOut;
		LastTime = CurrTime;
	}
	byte a = (t*255)/ExitTimeOut;
	ColorExitTimer = RGB(255-a,a,0);
	ExitTimer->Text = String(t);
	dxStatusBar1->Refresh();

}
