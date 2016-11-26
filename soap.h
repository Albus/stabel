// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://94.228.240.244:8081/jex/ws/selftabel.1cws?wsdl
//  >Import : http://94.228.240.244:8081/jex/ws/selftabel.1cws?wsdl>0
// Encoding : UTF-8
// Codegen  : [wfOutputLiteralTypes+, wfMapArraysToClasses+, wfCreateArrayElemTypeAlias+]
// Version  : 1.0
// (26.11.2016 19:22:02 - - $Rev: 34800 $)
// ************************************************************************ //

#ifndef   soapH
#define   soapH

#include <System.hpp>
#include <InvokeRegistry.hpp>
#include <XSBuiltIns.hpp>
#include <SOAPHTTPClient.hpp>

#if !defined(SOAP_REMOTABLE_CLASS)
#define SOAP_REMOTABLE_CLASS __declspec(delphiclass)
#endif
#if !defined(IS_REF)
#define IS_REF 0x0080
#endif


namespace NS_selftabel {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Embarcadero types; however, they could also 
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:boolean         - "http://www.w3.org/2001/XMLSchema"[Gbl]
// !:string          - "http://www.w3.org/2001/XMLSchema"[Gbl]
// !:integer         - "http://www.w3.org/2001/XMLSchema"[Gbl]



// ************************************************************************ //
// Namespace : SelfTabel
// soapAction: SelfTabel#selftabel:%operationName%
// transport : http://schemas.xmlsoap.org/soap/http
// style     : document
// use       : literal
// binding   : selftabelSoap12Binding
// service   : selftabel
// port      : selftabelSoap12
// URL       : http://94.228.240.244:8081/jex/ws/selftabel.1cws
// ************************************************************************ //
__interface INTERFACE_UUID("{51BBADE7-41EC-D5B1-174D-593F7258BD48}") selftabelPortType : public IInvokable
{
public:
  virtual UnicodeString   CheckIn(const __int64 Apt, const UnicodeString BC, const __int64 isnight) = 0; 
  virtual UnicodeString   CheckOut(const __int64 Apt, const UnicodeString BC, const __int64 isnight) = 0; 
  virtual UnicodeString   Test() = 0; 
  virtual __int64         GetAllowedAction(const __int64 Apt, const UnicodeString BC) = 0; 
  virtual bool            AptIsSelfTabeling(const __int64 AptCode) = 0; 
};
typedef DelphiInterface<selftabelPortType> _di_selftabelPortType;

_di_selftabelPortType GetselftabelPortType(bool useWSDL=false, System::String addr= System::String(), Soaphttpclient::THTTPRIO* HTTPRIO=0);


};     // NS_selftabel

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace NS_selftabel;
#endif



#endif // selftabelH
