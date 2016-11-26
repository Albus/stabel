//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form.h"
#include "ping.h"
#include "pgquery.h"
//---------------------------------------------------------------------------
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

System::UnicodeString DayMessage = "Вы работаете в\nДНЕВНУЮ смену" ;
System::UnicodeString NightMessage = "Вы работаете в\nНОЧНУЮ смену" ;
System::UnicodeString ConfigNotExistMessage = "НЕ МОГУ НАЙТИ ФАЙЛ КОНФИГУРАЦИИ БД.\n\n(для выхода нажмите ESCAPE)" ;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormActivate(TObject *Sender)
{
	PingTread->FreeOnTerminate = true;
	PingTread->Start();

}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	PingTread->Terminate();
}

//---------------------------------------------------------------------------


void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{
	Label1->Caption = !SpeedButton1->Down ? DayMessage : NightMessage ;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
	lIniFileName = ExtractFilePath(Application->ExeName) + "\\cfg\\aptrtlwh.cfg";
	if(!FileExists(lIniFileName,true)){
		this->Enabled = false;
		Label1->Font->Color = clRed ;
		Label1->Caption = ConfigNotExistMessage;
	} else {
		Label1->Caption = DayMessage ;
		SpeedButton1->Down = false ;
	}

}
//---------------------------------------------------------------------------


void __fastcall TForm2::ButtonCloseClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ShtrihChange(TObject *Sender)
{
	if (Shtrih->GetTextLen()==13) {

	}
}
//---------------------------------------------------------------------------

