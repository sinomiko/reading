// view.h

#pragma once
#include "stringdlg.h"
#include "stringlistdlg.h"

///////////////////////////////////////////////////////////////////
// A view class

template <typename MainWindow>
class CView : public CWindowImpl<CView>, public CDynamicChain {
public:
  CView(CDocument<MainWindow>* pdoc) : m_pdoc(pdoc) {
    // Set the document-managed string
    m_pdoc->SetString(__T("ATL Doc/View"));
  }

BEGIN_MSG_MAP(CView)
  // Handle view messages
  MESSAGE_HANDLER(WM_PAINT, OnPaint)

// Handle messages from the main window
ALT_MSG_MAP(MSG_CHAIN_ID)
  COMMAND_ID_HANDLER(ID_EDIT_STRING, OnEditString)
  COMMAND_ID_HANDLER(ID_CHOOSE_STRING, OnChooseString)

  // Any messages we don't want, route to the document
  CHAIN_MSG_MAP_DYNAMIC(CDocument<MainWindow>::MSG_CHAIN_ID)
END_MSG_MAP()

  // Message chaining ID so main window can route messages to the view
  enum { MSG_CHAIN_ID = 1340 };

private:
  LRESULT OnPaint(UINT, WPARAM, LPARAM, BOOL&) {
    PAINTSTRUCT ps;
    HDC         hdc = BeginPaint(&ps);
    RECT        rect; GetClientRect(&rect);

    // Draw the document-managed string
    DrawText(hdc, m_pdoc->GetString(), -1, &rect,
             DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    EndPaint(&ps);
    return 0;
  }

  LRESULT OnEditString(WORD, UINT, HWND, BOOL&)
  {
    CStringDlg  dlg;
    strcpy(dlg.m_sz, m_pdoc->GetString());

    if( dlg.DoModal(m_hWnd) == IDOK ) {
      m_pdoc->SetString(dlg.m_sz);
      Invalidate();
    }

    return 0;
  }

  LRESULT OnChooseString(WORD, UINT, HWND, BOOL&)
  {
    CStringListDlg  dlg;
    strcpy(dlg.m_sz, m_pdoc->GetString());

    if( dlg.DoModal(m_hWnd) == IDOK ) {
      m_pdoc->SetString(dlg.m_sz);
      Invalidate();
    }

    return 0;
  }

private:
  CDocument<MainWindow>*  m_pdoc;
};

