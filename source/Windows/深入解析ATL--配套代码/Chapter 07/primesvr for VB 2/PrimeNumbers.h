// PrimeNumbers.h : Declaration of the CPrimeNumbers

#ifndef __PRIMENUMBERS_H_
#define __PRIMENUMBERS_H_

#include "resource.h"       // main symbols
#include "isprime.h"

/////////////////////////////////////////////////////////////////////////////
// CPrimeNumbers

/**/
class PrimesContainer {
public:
  class iterator; // Forward declaration

  PrimesContainer() : m_min(0), m_max(0) {}

  // For IPrimeNumbers::CalcPrimes
  void SetRange(long min, long max)
  { m_min = min; m_max = max; }

  // For IPrimeNumbers::get_Count
  size_t  size()
  { return CountPrimes(m_min, m_max); }

  // For IPrimeNumbers::get_Item
  long operator[](size_t i)
  { return NthPrime(i + 1, m_min, m_max); }

  // The rest is for CComEnumOnSTL
  iterator begin()
  { return iterator(m_min, m_max); }

  iterator end()
  { return iterator(); }

  class iterator {
  public:
    iterator (long min = -1, long max = -1)
    : m_max(max), m_next(NthPrime(1, min, max))
    { if( m_next == -1 ) m_max = -1;  } // Match end()

    bool operator!=(const iterator& rhs)
    { return (m_next != rhs.m_next || m_max != rhs.m_max); }

    long& operator*()
    { return m_next; }

    iterator operator++(int) {
      iterator it(m_next, m_max);
      m_next = NthPrime(1, m_next + 1, m_max);
      if( m_next == -1 ) m_max = -1; // Match end()
      return it;
    }

  private:
    long  m_next, m_max;
  };

private:
  long  m_min, m_max;
};
/**/

// Needed for implementation of get_Item.
// Coverts the storage type (VARIANT) to the item item (long).
struct _CopyVariantFromLong {
	static HRESULT copy(VARIANT* p1, long* p2) {
    p1->vt = VT_I4;
    p1->lVal = *p2;
    return S_OK;
  }
	
  static void init(VARIANT* p)    { VariantInit(p); }
  static void destroy(VARIANT* p) { VariantClear(p); }
};

//typedef CComEnumOnSTL<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _CopyVariantFromLong, vector<long> >
//        CComEnumVariantOnVectorOfLongs;

// Needed for implementation of get__NewEnum.
// Coverts the storage type (long) to the enumeration (VARIANT).
struct _CopyLongFromVariant {
	static HRESULT copy(long* p1, VARIANT* p2) {
    if( p2->vt == VT_I4 ) {
      *p1 = p2->lVal;
      return S_OK;
    }
    else {
      VARIANT var;
      HRESULT hr = VariantChangeType(&var, p2, 0, VT_I4);
      if( SUCCEEDED(hr) ) *p1 = var.lVal;
      return hr;
    }
  }
	
  static void init(long* p)    { }
  static void destroy(long* p) { }
};

// Needed for implementation of IDispatch methods
typedef IDispatchImpl<IPrimeNumbers, &IID_IPrimeNumbers>
        IPrimeNumbersDualImpl;

// Needed for implementation of get__NewEnum method
typedef CComEnumOnSTL<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT,
                      _CopyVariantFromLong, PrimesContainer>
        CComEnumVariantOnPrimesContainer;

// Needed for implementation of standard collection methods
typedef ICollectionOnSTLImpl<IPrimeNumbersDualImpl,
                             PrimesContainer, long, _Copy<long>,
                             CComEnumVariantOnPrimesContainer>
        IPrimeNumbersCollImpl;

class ATL_NO_VTABLE CPrimeNumbers : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPrimeNumbers, &CLSID_PrimeNumbers>,
  public IPrimeNumbersCollImpl
{
public:

DECLARE_REGISTRY_RESOURCEID(IDR_PRIMENUMBERS)
DECLARE_NOT_AGGREGATABLE(CPrimeNumbers)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPrimeNumbers)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IPrimeNumbers)
END_COM_MAP()

// IPrimeNumbers
public:
  STDMETHODIMP CalcPrimes(long min, long max);
};

#endif //__PRIMENUMBERS_H_
