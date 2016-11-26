//---------------------------------------------------------------------------

#ifndef pgqueryH
#define pgqueryH

//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class PgQuery : public TThread
{
protected:
	void __fastcall Execute ();
	void __fastcall FatalError ();
public:
	TPgConnection *Connection;
	TPgQuery *Query;
	__fastcall PgQuery(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
