// WindowsApp.cpp : Defines the entry point for the application.

#include "stdafx.h"
#include "resource.h"
#include "mainwnd.h"

// The single, global ATL module
CComModule _Module;

// Entry point
int APIENTRY WinMain(HINSTANCE hinst,
                     HINSTANCE /*hinstPrev*/,
                     LPSTR     pszCmdLine,
                     int       nCmdShow)
{
  // Initialize the ATL module
  _Module.Init(0, hinst);

  // Create the main window
  CMainWindow wnd;

  // Load a menu
  HMENU hMenu = LoadMenu(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MENU));

  // Use the value 0 for the style and the extended style
  // to get the window traits for this class.
  wnd.Create(0, CWindow::rcDefault, __T("Windows Application"), 0, 0, (UINT)hMenu);
  if( !wnd ) return -1;
  
  // Show the main window
  wnd.CenterWindow();
  wnd.ShowWindow(nCmdShow);
  wnd.UpdateWindow();
  
  // Main message loop
  MSG msg;
  while( GetMessage(&msg, 0, 0, 0) ) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  // Shutdown the ATL module
  _Module.Term();

  return msg.wParam;
}
