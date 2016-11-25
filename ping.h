//---------------------------------------------------------------------------

#ifndef pingH
#define pingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class ping : public TThread
{
private:
protected:
	void __fastcall Execute();
	void __fastcall OnTerminate();
	void __fastcall UpdateCaption();
public:
	__fastcall ping(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
