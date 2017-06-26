// Penguin.h : Declaration of the CPenguin

#ifndef __PENGUIN_H_
#define __PENGUIN_H_

#include "resource.h"       // main symbols
#include <atlctl.h>


/////////////////////////////////////////////////////////////////////////////
// CPenguin
class ATL_NO_VTABLE CPenguin : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IPenguin, &IID_IPenguin, &LIBID_BIRDSLib>,
	public CComControl<CPenguin>,
	public IPersistStreamInitImpl<CPenguin>,
	public IOleControlImpl<CPenguin>,
	public IOleObjectImpl<CPenguin>,
	public IOleInPlaceActiveObjectImpl<CPenguin>,
	public IViewObjectExImpl<CPenguin>,
	public IOleInPlaceObjectWindowlessImpl<CPenguin>,
	public CComCoClass<CPenguin, &CLSID_Penguin>
{
public:
	CPenguin()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PENGUIN)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPenguin)
	COM_INTERFACE_ENTRY(IPenguin)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
END_COM_MAP()

BEGIN_PROP_MAP(CPenguin)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CPenguin)
	CHAIN_MSG_MAP(CComControl<CPenguin>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IPenguin
public:
	STDMETHOD(Fly)();
	STDMETHOD(get_Name)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Name)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Wingspan)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Wingspan)(/*[in]*/ long newVal);

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		LPCTSTR pszText = _T("ATL 3.0 : Penguin");
		TextOut(di.hdcDraw, 
			(rc.left + rc.right) / 2, 
			(rc.top + rc.bottom) / 2, 
			pszText, 
			lstrlen(pszText));

		return S_OK;
	}
};

#endif //__PENGUIN_H_
