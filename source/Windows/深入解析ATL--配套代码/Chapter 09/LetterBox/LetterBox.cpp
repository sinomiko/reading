// LetterBox.cpp : Defines the entry point for the application.

#include "stdafx.h"
#include "resource.h"
#include "mainwnd.h"

// Required ATL module
CComModule _Module;

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, int nShow)
{
    // Initialize the ATL module
    _Module.Init(0, hinst);

    // Create and show the main window
    HMENU   hMenu = LoadMenu(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_LETTERBOX));
    TCHAR   szTitle[64] = "";
    LoadString(_Module.GetResourceInstance(), IDS_APP_TITLE, szTitle, sizeof(szTitle)/sizeof(*szTitle));

    CMainWindow wndMain;
    wndMain.Create(0, CWindow::rcDefault, szTitle, 0, 0, (UINT)hMenu);
    wndMain.ShowWindow(nShow);
    wndMain.UpdateWindow();

    // Pump messages
    HACCEL  haccel = LoadAccelerators(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDC_LETTERBOX));
    MSG     msg;
    while( GetMessage(&msg, 0, 0, 0) )
    {
        if( !TranslateAccelerator(msg.hwnd, haccel, &msg) )
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    // Terminate the ATL module
    _Module.Term();
    
    return 0;
}
