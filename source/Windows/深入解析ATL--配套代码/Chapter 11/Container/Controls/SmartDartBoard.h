// SmartDartBoard.h : Declaration of the CSmartDartBoard

#ifndef __SMARTDARTBOARD_H_
#define __SMARTDARTBOARD_H_

#include "resource.h"       // main symbols
#include <atlctl.h>


/////////////////////////////////////////////////////////////////////////////
// CSmartDartBoard

class CSmartDartBoard;

typedef IDispEventImpl<1, CSmartDartBoard, &DIID_DWebBrowserEvents2, &LIBID_SHDocVw, 1, 0>
        BrowserEvents;

typedef IDispEventImpl<2, CSmartDartBoard, &DIID_HTMLInputTextElementEvents, &LIBID_MSHTML, 4, 0>
        ButtonEvents;

class ATL_NO_VTABLE CSmartDartBoard : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<ISmartDartBoard, &IID_ISmartDartBoard, &LIBID_CONTROLSLib>,
	public IDispatchImpl<ISmartDartBoardUI, &IID_ISmartDartBoardUI, &LIBID_CONTROLSLib>,
	public CComControl<CSmartDartBoard>,
	public IPersistStreamInitImpl<CSmartDartBoard>,
	public IOleControlImpl<CSmartDartBoard>,
	public IOleObjectImpl<CSmartDartBoard>,
	public IOleInPlaceActiveObjectImpl<CSmartDartBoard>,
	public IViewObjectExImpl<CSmartDartBoard>,
	public IOleInPlaceObjectWindowlessImpl<CSmartDartBoard>,
	public IPersistStorageImpl<CSmartDartBoard>,
	public IPersistPropertyBagImpl<CSmartDartBoard>,
	public ISpecifyPropertyPagesImpl<CSmartDartBoard>,
	public IQuickActivateImpl<CSmartDartBoard>,
	public IDataObjectImpl<CSmartDartBoard>,
	public IProvideClassInfo2Impl<&CLSID_SmartDartBoard, NULL, &LIBID_CONTROLSLib>,
	public CComCoClass<CSmartDartBoard, &CLSID_SmartDartBoard>,
  // Sink browser events
  public BrowserEvents,
  // Sink events on the DHTML Reset button
  public ButtonEvents,
  // Turn off IE context menu
  public IDispatchImpl<IDocHostUIHandlerDispatch, &IID_IDocHostUIHandlerDispatch, &LIBID_ATLLib>
{
public:
  CSmartDartBoard();

DECLARE_REGISTRY_RESOURCEID(IDR_SMARTDARTBOARD)
DECLARE_NOT_AGGREGATABLE(CSmartDartBoard)
DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSmartDartBoard)
	COM_INTERFACE_ENTRY(ISmartDartBoard)
	COM_INTERFACE_ENTRY(ISmartDartBoardUI)
	COM_INTERFACE_ENTRY2(IDispatch, ISmartDartBoard)
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
  COM_INTERFACE_ENTRY(IPersistPropertyBag)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()

BEGIN_PROP_MAP(CSmartDartBoard)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
  PROP_ENTRY("Score", 1, CLSID_NULL)
END_PROP_MAP()

BEGIN_SINK_MAP(CSmartDartBoard)
  SINK_ENTRY_EX(1, DIID_DWebBrowserEvents2, 0x00000103, OnDocumentComplete)
  SINK_ENTRY_EX(2, DIID_HTMLInputTextElementEvents, DISPID_CLICK, OnClickReset)
END_SINK_MAP()

  // Event handlers
  void __stdcall OnDocumentComplete(IDispatch*, VARIANT*);
  VARIANT_BOOL __stdcall OnClickReset();

BEGIN_MSG_MAP(CSmartDartBoard)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
	CHAIN_MSG_MAP(CComControl<CSmartDartBoard>)
END_MSG_MAP()

  // Message handlers
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
  LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

// IViewObjectEx
	DECLARE_VIEW_STATUS(0)

// ISmartDartBoard/ISmartDartBoardUI
public:
	STDMETHOD(get_Score)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Score)(/*[in]*/ long newVal);
  STDMETHODIMP ResetScore();
  STDMETHODIMP AddToScore(long ringValue);

// Helpers
private:
  HRESULT SetScoreSpan();
  HRESULT GetHtmlElement(LPCOLESTR pszElementID, IHTMLElement** ppElement);

// IDocHostUIHandlerDispatch
public:
  STDMETHODIMP ShowContextMenu(
    DWORD dwID, 
    DWORD x, 
    DWORD y, 
    IUnknown* pcmdtReserved,  
    IDispatch* pdispReserved,
    HRESULT* dwRetVal);
  STDMETHODIMP GetHostInfo(
    DWORD* pdwFlags,
    DWORD* pdwDoubleClick);
  STDMETHODIMP ShowUI(
    DWORD dwID,
    IUnknown* pActiveObject,
    IUnknown* pCommandTarget,
    IUnknown* pFrame,
    IUnknown* pDoc,
    HRESULT* dwRetVal);
  STDMETHODIMP HideUI();
  STDMETHODIMP UpdateUI();
  STDMETHODIMP EnableModeless(
    VARIANT_BOOL fEnable);
  STDMETHODIMP OnDocWindowActivate(
    VARIANT_BOOL fActivate);
  STDMETHODIMP OnFrameWindowActivate(
    VARIANT_BOOL fActivate);
  STDMETHODIMP ResizeBorder(
    long left,
    long top,
    long right,
    long bottom,
    IUnknown * pUIWindow,
    VARIANT_BOOL fFrameWindow);
  STDMETHODIMP TranslateAccelerator(
    DWORD hWnd,
    DWORD nMessage,
    DWORD wParam,
    DWORD lParam,
    BSTR bstrGuidCmdGroup, 
    DWORD nCmdID,
    HRESULT* dwRetVal);
  STDMETHODIMP GetOptionKeyPath(
    BSTR* pbstrKey,
    DWORD dw);
  STDMETHODIMP GetDropTarget(
    IUnknown* pDropTarget, 
    IUnknown** ppDropTarget);
  STDMETHODIMP GetExternal(
    IDispatch **ppDispatch);
  STDMETHODIMP TranslateUrl(
    DWORD dwTranslate,
    BSTR bstrURLIn,
    BSTR* pbstrURLOut);
  STDMETHODIMP FilterDataObject(
    IUnknown *pDO,
    IUnknown **ppDORet);

private:
  long  m_nScore;
	CComPtr<IWebBrowser2> m_spBrowser;
};

#endif //__SMARTDARTBOARD_H_
