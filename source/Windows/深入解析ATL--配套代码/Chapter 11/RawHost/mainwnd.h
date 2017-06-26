// MainWnd.h: Defines main window for application

#pragma once
#ifndef MAINWND_H
#define MAINWND_H

typedef CWinTraitsOR<0, WS_EX_CLIENTEDGE, CFrameWinTraits>
CMainWindowTraits;

class CMainWindow : public CWindowImpl<CMainWindow, CWindow, CMainWindowTraits>
{
public:
  CMainWindow()
  {
    // Initialize window info
    CWndClassInfo&  wci = GetWndClassInfo();
    if( !wci.m_atom )
    {
      wci.m_wc.hIcon = LoadIcon(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_RAWHOST));
      wci.m_wc.hIconSm = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_RAWHOST), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
      wci.m_wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
      wci.m_bSystemCursor = TRUE;
      wci.m_lpszCursorID = IDC_ARROW;
    }
  }
  
BEGIN_MSG_MAP(CMainWindow)
  MESSAGE_HANDLER(WM_CREATE, OnCreate)
  MESSAGE_HANDLER(WM_SIZE, OnSize)
  COMMAND_ID_HANDLER(ID_FILE_EXIT, OnFileExit)
  COMMAND_ID_HANDLER(ID_HELP_ABOUT, OnHelpAbout)
END_MSG_MAP()
    
  // Handler prototypes:
  //  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  //  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  //  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    
  LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& lResult)
  {
    // Create host window, CAxHostWindow object and host the control
    RECT    rect; GetClientRect(&rect);
    LPCTSTR pszName = __T("ATLInternals.BullsEye");
    HWND    hwndContainer = m_ax.Create(__T("AtlAxWin"), m_hWnd, rect, pszName, WS_CHILD | WS_VISIBLE);
    if( !hwndContainer ) return -1;
    
    return 0;
  }
  
  LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& lResult)
  {
    RECT rect = { 0, 0, LOWORD(lParam), HIWORD(lParam) };
    return m_ax.MoveWindow(&rect);
  }
  
  LRESULT OnFileExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    DestroyWindow();
    return 0;
  }
  
  LRESULT OnHelpAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    CSimpleDialog<IDD_ABOUTBOX> dlg;
    dlg.DoModal();
    return 0;
  }
  
  void OnFinalMessage(HWND)
  {
    PostQuitMessage(0);
  }
  
private:
  CWindow m_ax;
};

#endif  // MAINWND_H
