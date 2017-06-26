// LettersDlg.h

#pragma once

class CLettersDlg : public CDialogImpl<CLettersDlg> {
public:
  // Set the CMessageMap* and the message map id
  CLettersDlg() : m_edit(this, 1) {}

BEGIN_MSG_MAP(CLettersDlg)
  MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
  COMMAND_ID_HANDLER(IDOK, OnCommand)
  COMMAND_ID_HANDLER(IDCANCEL, OnCommand)
ALT_MSG_MAP(1)
  MESSAGE_HANDLER(WM_CHAR, OnEditChar)
END_MSG_MAP()

  enum { IDD = IDD_LETTERS_ONLY };

  LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&) {
    // Subclass the existing child edit control
    m_edit.SubclassWindow(GetDlgItem(IDC_EDIT));

    return 1; // Let the dialog manager set the initial focus
  }

  LRESULT OnEditChar(UINT, WPARAM wparam, LPARAM, BOOL& bHandled) {
    if( isalpha((TCHAR)wparam) ) bHandled = FALSE;
    else                         MessageBeep(0xFFFFFFFF);
    return 0;
  }

  LRESULT OnCommand(WORD, UINT nID, HWND, BOOL&) {
    EndDialog(nID);
    return 0;
  }

private:
  CContainedWindowT<ATLControls::CEdit> m_edit;
};