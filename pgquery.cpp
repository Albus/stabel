#include <vcl.h>
#pragma hdrstop
#include "pgquery.h"
#pragma package(smart_init)

__fastcall PgQuery::PgQuery(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}

UnicodeString *FatalErrorMessage;
void __fastcall PgQuery::FatalError ()
{

}

void __fastcall PgQuery::Execute()
{
	NameThreadForDebugging("PgQuery");
	TIniFile *lIni = NULL;
	UnicodeString lIniFileName = ExtractFilePath(Application->ExeName) + "\\cfg\\aptrtlwh.cfg";
	if(!FileExists(lIniFileName,true)){
		FatalErrorMessage = &ConfigNotExistMessage;
		Synchronize(&FatalError);
		return;
	} else lIni = new TIniFile(lIniFileName);
	if (!lIni->SectionExists("DB")) {
		FatalErrorMessage = &ConfigCanNotFindDBSectionMessage;
		Synchronize(&FatalError);
		return;
	}
	Connection->Server	 = lIni->ReadString("DB", "server", "1.1.1.1");
	Connection->Port     = lIni->ReadInteger("DB", "port", 5432);
	Connection->Database = lIni->ReadString("DB", "database", "blabla");
	Connection->Username = lIni->ReadString("DB", "username", "blabla");
	Connection->Password = lIni->ReadString("DB", "password", "blabla");
	try { Connection->Connect();
	} catch (...) {
		FatalErrorMessage = &PgCanNotConnect;
		Synchronize(&FatalError);
		return;
	}
}
