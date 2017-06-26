// EnumPrimes.h : Declaration of the CEnumPrimes

#ifndef __ENUMPRIMES_H_
#define __ENUMPRIMES_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnumPrimes
class ATL_NO_VTABLE CEnumPrimes : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEnumPrimes, &CLSID_EnumPrimes>,
	public IEnumPrimes
{
public:
	CEnumPrimes()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ENUMPRIMES)
DECLARE_NOT_AGGREGATABLE(CEnumPrimes)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CEnumPrimes)
	COM_INTERFACE_ENTRY(IEnumPrimes)
END_COM_MAP()

// IEnumPrimes
public:
};

#endif //__ENUMPRIMES_H_
