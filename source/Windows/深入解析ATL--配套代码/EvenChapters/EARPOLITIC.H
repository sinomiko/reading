// EarPolitic.h : Declaration of the CEarPolitic

#ifndef __EARPOLITIC_H_
#define __EARPOLITIC_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEarPolitic

static const int  DEFENDANT_SOURCE_ID = 0 ;
static const int  PLAINTIFF_SOURCE_ID = 1 ;

class CEarPolitic;

typedef IDispEventImpl<DEFENDANT_SOURCE_ID, CEarPolitic, &DIID__ISpeakerEvents, &LIBID_ATLINTERNALSLib, LIBRARY_MAJOR, LIBRARY_MINOR> DefendantEventImpl; 
typedef IDispEventSimpleImpl<PLAINTIFF_SOURCE_ID, CEarPolitic, &DIID__ISpeakerEvents> PlaintiffEventImpl; 

class ATL_NO_VTABLE CEarPolitic : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEarPolitic, &CLSID_EarPolitic>,
	public ISupportErrorInfo,
	public IDispatchImpl<IListener, &IID_IListener, &LIBID_ATLINTERNALSLib>,
    public IDispatchImpl<INamedObject, &IID_INamedObject, &LIBID_ATLINTERNALSLib>,
    public DefendantEventImpl,
    public PlaintiffEventImpl,
    public IPersistPropertyBagImpl<CEarPolitic>,
    public IPersistStreamInitImpl<CEarPolitic>,
    public CSupportDirtyBit
{
public:
	CEarPolitic() { m_name = OLESTR ("Anonymous"); }

    void FinalRelease ()
    {
        ATLASSERT (!m_defendant); // Something is seriously wrong if this asserts
        ATLASSERT (!m_plaintiff); // We have a connection to someone who doesn't
                                  //  have a reference to us???
    }

DECLARE_REGISTRY_RESOURCE(EARPOLITIC)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CEarPolitic)
	COM_INTERFACE_ENTRY(IListener)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY2(IDispatch, IListener)
	COM_INTERFACE_ENTRY(INamedObject)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY(IPersistPropertyBag)
END_COM_MAP()

BEGIN_SINK_MAP(CEarPolitic)
   SINK_ENTRY_EX(DEFENDANT_SOURCE_ID, DIID__ISpeakerEvents, DISPID_ONWHISPER, OnHearDefendantWhisper)
   SINK_ENTRY_EX(DEFENDANT_SOURCE_ID, DIID__ISpeakerEvents, DISPID_ONTALK,    OnHearDefendantTalk)
   SINK_ENTRY_EX(DEFENDANT_SOURCE_ID, DIID__ISpeakerEvents, DISPID_ONYELL,    OnHearDefendantYell)

   SINK_ENTRY_INFO(PLAINTIFF_SOURCE_ID, DIID__ISpeakerEvents, DISPID_ONWHISPER, OnHearPlaintiffWhisper, &OnHearWhisperInfo)
   SINK_ENTRY_INFO(PLAINTIFF_SOURCE_ID, DIID__ISpeakerEvents, DISPID_ONTALK,    OnHearPlaintiffTalk,    &OnHearTalkInfo)
   SINK_ENTRY_INFO(PLAINTIFF_SOURCE_ID, DIID__ISpeakerEvents, DISPID_ONYELL,    OnHearPlaintiffYell,    &OnHearYellInfo)
END_SINK_MAP()

BEGIN_CATEGORY_MAP(CEarPolitic)
IMPLEMENTED_CATEGORY(CATID_ATLINTERNALS_SAMPLES)
END_CATEGORY_MAP()

BEGIN_PROP_MAP(CEarPolitic)
PROP_ENTRY_EX("Name",   DISPID_NAME,   CLSID_NULL, IID_INamedObject)
END_PROP_MAP()

public:
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IListener
	STDMETHOD(StopListening)(SpeakerRole role);
	STDMETHOD(ListenTo)(SpeakerRole role, IUnknown* pSpeaker);

// INamedObject
	STDMETHOD(get_Name)(BSTR * pVal)
	{
		if (pVal == NULL) return E_POINTER;
		
        *pVal = m_name.Copy ();
		return S_OK;
	}
	STDMETHOD(put_Name)(BSTR pVal)
	{
		m_name = pVal;
        return S_OK;
	}

// ISpeakerEvents
public:
    void __stdcall OnHearDefendantWhisper(BSTR bstrText);
    void __stdcall OnHearDefendantTalk(BSTR bstrText);
    void __stdcall OnHearDefendantYell(BSTR bstrText);
    void __stdcall OnHearPlaintiffWhisper(BSTR bstrText);
    void __stdcall OnHearPlaintiffTalk(BSTR bstrText);
    void __stdcall OnHearPlaintiffYell(BSTR bstrText);

private:
	CComBSTR            m_name;
	CComPtr<IUnknown>   m_defendant;
	CComPtr<IUnknown>   m_plaintiff;

    void CreateText (CComBSTR& title, LPCOLESTR strRole, LPCOLESTR strAction, LPUNKNOWN punk);

    static _ATL_FUNC_INFO OnHearWhisperInfo ;
    static _ATL_FUNC_INFO OnHearTalkInfo ;
    static _ATL_FUNC_INFO OnHearYellInfo ;
};

#endif //__EARPOLITIC_H_
