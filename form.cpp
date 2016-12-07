#include <vcl.h>
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

	unsigned short ret = 0;

	if (AP->Text.Length() > 0) {
		Status("Выполняем запрос к серверу .....");

	request:
		try {
			AllowedAction = SOAP()->GetAllowedAction(aNum->Text.ToInt(),
				Shtrih->Text);
		}
		catch (Exception& E) {
			if (ret++ < 4) {
				Status(E.Message);
				goto request;
			}
		}
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
	UnicodeString lIniFileName = ExtractFilePath(Application->ExeName) +
		"\\cfg\\aptrtlwh.cfg";
	TIniFile *lIni = NULL;
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
	ProgressBarExitTimer->Min = 0;
	ProgressBarExitTimer->Max = ExitTimeOut;
	ProgressBarExitTimer->Position = ProgressBarExitTimer->Max;

	char chBuffV[255];
	char chLang[255];
	GetVersionOfFile(AnsiString(Application->ExeName).c_str(), chBuffV, 255,
		chLang, 255);
	VersionText->Text = String(chBuffV);

	SetWindowTheme(SelfTabel->WindowHandle, L" ", NULL);
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

void __fastcall TSelfTabel::Timer1000Timer(TObject *Sender) {
	static short t = ExitTimeOut;
	static unsigned long LastTime = 0;
	if (t == 0)
		Close();
	GetLastInputInfo(&lpi);
	unsigned long CurrTime = lpi.dwTime;
	if (LastTime == CurrTime)
		t--;
	else {
		t = ExitTimeOut;
		LastTime = CurrTime;
	}
	ProgressBarExitTimer->Position = t;
	Application->ProcessMessages();
}

void __fastcall TSelfTabel::GetVersionOfFile(char * pszAppName, // file
	char * pszVerBuff, // receives version
	int iVerBuffLen, // size of buffer
	char * pszLangBuff, // receives language
	int iLangBuffLen) // size of buffer
{
	DWORD dwScratch;
	DWORD * pdwLangChar;
	DWORD dwInfSize;
	UINT uSize;
	BYTE * pbyInfBuff;
	char szVersion[32];
	char szResource[80];
	char * pszVersion = szVersion;

	dwInfSize = GetFileVersionInfoSizeA(pszAppName, &dwScratch);

	if (dwInfSize) {
		pbyInfBuff = new BYTE[dwInfSize];
		memset(pbyInfBuff, 0, dwInfSize);
		if (pbyInfBuff) {
			if (GetFileVersionInfoA(pszAppName, 0, dwInfSize, pbyInfBuff)) {
				if (VerQueryValueA(pbyInfBuff, "\\VarFileInfo\\Translation",
					(void**)(&pdwLangChar), &uSize)) {
					if (VerLanguageNameA(LOWORD(*pdwLangChar), szResource,
						sizeof(szResource))) {
						strncpy(pszLangBuff, szResource, iLangBuffLen);
					}
					wsprintfA(szResource,
						"\\StringFileInfo\\%04X%04X\\FileVersion",
						LOWORD(*pdwLangChar), HIWORD(*pdwLangChar));

					if (VerQueryValueA(pbyInfBuff, szResource,
						(void**)(&pszVersion), &uSize)) {
						strncpy(pszVerBuff, pszVersion, iVerBuffLen - 1);
					}
				}
			}
			delete[]pbyInfBuff;
		}
	}
}

void __fastcall TSelfTabel::ThreadUpdatePgTableAfterRun(TIdThreadComponent *Sender)
{
	TPgQuery* query = new TPgQuery(Sender);
	query->Connection = Connection;

//CREATE SEQUENCE reg.reg_work_time_id_seq
//INCREMENT 1 MINVALUE 1
//MAXVALUE 9223372036854775807 START 1
//CACHE 1;
//CREATE OR REPLACE FUNCTION public.tf__reg_work_time__b01u (
//)
//RETURNS trigger AS
//$body$
//BEGIN
//  IF (OLD.time_end_client IS NULL) AND (NEW.time_end_client IS NOT NULL) THEN
//	NEW.time_end_server = now();
//  END IF;
//
//  RETURN NEW;
//END;
//$body$
//LANGUAGE 'plpgsql'
//VOLATILE
//CALLED ON NULL INPUT
//SECURITY INVOKER
//COST 100;
//
//CREATE TABLE reg.reg_work_time (
//  id INTEGER DEFAULT nextval('reg.reg_work_time_id_seq'::regclass) NOT NULL,
//  time_begin_server TIMESTAMP(0) WITH TIME ZONE DEFAULT now() NOT NULL,
//  time_begin_client TIMESTAMP(0) WITH TIME ZONE NOT NULL,
//  time_begin_inet TIMESTAMP(0) WITH TIME ZONE,
//  time_end_server TIMESTAMP(0) WITH TIME ZONE,
//  time_end_client TIMESTAMP(0) WITH TIME ZONE,
//  time_end_inet TIMESTAMP(0) WITH TIME ZONE,
//  login_key VARCHAR(32) NOT NULL,
//  is_night BOOLEAN NOT NULL,
//  time_sended TIMESTAMP(0) WITH TIME ZONE,
//  CONSTRAINT reg_work_time_pkey PRIMARY KEY(id)
//) ;
//
//ALTER TABLE reg.reg_work_time
//  ALTER COLUMN time_end_server SET STATISTICS 0;
//
//ALTER TABLE reg.reg_work_time
//  ALTER COLUMN time_end_client SET STATISTICS 0;
//
//ALTER TABLE reg.reg_work_time
//  ALTER COLUMN time_end_inet SET STATISTICS 0;
//
//COMMENT ON COLUMN reg.reg_work_time.id
//IS 'ID';
//
//COMMENT ON COLUMN reg.reg_work_time.time_begin_server
//IS 'Время начала смены (по данным сервера БД)';
//
//COMMENT ON COLUMN reg.reg_work_time.time_begin_client
//IS 'Время начала смены (по данным клиента)';
//
//COMMENT ON COLUMN reg.reg_work_time.time_begin_inet
//IS 'Время начала смены (по данным сервера NTP)';
//
//COMMENT ON COLUMN reg.reg_work_time.time_end_server
//IS 'Время окончания смены (по данным сервера БД)';
//
//COMMENT ON COLUMN reg.reg_work_time.time_end_client
//IS 'Время окончания смены (по данным клиента)';
//
//COMMENT ON COLUMN reg.reg_work_time.time_end_inet
//IS 'Время окончания смены (по данным сервера NTP)';
//
//COMMENT ON COLUMN reg.reg_work_time.login_key
//IS 'Ключ доступа (бейдж сотрудника)';
//
//COMMENT ON COLUMN reg.reg_work_time.is_night
//IS 'Признак ночной смены';
//
//COMMENT ON COLUMN reg.reg_work_time.time_sended
//IS 'Время отправки данных в офис';
//
//CREATE INDEX reg_work_time_idx ON reg.reg_work_time
//  USING btree (id)
//  WHERE (time_sended IS NULL);
//
//CREATE UNIQUE INDEX reg_work_time_idx1 ON reg.reg_work_time
//  USING btree (login_key COLLATE pg_catalog."default")
//  WHERE (time_end_server IS NULL);
//
//CREATE TRIGGER tr__reg_work_time__b01u
//  BEFORE UPDATE OF time_end_client
//  ON reg.reg_work_time FOR EACH ROW
//  EXECUTE PROCEDURE public.tf__reg_work_time__b01u();
//
//ALTER SEQUENCE reg.reg_work_time_id_seq OWNED BY reg.reg_work_time.id;

	query->Free();
}
//---------------------------------------------------------------------------

