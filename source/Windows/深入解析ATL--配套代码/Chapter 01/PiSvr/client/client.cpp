// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\pisvr.h"
#include "..\pisvr_i.c"

HRESULT TestCalcPi() {
  CComPtr<IAdvertiseMyself> spAdvertise;
  if( SUCCEEDED(spAdvertise.CoCreateInstance(CLSID_CalcPi)) ) {
    spAdvertise->ShowAd(CComBSTR("CalcPi Client"));
  }

  return S_OK;
}

int main(int argc, char* argv[])
{
  CoInitialize(0);
  TestCalcPi();
  CoUninitialize();

  return 0;
}
