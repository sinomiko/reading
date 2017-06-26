// IDropTargetImpl.h: interface for the IDropTargetImpl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IDROPTARGETIMPL_H__6ED143B1_4A64_11D2_BCF0_00A0C9C8E50D__INCLUDED_)
#define AFX_IDROPTARGETIMPL_H__6ED143B1_4A64_11D2_BCF0_00A0C9C8E50D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>
class ATL_NO_VTABLE  IDropTargetImpl : public IDropTarget  
{
public:
	IDropTargetImpl();
	virtual ~IDropTargetImpl();

// Operations
	BOOL Register(CWnd* pWnd);
	virtual void Revoke();  // virtual for implementation

// Overridables
	virtual DROPEFFECT OnDragEnter(CWnd* pWnd, COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual DROPEFFECT OnDragOver(CWnd* pWnd, COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual BOOL OnDrop(CWnd* pWnd, COleDataObject* pDataObject,
		DROPEFFECT dropEffect, CPoint point);
	virtual DROPEFFECT OnDropEx(CWnd* pWnd, COleDataObject* pDataObject,
		DROPEFFECT dropDefault, DROPEFFECT dropList, CPoint point);
	virtual void OnDragLeave(CWnd* pWnd);
	virtual DROPEFFECT OnDragScroll(CWnd* pWnd, DWORD dwKeyState,
		CPoint point);

// Implementation
public:

protected:
	HWND m_hWnd;            // HWND this IDropTarget is attached to
    CComPtr<IDataObject>    m_spDataObject;    // != NULL between OnDragEnter, OnDragLeave
	UINT m_nTimerID;        // != MAKEWORD(-1, -1) when in scroll area
	DWORD m_dwLastTick;     // only valid when m_nTimerID valid
	UINT m_nScrollDelay;    // time to next scroll

	// metrics for drag-scrolling
	static AFX_DATA int nScrollInset;
	static AFX_DATA UINT nScrollDelay;
	static AFX_DATA UINT nScrollInterval;

	// implementation helpers
	void SetupTimer(CView* pView, UINT nTimerID);
	void CancelTimer(CWnd* pWnd);

// Interface Maps
public:
    STDMETHOD(DragEnter)(LPDATAOBJECT, DWORD, POINTL, LPDWORD);
    STDMETHOD(DragOver)(DWORD, POINTL, LPDWORD);
    STDMETHOD(DragLeave)();
    STDMETHOD(Drop)(LPDATAOBJECT, DWORD, POINTL pt, LPDWORD);
};

#endif // !defined(AFX_IDROPTARGETIMPL_H__6ED143B1_4A64_11D2_BCF0_00A0C9C8E50D__INCLUDED_)
