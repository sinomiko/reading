// Balloon.h : Declaration of the CBalloon

#ifndef __BALLOON_H_
#define __BALLOON_H_

#include "resource.h"       // main symbols

inline
HRESULT WINAPI _This(void* pv, REFIID iid, void** ppvObject, DWORD) {
  ATLASSERT(iid == IID_NULL);
  *ppvObject = pv;
  return S_OK;
}

#define COM_INTERFACE_ENTRY_THIS() COM_INTERFACE_ENTRY_FUNC(IID_NULL, 0, _This)

/////////////////////////////////////////////////////////////////////////////
// CBalloon
class ATL_NO_VTABLE CBalloon : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<CBalloon>,
  public IBalloon {
public:
DECLARE_REGISTRY_RESOURCEID(IDR_BALLOON)
DECLARE_NOT_AGGREGATABLE(CBalloon)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CBalloon)
  COM_INTERFACE_ENTRY(IBalloon)
  COM_INTERFACE_ENTRY_THIS()
END_COM_MAP()
    
    // IBalloon
public:
  STDMETHOD(get_Color)(/*[out, retval]*/ long *pVal);
  
private:
  COLORREF  m_rgbColor;
  
  friend class CBalloonMan;
};

#endif //__BALLOON_H_
