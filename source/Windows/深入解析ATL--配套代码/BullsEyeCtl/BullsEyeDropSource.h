// BullsEyeDropSource.h: Definition of the CBullsEyeDropSource class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BULLSEYEDROPSOURCE_H__6ED143B5_4A64_11D2_BCF0_00A0C9C8E50D__INCLUDED_)
#define AFX_BULLSEYEDROPSOURCE_H__6ED143B5_4A64_11D2_BCF0_00A0C9C8E50D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

#include "IDropSourceImpl.h"

/////////////////////////////////////////////////////////////////////////////
// CBullsEyeDropSource

class CBullsEyeDropSource : 
	public IDropSourceImpl<CBullsEyeDropSource>,
	public CComObjectRootEx<CComSingleThreadModel>
{
public:
	CBullsEyeDropSource() {}
BEGIN_COM_MAP(CBullsEyeDropSource)
	COM_INTERFACE_ENTRY(IDropSource)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(CBullsEyeDropSource) 

DECLARE_NO_REGISTRY()

BEGIN_CATEGORY_MAP(CBullsEyeDropSource)
END_CATEGORY_MAP()

	static void WINAPI ObjectMain(bool bStarting)
    {
        IDropSourceImpl<CBullsEyeDropSource>::ObjectMain(bStarting);
    }

// IBullsEyeDropSource
public:
};

#endif // !defined(AFX_BULLSEYEDROPSOURCE_H__6ED143B5_4A64_11D2_BCF0_00A0C9C8E50D__INCLUDED_)
