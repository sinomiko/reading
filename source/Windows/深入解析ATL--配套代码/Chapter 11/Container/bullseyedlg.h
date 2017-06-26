// bullseyedlg.h

#pragma once
#ifndef __BULLSEYEDLG_H__
#define __BULLSEYEDLG_H__

#include "resource.h"
#import "..\..\BULLSEYECTL\BullsEyeCtl.tlb" raw_interfaces_only raw_native_types no_namespace named_guids

class CBullsEyeDlg :
  public CAxDialogImpl<CBullsEyeDlg>,
  public IDispEventImpl<IDC_BULLSEYE, CBullsEyeDlg>
{
public:
BEGIN_MSG_MAP(CBullsEyeDlg)
  MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
  MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
  COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
  COMMAND_HANDLER(ID_FEWER_RINGS, BN_CLICKED, OnClickedFewerRings)
  COMMAND_HANDLER(ID_MORE_RINGS, BN_CLICKED, OnClickedMoreRings)
END_MSG_MAP()

BEGIN_SINK_MAP(CBullsEyeDlg)
  SINK_ENTRY(IDC_BULLSEYE, 0x2, OnScoreChanged)
END_SINK_MAP()
    
  enum { IDD = IDD_BULLSEYE };
  
  LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    // Attach to the BullsEye control
    //m_axBullsEye.Attach(GetDlgItem(IDC_BULLSEYE));

    // Cache BullsEye interface
    //m_axBullsEye.QueryControl(&m_spBullsEye);
    GetDlgControl(IDC_BULLSEYE, IID_IBullsEye, (void**)&m_spBullsEye);

    AtlAdviseSinkMap(this, true);
    SetDlgItemInt(IDC_SCORE, 0);
    return 0;
  }
  
  LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
    AtlAdviseSinkMap(this, false);
    return 0;
  }
  
  LRESULT OnClickedFewerRings(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    ATLASSERT(m_spBullsEye);

    short nRings;
    m_spBullsEye->get_RingCount(&nRings);
    m_spBullsEye->put_RingCount(nRings - 1);

		return 0;
	}

  LRESULT OnClickedMoreRings(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
    ATLASSERT(m_spBullsEye);

    short nRings;
    m_spBullsEye->get_RingCount(&nRings);
    m_spBullsEye->put_RingCount(nRings + 1);

		return 0;
	}

  LRESULT OnCancel(WORD, UINT, HWND, BOOL&)
  {
    EndDialog(IDCANCEL);
    return 0;
  }
  
  VOID __stdcall OnScoreChanged(LONG ringValue)
  {
    SetDlgItemInt(IDC_SCORE, GetDlgItemInt(IDC_SCORE) + ringValue);
  }

private:
  //CAxWindow2          m_axBullsEye;
  CComPtr<IBullsEye>  m_spBullsEye;
};

#endif  // __BULLSEYEDLG_H__
