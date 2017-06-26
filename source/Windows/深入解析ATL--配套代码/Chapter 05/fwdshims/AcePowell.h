// AcePowell.h : Declaration of the CAcePowell

#ifndef __ACEPOWELL_H_
#define __ACEPOWELL_H_

#include "resource.h"       // main symbols

template <typename Deriving>
struct ATL_NO_VTABLE _IArtist : public IArtist {
  STDMETHODIMP Draw() { return static_cast<Deriving*>(this)->ArtistDraw(); }
};

template <typename Deriving>
struct ATL_NO_VTABLE _ICowboy : public ICowboy {
  STDMETHODIMP Draw() { return static_cast<Deriving*>(this)->CowboyDraw(); }
};

/////////////////////////////////////////////////////////////////////////////
// CAcePowell
class ATL_NO_VTABLE CAcePowell : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAcePowell, &CLSID_AcePowell>,
	public _IArtist<CAcePowell>,
    public _ICowboy<CAcePowell>
{
public:
DECLARE_REGISTRY_RESOURCEID(IDR_ACEPOWELL)
DECLARE_NOT_AGGREGATABLE(CAcePowell)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CAcePowell)
	COM_INTERFACE_ENTRY(IArtist)
	COM_INTERFACE_ENTRY(ICowboy)
END_COM_MAP()

// IAcePowell
public:
    HRESULT ArtistDraw() { MessageBox(0, "Say Cheese", "IArtist::Draw", MB_SETFOREGROUND); return S_OK; }
    HRESULT CowboyDraw() { MessageBox(0, "Ye-ha!", "ICowboy::Draw", MB_SETFOREGROUND); return S_OK; }
};

#endif //__ACEPOWELL_H_
