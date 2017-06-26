/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Sep 12 18:43:41 1998
 */
/* Compiler settings for D:\ATLInternals\CategorizeProperties.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "CategorizeProperties.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 

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


/* Standard interface: __MIDL_itf_CategorizeProperties_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICategorizeProperties, ver. 0.0,
   GUID={0x4D07FC10,0xF931,0x11CE,{0xB0,0x01,0x00,0xAA,0x00,0x68,0x84,0xE5}} */

#pragma data_seg(".rdata")

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

const CInterfaceProxyVtbl * _CategorizeProperties_ProxyVtblList[] = 
{
    0
};

const CInterfaceStubVtbl * _CategorizeProperties_StubVtblList[] = 
{
    0
};

PCInterfaceName const _CategorizeProperties_InterfaceNamesList[] = 
{
    0
};


#define _CategorizeProperties_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _CategorizeProperties, pIID, n)

int __stdcall _CategorizeProperties_IID_Lookup( const IID * pIID, int * pIndex )
{
    return 0;
}

const ExtendedProxyFileInfo CategorizeProperties_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _CategorizeProperties_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _CategorizeProperties_StubVtblList,
    (const PCInterfaceName * ) & _CategorizeProperties_InterfaceNamesList,
    0, // no delegation
    & _CategorizeProperties_IID_Lookup, 
    0,
    1,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
