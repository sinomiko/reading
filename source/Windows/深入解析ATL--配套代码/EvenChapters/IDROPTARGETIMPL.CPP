// IDropTargetImpl.cpp: implementation of the IDropTargetImpl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IDropTargetImpl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFX_DATADEF int IDropTargetImpl::nScrollInset;
AFX_DATADEF UINT IDropTargetImpl::nScrollDelay;
AFX_DATADEF UINT IDropTargetImpl::nScrollInterval;

IDropTargetImpl::IDropTargetImpl()
{
	// initialize local state
	m_hWnd          = NULL;
	m_spDataObject  = NULL;
	m_nTimerID      = MAKEWORD(-1, -1);

	AfxLockGlobals(CRIT_DROPTARGET);
	static BOOL bInitialized;
	if (!bInitialized) {
		// get scroll metrics from win.ini
		static const TCHAR szWindows[] = _T("windows");
		static const TCHAR szScrollDelay[] = _T("DragScrollDelay");
		static const TCHAR szScrollInset[] = _T("DragScrollInset");
		static const TCHAR szScrollInterval[] = _T("DragScrollInterval");

		nScrollInset = GetProfileInt(szWindows, szScrollInset, DD_DEFSCROLLINSET);
		nScrollDelay = GetProfileInt(szWindows, szScrollDelay, DD_DEFSCROLLDELAY);
		nScrollInterval = GetProfileInt(szWindows, szScrollInterval, DD_DEFSCROLLINTERVAL);

		// now initialized, no need to call Initialize any more
		bInitialized = TRUE;
	}
	AfxUnlockGlobals(CRIT_DROPTARGET);
}

IDropTargetImpl::~IDropTargetImpl()
{
	if (m_hWnd != NULL) {
		TRACE0("IDropTargetImpl::Revoke not called before destructor --\n");
		TRACE0("\tmay cause RIPs under debug Windows.\n");
		Revoke();
	}
}

BOOL IDropTargetImpl::Register(CWnd* pWnd)
{
	ATLASSERT(m_hWnd == NULL);     // registering drop target twice?

	LPUNKNOWN lpUnknown = (LPUNKNOWN)GetInterface(&IID_IUnknown);
	ATLASSERT(lpUnknown != NULL);

	// the object must be locked externally to keep LRPC connections alive
	if (CoLockObjectExternal(lpUnknown, TRUE, FALSE) != S_OK)
		return FALSE;

	// connect the HWND to the IDropTargetImpl implementation
	if (RegisterDragDrop(pWnd->m_hWnd,
		(LPDROPTARGET)GetInterface(&IID_IDropTargetImpl)) != S_OK)
	{
		CoLockObjectExternal(lpUnknown, FALSE, FALSE);
		return FALSE;
	}

	// connect internal data
	m_hWnd = pWnd->m_hWnd;
	ATLASSERT(pWnd->m_pDropTarget == NULL);
	pWnd->m_pDropTarget = this;

	return TRUE;
}

void IDropTargetImpl::Revoke()
{
	ATLASSERT_VALID(this);
	ATLASSERT(m_lpDataObject == NULL);

	if (m_hWnd == NULL)
	{
		ATLASSERT(m_nTimerID == MAKEWORD(-1, -1));
		return;
	}

	// disconnect from OLE
	RevokeDragDrop(m_hWnd);
	CoLockObjectExternal((LPUNKNOWN)GetInterface(&IID_IUnknown), FALSE, TRUE);

	// disconnect internal data
	CWnd::FromHandle(m_hWnd)->m_pDropTarget = NULL;
	m_hWnd = NULL;
}

/////////////////////////////////////////////////////////////////////////////
// default implementation of drag/drop scrolling

DROPEFFECT IDropTargetImpl::OnDragScroll(CWnd* pWnd, DWORD dwKeyState,
	CPoint point)
{
	ATLASSERT_VALID(pWnd);

	// CWnds are allowed, but don't support autoscrolling
	if (!pWnd->IsKindOf(RUNTIME_CLASS(CView)))
		return DROPEFFECT_NONE;
	CView* pView = (CView*)pWnd;
	DROPEFFECT dropEffect = pView->OnDragScroll(dwKeyState, point);

	// DROPEFFECT_SCROLL means do the default
	if (dropEffect != DROPEFFECT_SCROLL)
		return dropEffect;

	// get client rectangle of destination window
	CRect rectClient;
	pWnd->GetClientRect(&rectClient);
	CRect rect = rectClient;

	// hit-test against inset region
	UINT nTimerID = MAKEWORD(-1, -1);
	rect.InflateRect(-nScrollInset, -nScrollInset);
	CSplitterWnd* pSplitter = NULL;
	if (rectClient.PtInRect(point) && !rect.PtInRect(point))
	{
		// determine which way to scroll along both X & Y axis
		if (point.x < rect.left)
			nTimerID = MAKEWORD(SB_LINEUP, HIBYTE(nTimerID));
		else if (point.x >= rect.right)
			nTimerID = MAKEWORD(SB_LINEDOWN, HIBYTE(nTimerID));
		if (point.y < rect.top)
			nTimerID = MAKEWORD(LOBYTE(nTimerID), SB_LINEUP);
		else if (point.y >= rect.bottom)
			nTimerID = MAKEWORD(LOBYTE(nTimerID), SB_LINEDOWN);
		ATLASSERT(nTimerID != MAKEWORD(-1, -1));

		// check for valid scroll first
		pSplitter = CView::GetParentSplitter(pView, FALSE);
		BOOL bEnableScroll = FALSE;
		if (pSplitter != NULL)
			bEnableScroll = pSplitter->DoScroll(pView, nTimerID, FALSE);
		else
			bEnableScroll = pView->OnScroll(nTimerID, 0, FALSE);
		if (!bEnableScroll)
			nTimerID = MAKEWORD(-1, -1);
	}

	if (nTimerID == MAKEWORD(-1, -1))
	{
		if (m_nTimerID != MAKEWORD(-1, -1))
		{
			// send fake OnDragEnter when transition from scroll->normal
			COleDataObject dataObject;
			dataObject.Attach(m_lpDataObject, FALSE);
			OnDragEnter(pWnd, &dataObject, dwKeyState, point);
			m_nTimerID = MAKEWORD(-1, -1);
		}
		return DROPEFFECT_NONE;
	}

	// save tick count when timer ID changes
	DWORD dwTick = GetTickCount();
	if (nTimerID != m_nTimerID)
	{
		m_dwLastTick = dwTick;
		m_nScrollDelay = nScrollDelay;
	}

	// scroll if necessary
	if (dwTick - m_dwLastTick > m_nScrollDelay)
	{
		if (pSplitter != NULL)
			pSplitter->DoScroll(pView, nTimerID, TRUE);
		else
			pView->OnScroll(nTimerID, 0, TRUE);
		m_dwLastTick = dwTick;
		m_nScrollDelay = nScrollInterval;
	}
	if (m_nTimerID == MAKEWORD(-1, -1))
	{
		// send fake OnDragLeave when transitioning from normal->scroll
		OnDragLeave(pWnd);
	}

	m_nTimerID = nTimerID;
	// check for force link
	if ((dwKeyState & (MK_CONTROL|MK_SHIFT)) == (MK_CONTROL|MK_SHIFT))
		dropEffect = DROPEFFECT_SCROLL|DROPEFFECT_LINK;
	// check for force copy
	else if ((dwKeyState & MK_CONTROL) == MK_CONTROL)
		dropEffect = DROPEFFECT_SCROLL|DROPEFFECT_COPY;
	// check for force move
	else if ((dwKeyState & MK_ALT) == MK_ALT ||
		(dwKeyState & MK_SHIFT) == MK_SHIFT)
		dropEffect = DROPEFFECT_SCROLL|DROPEFFECT_MOVE;
	// default -- recommended action is move
	else
		dropEffect = DROPEFFECT_SCROLL|DROPEFFECT_MOVE;
	return dropEffect;
}

/////////////////////////////////////////////////////////////////////////////
// IDropTargetImpl::IDropTargetImpl implementation

// helper to filter out invalid DROPEFFECTs
AFX_STATIC DROPEFFECT AFXAPI
_AfxFilterDropEffect(DROPEFFECT dropEffect, DROPEFFECT dwEffects)
{
	// return allowed dropEffect and DROPEFFECT_NONE
	if ((dropEffect & dwEffects) != 0)
		return dropEffect;

	// map common operations (copy/move) to alternates, but give negative
	//  feedback for DROPEFFECT_LINK.
	switch (dropEffect)
	{
	case DROPEFFECT_COPY:
		if (dwEffects & DROPEFFECT_MOVE)
			return DROPEFFECT_MOVE;
		else if (dwEffects & DROPEFFECT_LINK)
			return DROPEFFECT_LINK;
		break;
	case DROPEFFECT_MOVE:
		if (dwEffects & DROPEFFECT_COPY)
			return DROPEFFECT_COPY;
		else if (dwEffects & DROPEFFECT_LINK)
			return DROPEFFECT_LINK;
		break;
	case DROPEFFECT_LINK:
		break;
	}

	return DROPEFFECT_NONE;
}

STDMETHODIMP IDropTargetImpl::DragEnter(LPDATAOBJECT lpDataObject, DWORD dwKeyState, POINTL pt, LPDWORD pdwEffect)
{
	ATLASSERT(pdwEffect != NULL);
	ATLASSERT(lpDataObject != NULL);

	SCODE sc = E_UNEXPECTED;
	TRY
	{
		// cache lpDataObject
		lpDataObject->AddRef();
		RELEASE(pThis->m_lpDataObject);
		pThis->m_lpDataObject = lpDataObject;

		CWnd* pWnd = CWnd::FromHandle(pThis->m_hWnd);
		ATLASSERT_VALID(pWnd);
		CPoint point((int)pt.x, (int)pt.y);
		pWnd->ScreenToClient(&point);

		// check first for entering scroll area
		DROPEFFECT dropEffect = pThis->OnDragScroll(pWnd, dwKeyState, point);
		if ((dropEffect & DROPEFFECT_SCROLL) == 0)
		{
			// funnel through OnDragEnter since not in scroll region
			COleDataObject dataObject;
			dataObject.Attach(lpDataObject, FALSE);
			dropEffect = pThis->OnDragEnter(pWnd, &dataObject, dwKeyState,
				point);
		}
		*pdwEffect = _AfxFilterDropEffect(dropEffect, *pdwEffect);
		sc = S_OK;
	}
	END_TRY

	return sc;
}

STDMETHODIMP IDropTargetImpl::DragOver(DWORD dwKeyState, POINTL pt, LPDWORD pdwEffect)
{
	ATLASSERT(pdwEffect != NULL);
	ATLASSERT(pThis->m_lpDataObject != NULL);

	SCODE sc = E_UNEXPECTED;
	TRY
	{
		CWnd* pWnd = CWnd::FromHandle(pThis->m_hWnd);
		ATLASSERT_VALID(pWnd);
		CPoint point((int)pt.x, (int)pt.y);
		pWnd->ScreenToClient(&point);

		// check first for entering scroll area
		DROPEFFECT dropEffect = pThis->OnDragScroll(pWnd, dwKeyState, point);
		if ((dropEffect & DROPEFFECT_SCROLL) == 0)
		{
			// funnel through OnDragOver
			COleDataObject dataObject;
			dataObject.Attach(pThis->m_lpDataObject, FALSE);
			dropEffect = pThis->OnDragOver(pWnd, &dataObject, dwKeyState,
				point);
		}
		*pdwEffect = _AfxFilterDropEffect(dropEffect, *pdwEffect);
		sc = S_OK;
	}
	END_TRY

	return sc;
}

STDMETHODIMP IDropTargetImplDragLeave()
{
	CWnd* pWnd = CWnd::FromHandle(pThis->m_hWnd);
	ATLASSERT_VALID(pWnd);

	// cancel drag scrolling
	pThis->m_nTimerID = MAKEWORD(-1, -1);

	// allow derivative to do own cleanup
	COleDataObject dataObject;
	dataObject.Attach(pThis->m_lpDataObject, FALSE);
	pThis->OnDragLeave(pWnd);

	// release cached data object
	RELEASE(pThis->m_lpDataObject);

	return S_OK;
}

STDMETHODIMP IDropTargetImpl::Drop(THIS_ LPDATAOBJECT lpDataObject, DWORD dwKeyState, POINTL pt, LPDWORD pdwEffect)
{
	ATLASSERT(pdwEffect != NULL);
	ATLASSERT(lpDataObject != NULL);

	SCODE sc = E_UNEXPECTED;
	TRY
	{
		// cancel drag scrolling
		pThis->m_nTimerID = MAKEWORD(-1, -1);

		// prepare for call to OnDragOver
		CWnd* pWnd = CWnd::FromHandle(pThis->m_hWnd);
		ATLASSERT_VALID(pWnd);
		COleDataObject dataObject;
		dataObject.Attach(lpDataObject, FALSE);
		CPoint point((int)pt.x, (int)pt.y);
		pWnd->ScreenToClient(&point);

		// verify that drop is legal
		DROPEFFECT dropEffect = _AfxFilterDropEffect(pThis->OnDragOver(pWnd,
			&dataObject, dwKeyState, point), *pdwEffect);

		// execute the drop (try OnDropEx then OnDrop for backward compatibility)
		DROPEFFECT temp = pThis->OnDropEx(pWnd, &dataObject, dropEffect, *pdwEffect, point);
		if (temp != -1) {
			// OnDropEx was implemented, return its drop effect
			dropEffect = temp;
		}
		else if (dropEffect != DROPEFFECT_NONE) {
			// OnDropEx not implemented
			if (!pThis->OnDrop(pWnd, &dataObject, dropEffect, point))
				dropEffect = DROPEFFECT_NONE;
		}
		else
		{
			// drop not accepted, allow cleanup
			pThis->OnDragLeave(pWnd);
		}

		// release potentially cached data object
		RELEASE(pThis->m_lpDataObject);
		*pdwEffect = dropEffect;
		sc = S_OK;
	}
	END_TRY

	return sc;
}

/////////////////////////////////////////////////////////////////////////////
// IDropTargetImpl diagnostics

#ifdef _DEBUG
void IDropTargetImpl::AssertValid() const
{
	CCmdTarget::AssertValid();
	if (m_lpDataObject != NULL)
		CWnd::FromHandle(m_hWnd)->AssertValid();
}

void IDropTargetImpl::Dump(CDumpContext& dc) const
{
	CCmdTarget::Dump(dc);

	dc << "m_hWnd = " << m_hWnd;
	dc << "\nm_lpDataObject = " << m_lpDataObject;
	dc << "\nm_nTimerID = " << m_nTimerID;
	dc << "\nm_dwLastTick = " << m_dwLastTick;

	dc << "\n";
}
#endif

/////////////////////////////////////////////////////////////////////////////
