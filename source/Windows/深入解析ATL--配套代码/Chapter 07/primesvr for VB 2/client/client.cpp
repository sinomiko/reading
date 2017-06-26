// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\primesvr.h"
#include "..\primesvr_i.c"
#include "enum_iterator.h"

struct OutputPrime {
  void operator()(const long& nPrime) {
    cout << nPrime << " ";
  }
  void operator()(const VARIANT& varPrime) {
    switch( varPrime.vt )
    {
    case VT_I4:   cout << varPrime.lVal << " "; break;
    case VT_BSTR: wcout << varPrime.bstrVal << endl; break;
    }
  }
};


void TestPrimeNumbers()
{
  CComPtr<IPrimeNumbers>  spPrimes;
  if( SUCCEEDED(spPrimes.CoCreateInstance(CLSID_PrimeNumbers)) )
  {
    // Populate the collection
    HRESULT hr;
    hr = spPrimes->CalcPrimes(0, 1000);

    // Count the number of items in the collection
    long  nPrimes;
    hr = spPrimes->get_Count(&nPrimes);
    cout << "Primes: " << nPrimes << endl;

    /*
    for( long i = 1; i <= nPrimes; ++i ) {
      long  nPrime;
      hr = spPrimes->get_Item(i, &nPrime);
      cout << nPrime << " ";
    }
    */

    // Enumerate over the collection using sequencial access
    CComPtr<IUnknown> spunkEnum;
    hr = spPrimes->get__NewEnum(&spunkEnum);
    for_each(variant_iterator(spunkEnum), variant_iterator(), OutputPrime());
  }
}

void TestPrimeNumberWords()
{
  CComPtr<IPrimeNumberWords>  spPrimes;
  if( SUCCEEDED(spPrimes.CoCreateInstance(CLSID_PrimeNumberWords)) )
  {
    // Populate the collection
    HRESULT hr;
    hr = spPrimes->CalcPrimes(0, 100);

    // Count the number of items in the collection
    long  nPrimes;
    hr = spPrimes->get_Count(&nPrimes);
    cout << "Primes: " << nPrimes << endl;

    /*
    for( long i = 1; i <= nPrimes; ++i ) {
      CComBSTR  bstrPrime;
      hr = spPrimes->get_Item(i, &bstrPrime);
      wcout << static_cast<BSTR>(bstrPrime) << endl;
    }
    */

    // Enumerate over the collection using sequencial access
    CComPtr<IUnknown> spunkEnum;
    hr = spPrimes->get__NewEnum(&spunkEnum);
    for_each(variant_iterator(spunkEnum), variant_iterator(), OutputPrime());
  }
}

void main() {
  CoInitialize(0);
  //TestPrimeNumbers();
  TestPrimeNumberWords();
  CoUninitialize();
}

