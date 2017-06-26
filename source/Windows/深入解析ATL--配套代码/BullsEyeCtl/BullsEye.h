// BullsEye.h : Declaration of the CBullsEye

#ifndef __BULLSEYE_H_
#define __BULLSEYE_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "BullsEyeEventsCP.h"
#include "IDropSourceImpl.h"

/////////////////////////////////////////////////////////////////////////////
// CBullsEyeLicense

// Licensed objects implement IClassFactory2 to validate instantiation requests.

// To create a licensed object successfully using IClassFactory2::CreateInstance,
//   the creation request must occur on a design-time licensed system.

// To create a licensed object successfully using IClassFactory2::CreateInstanceLic,
//   the client must present a valid run-time license key, or,
//   the client presents no run-time license key and
//   the creation request occurs on a design-time licensed system.

// A client can determine if the current systemn is licensed to use an object
// and if a run-time key is available by calling IClassFactory2:GetLicInfo.

// On a design-time licensed system, a client can obtain a run-time license key
// by calling IClassFactory2::RequestLicKey.


// The ATL implementation of IClassFactory2 uses the following methods:

// IsLicenseValid returns a non-zero value when the current system possesses a design-time license.
// VerifyLicenseKey returns a non-zero value when the caller provides a correct run-time license key.
// GetLicenseKey returns a run-time license key.

class CBullsEyeLicense {
private:
    static const GUID RunTimeLicenseKey ;

protected:
    // This should check for a hardware dongle, secret registry key, or similar
    // indication that this system is licensed to use the object at design-time.
    static BOOL IsLicenseValid() { return TRUE; }

    // Verify the presented run-time license key.
    // It should be the "string-ized" GUID.
    static BOOL VerifyLicenseKey(BSTR bstr) {
        OLECHAR buf [40];

        int i = StringFromGUID2 (RunTimeLicenseKey, buf, sizeof (buf));
        ATLASSERT (i != 0);

        return !lstrcmpW(bstr, buf);
    }

    // Return a run-time license key as a BSTR.
    // We use a "string-ized" GUID as the key.
    static BOOL GetLicenseKey(DWORD dwReserved, BSTR* pBstr) {
        OLECHAR buf [40];

        int i = StringFromGUID2 (RunTimeLicenseKey, buf, sizeof (buf));
        ATLASSERT (i != 0);

        *pBstr = SysAllocString(buf); 
        return TRUE;
    }

};


/////////////////////////////////////////////////////////////////////////////
// CBullsEye

const int PROPCAT_Scoring = 1;
    
class ATL_NO_VTABLE CBullsEye : 
    // COM object implementation
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBullsEye, &CLSID_BullsEye>,
    // Control implementation
	public CComControl<CBullsEye>,
	public CStockPropImpl<CBullsEye, IBullsEye, &IID_IBullsEye, &LIBID_BullsEyeLib>,
	public IOleControlImpl<CBullsEye>,
	public IOleObjectImpl<CBullsEye>,
	public IOleInPlaceActiveObjectImpl<CBullsEye>,
	public IViewObjectExImpl<CBullsEye>,
	public IOleInPlaceObjectWindowlessImpl<CBullsEye>,
	public IQuickActivateImpl<CBullsEye>,
	public IDataObjectImpl<CBullsEye>,
    // Object Safety support
    public IObjectSafetyImpl<CBullsEye, INTERFACESAFE_FOR_UNTRUSTED_CALLER |
                                        INTERFACESAFE_FOR_UNTRUSTED_DATA>,
    // Persistance
	public IPersistStreamInitImpl<CBullsEye>,
	public IPersistStorageImpl<CBullsEye>,
    public IPersistPropertyBagImpl<CBullsEye>,
    // Property page implementation
	public ISpecifyPropertyPagesImpl<CBullsEye>,
	public IPerPropertyBrowsingImpl<CBullsEye>,
    // Property categories for Visual Basic Property View
    public ICategorizeProperties,
    // Connection point container support
	public IConnectionPointContainerImpl<CBullsEye>,
            // Must update second parameter to default source (event) dispinterface IID
	public IProvideClassInfo2Impl<&CLSID_BullsEye, &DIID__IBullsEyeEvents, &LIBID_BullsEyeLib>,
    // events and property change notifications
	public CProxy_IBullsEyeEvents<CBullsEye>,
    public IPropertyNotifySinkCP<CBullsEye>,
    // Drop source implementation
    public IDropSourceImpl<CBullsEye>
{
public:
	CBullsEye();
	~CBullsEye();

    static void WINAPI ObjectMain(bool bStarting)
    {
        m_cfEmbeddedObject   = RegisterClipboardFormat(CF_EMBEDDEDOBJECT); 
        m_cfObjectDescriptor = RegisterClipboardFormat(CF_OBJECTDESCRIPTOR); 

        IDropSourceImpl<CBullsEye>::ObjectMain(bStarting);
    }

DECLARE_CLASSFACTORY2(CBullsEyeLicense)
DECLARE_REGISTRY_RESOURCEID(IDR_BULLSEYE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CBullsEye)
    // Control implementation
	COM_INTERFACE_ENTRY(IBullsEye)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IDataObject)
    // Object Safety support
    COM_INTERFACE_ENTRY(IObjectSafety)
    // Persistance
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IPersistPropertyBag)
    // Propert page implementation
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IPerPropertyBrowsing)
    // Property categories for Visual Basic Property View
	COM_INTERFACE_ENTRY(ICategorizeProperties)
    // Connection point container support
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
    // Drop source implementation
    COM_INTERFACE_ENTRY(IDropSource)
END_COM_MAP()

BEGIN_CATEGORY_MAP(CBullsEye)
IMPLEMENTED_CATEGORY(CATID_ATLINTERNALS_SAMPLES)
END_CATEGORY_MAP()

BEGIN_CONNECTION_POINT_MAP(CBullsEye)
	CONNECTION_POINT_ENTRY(DIID__IBullsEyeEvents)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
END_CONNECTION_POINT_MAP()

BEGIN_PROP_MAP(CBullsEye)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("BackStyle",      DISPID_BACKSTYLE,      CLSID_BullsEyePropPage)
	PROP_ENTRY("Beep",           DISPID_BEEP,           CLSID_BullsEyePropPage)
	PROP_ENTRY("Enabled",        DISPID_ENABLED,        CLSID_BullsEyePropPage)
	PROP_ENTRY("RingCount",      DISPID_RINGCOUNT,      CLSID_BullsEyePropPage)

    PROP_ENTRY("AlternateColor", DISPID_ALTERNATECOLOR, CLSID_StockColorPage)
	PROP_ENTRY("BackColor",      DISPID_BACKCOLOR,      CLSID_StockColorPage)
	PROP_ENTRY("CenterColor",    DISPID_CENTERCOLOR,    CLSID_StockColorPage)
	PROP_ENTRY("ForeColor",      DISPID_FORECOLOR,      CLSID_StockColorPage)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CBullsEye)
	CHAIN_MSG_MAP(CComControl<CBullsEye>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    HRESULT FinalConstruct ();

// IPerPropertyBrowsing
	STDMETHODIMP GetDisplayString(/*[in]*/ DISPID dispid, /*[out]*/ BSTR *pBstr);
    STDMETHODIMP GetPredefinedStrings(/*[in]*/ DISPID dispID, /*[out]*/ CALPOLESTR *pcaStringsOut, /*[out]*/ CADWORD *pcaCookiesOut);
    STDMETHODIMP GetPredefinedValue(/*[in]*/ DISPID dispID, /*[in]*/DWORD dwCookie, /*[out]*/VARIANT* pVarOut);
    STDMETHODIMP MapPropertyToPage(/*[in]*/ DISPID dispID, /*[out*/ CLSID *pClsid);

// ICategorizeProperties
    STDMETHODIMP MapPropertyToCategory(/*[in]*/ DISPID dispid, /*[out]*/ PROPCAT* ppropcat);
    STDMETHODIMP GetCategoryName(/*[in]*/ PROPCAT propcat, /*[in]*/ LCID lcid, /*[out]*/ BSTR* pbstrName);

// IViewObjectEx
	STDMETHODIMP GetViewStatus (DWORD* pdwStatus);
    STDMETHODIMP QueryHitPoint (DWORD dwAspect, LPCRECT pRectBounds, POINT ptlLoc, LONG lCloseHint, DWORD* pHitResult);
    STDMETHODIMP QueryHitRect (DWORD dwAspect, LPCRECT pRectBounds, LPCRECT prcLoc, LONG lCloseHint, DWORD* pHitResult);

// IDataObject
    STDMETHODIMP QueryGetData(FORMATETC* pformatetc);
    STDMETHODIMP EnumFormatEtc(DWORD dwDirection, IEnumFORMATETC** ppenumFormatEtc);

// IOleObject
    STDMETHODIMP GetMiscStatus (DWORD dwAspect, DWORD *pdwStatus);

// IOleControl
    STDMETHODIMP OnAmbientPropertyChange (DISPID dispid);
    STDMETHODIMP GetControlInfo(CONTROLINFO *pCI);

//IOleInPlaceActiveObject
    STDMETHODIMP TranslateAccelerator(MSG *pMsg);

// CComControlBase
    HRESULT IQuickActivate_QuickActivate(QACONTAINER *pQACont, QACONTROL *pQACtrl);
    HRESULT IOleObject_SetClientSite(IOleClientSite *pClientSite);
    HRESULT IPersistStreamInit_Load(LPSTREAM pStm, ATL_PROPMAP_ENTRY* pMap);
    HRESULT IPersistStreamInit_Save(LPSTREAM pStm, BOOL fClearDirty, ATL_PROPMAP_ENTRY* pMap);
    HRESULT IPersistPropertyBag_Load(LPPROPERTYBAG pPropBag, LPERRORLOG pErrorLog, ATL_PROPMAP_ENTRY* pMap);
    HRESULT IPersistPropertyBag_Save(LPPROPERTYBAG pPropBag, BOOL fClearDirty, BOOL fSaveAllProperties, ATL_PROPMAP_ENTRY* pMap);
    STDMETHODIMP InitNew();

// IBullsEye
public:
    STDMETHODIMP get_AlternateColor(/*[out, retval]*/ OLE_COLOR *pVal);
    STDMETHODIMP put_AlternateColor(/*[in]*/ OLE_COLOR newVal);
    STDMETHODIMP get_Application(/*[out, retval]*/ LPDISPATCH *pVal);
    STDMETHODIMP get_Beep(/*[out, retval]*/ VARIANT_BOOL *pVal);
    STDMETHODIMP put_Beep(/*[in]*/ VARIANT_BOOL newVal);
    STDMETHODIMP put_BackStyle(/*[in]*/ LONG nBackStyle);
    STDMETHODIMP put_BackColor(/*[in]*/OLE_COLOR newVal);
    STDMETHODIMP get_CenterColor(/*[out, retval]*/ OLE_COLOR *pVal);
    STDMETHODIMP put_CenterColor(/*[in]*/ OLE_COLOR newVal);
    STDMETHODIMP get_Parent(/*[out, retval]*/ LPDISPATCH *pVal);
    STDMETHODIMP get_RingValue(/*[in]*/ short sRingNumber, /*[out, retval]*/ long *pVal);
    STDMETHODIMP put_RingValue(/*[in]*/ short sRingNumber, /*[in]*/ long newVal);
    STDMETHODIMP get_RingCount(/*[out, retval]*/ short *pVal);
    STDMETHODIMP put_RingCount(/*[in]*/ short newVal);

    STDMETHODIMP Refresh();
    STDMETHODIMP DoClick();
    STDMETHODIMP AboutBox();

    HRESULT OnDraw(ATL_DRAWINFO& di);
    HRESULT OnDrawAdvanced(ATL_DRAWINFO& di);

    void DrawBullsEye (ATL_DRAWINFO& di);

    LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    int HitTest (const CPoint& pt);

// Implementation
public:
    OLE_COLOR                   m_clrBackColor;     // BackColor stock property
	OLE_COLOR                   m_clrForeColor;     // ForeColor stock property
    long                        m_nBorderStyle;     // BorderStyle stock property
    long                        m_nBorderWidth;     // BorderWidth stock property
    long                        m_nBackStyle;       // BackStyle stock property
	BOOL                        m_bEnabled;         // Enabled stock property

    OLE_COLOR                   m_clrCenterColor ;      // Center (even rings) color
	OLE_COLOR                   m_clrAlternateColor ;   // Alternate (odd rings) color
	VARIANT_BOOL                m_beep ;                // Beep on ring hit?
	CSimpleArray<long>          m_ringValues ;          // Point values for rings

    short                       m_nAppearance;      // Ambient Appearance property

    bool                        m_bAmbientsFetched; // Have we retrieved the ambients yet?

    HPEN                        m_borderPen ;       // Pen for border of rings
	HBRUSH                      m_backBrush ;       // Brush for background around bullseye
	HBRUSH                      m_alternateBrush ;  // Brush for alternate ring color
	HBRUSH                      m_centerBrush ;     // Brush for center ring color

	void    HitRing (short sRingNumber);
    HRESULT GetPropertyFromDocument (/* [in] */ LPOLESTR pszProperty, /* [out] */ IDispatch** pDisp) ;
	HRESULT GetApplicationFromServiceProvider (/* [out] */ IDispatch** pDisp) ;
    HRESULT SendOnViewExChange(DWORD dwViewStatus);

    static CLIPFORMAT m_cfEmbeddedObject;
    static CLIPFORMAT m_cfObjectDescriptor;
};

#endif //__BULLSEYE_H_
