#include "stdafx.h"
#include "BugFixes.h"

HRESULT __stdcall FixedAtlIPersistPropertyBag_Load(LPPROPERTYBAG pPropBag, LPERRORLOG pErrorLog, ATL_PROPMAP_ENTRY* pMap, void* pThis, IUnknown* pUnk)
{
	USES_CONVERSION;
	CComPtr<IDispatch> pDispatch;
	const IID* piidOld = NULL;
	for (int i = 0; pMap[i].pclsidPropPage != NULL; i++)
	{
		if (pMap[i].szDesc == NULL)
			continue;

		CComVariant var ;
		// If raw entry skip it - we don't handle it for property bags just yet
		if (pMap[i].dwSizeData != 0) {
			void* pData = (void*) (pMap[i].dwOffsetData + (DWORD)pThis);

            var.vt = pMap[i].vt;    // BUG FIX line added

			HRESULT hr = pPropBag->Read(pMap[i].szDesc, &var, pErrorLog);
			if (SUCCEEDED(hr)) {
				// check the type - we only deal with limited set
				switch (pMap[i].vt)
				{
				case VT_UI1:
				case VT_I1:
					*((BYTE*)pData) = var.bVal;
					break;
				case VT_BOOL:
					*((VARIANT_BOOL*)pData) = var.boolVal;
					break;
				case VT_I2:         // BUG FIX line added
				case VT_UI2:
					*((short*)pData) = var.iVal;
					break;
				case VT_I4:         // BUG FIX line added
				case VT_UI4:
				case VT_INT:
				case VT_UINT:
					*((long*)pData) = var.lVal;
					break;
				}
			}
			continue;
		}

		if (pMap[i].piidDispatch != piidOld)
		{
			pDispatch.Release();
			if (FAILED(pUnk->QueryInterface(*pMap[i].piidDispatch, (void**)&pDispatch)))
			{
				ATLTRACE2(atlTraceCOM, 0, _T("Failed to get a dispatch pointer for property #%i\n"), i);
				return E_FAIL;
			}
			piidOld = pMap[i].piidDispatch;
		}

		if (FAILED(CComDispatchDriver::GetProperty(pDispatch, pMap[i].dispid, &var)))
		{
			ATLTRACE2(atlTraceCOM, 0, _T("Invoked failed on DISPID %x\n"), pMap[i].dispid);
			return E_FAIL;
		}

		HRESULT hr = pPropBag->Read(pMap[i].szDesc, &var, pErrorLog);
		if (FAILED(hr))
		{
			if (hr == E_INVALIDARG)
			{
				ATLTRACE2(atlTraceCOM, 0, _T("Property %s not in Bag\n"), OLE2CT(pMap[i].szDesc));
			}
			else
			{
				// Many containers return different ERROR values for Member not found
				ATLTRACE2(atlTraceCOM, 0, _T("Error attempting to read Property %s from PropertyBag \n"), OLE2CT(pMap[i].szDesc));
			}
			continue;
		}

		if (FAILED(CComDispatchDriver::PutProperty(pDispatch, pMap[i].dispid, &var)))
		{
			ATLTRACE2(atlTraceCOM, 0, _T("Invoked failed on DISPID %x\n"), pMap[i].dispid);
			return E_FAIL;
		}
	}
	return S_OK;
}
