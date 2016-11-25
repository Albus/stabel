//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form.h"
#include "ping.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxStatusBar"
#pragma resource "*.dfm"
TForm2 *Form2;
ping *PingTread = new ping(true);

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
