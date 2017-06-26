// SmartProxy.h : Declaration of the CSmartProxy

#ifndef __SMARTPROXY_H_
#define __SMARTPROXY_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSmartProxy
class ATL_NO_VTABLE CSmartProxy : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<CSmartProxy, &CLSID_SmartProxy>,
  public IUnknown
{
public:
DECLARE_REGISTRY_RESOURCEID(IDR_SMARTPROXY)
DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSmartProxy)
  COM_INTERFACE_ENTRY(IUnknown)
  COM_INTERFACE_ENTRY_FUNC_BLIND(0, _QI)
END_COM_MAP()
    
public:
  static HRESULT WINAPI _QI(void* pv, REFIID iid, void** ppvObject, DWORD) {
    // Forward to QI member function
    return ((CSmartProxy*)pv)->QI(iid, ppvObject);
  }
  
  // Per-object implementation of QI
  HRESULT QI(REFIID riid, void** ppv) { return E_NOINTERFACE; }
};

class CSmarterProxy : public CSmartProxy {
public:
BEGIN_COM_MAP(CSmarterProxy)
  COM_INTERFACE_ENTRY(IUnknown)
  COM_INTERFACE_ENTRY_CHAIN(CSmartProxy)
END_COM_MAP()
};

#endif //__SMARTPROXY_H_
