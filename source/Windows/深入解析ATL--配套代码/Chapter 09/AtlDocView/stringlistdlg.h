// stringlistdlg.h

#pragma once
#include "resource.h"

class CStringListDlg : public CDialogImpl<CStringListDlg> {
public:
  CStringListDlg() { *m_sz = 0; }

BEGIN_MSG_MAP(CStringListDlg)
  MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
  COMMAND_ID_HANDLER(IDOK, OnOK)
  COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
END_MSG_MAP()

  enum { IDD = IDD_CHOOSE_STRING };
  TCHAR m_sz[64];

private:
  LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&) {
    CenterWindow();

    // Cache listbox HWND
    m_lb.Attach(GetDlgItem(IDC_LIST));

    // Populate the listbox
    m_lb.AddString(__T("Hello, ATL"));
    m_lb.AddString(__T("Ain't ATL Cool?"));
    m_lb.AddString(__T("ATL is your friend"));

    // Set initial selection
    int n = m_lb.FindString(0, m_sz);
    if( n == LB_ERR ) n = 0;
    m_lb.SetCurSel(n);

    return 1; // Let dialog manager set initial focus
  }

  LRESULT OnOK(WORD, UINT, HWND, BOOL&) {
    // Copy the selected item
    int n = m_lb.GetCurSel();
    if( n == LB_ERR ) n = 0;
    m_lb.GetText(n, m_sz);

    EndDialog(IDOK);
    return 0;
  }

  LRESULT OnCancel(WORD, UINT, HWND, BOOL&) {
    EndDialog(IDCANCEL);
    return 0;
  }

private:
  ATLControls::CListBox  m_lb;
};
