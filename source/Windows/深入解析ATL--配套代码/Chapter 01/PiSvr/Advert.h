// Advert.h : Declaration of the CAdvert

#ifndef __ADVERT_H_
#define __ADVERT_H_

#include "resource.h"       // main symbols
#include <atlhost.h>

/////////////////////////////////////////////////////////////////////////////
// CAdvert
class CAdvert : 
public CAxDialogImpl<CAdvert>
{
public:
  CAdvert()
  {
  }
  
  ~CAdvert()
  {
  }
  
  enum { IDD = IDD_ADVERT };
  
  BEGIN_MSG_MAP(CAdvert)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    COMMAND_ID_HANDLER(IDOK, OnOK)
    COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
    END_MSG_MAP()
    // Handler prototypes:
    //  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    //  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    //  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
    
    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
    if( m_bstrClient.Length() )
    {
      CComBSTR  bstrCaption = OLESTR("CalcPi sponsered by ");
      bstrCaption += m_bstrClient;
      
      USES_CONVERSION;
      SetWindowText(OLE2CT(bstrCaption));
    }
    
    return 1;  // Let the system set the focus
  }
  
  LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    EndDialog(wID);
    return 0;
  }
  
  LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    EndDialog(wID);
    return 0;
  }
  
  CComBSTR  m_bstrClient;
};

#endif //__ADVERT_H_
