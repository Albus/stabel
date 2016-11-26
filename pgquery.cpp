//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pgquery.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall PgQuery::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall PgQuery::PgQuery(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall PgQuery::Execute()
{
	NameThreadForDebugging("PgQuery");
	//---- Place thread code here ----
//	UnicodeString lIniFileName = ExtractFilePath(Application->ExeName) + "\\cfg\\aptrtlwh.cfg";
//		if (!FileExists(lIniFileName)) throw Exception("Не найден файл " + lIniFileName);
//		TIniFile * lIni = new TIniFile(lIniFileName);
//		if (!lIni->SectionExists("DB")) throw Exception("В файле настроек не найдена секция [DB]");
//		Connection->Server   = lIni->ReadString("DB", "server", "1.1.1.1");
//		Connection->Port     = lIni->ReadInteger("DB", "port", 5432);
//		Connection->Database = lIni->ReadString("DB", "database", "blabla");
//		Connection->Username = lIni->ReadString("DB", "username", "blabla");
//		Connection->Password = lIni->ReadString("DB", "password", "blabla");
//		try
//		{
//			Connection->Connect();
//		}
//		catch (Exception &E)
//		{
//			throw Exception("Не могу установить соединение с базой");
//		}
//		if(Connection->Connected) // Сервер аптеки достуен
//		{
//			PgQuery1->Open();
//			AptNum->Text = PgQuery1->FieldByName("id_dep")->AsString;
//			PgQuery1->Close();
//			Connection->Disconnect();
//
//			ShtrihCode->Enabled = True; // ШК РАЗРЕШИТЬ
//			AptNum->Enabled = False;// Номер аптеки ЗАПРЕТИТЬ
//
//			ShtrihCode->Color = FormGreen;
//			AptNum->Color = FormGray;
//
//		}
//		else  // Сервер аптеки НЕ доступен
//		{
//			ShtrihCode->Enabled = False;// ШК ЗАПРЕТИТЬ
//			AptNum->Enabled = False;// Номер аптеки ЗАПРЕТИТЬ
//
//			ShtrihCode->Color = FormRed;
//			AptNum->Color = FormGray;
//
//			ShowMessage("ОШИБКА: не доступен сервер аптеки !!!");
//		}

}
//---------------------------------------------------------------------------
