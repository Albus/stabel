//---------------------------------------------------------------------------

#ifndef pingH
#define pingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class ping : public TThread
{
private:
	void __fastcall ChooseConnection();
	void __fastcall IdTCPClientConnected(TObject *Sender);
	void __fastcall IdTCPClientDisConnected(TObject *Sender);
protected:
	void __fastcall Execute();
	void __fastcall OnTerminate();

public:
	__fastcall ping(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
