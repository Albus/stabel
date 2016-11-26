//---------------------------------------------------------------------------

#ifndef pgqueryH
#define pgqueryH
#include "form.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class PgQuery : public TThread
{
protected:
	void __fastcall Execute();
public:
	TPgConnection *Connection;
	TPgQuery *Query;
	__fastcall PgQuery(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
