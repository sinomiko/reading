// EarPolitic.cpp : Implementation of CEarPolitic
#include "stdafx.h"
#include "ATLInternals.h"
#include "EarPolitic.h"

/////////////////////////////////////////////////////////////////////////////
// CEarPolitic

_ATL_FUNC_INFO CEarPolitic::OnHearWhisperInfo = {CC_STDCALL, VT_EMPTY, 1, { VT_BSTR }};
_ATL_FUNC_INFO CEarPolitic::OnHearTalkInfo    = {CC_STDCALL, VT_EMPTY, 1, { VT_BSTR }};
_ATL_FUNC_INFO CEarPolitic::OnHearYellInfo    = {CC_STDCALL, VT_EMPTY, 1, { VT_BSTR }};

STDMETHODIMP CEarPolitic::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IListener
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

void __stdcall CEarPolitic::OnHearDefendantWhisper(BSTR bstrText)
{
    USES_CONVERSION;

    CComBSTR title ;
    CreateText (title, OLESTR("defendant"), OLESTR("whispering"), m_defendant);

    MessageBox (NULL, OLE2CT(bstrText), OLE2CT(title), MB_OK);
}

void __stdcall CEarPolitic::OnHearDefendantTalk(BSTR bstrText)
{
    USES_CONVERSION;

    CComBSTR title ;
    CreateText (title, OLESTR("defendant"), OLESTR("talking"), m_defendant);

    MessageBox (NULL, OLE2CT(bstrText), OLE2CT(title), MB_OK);
}

void __stdcall CEarPolitic::OnHearDefendantYell(BSTR bstrText)
{
    USES_CONVERSION;

    CComBSTR title ;
    CreateText (title, OLESTR("defendant"), OLESTR("yelling"), m_defendant);

    MessageBox (NULL, OLE2CT(bstrText), OLE2CT(title), MB_OK);
}

void __stdcall CEarPolitic::OnHearPlaintiffWhisper(BSTR bstrText)
{
    USES_CONVERSION;

    CComBSTR title ;
    CreateText (title, OLESTR("plaintiff"), OLESTR("whispering"), m_plaintiff);
    
    MessageBox (NULL, OLE2CT(bstrText), OLE2CT(title), MB_OK);
}

void __stdcall CEarPolitic::OnHearPlaintiffTalk(BSTR bstrText)
{
    USES_CONVERSION;

    CComBSTR title ;
    CreateText (title, OLESTR("plaintiff"), OLESTR("talking"), m_plaintiff);

    MessageBox (NULL, OLE2CT(bstrText), OLE2CT(title), MB_OK);
}

void __stdcall CEarPolitic::OnHearPlaintiffYell(BSTR bstrText)
{
    USES_CONVERSION;

    CComBSTR title ;
    CreateText (title, OLESTR("plaintiff"), OLESTR("yelling"), m_plaintiff);

    MessageBox (NULL, OLE2CT(bstrText), OLE2CT(title), MB_OK);
}

void CEarPolitic::CreateText (CComBSTR& text, LPCOLESTR strRole, LPCOLESTR strAction, LPUNKNOWN punk)
{
    text.Empty ();

    text = m_name;
    text += OLESTR (" hears the ");
    text += strRole;
    text += OLESTR (" (");
    
    CComQIPtr<INamedObject> pno = punk;
    CComBSTR name;
    HRESULT hr = pno->get_Name (&name) ;

    text.AppendBSTR (name);
    text += OLESTR (") ");
    
    text += strAction;
}

STDMETHODIMP CEarPolitic::ListenTo(SpeakerRole role, IUnknown *pSpeaker)
{
    HRESULT hr = StopListening (role) ; // Validates role
    if (FAILED (hr)) return hr ;

    switch (role) {
    case Defendant:
        hr = DefendantEventImpl::DispEventAdvise (pSpeaker, &DIID__ISpeakerEvents) ;
        if (SUCCEEDED (hr))
            m_defendant = pSpeaker ;
        else
            Error (OLESTR("The defendant does not support listening"),
                   __uuidof(IListener), hr);
        break;

    case Plaintiff:
        hr = PlaintiffEventImpl::DispEventAdvise (pSpeaker, &DIID__ISpeakerEvents) ;
        if (SUCCEEDED (hr))
            m_plaintiff = pSpeaker ;
        else
            Error (OLESTR("The Plaintiff does not support listening"),
                   __uuidof(IListener), hr);
        break;
    }

	return hr;
}

STDMETHODIMP CEarPolitic::StopListening(SpeakerRole role)
{
    HRESULT hr = S_OK ;
    switch (role) {
    case Defendant:
        if (m_defendant)
            hr = DefendantEventImpl::DispEventUnadvise (m_defendant, &DIID__ISpeakerEvents) ;

        if FAILED(hr)
            Error (OLESTR("Unexpected error trying to stop listening to the defendant"),
                   __uuidof(IListener), hr);

        m_defendant = NULL;
        break;

    case Plaintiff:
        if (m_plaintiff)
            hr = PlaintiffEventImpl::DispEventUnadvise (m_plaintiff, &DIID__ISpeakerEvents) ;

        if FAILED(hr)
            Error (OLESTR("Unexpected error trying to stop listening to the Plaintiff"),
                   __uuidof(IListener), hr);

        m_plaintiff = NULL;
        break;

    default:
        hr = E_INVALIDARG;
        break;
    }

    return hr;
}
