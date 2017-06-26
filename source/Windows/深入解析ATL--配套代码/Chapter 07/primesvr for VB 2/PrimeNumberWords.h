// PrimeNumberWords.h : Declaration of the CPrimeNumberWords

#ifndef __PRIMENUMBERWORDS_H_
#define __PRIMENUMBERWORDS_H_

#include "resource.h"       // main symbols
#include "isprime.h"
#include "numword.h"

struct _CopyVariantFromAdaptBstr {
	static HRESULT copy(VARIANT* p1, CAdapt<CComBSTR>* p2) {
    p1->vt = VT_BSTR;
    p1->bstrVal = p2->m_T.Copy();
    return (p1->bstrVal ? S_OK : E_OUTOFMEMORY);
  }
	
  static void init(VARIANT* p)    { VariantInit(p); }
  static void destroy(VARIANT* p) { VariantClear(p); }
};

struct _CopyBstrFromAdaptBstr {
	static HRESULT copy(BSTR* p1, CAdapt<CComBSTR>* p2) {
    *p1 = SysAllocString(p2->m_T);
    return (p1 ? S_OK : E_OUTOFMEMORY);
  }
	
  static void init(BSTR* p)    { }
  static void destroy(BSTR* p) { SysFreeString(*p); }
};

typedef CComEnumOnSTL<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT,
                      _CopyVariantFromAdaptBstr, vector< CAdapt<CComBSTR> > >
        CComEnumVariantOnVectorOfAdaptBstr;

typedef IDispatchImpl<IPrimeNumberWords, &IID_IPrimeNumberWords>
        IPrimeNumberWordsDualImpl;

typedef ICollectionOnSTLImpl<IPrimeNumberWordsDualImpl,
                             vector< CAdapt<CComBSTR> >,
                             BSTR,
                             _CopyBstrFromAdaptBstr,
                             CComEnumVariantOnVectorOfAdaptBstr>
        IPrimeNumberWordsCollImpl;

/////////////////////////////////////////////////////////////////////////////
// CPrimeNumberWords
class ATL_NO_VTABLE CPrimeNumberWords : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPrimeNumberWords, &CLSID_PrimeNumberWords>,
	//public IDispatchImpl<IPrimeNumberWords, &IID_IPrimeNumberWords, &LIBID_PRIMESVRLib>
	public IPrimeNumberWordsCollImpl
{
public:
	CPrimeNumberWords()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PRIMENUMBERWORDS)
DECLARE_NOT_AGGREGATABLE(CPrimeNumberWords)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPrimeNumberWords)
	COM_INTERFACE_ENTRY(IPrimeNumberWords)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IPrimeNumberWords
public:
  STDMETHODIMP CalcPrimes(long min, long max) {
    while( min <= max ) {
      if( IsPrime(min) ) {
        char  sz[64];
        CComBSTR  bstr = NumWord(min, sz);
        //m_rgPrimes.push_back(bstr);
        m_coll.push_back(bstr);
      }
      ++min;
    }

    return S_OK;
  }
/*
  STDMETHODIMP get_Count(long* pnCount)
  { *pnCount = m_rgPrimes.size(); return S_OK; }

  STDMETHODIMP get_Item(long n, BSTR* pbstrPrimeWord) {
    if( n < 1 || n > m_rgPrimes.size() ) return E_INVALIDARG;

    //CComBSTR& bstr = m_rgPrimes[n-1].m_T;
    CComBSTR& bstr = m_rgPrimes[n-1];
    return bstr.CopyTo(pbstrPrimeWord);
  }

  STDMETHODIMP get__NewEnum(IUnknown** ppunkEnum) {
    *ppunkEnum = 0;

    CComObject<CComEnumVariantOnVectorOfAdaptBstr>* pe = 0;
    HRESULT hr = pe->CreateInstance(&pe);
    if( SUCCEEDED(hr) ) {
      pe->AddRef();

      hr = pe->Init(this->GetUnknown(), m_rgPrimes);
      if( SUCCEEDED(hr) ) {
        hr = pe->QueryInterface(ppunkEnum);
      }

      pe->Release();
    }

    return hr;
  }


private:
    vector< CAdapt<CComBSTR> >  m_rgPrimes;
  */
};

#endif //__PRIMENUMBERWORDS_H_
