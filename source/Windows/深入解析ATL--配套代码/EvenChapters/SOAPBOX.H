// SoapBox.h : Declaration of the CSoapBox

#ifndef __SOAPBOX_H_
#define __SOAPBOX_H_

#include "resource.h"       // main symbols
#include "ClimbableObjectCP.h"


/////////////////////////////////////////////////////////////////////////////
// CSoapBox
class ATL_NO_VTABLE CSoapBox : 
	public CComObjectRootEx<CComSingleThreadModel>,
//	public CComCoClass<CSoapBox, &CLSID_SoapBox>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CSoapBox>,
	public IDispatchImpl<IClimbableObject, &IID_IClimbableObject, &LIBID_ATLINTERNALSLib>,
	public CProxy_IClimbableObjectEvents< CSoapBox >
{
public:
	CSoapBox()
	{
	}

// DECLARE_REGISTRY_RESOURCEID(IDR_SOAPBOX)

    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) {
    HRESULT hr = _Module.UpdateRegistryFromResource(IDR_SOAPBOX, bRegister);
    if (FAILED (hr)) return hr ;
    hr = AtlRegisterClassCategoriesHelper(GetObjectCLSID(), GetCategoryMap (), bRegister) ;
    return hr;
    }

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSoapBox)
	COM_INTERFACE_ENTRY(IClimbableObject)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CSoapBox)
    CONNECTION_POINT_ENTRY(DIID__IClimbableObjectEvents)
END_CONNECTION_POINT_MAP()

BEGIN_CATEGORY_MAP(CSoapBox)
IMPLEMENTED_CATEGORY(CATID_ATLINTERNALS_SAMPLES)
END_CATEGORY_MAP()

	static const CLSID& WINAPI GetObjectCLSID() { return CLSID_SoapBox; }

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ISoapBox
public:
    STDMETHODIMP ClimbOn(IUnknown* pClimber) { return S_OK; }
    STDMETHODIMP ClimbOff() { return S_OK; }

};

#endif //__SOAPBOX_H_
