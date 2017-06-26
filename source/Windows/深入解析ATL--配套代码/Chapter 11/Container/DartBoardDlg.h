// DartBoardDlg.h

#pragma once
#ifndef __DARTBOARDDLG_H__
#define __DARTBOARDDLG_H__

class CDartBoardDlg : public CAxDialogImpl<CDartBoardDlg>
{
public:
BEGIN_MSG_MAP(CDartBoardDlg)
  COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
END_MSG_MAP()

  enum { IDD = IDD_DARTBOARD };

private:
  LRESULT OnCancel(WORD, UINT, HWND, BOOL&)
  { EndDialog(IDCANCEL); return 0; }
};

#endif  // __DARTBOARDDLG_H__
