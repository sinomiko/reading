
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 5.03.0280 */
/* at Tue Apr 11 17:40:43 2000
 */
/* Compiler settings for C:\ATL Internals\BullsEyeCtl\BullsEyeCtl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AXP64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IBullsEye,0x7DC59CC4,0x36C0,0x11D2,0xAC,0x05,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);


MIDL_DEFINE_GUID(IID, LIBID_BullsEyeLib,0xC8B7D8C8,0x8D62,0x11D2,0xBD,0x9C,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);


MIDL_DEFINE_GUID(IID, DIID__IBullsEyeEvents,0x19FF9872,0x36ED,0x11d2,0xAC,0x05,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);


MIDL_DEFINE_GUID(CLSID, CLSID_BullsEye,0x7DC59CC5,0x36C0,0x11D2,0xAC,0x05,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);


MIDL_DEFINE_GUID(CLSID, CLSID_BullsEyePropPage,0x7DC59CC8,0x36C0,0x11D2,0xAC,0x05,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AXP64)*/


#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 5.03.0280 */
/* at Tue Apr 11 17:40:43 2000
 */
/* Compiler settings for C:\ATL Internals\BullsEyeCtl\BullsEyeCtl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win64 (32b run,appending), ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AXP64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IBullsEye,0x7DC59CC4,0x36C0,0x11D2,0xAC,0x05,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);


MIDL_DEFINE_GUID(IID, LIBID_BullsEyeLib,0xC8B7D8C8,0x8D62,0x11D2,0xBD,0x9C,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);


MIDL_DEFINE_GUID(IID, DIID__IBullsEyeEvents,0x19FF9872,0x36ED,0x11d2,0xAC,0x05,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);


MIDL_DEFINE_GUID(CLSID, CLSID_BullsEye,0x7DC59CC5,0x36C0,0x11D2,0xAC,0x05,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);


MIDL_DEFINE_GUID(CLSID, CLSID_BullsEyePropPage,0x7DC59CC8,0x36C0,0x11D2,0xAC,0x05,0x00,0xA0,0xC9,0xC8,0xE5,0x0D);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AXP64)*/

