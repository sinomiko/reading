// AcePowell.h : Declaration of the CAcePowell

#ifndef __ACEPOWELL_H_
#define __ACEPOWELL_H_

#include "resource.h"       // main symbols
#include "atlcompose.h"

/////////////////////////////////////////////////////////////////////////////
// CAcePowell
class ATL_NO_VTABLE CAcePowell : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<CAcePowell, &CLSID_AcePowell>,
  public IDispatchImpl<IAcePowell, &IID_IAcePowell, &LIBID_COMPOSITIONLib>,
  public IArtist
{
public:
  CAcePowell()
  {
    OutputDebugString("CAcePowell()\n");
  }
  
  ~CAcePowell()
  {
    OutputDebugString("~CAcePowell()\n");
  }
  
  DECLARE_REGISTRY_RESOURCEID(IDR_ACEPOWELL)
    
  BEGIN_COM_MAP(CAcePowell)
    COM_INTERFACE_ENTRY(IAcePowell)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IArtist)
    COM_INTERFACE_ENTRY_COMPOSED(ICowboyEx, XCowboy)
    COM_INTERFACE_ENTRY_COMPOSED(ICowboy, XCowboy)
  END_COM_MAP()
    
  // IArtist
  STDMETHODIMP Draw()
  {
    MessageBox(0, "Say 'Cheese.'", "IArtist::Draw", MB_SETFOREGROUND);
    return S_OK;
  }
  
  // ICowboy
  BEGIN_COMPOSED_CLASS(CAcePowell, ICowboyEx, XCowboy)
    
    STDMETHODIMP Draw()
    {
      MessageBox(0, "Reach for the sky.", "ICowboy::Draw", MB_SETFOREGROUND);
      return S_OK;
    }
  
    STDMETHODIMP QuickDraw()
    {
      MessageBox(0, "Reach for the sky more quickly.", "ICowboyEx::QuickDraw", MB_SETFOREGROUND);
      return S_OK;
    }
  
  END_COMPOSED_CLASS(XCowboy)
};

#endif //__ACEPOWELL_H_
