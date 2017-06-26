// mainwnd.cpp

#include "stdafx.h"
#include "mainwnd.h"
#include "filedlg.h"
#include "bullseyedlg.h"
#include "dartboarddlg.h"

// CMainWindow

CMainWindow::CMainWindow()
:   m_bDirty(false)
{
  // Initialize window info
  CWndClassInfo&  wci = GetWndClassInfo();
  if( !wci.m_atom )
  {
    wci.m_wc.hIcon = LoadIcon(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_CONTAINER));
    wci.m_wc.hIconSm = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDI_CONTAINER), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
    wci.m_wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wci.m_bSystemCursor = TRUE;
    wci.m_lpszCursorID = IDC_ARROW;
  }
}

void CMainWindow::UpdateTitle()
{
  tstring sTitle;
  SHFILEINFO  fi = { 0 };
  LPCTSTR     pszPathName = (m_sFileName.size() ? m_sFileName.c_str() : "Untitled.cfl");
  ATLASSERT(pszPathName && *pszPathName);
  
  if( SHGetFileInfo(pszPathName, 0, &fi, sizeof(fi), SHGFI_DISPLAYNAME) )
  {
    sTitle = fi.szDisplayName;
    sTitle += " - ";
  }
  
  sTitle += "Container";
  SetWindowText(sTitle.c_str());
}

bool CMainWindow::New()
{
  if( !Close() ) return false;
  
  // Reset document bits
  m_sFileName = "";
  m_bDirty = false;
  UpdateTitle();
  
  return true;
}

bool CMainWindow::InsertControl(REFCLSID clsid)
{
  ATLASSERT(!m_ax);
  USES_CONVERSION;
  
  RECT    rect; GetClientRect(&rect);
  OLECHAR szClsid[40]; StringFromGUID2(clsid, szClsid, lengthof(szClsid));
  
  // Create the control's host window
  if( !m_ax.Create(m_hWnd, rect, 0, WS_CHILD | WS_VISIBLE, 0, ID_CHILD_CONTROL) ||
    
    // Create the control, setting up the IPropertyNotifySink connection point
    FAILED(m_ax.CreateControlEx(szClsid, 0, 0, 0,
                                IID_IPropertyNotifySink,
                                this)) )
  {
    MessageBox(__T("Unable to create control"), __T("Error"));
    return false;
  }
  
  // Set up _IBullsEyeEvents connection point (if available)
  if( clsid == CLSID_BullsEye ) AtlAdviseSinkMap(this, true);

  // Set initial BullsEye properties  
  CComPtr<IBullsEye>  spBullsEye;
  HRESULT hr = m_ax.QueryControl(&spBullsEye);
  if( SUCCEEDED(hr) ) {
    spBullsEye->put_Beep(VARIANT_TRUE);
    spBullsEye->put_CenterColor(RGB(0, 0, 255));
  }

  // Set up ambient background
  CComPtr<IAxWinAmbientDispatch> spAmbient;
  hr = m_ax.QueryHost(&spAmbient);
  if( SUCCEEDED(hr) ) {
    spAmbient->put_BackColor(RGB(0, 255, 0));
  }
  
  // Reset document bits
  m_bDirty = true;
  return true;
}

bool CMainWindow::Save(bool bSaveAs)
{
  USES_CONVERSION;
  
  // Make sure we have a file name
  tstring sFileName = (bSaveAs ? __T("") : m_sFileName);
  if( !sFileName.size() )
  {
    LPCTSTR pszInitialFile = (m_sFileName.size() ? m_sFileName.c_str() : "Untitled.cfl");
    CFileSaveDialog dlg(__T("Container Files\0*.cfl\0\0"), pszInitialFile, __T("cfl"));
    if( dlg.DoModal() == IDOK )
    {
      sFileName = dlg.lpstrFile;
      ATLASSERT(sFileName.size());
    }
    else return false;
  }
  
  // Make sure object can be saved
  CComQIPtr<IPersistStream> spPersistStream;
  HRESULT hr = m_ax.QueryControl(&spPersistStream);
  if( FAILED(hr) )
  {
    hr = m_ax.QueryControl(IID_IPersistStreamInit, (void**)&spPersistStream);
    if( FAILED(hr) )
    {
      MessageBox(__T("Object can't be saved"), __T("Error"));
      return false;
    }
  }
  
  // Save object to stream in a storage
  CComPtr<IStorage>   spStorage;
  hr = StgCreateDocfile(T2COLE(sFileName.c_str()),
                        STGM_DIRECT | STGM_WRITE | STGM_SHARE_EXCLUSIVE | STGM_CREATE,
                        0, &spStorage);
  if( SUCCEEDED(hr) )
  {
    CComPtr<IStream>    spStream;
    hr = spStorage->CreateStream(OLESTR("Contents"),
                                 STGM_DIRECT | STGM_WRITE | STGM_SHARE_EXCLUSIVE | STGM_CREATE,
                                 0, 0, &spStream);
    if( SUCCEEDED(hr) )
    {
      // Get and store the CLSID
      CLSID clsid;
      hr = spPersistStream->GetClassID(&clsid);
      if( SUCCEEDED(hr) )
      {
        hr = spStream->Write(&clsid, sizeof(clsid), 0);
        
        // Save the object
        hr = spPersistStream->Save(spStream, TRUE);
      }
    }
  }
  
  if( FAILED(hr) )
  {
    MessageBox(__T("Unable to save file"), __T("Error"));
    return false;
  }
  
  // Reset document bits
  m_sFileName = sFileName;
  m_bDirty = false;
  UpdateTitle();
  
  return true;
}

bool CMainWindow::Open()
{
  USES_CONVERSION;
  
  // Get a file name
  tstring sFileName;
  CFileOpenDialog dlg(__T("Container Files\0*.cfl\0\0"));
  if( dlg.DoModal() == IDOK )
  {
    sFileName = dlg.lpstrFile;
    ATLASSERT(sFileName.size());
  }
  else return false;
  
  // Close the one we've got
  if( !Close() ) return false;
  
  // Open object a stream in the storage
  CComPtr<IStorage>   spStorage;
  CComPtr<IStream>    spStream;
  HRESULT             hr;
  hr = StgOpenStorage(T2COLE(sFileName.c_str()), 0,
                      STGM_DIRECT | STGM_READ | STGM_SHARE_EXCLUSIVE,
                      0, 0, &spStorage);
  if( SUCCEEDED(hr) )
  {
    hr = spStorage->OpenStream(OLESTR("Contents"), 0,
                               STGM_DIRECT | STGM_READ | STGM_SHARE_EXCLUSIVE,
                               0, &spStream);
  }
  
  if( FAILED(hr) )
  {
    MessageBox(__T("Unable to open file"), __T("Error"));
    return false;
  }
  
  // Read a CLSID from the stream
  CLSID   clsid;
  hr = spStream->Read(&clsid, sizeof(clsid), 0);
  if( FAILED(hr) )
  {
    MessageBox(__T("Invalid file format"), __T("Error"));
    return false;
  }
  
  RECT    rect; GetClientRect(&rect);
  OLECHAR szClsid[40]; StringFromGUID2(clsid, szClsid, lengthof(szClsid));
  
  // Create the control's host window
  if( !m_ax.Create(m_hWnd, rect, 0, WS_CHILD | WS_VISIBLE, 0, ID_CHILD_CONTROL) ||
    
    // Create the control, persisting from the stream
    // and setting up the IPropertyNotifySink connection point
    //FAILED(m_ax.CreateControl(szClsid, spStream)) )
    FAILED(m_ax.CreateControlEx(szClsid, spStream, 0, 0,
                                IID_IPropertyNotifySink,
                                this)) )
  {
    MessageBox(__T("Unable to create control"), __T("Error"));
    return false;
  }
  
  // Set up _IBullsEyeEvents connection point (if available)
  if( clsid == CLSID_BullsEye ) AtlAdviseSinkMap(this, true);
  
  // Reset document bits
  m_sFileName = sFileName;
  m_bDirty = false;
  UpdateTitle();
  
  return true;
}

bool CMainWindow::Close()
{
  if( !m_ax ) return true;
  
  bool bCanClose = !m_bDirty;
  if( m_bDirty )
  {
    switch( MessageBox(__T("Save changes?"), __T("Container"), MB_YESNOCANCEL) )
    {
    case IDYES:
      bCanClose = Save(false);
    break;
      
    case IDNO:
      bCanClose = true;
    break;
      
    case IDCANCEL:
      bCanClose = false;
    break;
    }
  }
  
  if( bCanClose )
  {
    // Disconnect sink map
    AtlAdviseSinkMap(this, false);
    
    // Also disconnects IPropertyNotifySink connection point
    m_ax.DestroyWindow();
    return true;
  }
  
  return false;
}

// WM_XXX handlers

BOOL CMainWindow::PreTranslateAccelerator(MSG* pMsg)
{
  // Accelerators are only keyboard or mouse messages
  if ((pMsg->message < WM_KEYFIRST || pMsg->message > WM_KEYLAST) &&
    (pMsg->message < WM_MOUSEFIRST || pMsg->message > WM_MOUSELAST))
    return FALSE;
  
  // Find a direct child of this window from the window that has focus.
  // This will be AxHost window for the hosted control.
  HWND hWndCtl = ::GetFocus();
  if( IsChild(hWndCtl) && ::GetParent(hWndCtl) != m_hWnd )
  {
    do hWndCtl = ::GetParent(hWndCtl);
    while( ::GetParent(hWndCtl) != m_hWnd );
  }
  
  // Give the control (via the AxHost) a chance to translate this message
  if (::SendMessage(hWndCtl, WM_FORWARDMSG, 0, (LPARAM)pMsg) ) return TRUE;
  
  // Check for dialog-type navigation accelerators
  return IsDialogMessage(pMsg);
}

LRESULT CMainWindow::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& lResult)
{
  if( !New() ) return -1;
  return 0;
}

LRESULT CMainWindow::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& lResult)
{
  if( m_ax )
  {
    RECT rect = { 0, 0, LOWORD(lParam), HIWORD(lParam) };
    m_ax.MoveWindow(&rect);
  }
  
  return 0;
}

LRESULT CMainWindow::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& lResult)
{
  if( Close() ) lResult = false;
  return 0;
}

void CMainWindow::OnFinalMessage(HWND)
{
  PostQuitMessage(0);
}

// WM_COMMAND handlers

HRESULT ShowProperties(IUnknown* punkControl, HWND hwndParent) {
  HRESULT hr = E_FAIL;

  // Ask the control to specify its property pages
  CComQIPtr<ISpecifyPropertyPages> spPages = punkControl;
  if (spPages) {

    CAUUID  pages;
    hr = spPages->GetPages(&pages);
    if( SUCCEEDED(hr) ) {
      // Add your custom property pages here

      // Show the property pages
      CComQIPtr<IOleObject> spObj = punkControl;
      if( spObj ) {
        LPOLESTR pszTitle = 0;
        spObj->GetUserType(USERCLASSTYPE_SHORT, &pszTitle);
        
        hr = OleCreatePropertyFrame(hwndParent, 10, 10, pszTitle,
                                    1, &punkControl, pages.cElems,
                                    pages.pElems, LOCALE_USER_DEFAULT, 0, 0);
        
        CoTaskMemFree(pszTitle);
      }
      CoTaskMemFree(pages.pElems);
    }
  }
  
  return hr;
}

LRESULT CMainWindow::OnEditProperties(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  CComPtr<IUnknown> spunk;
  if( SUCCEEDED(m_ax.QueryControl(&spunk)) )
  {
    /*
  CComPtr<IOleObject> spoo;
  if( SUCCEEDED(m_ax.QueryControl(&spoo)) )
  {
    CComPtr<IOleClientSite> spcs; m_ax.QueryHost(&spcs);
    RECT    rect; m_ax.GetClientRect(&rect);
    
    if( FAILED(spoo->DoVerb(OLEIVERB_PROPERTIES, 0, spcs, -1, m_ax.m_hWnd, &rect)) )
    {
      MessageBox(__T("Properties unavailable"), __T("Error"));
    }
    */
    if( FAILED(ShowProperties(spunk, m_hWnd)) )
    {
      MessageBox(__T("Properties unavailable"), __T("Error"));
    }
  }
  
  return 0;
}

LRESULT CMainWindow::OnFileNew(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  New();
  return 0;
}

LRESULT CMainWindow::OnFileOpen(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  Open();
  return 0;
}

LRESULT CMainWindow::OnFileSave(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  Save(false);
  return 0;
}

LRESULT CMainWindow::OnFileSaveAs(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  Save(true);
  return 0;
}

LRESULT CMainWindow::OnFileExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  if( Close() ) DestroyWindow();
  return 0;
}

LRESULT CMainWindow::OnEditInsertControl(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  // Make sure we haven't already got one
  if( m_ax )
  {
    MessageBox(__T("Control already inserted"), __T("Error"));
    return false;
  }
  
  // Show built-in OLE UI
  OLEUIINSERTOBJECT	io = { sizeof(io) };
  TCHAR				szFile[_MAX_PATH] = "";
  
  io.lpszFile = szFile;
  io.cchFile  = lengthof(szFile);
  io.dwFlags  = IOF_DISABLELINK |
                IOF_DISABLEDISPLAYASICON |
                IOF_SHOWINSERTCONTROL |
                IOF_SELECTCREATECONTROL;
  
  if( OleUIInsertObject(&io) == OLEUI_OK )
  {
    if( io.dwFlags & IOF_SELECTCREATECONTROL )
      InsertControl(io.clsid);
    else
      MessageBox(__T("This application only supports inserting controls."));
  }
  
  return 0;
}

LRESULT CMainWindow::OnEditShowBullsEye(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  CBullsEyeDlg dlg;
  dlg.DoModal();
  return 0;
}

LRESULT CMainWindow::OnEditShowDartBoard(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  CDartBoardDlg dlg;
  dlg.DoModal();
  return 0;
}

LRESULT CMainWindow::OnHelpAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
  CSimpleDialog<IDD_ABOUTBOX> dlg;
  dlg.DoModal();
  return 0;
}

// Sink handlers
void __stdcall CMainWindow::OnRingHit(short nRingNumber)
{
  TCHAR   sz[32];
  wsprintf(sz, __T("You hit ring %d!"), nRingNumber);
  MessageBox(sz, __T("Good shot!"));
}

// IPropertyNotifySink
STDMETHODIMP CMainWindow::QueryInterface(REFIID riid, void** ppv)
{
  if( riid == IID_IUnknown || riid == IID_IPropertyNotifySink )
    *ppv = static_cast<IPropertyNotifySink*>(this);
  else
    *ppv = 0;
  
  if( *ppv )
  {
    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return S_OK;
  }
  
  return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CMainWindow::AddRef()
{
  return 2;
}

STDMETHODIMP_(ULONG) CMainWindow::Release()
{
  return 1;
}

STDMETHODIMP CMainWindow::OnChanged(DISPID dispID)
{
  m_bDirty = true;
  return S_OK;
}

STDMETHODIMP CMainWindow::OnRequestEdit(DISPID dispID)
{
  return S_OK;
}

