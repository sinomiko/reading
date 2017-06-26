/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.01.75 */
/* at Fri Aug 14 01:49:20 1998
 */
/* Compiler settings for composition.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY

#include "rpcproxy.h"
#include "composition.h"

#define TYPE_FORMAT_STRING_SIZE   1                                 
#define PROC_FORMAT_STRING_SIZE   37                                

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IAcePowell, ver. 0.0,
   GUID={0xADF259F7,0x5967,0x11D1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")
CINTERFACE_PROXY_VTABLE(7) _IAcePowellProxyVtbl = 
{
    0,
    &IID_IAcePowell,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IAcePowell_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IAcePowellStubVtbl =
{
    &IID_IAcePowell,
    0,
    7,
    &IAcePowell_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IArtist, ver. 0.0,
   GUID={0x2CEA24D0,0x5980,0x11d1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IArtist_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IArtist_FormatStringOffsetTable[] = 
    {
    0
    };

static const MIDL_SERVER_INFO IArtist_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IArtist_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IArtist_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IArtist_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(4) _IArtistProxyVtbl = 
{
    &IArtist_ProxyInfo,
    &IID_IArtist,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *)-1 /* IArtist::Draw */
};

const CInterfaceStubVtbl _IArtistStubVtbl =
{
    &IID_IArtist,
    &IArtist_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ICowboy, ver. 0.0,
   GUID={0x2CEA24D1,0x5980,0x11d1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICowboy_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ICowboy_FormatStringOffsetTable[] = 
    {
    0
    };

static const MIDL_SERVER_INFO ICowboy_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ICowboy_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ICowboy_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ICowboy_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(4) _ICowboyProxyVtbl = 
{
    &ICowboy_ProxyInfo,
    &IID_ICowboy,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *)-1 /* ICowboy::Draw */
};

const CInterfaceStubVtbl _ICowboyStubVtbl =
{
    &IID_ICowboy,
    &ICowboy_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ICowboyEx, ver. 0.0,
   GUID={0x6B438A90,0x59EE,0x11d1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICowboyEx_ServerInfo;

#pragma code_seg(".orpc")

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x301004b, /* MIDL Version 3.1.75 */
    0,
    0,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short ICowboyEx_FormatStringOffsetTable[] = 
    {
    0,
    18
    };

static const MIDL_SERVER_INFO ICowboyEx_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ICowboyEx_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ICowboyEx_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ICowboyEx_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(5) _ICowboyExProxyVtbl = 
{
    &ICowboyEx_ProxyInfo,
    &IID_ICowboyEx,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *)-1 /* ICowboy::Draw */ ,
    (void *)-1 /* ICowboyEx::QuickDraw */
};

const CInterfaceStubVtbl _ICowboyExStubVtbl =
{
    &IID_ICowboyEx,
    &ICowboyEx_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

#pragma data_seg(".rdata")

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Draw */


	/* Procedure Draw */

			0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/*  2 */	NdrFcShort( 0x3 ),	/* 3 */
#ifndef _ALPHA_
/*  4 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x4,		/* 4 */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */

/* 12 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 14 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 16 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QuickDraw */

/* 18 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 20 */	NdrFcShort( 0x4 ),	/* 4 */
#ifndef _ALPHA_
/* 22 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x8 ),	/* 8 */
/* 28 */	0x4,		/* 4 */
			0x1,		/* 1 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 32 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {

			0x0
        }
    };

const CInterfaceProxyVtbl * _composition_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ICowboyExProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IArtistProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ICowboyProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAcePowellProxyVtbl,
    0
};

const CInterfaceStubVtbl * _composition_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ICowboyExStubVtbl,
    ( CInterfaceStubVtbl *) &_IArtistStubVtbl,
    ( CInterfaceStubVtbl *) &_ICowboyStubVtbl,
    ( CInterfaceStubVtbl *) &_IAcePowellStubVtbl,
    0
};

PCInterfaceName const _composition_InterfaceNamesList[] = 
{
    "ICowboyEx",
    "IArtist",
    "ICowboy",
    "IAcePowell",
    0
};

const IID *  _composition_BaseIIDList[] = 
{
    0,
    0,
    0,
    &IID_IDispatch,
    0
};


#define _composition_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _composition, pIID, n)

int __stdcall _composition_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _composition, 4, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _composition, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _composition, 4, *pIndex )
    
}

const ExtendedProxyFileInfo composition_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _composition_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _composition_StubVtblList,
    (const PCInterfaceName * ) & _composition_InterfaceNamesList,
    (const IID ** ) & _composition_BaseIIDList,
    & _composition_IID_Lookup, 
    4,
    2
};
