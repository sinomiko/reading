/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Nov 22 21:26:27 1998
 */
/* Compiler settings for D:\ATLBook\src\Chapter 05\this\this.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __this_h__
#define __this_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IBalloonMan_FWD_DEFINED__
#define __IBalloonMan_FWD_DEFINED__
typedef interface IBalloonMan IBalloonMan;
#endif 	/* __IBalloonMan_FWD_DEFINED__ */


#ifndef __IBalloon_FWD_DEFINED__
#define __IBalloon_FWD_DEFINED__
typedef interface IBalloon IBalloon;
#endif 	/* __IBalloon_FWD_DEFINED__ */


#ifndef __ISmartProxy_FWD_DEFINED__
#define __ISmartProxy_FWD_DEFINED__
typedef interface ISmartProxy ISmartProxy;
#endif 	/* __ISmartProxy_FWD_DEFINED__ */


#ifndef __IBalloon_FWD_DEFINED__
#define __IBalloon_FWD_DEFINED__
typedef interface IBalloon IBalloon;
#endif 	/* __IBalloon_FWD_DEFINED__ */


#ifndef __BalloonMan_FWD_DEFINED__
#define __BalloonMan_FWD_DEFINED__

#ifdef __cplusplus
typedef class BalloonMan BalloonMan;
#else
typedef struct BalloonMan BalloonMan;
#endif /* __cplusplus */

#endif 	/* __BalloonMan_FWD_DEFINED__ */


#ifndef __SmartProxy_FWD_DEFINED__
#define __SmartProxy_FWD_DEFINED__

#ifdef __cplusplus
typedef class SmartProxy SmartProxy;
#else
typedef struct SmartProxy SmartProxy;
#endif /* __cplusplus */

#endif 	/* __SmartProxy_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_this_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_this_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_this_0000_v0_0_s_ifspec;

#ifndef __IBalloonMan_INTERFACE_DEFINED__
#define __IBalloonMan_INTERFACE_DEFINED__

/* interface IBalloonMan */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBalloonMan;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB693B56-80E2-11D2-987D-00600823CFFB")
    IBalloonMan : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateBalloon( 
            long rgbColor,
            IBalloon __RPC_FAR *__RPC_FAR *ppBalloon) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBalloonManVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBalloonMan __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBalloonMan __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBalloonMan __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateBalloon )( 
            IBalloonMan __RPC_FAR * This,
            long rgbColor,
            IBalloon __RPC_FAR *__RPC_FAR *ppBalloon);
        
        END_INTERFACE
    } IBalloonManVtbl;

    interface IBalloonMan
    {
        CONST_VTBL struct IBalloonManVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBalloonMan_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBalloonMan_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBalloonMan_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBalloonMan_CreateBalloon(This,rgbColor,ppBalloon)	\
    (This)->lpVtbl -> CreateBalloon(This,rgbColor,ppBalloon)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IBalloonMan_CreateBalloon_Proxy( 
    IBalloonMan __RPC_FAR * This,
    long rgbColor,
    IBalloon __RPC_FAR *__RPC_FAR *ppBalloon);


void __RPC_STUB IBalloonMan_CreateBalloon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBalloonMan_INTERFACE_DEFINED__ */


#ifndef __IBalloon_INTERFACE_DEFINED__
#define __IBalloon_INTERFACE_DEFINED__

/* interface IBalloon */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBalloon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB693B58-80E2-11D2-987D-00600823CFFB")
    IBalloon : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Color( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBalloonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBalloon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBalloon __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBalloon __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Color )( 
            IBalloon __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        END_INTERFACE
    } IBalloonVtbl;

    interface IBalloon
    {
        CONST_VTBL struct IBalloonVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBalloon_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBalloon_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBalloon_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBalloon_get_Color(This,pVal)	\
    (This)->lpVtbl -> get_Color(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IBalloon_get_Color_Proxy( 
    IBalloon __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IBalloon_get_Color_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBalloon_INTERFACE_DEFINED__ */


#ifndef __ISmartProxy_INTERFACE_DEFINED__
#define __ISmartProxy_INTERFACE_DEFINED__

/* interface ISmartProxy */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISmartProxy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB693B5E-80E2-11D2-987D-00600823CFFB")
    ISmartProxy : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ISmartProxyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISmartProxy __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISmartProxy __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISmartProxy __RPC_FAR * This);
        
        END_INTERFACE
    } ISmartProxyVtbl;

    interface ISmartProxy
    {
        CONST_VTBL struct ISmartProxyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISmartProxy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISmartProxy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISmartProxy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISmartProxy_INTERFACE_DEFINED__ */



#ifndef __THISLib_LIBRARY_DEFINED__
#define __THISLib_LIBRARY_DEFINED__

/* library THISLib */
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_THISLib;

EXTERN_C const CLSID CLSID_BalloonMan;

#ifdef __cplusplus

class DECLSPEC_UUID("CB693B57-80E2-11D2-987D-00600823CFFB")
BalloonMan;
#endif

EXTERN_C const CLSID CLSID_SmartProxy;

#ifdef __cplusplus

class DECLSPEC_UUID("CB693B5F-80E2-11D2-987D-00600823CFFB")
SmartProxy;
#endif
#endif /* __THISLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
