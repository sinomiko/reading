// BalloonMan.cpp : Implementation of CBallonMan
#include "stdafx.h"
#include "This.h"
#include "BalloonMan.h"

/////////////////////////////////////////////////////////////////////////////
// CBalloonMan

STDMETHODIMP CBalloonMan::CreateBalloon(long rgbColor, IBalloon **ppBalloon) {
  // Create balloon
  HRESULT     hr = CBalloon::CreateInstance(0, ppBalloon);

  if( SUCCEEDED(hr) ) {
    // Use backdoor to acquire CBalloon's this pointer
    CBalloon*   pBalloonThis = 0;
    hr = (*ppBalloon)->QueryInterface(IID_NULL, (void**)&pBalloonThis);
    if( SUCCEEDED(hr) ) {
      // Use CBalloon's this pointer for private initialization
      pBalloonThis->m_rgbColor = rgbColor;
    }
  }

  if( FAILED(hr) ) {
    (*ppBalloon)->Release();
    *ppBalloon = 0;
  }

	return hr;
}
