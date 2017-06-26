/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Nov 20 17:39:29 1998
 */
/* Compiler settings for D:\ATLBook\src\Chapter 01\PiSvr\PiSvr.idl:
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

#ifndef __PiSvr_h__
#define __PiSvr_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ICalcPi_FWD_DEFINED__
#define __ICalcPi_FWD_DEFINED__
typedef interface ICalcPi ICalcPi;
#endif 	/* __ICalcPi_FWD_DEFINED__ */


#ifndef __IAdvertiseMyself_FWD_DEFINED__
#define __IAdvertiseMyself_FWD_DEFINED__
typedef interface IAdvertiseMyself IAdvertiseMyself;
#endif 	/* __IAdvertiseMyself_FWD_DEFINED__ */


#ifndef ___ICalcPiEvents_FWD_DEFINED__
#define ___ICalcPiEvents_FWD_DEFINED__
typedef interface _ICalcPiEvents _ICalcPiEvents;
#endif 	/* ___ICalcPiEvents_FWD_DEFINED__ */


#ifndef __CalcPi_FWD_DEFINED__
#define __CalcPi_FWD_DEFINED__

#ifdef __cplusplus
typedef class CalcPi CalcPi;
#else
typedef struct CalcPi CalcPi;
#endif /* __cplusplus */

#endif 	/* __CalcPi_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ICalcPi_INTERFACE_DEFINED__
#define __ICalcPi_INTERFACE_DEFINED__

/* interface ICalcPi */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICalcPi;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DEC22F36-DD78-11D1-97FD-006008243C8C")
    ICalcPi : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Digits( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Digits( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalcPi( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrPi) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICalcPiVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICalcPi __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICalcPi __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICalcPi __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICalcPi __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICalcPi __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICalcPi __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICalcPi __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Digits )( 
            ICalcPi __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Digits )( 
            ICalcPi __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalcPi )( 
            ICalcPi __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrPi);
        
        END_INTERFACE
    } ICalcPiVtbl;

    interface ICalcPi
    {
        CONST_VTBL struct ICalcPiVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalcPi_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICalcPi_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICalcPi_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICalcPi_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICalcPi_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICalcPi_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICalcPi_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICalcPi_get_Digits(This,pVal)	\
    (This)->lpVtbl -> get_Digits(This,pVal)

#define ICalcPi_put_Digits(This,newVal)	\
    (This)->lpVtbl -> put_Digits(This,newVal)

#define ICalcPi_CalcPi(This,pbstrPi)	\
    (This)->lpVtbl -> CalcPi(This,pbstrPi)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICalcPi_get_Digits_Proxy( 
    ICalcPi __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ICalcPi_get_Digits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICalcPi_put_Digits_Proxy( 
    ICalcPi __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ICalcPi_put_Digits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICalcPi_CalcPi_Proxy( 
    ICalcPi __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrPi);


void __RPC_STUB ICalcPi_CalcPi_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICalcPi_INTERFACE_DEFINED__ */


#ifndef __IAdvertiseMyself_INTERFACE_DEFINED__
#define __IAdvertiseMyself_INTERFACE_DEFINED__

/* interface IAdvertiseMyself */
/* [unique][helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IAdvertiseMyself;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7B568195-F63B-11D1-9818-00600823CFFB")
    IAdvertiseMyself : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ShowAd( 
            BSTR bstrClient) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAdvertiseMyselfVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAdvertiseMyself __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAdvertiseMyself __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAdvertiseMyself __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowAd )( 
            IAdvertiseMyself __RPC_FAR * This,
            BSTR bstrClient);
        
        END_INTERFACE
    } IAdvertiseMyselfVtbl;

    interface IAdvertiseMyself
    {
        CONST_VTBL struct IAdvertiseMyselfVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdvertiseMyself_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAdvertiseMyself_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAdvertiseMyself_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAdvertiseMyself_ShowAd(This,bstrClient)	\
    (This)->lpVtbl -> ShowAd(This,bstrClient)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAdvertiseMyself_ShowAd_Proxy( 
    IAdvertiseMyself __RPC_FAR * This,
    BSTR bstrClient);


void __RPC_STUB IAdvertiseMyself_ShowAd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAdvertiseMyself_INTERFACE_DEFINED__ */



#ifndef __PISVRLib_LIBRARY_DEFINED__
#define __PISVRLib_LIBRARY_DEFINED__

/* library PISVRLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_PISVRLib;

#ifndef ___ICalcPiEvents_DISPINTERFACE_DEFINED__
#define ___ICalcPiEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ICalcPiEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ICalcPiEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DEC22F38-DD78-11D1-97FD-006008243C8C")
    _ICalcPiEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICalcPiEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ICalcPiEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ICalcPiEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ICalcPiEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ICalcPiEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ICalcPiEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ICalcPiEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ICalcPiEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ICalcPiEventsVtbl;

    interface _ICalcPiEvents
    {
        CONST_VTBL struct _ICalcPiEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICalcPiEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ICalcPiEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ICalcPiEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ICalcPiEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ICalcPiEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ICalcPiEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ICalcPiEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICalcPiEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CalcPi;

#ifdef __cplusplus

class DECLSPEC_UUID("DEC22F37-DD78-11D1-97FD-006008243C8C")
CalcPi;
#endif
#endif /* __PISVRLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
