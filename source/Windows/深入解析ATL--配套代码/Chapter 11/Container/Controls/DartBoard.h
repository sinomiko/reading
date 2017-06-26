// DartBoard.h : Declaration of the CDartBoard

#ifndef __DARTBOARD_H_
#define __DARTBOARD_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "ControlsCP.h"
#import "..\..\..\BULLSEYECTL\BullsEyeCtl.tlb" raw_interfaces_only raw_native_types no_namespace named_guids

/////////////////////////////////////////////////////////////////////////////
// CDartBoard
class ATL_NO_VTABLE CDartBoard : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IDartBoard, &IID_IDartBoard, &LIBID_CONTROLSLib>,
	public CComCompositeControl<CDartBoard>,
	public IPersistStreamInitImpl<CDartBoard>,
	public IOleControlImpl<CDartBoard>,
	public IOleObjectImpl<CDartBoard>,
	public IOleInPlaceActiveObjectImpl<CDartBoard>,
	public IViewObjectExImpl<CDartBoard>,
	public IOleInPlaceObjectWindowlessImpl<CDartBoard>,
	public IPersistStorageImpl<CDartBoard>,
	public ISpecifyPropertyPagesImpl<CDartBoard>,
	public IQuickActivateImpl<CDartBoard>,
	public IDataObjectImpl<CDartBoard>,
	public IProvideClassInfo2Impl<&CLSID_DartBoard, NULL, &LIBID_CONTROLSLib>,
	public CComCoClass<CDartBoard, &CLSID_DartBoard>,
	public CProxy_IDartBoardEvents< CDartBoard >,
	public IConnectionPointContainerImpl<CDartBoard>,
	public IDispEventImpl<IDC_BULLSEYE, CDartBoard>
{
public:
  CDartBoard() : m_nScore(0)
  {
    m_bWindowOnly = TRUE;
    CalcExtent(m_sizeExtent);
  }

DECLARE_REGISTRY_RESOURCEID(IDR_DARTBOARD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDartBoard)
	COM_INTERFACE_ENTRY(IDartBoard)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROP_MAP(CDartBoard)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CDartBoard)
  MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
  COMMAND_ID_HANDLER(IDC_RESET, OnReset)
	CHAIN_MSG_MAP(CComCompositeControl<CDartBoard>)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

  LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
  {
    SetDlgItemInt(IDC_SCORE, m_nScore);
    return 0;
  }

  LRESULT OnReset(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
  {
    put_Score(0);
    return 0;
  }

BEGIN_SINK_MAP(CDartBoard)
	//Make sure the Event Handlers have __stdcall calling convention
	SINK_ENTRY(IDC_BULLSEYE, 0x2, OnScoreChangedBullseye)
END_SINK_MAP()

BEGIN_CONNECTION_POINT_MAP(CDartBoard)
	CONNECTION_POINT_ENTRY(DIID__IDartBoardEvents)
END_CONNECTION_POINT_MAP()

	STDMETHOD(OnAmbientPropertyChange)(DISPID dispid)
	{
		if (dispid == DISPID_AMBIENT_BACKCOLOR)
		{
			SetBackgroundColorFromAmbient();
			FireViewChange();
		}
		return IOleControlImpl<CDartBoard>::OnAmbientPropertyChange(dispid);
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(0)

  // Draw at design-time
  virtual HRESULT OnDraw(ATL_DRAWINFO& di)
  {
    if( m_bInPlaceActive ) return S_OK;
    
    // Draw background rectangle
    SelectObject(di.hdcDraw, GetStockObject(BLACK_PEN));
    SelectObject(di.hdcDraw, GetStockObject(GRAY_BRUSH));
    Rectangle(di.hdcDraw, di.prcBounds->left, di.prcBounds->top,
              di.prcBounds->right, di.prcBounds->bottom);
    
    // Draw proposed dialog rectangle
    SIZE  sizeMetric; CalcExtent(sizeMetric);
    SIZE  sizeDialog; AtlHiMetricToPixel(&sizeMetric, &sizeDialog);
    SIZE  sizeBounds = { di.prcBounds->right - di.prcBounds->left,
                         di.prcBounds->bottom - di.prcBounds->top };
    SIZE  sizeDialogBounds = { min(sizeDialog.cx, sizeBounds.cx),
                               min(sizeDialog.cy, sizeBounds.cy) };
    RECT  rectDialogBounds = { di.prcBounds->left, di.prcBounds->top,
                               di.prcBounds->left + sizeDialogBounds.cx,
                               di.prcBounds->top + sizeDialogBounds.cy };
    SelectObject(di.hdcDraw, GetStockObject(LTGRAY_BRUSH));
    Rectangle(di.hdcDraw, rectDialogBounds.left, rectDialogBounds.top,
              rectDialogBounds.right, rectDialogBounds.bottom);
    
    // Report natural and current size of dialog resource
    SetTextColor(di.hdcDraw, ::GetSysColor(COLOR_WINDOWTEXT));
    SetBkMode(di.hdcDraw, TRANSPARENT);
    
    TCHAR sz[256];
    wsprintf(sz, __T("Recommended: %d x %d\r\nCurrent: %d x %d"),
             sizeDialog.cx, sizeDialog.cy, sizeBounds.cx, sizeBounds.cy);
    
    DrawText(di.hdcDraw, sz, -1, &rectDialogBounds, DT_CENTER);
    
    return S_OK;
  }

// IDartBoard
public:
	STDMETHODIMP get_Score(long *pVal);
	STDMETHODIMP put_Score(long newVal);
	STDMETHODIMP ResetScore();

	enum { IDD = IDD_DARTBOARD };

private:
  long  m_nScore;

  VOID __stdcall OnScoreChangedBullseye(LONG ringValue)
  {
      put_Score(m_nScore + ringValue);
  }
};

#endif //__DARTBOARD_H_
