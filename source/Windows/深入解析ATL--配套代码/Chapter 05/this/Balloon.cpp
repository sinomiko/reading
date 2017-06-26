// Balloon.cpp : Implementation of CBalloon
#include "stdafx.h"
#include "This.h"
#include "Balloon.h"

/////////////////////////////////////////////////////////////////////////////
// CBalloon


STDMETHODIMP CBalloon::get_Color(long *pVal)
{
	*pVal = m_rgbColor;

	return S_OK;
}
