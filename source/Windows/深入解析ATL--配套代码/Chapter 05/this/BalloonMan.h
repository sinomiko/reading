// BalloonMan.h : Declaration of the CBallonMan

#ifndef __BALLOONMAN_H_
#define __BALLOONMAN_H_

#include "resource.h"       // main symbols
#include "Balloon.h"

/////////////////////////////////////////////////////////////////////////////
// CBalloonMan
class ATL_NO_VTABLE CBalloonMan : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBalloonMan, &CLSID_BalloonMan>,
	public IBalloonMan
{
public:
	CBalloonMan()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_BALLOONMAN)
DECLARE_NOT_AGGREGATABLE(CBalloonMan)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CBalloonMan)
	COM_INTERFACE_ENTRY(IBalloonMan)
END_COM_MAP()

// IBalloonMan
public:
	STDMETHOD(CreateBalloon)(long rgbColor, IBalloon** ppBalloon);
};

#endif //__BALLOONMAN_H_
