// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\fwdshims.h"

struct ComInit
{
    ComInit(DWORD dwCoInit = COINIT_APARTMENTTHREADED) { CoInitializeEx(0, dwCoInit); }
    ~ComInit() { CoUninitialize(); }
} g_com;

int main(int argc, char* argv[])
{
    CComPtr<IUnknown>   spunk;
    if( SUCCEEDED(spunk.CoCreateInstance(__uuidof(AcePowell))) )
    {
        CComQIPtr<ICowboy> spcb = spunk;
        if( spcb ) spcb->Draw();

        CComQIPtr<IArtist> spa = spunk;
        if( spa ) spa->Draw();
    }

	return S_OK;
}
