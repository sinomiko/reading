// ATLInternals.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f ATLInternalsps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "ATLInternals.h"

#include "ATLInternals_i.c"
#include "SoapBox.h"
#include "Demagogue.h"
#include "EarPolitic.h"


CComModule _Module;

#define OBJECT_ENTRY_NON_CREATEABLE_EX(clsid, class) {&clsid, class::UpdateRegistry, NULL, NULL, NULL, 0, NULL, class::GetCategoryMap, class::ObjectMain },

BEGIN_OBJECT_MAP(ObjectMap)
//OBJECT_ENTRY_NON_CREATEABLE(CSoapBox)
OBJECT_ENTRY_NON_CREATEABLE_EX(CLSID_SoapBox, CSoapBox)
OBJECT_ENTRY(CLSID_Demagogue, CDemagogue)
OBJECT_ENTRY(CLSID_EarPolitic, CEarPolitic)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_ATLINTERNALSLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers the server
    HRESULT hr = _Module.UpdateRegistryFromResource(IDR_ATLInternals, TRUE);
    if (FAILED (hr)) return hr ;

    // registers objects in object map, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    // unregisters the server
    HRESULT hr = _Module.UpdateRegistryFromResource(IDR_ATLInternals, FALSE);
    if (FAILED (hr)) return hr ;

    // unregisters objects in object map, typelib and all interfaces in typelib
    return _Module.UnregisterServer(TRUE);
}


