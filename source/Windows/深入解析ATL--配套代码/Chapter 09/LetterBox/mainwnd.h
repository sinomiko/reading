// MainWnd.h: Defines main window for application

#pragma once
#ifndef MAINWND_H
#define MAINWND_H

#include "LettersDlg.h"

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
      wci.m_wc.hIcon = LoadIcon(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_LETTERBOX));
      wci.m_wc.hIconSm = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_LETTERBOX), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
    }
  }
  
BEGIN_MSG_MAP(CMainWindow)
  MESSAGE_HANDLER(WM_CREATE, OnCreate)
  MESSAGE_HANDLER(WM_SIZE, OnSize)
  COMMAND_ID_HANDLER(ID_FILE_EXIT, OnExit)
  COMMAND_ID_HANDLER(ID_EDIT_LETTERS, OnLetters)
  COMMAND_ID_HANDLER(ID_HELP_ABOUT, OnAbout)
ALT_MSG_MAP(1)
  MESSAGE_HANDLER(WM_CHAR, OnEditChar)
END_MSG_MAP()
    
  LRESULT OnCreate(UINT, WPARAM, LPARAM, BOOL&) {
    if( m_edit.Create(this, 1, m_hWnd, &CWindow::rcDefault) ) {
      return 0;
    }
    return -1;
  }
  
  LRESULT OnSize(UINT, WPARAM, LPARAM lparam, BOOL&) {
    RECT rect = { 0, 0, LOWORD(lparam), HIWORD(lparam) };
    return m_edit.MoveWindow(&rect);
  }

  LRESULT OnEditChar(UINT, WPARAM wparam, LPARAM, BOOL& bHandled) {
    if( isalpha((TCHAR)wparam) ) bHandled = FALSE;
    else                         MessageBeep(0xFFFFFFFF);
    return 0;
  }

  LRESULT OnExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    DestroyWindow();
    return 0;
  }
  
  LRESULT OnAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    CSimpleDialog<IDD_ABOUTBOX> dlg;
    dlg.DoModal();
    return 0;
  }
  
  LRESULT OnLetters(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    CLettersDlg dlg;
    dlg.DoModal();
    return 0;
  }

  void OnFinalMessage(HWND)
  {
    PostQuitMessage(0);
  }

private:
  CContainedWindowT<ATLControls::CEdit> m_edit;
};

#endif  // MAINWND_H
