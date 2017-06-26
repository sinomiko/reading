// doc.h

#pragma once

///////////////////////////////////////////////////////////////////
// A document class: Stores string and handles file operations

template <typename MainWindow>
class CDocument : public CMessageMap {
public:
BEGIN_MSG_MAP(CMainWindow)

// Handle messages from the view and the main frame
ALT_MSG_MAP(MSG_CHAIN_ID)
  COMMAND_ID_HANDLER(ID_FILE_EXIT, OnFileExit)
END_MSG_MAP()

  CDocument(MainWindow* pwnd) : m_pwnd(pwnd) { *m_sz = 0; }

  void    SetString(LPCTSTR psz) { strcpy(m_sz, psz); }
  LPCTSTR GetString()            { return m_sz; }

  // Message chaining ID so view can route messages to the document
  enum { MSG_CHAIN_ID = 1340 };

// Message handlers
private:
  LRESULT OnFileExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    m_pwnd->DestroyWindow();
    return 0;
  }

private:
  MainWindow* m_pwnd;
  TCHAR       m_sz[64];
};
