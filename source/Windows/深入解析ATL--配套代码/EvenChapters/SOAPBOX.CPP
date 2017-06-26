// SoapBox.cpp : Implementation of CSoapBox
#include "stdafx.h"
#include "ATLInternals.h"
#include "SoapBox.h"

/////////////////////////////////////////////////////////////////////////////
// CSoapBox

STDMETHODIMP CSoapBox::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IClimbableObject
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
