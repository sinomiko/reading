// mainwnd.h

#pragma once
#include "doc.h"
#include "view.h"
#include "aboutbox.h"

///////////////////////////////////////////////////////////////////
// A main window class

// Main Window Traits
typedef CWinTraitsOR<0, WS_EX_CLIENTEDGE, CFrameWinTraits> CMainWinTraits;

// Main window class
class CMainWindow : public CWindowImpl<CMainWindow, CWindow, CMainWinTraits>
{
public:
BEGIN_MSG_MAP(CMainWindow)
  // Handle main window messages
  MESSAGE_HANDLER(WM_CREATE, OnCreate)    
  MESSAGE_HANDLER(WM_SIZE, OnSize)    

  // Route unhandled messages to the view
  CHAIN_MSG_MAP_ALT_MEMBER(m_view, CView<CMainWindow>::MSG_CHAIN_ID)

  // Pick up messages the view hasn't handled
  COMMAND_ID_HANDLER(ID_HELP_ABOUT, OnHelpAbout)
END_MSG_MAP()

  CMainWindow() : m_doc(this), m_view(&m_doc) {
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

    // Hook up the document to receive messages from the view
    m_view.SetChainEntry(CDocument<CMainWindow>::MSG_CHAIN_ID, &m_doc,
                         CDocument<CMainWindow>::MSG_CHAIN_ID);
  }

private:
  LRESULT OnCreate(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
    return (m_view.Create(m_hWnd, CWindow::rcDefault) ? 0 : -1);
  }

  LRESULT OnSize(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
      RECT rect = { 0, 0, LOWORD(lParam), HIWORD(lParam) };
      return m_view.MoveWindow(&rect);
  }

  LRESULT OnHelpAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    CAboutBox dlg;
    dlg.DoModal();
    return 0;
  }

  virtual void OnFinalMessage(HWND /*hwnd*/)
  { PostQuitMessage(0); }

private:
  CDocument<CMainWindow>  m_doc;
  CView<CMainWindow>      m_view;
};

