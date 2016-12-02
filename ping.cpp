// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ping.h"
#include "form.h"

#pragma package(smart_init)
// #pragma link "IndyCore.bpi"

TIdTCPClient *IdTCPClientVPN = new TIdTCPClient(NULL);
TIdTCPClient *IdTCPClientWWW = new TIdTCPClient(NULL);
TIdAntiFreeze *IdAntiFreezePing;

void __fastcall ping::ChooseConnection() {

	if (IdTCPClientVPN->Connected() || IdTCPClientWWW->Connected()) {
		SelfTabel->AP->Text = !IdTCPClientVPN->Connected() ?
			IdTCPClientVPN->Host + ":" + IdTCPClientVPN->Port :
			IdTCPClientWWW->Host + ":" + IdTCPClientWWW->Port;
	}
	else
		SelfTabel->AP->Text = "";

	SelfTabel->dxStatusBar1->Repaint();
}

void __fastcall ping::IdTCPClientConnected(TObject *Sender) {
	if (Sender == IdTCPClientVPN)
		SelfTabel->ColorVPN = clGreen;
	if (Sender == IdTCPClientWWW)
		SelfTabel->ColorWWW = clGreen;
	Synchronize(&ChooseConnection);
}

void __fastcall ping::IdTCPClientDisConnected(TObject *Sender) {
	if (Sender == IdTCPClientVPN)
		SelfTabel->ColorVPN = clRed;
	if (Sender == IdTCPClientWWW)
		SelfTabel->ColorWWW = clRed;
	Synchronize(&ChooseConnection);
}

// ---------------------------------------------------------------------------

__fastcall ping::ping(bool CreateSuspended) : TThread(CreateSuspended) {
	IdTCPClientVPN->Host = "192.168.10.8";
	IdTCPClientWWW->Host = "94.228.240.244";
	IdTCPClientVPN->Port = 80;
	IdTCPClientWWW->Port = 8081;
	IdTCPClientVPN->ConnectTimeout = 1000;
	IdTCPClientWWW->ConnectTimeout = 1000;
}

// ---------------------------------------------------------------------------
void __fastcall ping::Execute() {

	//li->cbSize = sizeof(TLastInputInfo);

	IdTCPClientVPN->OnConnected = &IdTCPClientConnected;
	IdTCPClientWWW->OnConnected = &IdTCPClientConnected;
	IdTCPClientVPN->OnDisconnected = &IdTCPClientDisConnected;
	IdTCPClientWWW->OnDisconnected = &IdTCPClientDisConnected;

	this->FreeOnTerminate = true;
	NameThreadForDebugging("ping");
	while (Terminated == false) {
		if (!IdTCPClientVPN->Connected()) {
			try {
				IdTCPClientVPN->Connect();
			}
			catch (...) {
			}
		}
		if (!IdTCPClientWWW->Connected()) {
			try {
				IdTCPClientWWW->Connect();
			}
			catch (...) {
			}
		}

		Sleep(800);
	}
}

void __fastcall ping::OnTerminate() {
	try {
		IdTCPClientVPN->Disconnect(true);
	}
	catch (...) {
	}
}
// ---------------------------------------------------------------------------
