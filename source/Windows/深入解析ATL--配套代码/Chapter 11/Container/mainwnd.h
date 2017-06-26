// MainWnd.h: Defines main window for application

#pragma once
#ifndef MAINWND_H
#define MAINWND_H

#include "axwin2.h"
#include "resource.h"
#import "..\..\BULLSEYECTL\BullsEyeCtl.tlb" raw_interfaces_only raw_native_types no_namespace named_guids

typedef CWinTraitsOR<0, WS_EX_CLIENTEDGE, CFrameWinTraits>
        CMainWindowTraits;

#define ID_CHILD_CONTROL 1

class CMainWindow :
  public CWindowImpl<CMainWindow, CWindow, CMainWindowTraits>,
  public IPropertyNotifySink,
  public IDispEventImpl<ID_CHILD_CONTROL,
                        CMainWindow,
                        &DIID__IBullsEyeEvents,
                        &LIBID_BullsEyeLib, 1, 0>
{
public:
  CMainWindow();

BEGIN_MSG_MAP(CMainWindow)
  MESSAGE_HANDLER(WM_CREATE, OnCreate)
  MESSAGE_HANDLER(WM_SIZE, OnSize)
  MESSAGE_HANDLER(WM_CLOSE, OnClose)
  COMMAND_ID_HANDLER(ID_FILE_NEW, OnFileNew)
  COMMAND_ID_HANDLER(ID_FILE_OPEN, OnFileOpen)
  COMMAND_ID_HANDLER(ID_FILE_SAVE, OnFileSave)
  COMMAND_ID_HANDLER(ID_FILE_SAVE_AS, OnFileSaveAs)
  COMMAND_ID_HANDLER(ID_FILE_EXIT, OnFileExit)
  COMMAND_ID_HANDLER(ID_EDIT_INSERTCONTROL, OnEditInsertControl)
  COMMAND_ID_HANDLER(ID_EDIT_PROPERTIES, OnEditProperties)
  COMMAND_ID_HANDLER(ID_EDIT_SHOWBULLSEYE, OnEditShowBullsEye)
  COMMAND_ID_HANDLER(ID_EDIT_SHOW_DARTBOARD, OnEditShowDartBoard)
  COMMAND_ID_HANDLER(ID_HELP_ABOUT, OnHelpAbout)
END_MSG_MAP()

BEGIN_SINK_MAP(CMainWindow)
  SINK_ENTRY_EX(ID_CHILD_CONTROL, DIID__IBullsEyeEvents, 1, OnRingHit)
END_SINK_MAP()

  // Required to forward messages to the control
  BOOL PreTranslateAccelerator(MSG* pMsg);

public:
  // IPropertyNotifySink
  STDMETHODIMP QueryInterface(REFIID riid, void** ppv);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();
  STDMETHODIMP OnChanged(DISPID dispID);
  STDMETHODIMP OnRequestEdit(DISPID dispID);

private:
  // WM_XXX handlers
  LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& lResult);
  LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& lResult);
  LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& lResult);
  void OnFinalMessage(HWND);

  // WM_COMMAND handlers
  LRESULT OnFileNew(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnFileOpen(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnFileSave(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnFileSaveAs(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnFileExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnEditInsertControl(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnEditProperties(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnEditShowBullsEye(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnEditShowDartBoard(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnHelpAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

  // Sink handlers
  void __stdcall OnRingHit(short nRingNumber);

  // Persistance helpers
  bool New();
  bool Save(bool bSaveAs);
  bool Open();
  bool Close();
  void UpdateTitle();

  bool InsertControl(REFCLSID clsid);

private:
  CAxWindow2  m_ax;
  bool        m_bDirty;
  tstring     m_sFileName;
};

#endif  // MAINWND_H
