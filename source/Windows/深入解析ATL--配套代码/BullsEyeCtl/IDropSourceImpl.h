// IDropSourceImpl.h: interface for the IDropSourceImpl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IDROPSOURCEIMPL_H__6ED143B2_4A64_11D2_BCF0_00A0C9C8E50D__INCLUDED_)
#define AFX_IDROPSOURCEIMPL_H__6ED143B2_4A64_11D2_BCF0_00A0C9C8E50D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>
class ATL_NO_VTABLE IDropSourceImpl : public IDropSource  
{
public:
    IDropSourceImpl()
    {
	    m_bDragStarted = false;
	    m_dwButtonCancel = 0;
	    m_dwButtonDrop = 0;
    }
    virtual ~IDropSourceImpl() {}

	static void WINAPI ObjectMain(bool /* bStarting */)
    {
        // get drag metrics from win.ini
        static const TCHAR szWindows[] = _T("windows");
        static const TCHAR szDragMinDist[] = _T("DragMinDist");
        static const TCHAR szDragDelay[] = _T("DragDelay");

        nDragMinDist = ::GetProfileInt(szWindows, szDragMinDist, DD_DEFDRAGMINDIST);
        nDragDelay = ::GetProfileInt(szWindows, szDragDelay, DD_DEFDRAGDELAY);
    }

    DWORD DoDragDrop(DWORD dwEffects, LPCRECT lpRectStartDrag)
    {
        ATLTRACE2(atlTraceCOM, 0, _T("IDropSourceImpl::DoDragDrop\n"));
        T* pT = static_cast<T*>(this);

        // setup drag/drop sensitivity rect
	    m_bDragStarted = false;

        if (lpRectStartDrag != NULL) {
		    // set drop source drag start rect to parameter provided
		    m_rectStartDrag.CopyRect(lpRectStartDrag);
	    }
	    else {
		    // otherwise start with default empty rectangle around current point
		    CPoint ptCursor;
		    GetCursorPos(&ptCursor);
		    m_rectStartDrag.SetRect(
			    ptCursor.x, ptCursor.y, ptCursor.x, ptCursor.y);
	    }

	    if (m_rectStartDrag.IsRectNull()) {
		    // null rect specifies no OnBeginDrag wait loop
		    m_bDragStarted = true;
	    }
	    else if (m_rectStartDrag.IsRectEmpty()) {
		    // empty rect specifies drag drop around starting point
		    m_rectStartDrag.InflateRect(nDragMinDist, nDragMinDist);
	    }

	    // before calling OLE drag/drop code, wait for mouse to move outside
	    //  the rectangle
	    if (!OnBeginDrag(pT))
		    return DROPEFFECT_NONE;

	    // call global OLE api to do the drag drop
	    CComPtr<IDataObject> spDataObject ;
        HRESULT hr = pT->_InternalQueryInterface (IID_IDataObject, (void**) &spDataObject);
        ATLASSERT (SUCCEEDED (hr));

	    CComPtr<IDropSource> spDropSource ;
        hr = pT->_InternalQueryInterface (IID_IDropSource, (void**) &spDropSource);
        ATLASSERT (SUCCEEDED (hr));

	    DWORD dwResultEffect = DROPEFFECT_NONE;
	    ::DoDragDrop(spDataObject, spDropSource, dwEffects, &dwResultEffect);
	    return dwResultEffect;
    }

// Implementation
public:
// IDropSource
    STDMETHOD(QueryContinueDrag)(BOOL fEscapePressed, DWORD grfKeyState)
    {
        ATLTRACE2(atlTraceCOM, 0, _T("IDropSourceImpl::QueryContinueDrag\n"));
        T* pT = static_cast<T*>(this);

	    // check escape key or right button -- and cancel
	    if (fEscapePressed || (grfKeyState & m_dwButtonCancel) != 0) {
		    m_bDragStarted = false; // avoid unecessary cursor setting
		    return DRAGDROP_S_CANCEL;
	    }

	    // check left/right-button up to end drag/drop and do the drop
	    if ((grfKeyState & m_dwButtonDrop) == 0)
		    return m_bDragStarted ? DRAGDROP_S_DROP : DRAGDROP_S_CANCEL;

	    // otherwise, keep polling...
	    return S_OK;
    }

    STDMETHOD(GiveFeedback)(DWORD)
    {
        ATLTRACE2(atlTraceCOM, 0, _T("IDropSourceImpl::GiveFeedback\n"));
        T* pT = static_cast<T*>(this);
        // don't change the cursor until drag is officially started
        return m_bDragStarted ? DRAGDROP_S_USEDEFAULTCURSORS : S_OK;
    }

    virtual bool OnBeginDrag(CWindow* pWnd)
    {
        ATLTRACE2(atlTraceCOM, 0, _T("IDropSourceImpl::OnBeginDrag\n"));
        T* pT = static_cast<T*>(this);

	    m_bDragStarted = false;

	    // opposite button cancels drag operation
	    m_dwButtonCancel = 0;
	    m_dwButtonDrop = 0;
	    if (GetKeyState(VK_LBUTTON) < 0) {
		    m_dwButtonDrop |= MK_LBUTTON;
		    m_dwButtonCancel |= MK_RBUTTON;
	    }
	    else if (GetKeyState(VK_RBUTTON) < 0) {
		    m_dwButtonDrop |= MK_RBUTTON;
		    m_dwButtonCancel |= MK_LBUTTON;
	    }

	    DWORD dwLastTick = GetTickCount();
        if (pT->m_bWndLess) {
	        HRESULT hr = pT->m_spInPlaceSite->SetCapture(TRUE);
        }
        else
            pWnd->SetCapture();

	    while (!m_bDragStarted) {
		    // some applications steal capture away at random times
            if (pT->m_bWndLess) {
    	        if (S_FALSE == pT->m_spInPlaceSite->GetCapture())
                    break ;
            }
            else
                if (::GetCapture() != pWnd->m_hWnd)
			        break;

		    // peek for next input message
		    MSG msg;
		    if (PeekMessage(&msg, NULL, WM_MOUSEFIRST, WM_MOUSELAST, PM_REMOVE) ||
			    PeekMessage(&msg, NULL, WM_KEYFIRST, WM_KEYLAST, PM_REMOVE)) {
			    // check for button cancellation (any button down will cancel)
			    if (msg.message == WM_LBUTTONUP || msg.message == WM_RBUTTONUP ||
				    msg.message == WM_LBUTTONDOWN || msg.message == WM_RBUTTONDOWN)
				    break;

			    // check for keyboard cancellation
			    if (msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE)
				    break;

			    // check for drag start transition
			    m_bDragStarted = !m_rectStartDrag.PtInRect(msg.pt);
		    }

		    // if the user sits here long enough, we eventually start the drag
		    if (GetTickCount() - dwLastTick > nDragDelay)
			    m_bDragStarted = true;
	    }
        if (pT->m_bWndLess) {
	        HRESULT hr = pT->m_spInPlaceSite->SetCapture(FALSE);
        }
        else
            ReleaseCapture();

	    return m_bDragStarted;
    }

    CRect m_rectStartDrag;  // when mouse leaves this rect, drag drop starts
	bool m_bDragStarted;    // has drag really started yet?
	DWORD m_dwButtonCancel; // which button will cancel (going down)
	DWORD m_dwButtonDrop;   // which button will confirm (going up)

	// metrics for drag start determination
	static UINT nDragMinDist;  // min. amount mouse must move for drag
	static UINT nDragDelay;    // delay before drag starts

};

template <class T> UINT IDropSourceImpl<T>::nDragMinDist;
template <class T> UINT IDropSourceImpl<T>::nDragDelay;


#endif // !defined(AFX_IDROPSOURCEIMPL_H__6ED143B2_4A64_11D2_BCF0_00A0C9C8E50D__INCLUDED_)
