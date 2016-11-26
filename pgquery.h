//---------------------------------------------------------------------------

#ifndef pgqueryH
#define pgqueryH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class PgQuery : public TThread
{
protected:
	void __fastcall Execute();
public:
	__fastcall PgQuery(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
