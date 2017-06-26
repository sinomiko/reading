// Demagogue.h : Declaration of the CDemagogue

#ifndef __DEMAGOGUE_H_
#define __DEMAGOGUE_H_

#include "resource.h"       // main symbols
#include "SpeakerEventsCP.h"

/////////////////////////////////////////////////////////////////////////////
// CDemagogue
class ATL_NO_VTABLE CDemagogue : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDemagogue, &CLSID_Demagogue>,
	public ISupportErrorInfo,
	public IDispatchImpl<ISpeaker, &IID_ISpeaker, &LIBID_ATLINTERNALSLib>,
	public CProxy_ISpeakerEvents<CDemagogue>,
	public IConnectionPointContainerImpl<CDemagogue>,
	public IDispatchImpl<INamedObject, &IID_INamedObject, &LIBID_ATLINTERNALSLib>,
    public IProvideClassInfo2Impl<&CLSID_Demagogue, &DIID__ISpeakerEvents, &LIBID_ATLINTERNALSLib, LIBRARY_MAJOR, LIBRARY_MINOR>,
    public IPersistPropertyBagImpl<CDemagogue>,
    public IPersistStreamInitImpl2<CDemagogue>,
    public IPersistMemoryImpl<CDemagogue>,
    public CSupportDirtyBit,
    public IMarshalByValueImpl<CDemagogue>
    {
public:
	CDemagogue()
	{
        m_volume = 0 ;
        m_name = OLESTR("Demosthenes") ;
        m_speech = 
        L"Phormio's inexperience in speaking, and his utter helplessness, "
        L"you all see for yourselves, men of Athens. "
        L"It is necessary for us, his friends, to state and set forth for you the facts, "
        L"which we know full well from having heard him often relate them; "
        L"in order that, when you have duly learned from us and have come to know the rights of the case, "
        L"you may give a verdict that is both just and in harmony with your oaths.";

    }

    void FinalRelease ()
    {
#ifdef _DEBUG
		int nConnections = m_vec.GetSize();
		int nConnectionIndex;
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++) {
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			if (sp != NULL)
                ATLASSERT (false); // We are going away with connections outstanding!!!
		}
#endif
    }

    static HRESULT WINAPI UpdateRegistry(BOOL b)
    {
        USES_CONVERSION;
        TCHAR szDate [32]; SYSTEMTIME st;  
        GetLocalTime(&st);
        wsprintf (szDate, _T("%.4d/%.2d/%.2d at %.2d:%.2d:%.2d"),
            st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
        _ATL_REGMAP_ENTRY rm[] = { { OLESTR("INSTALLDATE"), T2COLE(szDate)}, { 0, 0 }, };
        return _Module.UpdateRegistryFromResource(IDR_DEMAGOGUE, b, rm);
    }

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDemagogue)
	COM_INTERFACE_ENTRY(ISpeaker)
	COM_INTERFACE_ENTRY2(IDispatch, ISpeaker)
	COM_INTERFACE_ENTRY(INamedObject)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
    COM_INTERFACE_ENTRY(IProvideClassInfo2)
    COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY(IPersistPropertyBag)
    COM_INTERFACE_ENTRY(IPersistMemory)
    COM_INTERFACE_ENTRY(IMarshal)
END_COM_MAP()

BEGIN_CATEGORY_MAP(CDemagogue)
IMPLEMENTED_CATEGORY(CATID_ATLINTERNALS_SAMPLES)
END_CATEGORY_MAP()

BEGIN_PROP_MAP(CDemagogue)
PROP_ENTRY_EX("Speech", DISPID_SPEECH, CLSID_NULL, IID_ISpeaker)
PROP_ENTRY_EX("Volume", DISPID_VOLUME, CLSID_NULL, IID_ISpeaker)
PROP_ENTRY_EX("Name",   DISPID_NAME,   CLSID_NULL, IID_INamedObject)
END_PROP_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ISpeaker
public:
    STDMETHODIMP Speak();

	STDMETHODIMP get_Speech(/*[out, retval]*/ BSTR *pVal);
	STDMETHODIMP put_Speech(/*[in]*/ BSTR newVal);
	STDMETHODIMP get_Volume(/*[out, retval]*/ long *pVal);
	STDMETHODIMP put_Volume(/*[in]*/ long newVal);

    STDMETHODIMP Load (IPropertyBag *pBag, IErrorLog *pLog)
    {
      CComVariant v ((BSTR) NULL);  // Initialize the VARIANT to VT_BSTR
      HRESULT hr = pBag->Read(OLESTR("Name"), &v, pLog);
      if (FAILED (hr)) return hr;
      m_name = v.bstrVal;

      v = 0L;                       // Initialize the VARIANT to VT_I4
      hr = pBag->Read(OLESTR("Volume"), &v, pLog);
      if (FAILED (hr)) return hr;
      m_volume = v.lVal;

      v = (BSTR) NULL;              // Initialize the VARIANT to VT_BSTR
      hr = pBag->Read(OLESTR("Speech"), &v, pLog);
      if (FAILED (hr)) return hr;
      m_speech = v.bstrVal;

      return S_OK;
    }

    STDMETHODIMP Save (IPropertyBag *pBag, BOOL /* fClearDirty */, BOOL /* fSaveAllProperties */)
    {
      CComVariant v = m_name;
      HRESULT hr = pBag->Write(OLESTR("Name"), &v);
      if (FAILED(hr)) return hr;

      v = m_volume;
      hr = pBag->Write(OLESTR("Volume"), &v);
      if (FAILED(hr)) return hr;

      v = m_speech;
      hr = pBag->Write(OLESTR("Speech"), &v);
      if (FAILED(hr)) return hr;

      // fClearDirty and fSaveAllProperties not used
      return hr;
    }


public :

BEGIN_CONNECTION_POINT_MAP(CDemagogue)
	CONNECTION_POINT_ENTRY(DIID__ISpeakerEvents)
END_CONNECTION_POINT_MAP()

// INamedObject
	STDMETHOD(get_Name)(/*[out, retval]*/ BSTR * pVal)
	{
		if (pVal == NULL) return E_POINTER;

        *pVal = m_name.Copy() ;
		return S_OK;
	}
	STDMETHOD(put_Name)(/*[in]*/ BSTR pVal)
	{
        m_name = pVal;
        SetDirty(TRUE);
		return S_OK;
	}

private:
	CComBSTR m_name;
    long     m_volume;
	CComBSTR m_speech;
};

#endif //__DEMAGOGUE_H_
