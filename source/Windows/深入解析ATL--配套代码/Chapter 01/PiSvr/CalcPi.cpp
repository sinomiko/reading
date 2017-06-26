// CalcPi.cpp : Implementation of CCalcPi
#include "stdafx.h"
#include "PiSvr.h"
#include "CalcPi.h"
#include "NineDigitsOfPiAt.h"

/////////////////////////////////////////////////////////////////////////////
// CCalcPi

STDMETHODIMP CCalcPi::InterfaceSupportsErrorInfo(REFIID riid)
{
  static const IID* arr[] = 
  {
    &IID_ICalcPi
  };
  for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
  {
    if (InlineIsEqualGUID(*arr[i],riid))
      return S_OK;
  }
  return S_FALSE;
}

STDMETHODIMP CCalcPi::get_Digits(long *pVal)
{
  *pVal = m_nDigits;
  return S_OK;
}

STDMETHODIMP CCalcPi::put_Digits(long newVal)
{
  if( newVal < 0 )
    return Error(L"Can't calculate negative digits of PI");
  m_nDigits = newVal;
  FireViewChange();
  
  return S_OK;
}

STDMETHODIMP CCalcPi::CalcPi(BSTR *pbstrPi)
{
  _ASSERTE(m_nDigits >= 0);
  
  if( m_nDigits )
  {
    *pbstrPi = SysAllocStringLen(L"3.", m_nDigits+2);
    if( *pbstrPi )
    {
      for( int i = 0; i < m_nDigits; i += 9 )
      {
        long nNineDigits = NineDigitsOfPiStartingAt(i+1);
        swprintf(*pbstrPi + i+2, L"%09d", nNineDigits);
      }
      
      // Truncate to number of digits
      (*pbstrPi)[m_nDigits+2] = 0;

      // Fire each digit
      for( short j = 0; j != m_nDigits; ++j )
      {
        Fire_OnDigit(j, (*pbstrPi)[j+2] - L'0');
      }
    }
  }
  else
  {
    *pbstrPi = SysAllocString(L"3");
  }
  
  return *pbstrPi ? S_OK : E_OUTOFMEMORY;
}

HRESULT CCalcPi::OnDraw(ATL_DRAWINFO& di) {
  CComBSTR  bstrPi;
  if( SUCCEEDED(this->CalcPi(&bstrPi)) ) {
    USES_CONVERSION;
    DrawText(di.hdcDraw, OLE2CT(bstrPi), -1, (RECT*)di.prcBounds,
             DT_SINGLELINE | DT_CENTER | DT_VCENTER);
  }

  return S_OK;
}
