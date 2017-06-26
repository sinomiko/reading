// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\this.h"
#include "..\this_i.c"

const long rgbRed = RGB(0, 255, 255);

void CreateRedBalloon()
{
  CComPtr<IBalloonMan>  spBalloonMan;
  if( SUCCEEDED(spBalloonMan.CoCreateInstance(CLSID_BalloonMan)) ) {
    CComPtr<IBalloon> spBalloon;
    if( SUCCEEDED(spBalloonMan->CreateBalloon(rgbRed, &spBalloon)) ) {
      long  rgbColor;
      spBalloon->get_Color(&rgbColor);
      ATLASSERT(rgbColor == rgbRed);
    }
  }
}

int main(int argc, char* argv[])
{
  CoInitialize(0);
  CreateRedBalloon();
  CoUninitialize();
	return 0;
}
