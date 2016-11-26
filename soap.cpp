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

#include <vcl.h>
#pragma hdrstop

#if !defined(selftabelH)
#include "soap.h"
#endif



namespace NS_selftabel {

_di_selftabelPortType GetselftabelPortType(bool useWSDL, System::String addr, Soaphttpclient::THTTPRIO* HTTPRIO)
{
  static const char* defWSDL= "http://94.228.240.244:8081/jex/ws/selftabel.1cws?wsdl";
  static const char* defURL = "http://94.228.240.244:8081/jex/ws/selftabel.1cws";
  static const char* defSvc = "selftabel";
  static const char* defPrt = "selftabelSoap12";
  if (addr=="")
    addr = useWSDL ? defWSDL : defURL;
  Soaphttpclient::THTTPRIO* rio = HTTPRIO ? HTTPRIO : new Soaphttpclient::THTTPRIO(0);
  if (useWSDL) {
    rio->WSDLLocation = addr;
    rio->Service = defSvc;
    rio->Port = defPrt;
  } else {
    rio->URL = addr;
  }
  _di_selftabelPortType service;
  rio->QueryInterface(service);
  if (!service && !HTTPRIO)
    delete rio;
  return service;
}


// ************************************************************************ //
// This routine registers the interfaces and types exposed by the WebService.
// ************************************************************************ //
static void RegTypes()
{
  /* selftabelPortType */
  InvRegistry()->RegisterInterface(__delphirtti(selftabelPortType), L"SelfTabel", L"UTF-8");
  InvRegistry()->RegisterDefaultSOAPAction(__delphirtti(selftabelPortType), L"SelfTabel#selftabel:%operationName%");
  InvRegistry()->RegisterInvokeOptions(__delphirtti(selftabelPortType), ioDocument);
  InvRegistry()->RegisterInvokeOptions(__delphirtti(selftabelPortType), ioSOAP12);
  /* selftabelPortType.CheckIn */
  InvRegistry()->RegisterMethodInfo(__delphirtti(selftabelPortType), "CheckIn", "",
                                    "[ReturnName='return']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(selftabelPortType), "CheckIn", "return_", L"return", L"");
  /* selftabelPortType.CheckOut */
  InvRegistry()->RegisterMethodInfo(__delphirtti(selftabelPortType), "CheckOut", "",
                                    "[ReturnName='return']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(selftabelPortType), "CheckOut", "return_", L"return", L"");
  /* selftabelPortType.Test */
  InvRegistry()->RegisterMethodInfo(__delphirtti(selftabelPortType), "Test", "",
                                    "[ReturnName='return']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(selftabelPortType), "Test", "return_", L"return", L"");
  /* selftabelPortType.GetAllowedAction */
  InvRegistry()->RegisterMethodInfo(__delphirtti(selftabelPortType), "GetAllowedAction", "",
                                    "[ReturnName='return']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(selftabelPortType), "GetAllowedAction", "return_", L"return", L"");
  /* selftabelPortType.AptIsSelfTabeling */
  InvRegistry()->RegisterMethodInfo(__delphirtti(selftabelPortType), "AptIsSelfTabeling", "",
                                    "[ReturnName='return']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(selftabelPortType), "AptIsSelfTabeling", "return_", L"return", L"");
}
#pragma startup RegTypes 32

};     // NS_selftabel

