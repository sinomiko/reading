// WindowsApp.cpp : Defines the entry point for the application.

#include "stdafx.h"
#include "resource.h"

// The single, global ATL module
CComModule _Module;

// Main Window Traits
typedef CWinTraitsOR<0, WS_EX_CLIENTEDGE, CFrameWinTraits> CMainWinTraits;

// Main window class
class CMainWindow : public CWindowImpl<CMainWindow, CWindow, CMainWinTraits>
{
public:
BEGIN_MSG_MAP(CMainWindow)
  MESSAGE_HANDLER(WM_PAINT, OnPaint)
  COMMAND_ID_HANDLER(ID_FILE_EXIT, OnFileExit)
  COMMAND_ID_HANDLER(ID_HELP_ABOUT, OnHelpAbout)
END_MSG_MAP()

  CMainWindow() {
    // Retrieve the window class information
    CWndClassInfo& wci = GetWndClassInfo();

    // If the wc hasn't already been registered, update it
    if( !wci.m_atom ) {
      wci.m_wc.hIcon = LoadIcon(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_BAREBONES));
      wci.m_wc.hIconSm = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_BAREBONES), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
      wci.m_wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
      wci.m_bSystemCursor = FALSE;
      wci.m_lpszCursorID = MAKEINTRESOURCE(IDC_BAREBONES);
    }
  }

private:
  LRESULT OnPaint(UINT nMsg, WPARAM wparam, LPARAM lparam, BOOL& bHandled) {
    PAINTSTRUCT ps;
    HDC         hdc = BeginPaint(&ps);
    RECT        rect; GetClientRect(&rect);
    DrawText(hdc, __T("Hello, Windows"), -1, &rect,
             DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    EndPaint(&ps);

    return 0;
  }

  LRESULT OnFileExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    DestroyWindow();
    return 0;
  }

  LRESULT OnHelpAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    MessageBox("About", "Ain't ATL cool?");
    return 0;
  }

  virtual void OnFinalMessage(HWND /*hwnd*/)
  { PostQuitMessage(0); }
};

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
