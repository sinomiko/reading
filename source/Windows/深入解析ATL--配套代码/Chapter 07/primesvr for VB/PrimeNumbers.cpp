// PrimeNumbers.cpp : Implementation of CPrimeNumbers
#include "stdafx.h"
#include "Primesvr.h"
#include "PrimeNumbers.h"

/////////////////////////////////////////////////////////////////////////////
// CPrimeNumbers

STDMETHODIMP CPrimeNumbers::CalcPrimes(long min, long max) {
  m_coll.SetRange(min, max);
  return S_OK;
}

#if 0
STDMETHODIMP CPrimeNumbers::get_Count(long* pnCount) {
  *pnCount = m_rgPrimes.size();
  return S_OK;
}

STDMETHODIMP CPrimeNumbers::get_Item(long n, long* pnPrime) {
  // Oh, let's be 1-based today...
  if( n < 1 && n > m_rgPrimes.size() ) return E_INVALIDARG;

  //*pnPrime = m_rgPrimes[n-1].lVal;
  *pnPrime = m_rgPrimes[n-1];
  return S_OK;
}

/*
// w/o STL
typedef CComEnum< IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > CComEnumVariant;

STDMETHODIMP CPrimeNumbers::get__NewEnum(IUnknown** ppunkEnum)
{
  *ppunkEnum = 0;

  CComObject<CComEnumVariant>*  pe = 0;
  HRESULT hr = CComObject<CComEnumVariant>::CreateInstance(&pe);
  if( SUCCEEDED(hr) ) {
    pe->AddRef();

    // Copy data from vector<long> to VARIANT*
    size_t    nPrimes = m_rgPrimes.size();
    VARIANT*  rgvar = new VARIANT[nPrimes];
    if( rgvar )
    {
      ZeroMemory(rgvar, sizeof(VARIANT) * nPrimes);
      VARIANT*  pvar = &rgvar[0];
      for( vector<long>::iterator it = m_rgPrimes.begin();
           it != m_rgPrimes.end();
           ++pvar, ++it )
      {
        pvar->vt = VT_I4;
        pvar->lVal = *it;
      }

      // Initialize enumerator
      hr = pe->Init(&rgvar[0], &rgvar[nPrimes], 0, AtlFlagTakeOwnership);
      if( SUCCEEDED(hr) )
      {
        // Fill outbound parameter
        hr = pe->QueryInterface(IID_IUnknown, (void**)ppunkEnum);
      }
    }
    else
    {
      hr = E_OUTOFMEMORY;
    }

    pe->Release();
  }

  return hr;
}
*/

template <typename CollType, typename ThreadingModel = CComObjectThreadModel>
class CComContainerCopy :
  public CComObjectRootEx<ThreadingModel>,
  public IUnknown { // CComEnumOnSTL only needs an IUnknown*
public:
  CComContainerCopy() { ATLTRACE("CComContainerCopy()\n"); }
  ~CComContainerCopy() { ATLTRACE("~CComContainerCopy()\n"); }

  HRESULT Copy(const CollType& coll)
  { try { m_coll = coll; return S_OK; } catch(...) { return E_OUTOFMEMORY; } }

BEGIN_COM_MAP(CComContainerCopy)
    COM_INTERFACE_ENTRY(IUnknown)
END_COM_MAP()

  CollType  m_coll;
};

/**/
// W/ STL
STDMETHODIMP CPrimeNumbers::get__NewEnum(IUnknown** ppunkEnum) {
  *ppunkEnum = 0;

  //typedef CComEnumOnSTL<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT>, vector<VARIANT> >
  //        CComEnumVariantOnVector;
  typedef CComEnumOnSTL<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _CopyVariantFromLong, PrimesContainer >
          CComEnumVariantOnPrimesContainer;

  //CComObject<CComEnumVariantOnVectorOfLongs>* pe = 0;
  //CComObject<CComEnumVariantOnVector>* pe = 0;
  CComObject<CComEnumVariantOnPrimesContainer>* pe = 0;
  // Here we're using pe as a scoping mechanism,
  // as CreateInstance is a static method of CComObject
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
/**/
#endif  // 0
