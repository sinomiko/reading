// Demagogue.cpp : Implementation of CDemagogue
#include "stdafx.h"
#include "ATLInternals.h"
#include "Demagogue.h"

/////////////////////////////////////////////////////////////////////////////
// CDemagogue

// ISupportErrorInfo
STDMETHODIMP CDemagogue::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ISpeaker
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CDemagogue::get_Volume(long *pVal)
{
    if (NULL == pVal) return E_POINTER ;

    *pVal = m_volume ;
	return S_OK;
}

STDMETHODIMP CDemagogue::put_Volume(long newVal)
{
	m_volume = newVal ;
    SetDirty(true);
	return S_OK;
}

STDMETHODIMP CDemagogue::get_Speech(BSTR *pVal)
{
    if (NULL == pVal) return E_POINTER ;

    *pVal = m_speech.Copy () ;

	return S_OK;
}

STDMETHODIMP CDemagogue::put_Speech(BSTR newVal)
{
    m_speech = newVal ;
    SetDirty(true);
	return S_OK;
}

STDMETHODIMP CDemagogue::Speak()
{
    if (m_volume <= -100)
        Fire_OnWhisper (m_speech);

    if (m_volume >= 100)
        Fire_OnYell (m_speech);

	Fire_OnTalk (m_speech);

    return S_OK;
}
