//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ping.h"
#include "form.h"

#pragma package(smart_init)
//#pragma link "IndyCore.bpi"

TIdTCPClient *IdTCPClientVPN = new TIdTCPClient(NULL);
TIdTCPClient *IdTCPClientWWW = new TIdTCPClient(NULL);
TIdAntiFreeze *IdAntiFreezePing;

void __fastcall ping::ChooseConnection()
{
	 if (IdTCPClientVPN->Connected()||IdTCPClientWWW->Connected()){
		Form2->dxStatusBar1->Panels->Items[3]->Text = IdTCPClientVPN->Connected() ?
			IdTCPClientVPN->Host+":"+IdTCPClientVPN->Port : IdTCPClientWWW->Host+":"+IdTCPClientWWW->Port ;
	 } else Form2->dxStatusBar1->Panels->Items[3]->Text = "";
}

void __fastcall ping::IdTCPClientConnected(TObject *Sender)
{
	if(Sender==IdTCPClientVPN) Form2->dxStatusBar1->Panels->Items[0]->PanelStyle->Font->Color = clGreen;
	if(Sender==IdTCPClientWWW) Form2->dxStatusBar1->Panels->Items[1]->PanelStyle->Font->Color = clGreen;
	Synchronize(&ChooseConnection);
}

void __fastcall ping::IdTCPClientDisConnected(TObject *Sender)
{
	if(Sender==IdTCPClientVPN) Form2->dxStatusBar1->Panels->Items[0]->PanelStyle->Font->Color = clRed;
	if(Sender==IdTCPClientWWW) Form2->dxStatusBar1->Panels->Items[1]->PanelStyle->Font->Color = clRed;
	Synchronize(&ChooseConnection);
}

void __fastcall ping::UpdateCaption()
{
//	Form2->dxStatusBar1->Panels->Items[0]->Text = ( IdTCPClientWWW->Connected() ? "+WWW" : "-WWW" );
//	Form2->dxStatusBar1->Panels->Items[1]->Text = ( IdTCPClientVPN->Connected() ? "+VPN" : "-VPN" );
}
//---------------------------------------------------------------------------

__fastcall ping::ping(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	IdTCPClientVPN->Host="192.168.10.8";
	IdTCPClientWWW->Host="94.228.240.244";
	IdTCPClientVPN->Port=80;
	IdTCPClientWWW->Port=8081;
	IdTCPClientVPN->ConnectTimeout=1000;
	IdTCPClientWWW->ConnectTimeout=1000;
}

//---------------------------------------------------------------------------
void __fastcall ping::Execute()
{
	IdTCPClientVPN->OnConnected = &IdTCPClientConnected;
	IdTCPClientWWW->OnConnected = &IdTCPClientConnected;
	IdTCPClientVPN->OnDisconnected = &IdTCPClientDisConnected;
	IdTCPClientWWW->OnDisconnected = &IdTCPClientDisConnected;

	this->FreeOnTerminate = true;
	NameThreadForDebugging("ping");
	//---- Place thread code here ----
	while (Terminated == false){
		if (!IdTCPClientVPN->Connected()) { try { IdTCPClientVPN->Connect(); } catch (...) {	}}
		//Synchronize(&UpdateCaption);
		if (!IdTCPClientWWW->Connected()) { try { IdTCPClientWWW->Connect(); } catch (...) {	}}
		//http://94.228.240.244:8081/jex/ws/selftabel.1cws?wsdl
		Sleep(1000);
		//Synchronize(&UpdateCaption);
	}
}
void __fastcall ping::OnTerminate()
{
	try {
		IdTCPClientVPN->Disconnect(false);
	} catch (...) {
	}
}
//---------------------------------------------------------------------------
