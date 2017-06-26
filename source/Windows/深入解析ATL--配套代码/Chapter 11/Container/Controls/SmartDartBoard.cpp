// SmartDartBoard.cpp : Implementation of CSmartDartBoard

#include "stdafx.h"
#include "Controls.h"
#include "SmartDartBoard.h"

/////////////////////////////////////////////////////////////////////////////
// CSmartDartBoard

CSmartDartBoard::CSmartDartBoard()
: m_nScore(0)
{
  m_bWindowOnly = TRUE;
}

HRESULT CSmartDartBoard::SetScoreSpan()
{
  // Convert score to VARIANT
  CComVariant varScore = m_nScore;
  HRESULT hr = varScore.ChangeType(VT_BSTR);
  if( FAILED(hr) ) return hr;

  // Find score span element
  CComPtr<IHTMLElement> speScore;
  hr = GetHtmlElement(OLESTR("spanScore"), &speScore);
  if( FAILED(hr) ) return hr;

  // Set the element's inner text
  return speScore->put_innerText(varScore.bstrVal);
}

HRESULT CSmartDartBoard::GetHtmlElement(
  LPCOLESTR       pszElementID,
  IHTMLElement**  ppElement)
{
  ATLASSERT(ppElement);
  *ppElement = 0;

  // Get the document from the browser
  HRESULT hr = E_FAIL;
  CComPtr<IDispatch> spdispDoc;
  hr = m_spBrowser->get_Document(&spdispDoc);
  if( FAILED(hr) ) return hr;

  CComQIPtr<IHTMLDocument2> spDoc = spdispDoc;
  if( !spDoc ) return E_NOINTERFACE;

  // Get the All collection from the document
  CComPtr<IHTMLElementCollection> spAll;
  hr = spDoc->get_all(&spAll);
  if( FAILED(hr) ) return hr;

  // Get the element from the All collection
  CComVariant         varID = pszElementID;
  CComPtr<IDispatch>  spdispItem;
  hr = spAll->item(varID, CComVariant(0), &spdispItem);

  // Return the IHTMLElement interface
  return spdispItem->QueryInterface(ppElement);
}

// Message handlers
LRESULT CSmartDartBoard::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
  // Crashes under IE5b2
  //DispEventUnadvise(m_spBrowser);
  return 0;
}

// Sink event handlers
void __stdcall CSmartDartBoard::OnDocumentComplete(IDispatch*, VARIANT*)
{
  // Set the spanScore object's inner HTML
  SetScoreSpan();

  // Retrieve the Reset button
  HRESULT hr;
  CComPtr<IHTMLElement> speReset;
  hr = GetHtmlElement(OLESTR("cmdReset"), &speReset);
  if( FAILED(hr) ) return;

  // Set up the connection point w/ the button
  ButtonEvents::DispEventAdvise(speReset);
}

VARIANT_BOOL __stdcall CSmartDartBoard::OnClickReset()
{
  ResetScore();
  return VARIANT_TRUE;
}

// ISmartDartBoard
STDMETHODIMP CSmartDartBoard::get_Score(/*[out, retval]*/ long *pVal)
{
  *pVal = m_nScore;
  return S_OK;
}

STDMETHODIMP CSmartDartBoard::put_Score(/*[in]*/ long newVal)
{
  m_nScore = newVal;
  FireOnChanged(1);

  // Update the <spanScore> inner text
  if( m_spBrowser ) return SetScoreSpan();

  return S_OK;
}

STDMETHODIMP CSmartDartBoard::ResetScore()
{
  return put_Score(0);
}

// ISmartDartBoardUI
STDMETHODIMP CSmartDartBoard::AddToScore(long ringValue)
{
  return put_Score(m_nScore + ringValue);
}

LRESULT CSmartDartBoard::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
  // Wrap the control's window to use it to host control
  // (not an AtlAxWin, so no CAxHostWindow yet created)
  //CAxWindow wnd(m_hWnd);
  CAxWindow2 wnd(m_hWnd);
  
  // Create a CAxWinHost: It will subclass this window and
  // create a control based on an HTML resource.
  HRESULT hr = wnd.CreateControl(IDH_SMARTDARTBOARD);
  
  // Cache the IWebBrowser2 interface
  if (SUCCEEDED(hr))
    hr = wnd.QueryControl(IID_IWebBrowser2, (void**)&m_spBrowser);
  
  // Set up connection point w/ the browser
  if( SUCCEEDED(hr) )
    hr = BrowserEvents::DispEventAdvise(m_spBrowser);
  
  // Optional: Set the window.external interface
  if (SUCCEEDED(hr))
    hr = wnd.SetExternalDispatch(static_cast<ISmartDartBoardUI*>(this));

  // Optional: Set up the external UI handler
  //if( SUCCEEDED(hr) )
  //  hr = wnd.SetExternalUIHandler(this);

  // Turn off the context menu
  CComPtr<IAxWinAmbientDispatch> spAmbient;
  hr = wnd.QueryHost(&spAmbient);
  if( SUCCEEDED(hr) )
    spAmbient->put_AllowContextMenu(VARIANT_FALSE);
  
  return SUCCEEDED(hr) ? 0 : -1;
}

// ISmartDartBoard
STDMETHODIMP CSmartDartBoard::ShowContextMenu(
  DWORD dwID, 
  DWORD x, 
  DWORD y, 
  IUnknown* pcmdtReserved,  
  IDispatch* pdispReserved,
  HRESULT* dwRetVal)
{
  // Turn off IE4 context menu
  *dwRetVal = S_OK;
  return S_OK;
}

STDMETHODIMP CSmartDartBoard::GetHostInfo(
  DWORD* pdwFlags,
  DWORD* pdwDoubleClick)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::ShowUI(
  DWORD dwID,
  IUnknown* pActiveObject,
  IUnknown* pCommandTarget,
  IUnknown* pFrame,
  IUnknown* pDoc,
  HRESULT* dwRetVal)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::HideUI()
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::UpdateUI()
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::EnableModeless(
  VARIANT_BOOL fEnable)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::OnDocWindowActivate(
  VARIANT_BOOL fActivate)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::OnFrameWindowActivate(
  VARIANT_BOOL fActivate)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::ResizeBorder(
  long left,
  long top,
  long right,
  long bottom,
  IUnknown * pUIWindow,
  VARIANT_BOOL fFrameWindow)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::TranslateAccelerator(
  DWORD hWnd,
  DWORD nMessage,
  DWORD wParam,
  DWORD lParam,
  BSTR bstrGuidCmdGroup, 
  DWORD nCmdID,
  HRESULT* dwRetVal)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::GetOptionKeyPath(
  BSTR* pbstrKey,
  DWORD dw)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::GetDropTarget(
  IUnknown* pDropTarget, 
  IUnknown** ppDropTarget)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::GetExternal(
  IDispatch **ppDispatch)
{
  (*ppDispatch = static_cast<ISmartDartBoardUI*>(this))->AddRef();
  return S_OK;
}

STDMETHODIMP CSmartDartBoard::TranslateUrl(
  DWORD dwTranslate,
  BSTR bstrURLIn,
  BSTR* pbstrURLOut)
{
  return E_NOTIMPL;
}

STDMETHODIMP CSmartDartBoard::FilterDataObject(
  IUnknown *pDO,
  IUnknown **ppDORet)
{
  return E_NOTIMPL;
}

