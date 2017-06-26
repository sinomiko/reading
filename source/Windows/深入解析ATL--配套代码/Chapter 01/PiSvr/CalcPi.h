// CalcPi.h : Declaration of the CCalcPi

#ifndef __CALCPI_H_
#define __CALCPI_H_

#include "resource.h"       // main symbols
#include "PiSvrCP.h"
#include "advert.h"

/////////////////////////////////////////////////////////////////////////////
// CCalcPi
class ATL_NO_VTABLE CCalcPi : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<CCalcPi, &CLSID_CalcPi>,
  public ISupportErrorInfo,
  public IConnectionPointContainerImpl<CCalcPi>,
  public IDispatchImpl<ICalcPi, &IID_ICalcPi, &LIBID_PISVRLib>,
  public IPersistPropertyBagImpl<CCalcPi>,
  public IProvideClassInfo2Impl<&CLSID_CalcPi, &DIID__ICalcPiEvents>,
  public CProxy_ICalcPiEvents< CCalcPi >,
  public IAdvertiseMyself,
	public CComControl<CCalcPi>,
	public IPersistStreamInitImpl<CCalcPi>,
	public IPersistStorageImpl<CCalcPi>,
	public IOleControlImpl<CCalcPi>,
	public IOleObjectImpl<CCalcPi>,
	public IOleInPlaceActiveObjectImpl<CCalcPi>,
	public IViewObjectExImpl<CCalcPi>,
	public IOleInPlaceObjectWindowlessImpl<CCalcPi>
{
public:
  CCalcPi() : m_nDigits(0)
  {
  }
  
DECLARE_REGISTRY_RESOURCEID(IDR_CALCPI)

BEGIN_COM_MAP(CCalcPi)
  COM_INTERFACE_ENTRY(IAdvertiseMyself)
  COM_INTERFACE_ENTRY(ICalcPi)
  COM_INTERFACE_ENTRY(IDispatch)
  COM_INTERFACE_ENTRY(ISupportErrorInfo)
  COM_INTERFACE_ENTRY(IConnectionPointContainer)
  COM_INTERFACE_ENTRY(IPersistPropertyBag)
  COM_INTERFACE_ENTRY(IProvideClassInfo)
  COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
  COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
END_COM_MAP()
    
BEGIN_CONNECTION_POINT_MAP(CCalcPi)
  CONNECTION_POINT_ENTRY(DIID__ICalcPiEvents)
END_CONNECTION_POINT_MAP()

BEGIN_PROP_MAP(CCalcPi)
  PROP_ENTRY("Digits", 1, CLSID_NULL)
END_PROP_MAP()

BEGIN_CATEGORY_MAP(CCalcPi)
  IMPLEMENTED_CATEGORY(CATID_SafeForScripting)
  IMPLEMENTED_CATEGORY(CATID_SafeForInitializing)
END_CATEGORY_MAP()

BEGIN_MSG_MAP(CCalcPi)
	CHAIN_MSG_MAP(CComControl<CCalcPi>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
    
  // ISupportsErrorInfo
  STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
  
  // ICalcPi
public:
  STDMETHOD(CalcPi)(/*[out, retval]*/ BSTR* pbstrPi);
  STDMETHOD(get_Digits)(/*[out, retval]*/ long *pVal);
  STDMETHOD(put_Digits)(/*[in]*/ long newVal);

private:
  long m_nDigits;

public:
  BOOL m_bRequiresSave;

  // IAdvertiseMyself
  STDMETHOD(ShowAd)(BSTR bstrClient) {
    CAdvert ad;
    ad.m_bstrClient = bstrClient;
    ad.DoModal();
    return S_OK;
  }

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

  // Draw pi
  HRESULT OnDraw(ATL_DRAWINFO& di);
};

#endif //__CALCPI_H_
