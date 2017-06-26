// aboutbox.h

#pragma once

/*
class CAboutBox : public CDialogImpl<CAboutBox> {
public:
BEGIN_MSG_MAP(CAboutBox)
  MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
  COMMAND_ID_HANDLER(IDOK, OnOK);
END_MSG_MAP()

  enum { IDD = IDD_ABOUTBOX };

private:
  LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&) {
    CenterWindow();
    return 1;
  }

  LRESULT OnOK(WORD, UINT, HWND, BOOL&) {
    EndDialog(IDOK);
    return 0;
  }
};
*/

typedef CSimpleDialog<IDD_ABOUTBOX> CAboutBox;
