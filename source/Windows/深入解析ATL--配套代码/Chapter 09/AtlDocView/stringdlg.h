// stringdlg.h

#pragma once
#include "resource.h"

class CStringDlg : public CDialogImpl<CStringDlg> {
public:
  CStringDlg() { *m_sz = 0; }

BEGIN_MSG_MAP(CStringDlg)
  MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
  COMMAND_ID_HANDLER(IDOK, OnOK)
  COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
  COMMAND_HANDLER(IDC_STRING, EN_CHANGE, OnStringChange)
END_MSG_MAP()

  enum { IDD = IDD_SET_STRING };
  TCHAR m_sz[64];

private:
  void CheckValidString() {
    // Check the length of the string
    int cchString = m_edit.GetWindowTextLength();

    // Enable the OK button only if the string is of non-zero length
    m_ok.EnableWindow(cchString ? TRUE : FALSE);
  }

  LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&) {
    CenterWindow();

    // Cache HWNDs
    m_edit.Attach(GetDlgItem(IDC_STRING));
    m_ok.Attach(GetDlgItem(IDOK));

    // Copy the string from the data member to the child control (DDX)
    m_edit.SetWindowText(m_sz);

    // Check the string length (DDV)
    CheckValidString();

    return 1; // Let dialog manager set initial focus
  }

  LRESULT OnStringChange(WORD, UINT, HWND, BOOL&) {
    // Check the string length each time it changes (DDV)
    CheckValidString();

    return 0;
  }

  LRESULT OnOK(WORD, UINT, HWND, BOOL&) {
    // Copy the string from the child control to the data member (DDX)
    m_edit.GetWindowText(m_sz, lengthof(m_sz));

    EndDialog(IDOK);
    return 0;
  }

  LRESULT OnCancel(WORD, UINT, HWND, BOOL&) {
    EndDialog(IDCANCEL);
    return 0;
  }

private:
  CWindow m_edit;
  CWindow m_ok;
};

/*
class CStringDlg : public CDialogImpl<CStringDlg> {
public:
  CStringDlg() { *m_sz = 0; }

BEGIN_MSG_MAP(CStringDlg)
  MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
  COMMAND_ID_HANDLER(IDOK, OnOK)
  COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
END_MSG_MAP()

  enum { IDD = IDD_SET_STRING };
  TCHAR m_sz[64];

private:
  bool CheckValidString() {
    // Check the length of the string
    int cchString = ::GetWindowTextLength(GetDlgItem(IDC_STRING));
    return cchString ? true : false;
  }

  LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&) {
    CenterWindow();

    // Copy the string from the data member to the child control (DDX)
    SetDlgItemText(IDC_STRING, m_sz);

    return 1; // Let dialog manager set initial focus
  }

  LRESULT OnOK(WORD, UINT, HWND, BOOL&) {
    // Complain if the string is of zero length (DDV)
    if( !CheckValidString() ) {
      MessageBox("Please enter a string", "Hey!");
      return 0;
    }

    // Copy the string from the child control to the data member (DDX)
    GetDlgItemText(IDC_STRING, m_sz, lengthof(m_sz));

    EndDialog(IDOK);
    return 0;
  }

  LRESULT OnCancel(WORD, UINT, HWND, BOOL&) {
    EndDialog(IDCANCEL);
    return 0;
  }
};
*/
