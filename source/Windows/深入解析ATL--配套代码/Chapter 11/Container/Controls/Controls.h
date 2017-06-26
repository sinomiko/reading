/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Dec 14 23:47:45 1998
 */
/* Compiler settings for D:\ATLBook\src\Chapter 11\Container\Controls\Controls.idl:
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

#ifndef __Controls_h__
#define __Controls_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IDartBoard_FWD_DEFINED__
#define __IDartBoard_FWD_DEFINED__
typedef interface IDartBoard IDartBoard;
#endif 	/* __IDartBoard_FWD_DEFINED__ */


#ifndef ___IDartBoardEvents_FWD_DEFINED__
#define ___IDartBoardEvents_FWD_DEFINED__
typedef interface _IDartBoardEvents _IDartBoardEvents;
#endif 	/* ___IDartBoardEvents_FWD_DEFINED__ */


#ifndef __ISmartDartBoard_FWD_DEFINED__
#define __ISmartDartBoard_FWD_DEFINED__
typedef interface ISmartDartBoard ISmartDartBoard;
#endif 	/* __ISmartDartBoard_FWD_DEFINED__ */


#ifndef __ISmartDartBoardUI_FWD_DEFINED__
#define __ISmartDartBoardUI_FWD_DEFINED__
typedef interface ISmartDartBoardUI ISmartDartBoardUI;
#endif 	/* __ISmartDartBoardUI_FWD_DEFINED__ */


#ifndef __DartBoard_FWD_DEFINED__
#define __DartBoard_FWD_DEFINED__

#ifdef __cplusplus
typedef class DartBoard DartBoard;
#else
typedef struct DartBoard DartBoard;
#endif /* __cplusplus */

#endif 	/* __DartBoard_FWD_DEFINED__ */


#ifndef __SmartDartBoard_FWD_DEFINED__
#define __SmartDartBoard_FWD_DEFINED__

#ifdef __cplusplus
typedef class SmartDartBoard SmartDartBoard;
#else
typedef struct SmartDartBoard SmartDartBoard;
#endif /* __cplusplus */

#endif 	/* __SmartDartBoard_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IDartBoard_INTERFACE_DEFINED__
#define __IDartBoard_INTERFACE_DEFINED__

/* interface IDartBoard */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDartBoard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0700D3F3-913F-11D2-9887-00600823CFFB")
    IDartBoard : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Score( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Score( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetScore( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDartBoardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDartBoard __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDartBoard __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDartBoard __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDartBoard __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDartBoard __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDartBoard __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDartBoard __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Score )( 
            IDartBoard __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Score )( 
            IDartBoard __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetScore )( 
            IDartBoard __RPC_FAR * This);
        
        END_INTERFACE
    } IDartBoardVtbl;

    interface IDartBoard
    {
        CONST_VTBL struct IDartBoardVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDartBoard_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDartBoard_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDartBoard_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDartBoard_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDartBoard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDartBoard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDartBoard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDartBoard_get_Score(This,pVal)	\
    (This)->lpVtbl -> get_Score(This,pVal)

#define IDartBoard_put_Score(This,newVal)	\
    (This)->lpVtbl -> put_Score(This,newVal)

#define IDartBoard_ResetScore(This)	\
    (This)->lpVtbl -> ResetScore(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDartBoard_get_Score_Proxy( 
    IDartBoard __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDartBoard_get_Score_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDartBoard_put_Score_Proxy( 
    IDartBoard __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDartBoard_put_Score_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDartBoard_ResetScore_Proxy( 
    IDartBoard __RPC_FAR * This);


void __RPC_STUB IDartBoard_ResetScore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDartBoard_INTERFACE_DEFINED__ */



#ifndef __CONTROLSLib_LIBRARY_DEFINED__
#define __CONTROLSLib_LIBRARY_DEFINED__

/* library CONTROLSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CONTROLSLib;

#ifndef ___IDartBoardEvents_DISPINTERFACE_DEFINED__
#define ___IDartBoardEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDartBoardEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDartBoardEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0700D3F5-913F-11D2-9887-00600823CFFB")
    _IDartBoardEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDartBoardEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IDartBoardEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IDartBoardEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IDartBoardEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IDartBoardEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IDartBoardEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IDartBoardEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IDartBoardEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IDartBoardEventsVtbl;

    interface _IDartBoardEvents
    {
        CONST_VTBL struct _IDartBoardEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDartBoardEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IDartBoardEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IDartBoardEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IDartBoardEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IDartBoardEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IDartBoardEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IDartBoardEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDartBoardEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ISmartDartBoard_INTERFACE_DEFINED__
#define __ISmartDartBoard_INTERFACE_DEFINED__

/* interface ISmartDartBoard */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISmartDartBoard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("76FFDC15-93C7-11D2-9889-00600823CFFB")
    ISmartDartBoard : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Score( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Score( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetScore( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISmartDartBoardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISmartDartBoard __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISmartDartBoard __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISmartDartBoard __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISmartDartBoard __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISmartDartBoard __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISmartDartBoard __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISmartDartBoard __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Score )( 
            ISmartDartBoard __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Score )( 
            ISmartDartBoard __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetScore )( 
            ISmartDartBoard __RPC_FAR * This);
        
        END_INTERFACE
    } ISmartDartBoardVtbl;

    interface ISmartDartBoard
    {
        CONST_VTBL struct ISmartDartBoardVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISmartDartBoard_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISmartDartBoard_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISmartDartBoard_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISmartDartBoard_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISmartDartBoard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISmartDartBoard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISmartDartBoard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISmartDartBoard_get_Score(This,pVal)	\
    (This)->lpVtbl -> get_Score(This,pVal)

#define ISmartDartBoard_put_Score(This,newVal)	\
    (This)->lpVtbl -> put_Score(This,newVal)

#define ISmartDartBoard_ResetScore(This)	\
    (This)->lpVtbl -> ResetScore(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISmartDartBoard_get_Score_Proxy( 
    ISmartDartBoard __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISmartDartBoard_get_Score_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISmartDartBoard_put_Score_Proxy( 
    ISmartDartBoard __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISmartDartBoard_put_Score_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISmartDartBoard_ResetScore_Proxy( 
    ISmartDartBoard __RPC_FAR * This);


void __RPC_STUB ISmartDartBoard_ResetScore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISmartDartBoard_INTERFACE_DEFINED__ */


#ifndef __ISmartDartBoardUI_INTERFACE_DEFINED__
#define __ISmartDartBoardUI_INTERFACE_DEFINED__

/* interface ISmartDartBoardUI */
/* [unique][helpstring][uuid][dual][object] */ 


EXTERN_C const IID IID_ISmartDartBoardUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("76FFDC17-93C7-11D2-9889-00600823CFFB")
    ISmartDartBoardUI : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddToScore( 
            /* [in] */ long ringValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetScore( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISmartDartBoardUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISmartDartBoardUI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISmartDartBoardUI __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISmartDartBoardUI __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISmartDartBoardUI __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISmartDartBoardUI __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISmartDartBoardUI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISmartDartBoardUI __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToScore )( 
            ISmartDartBoardUI __RPC_FAR * This,
            /* [in] */ long ringValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetScore )( 
            ISmartDartBoardUI __RPC_FAR * This);
        
        END_INTERFACE
    } ISmartDartBoardUIVtbl;

    interface ISmartDartBoardUI
    {
        CONST_VTBL struct ISmartDartBoardUIVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISmartDartBoardUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISmartDartBoardUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISmartDartBoardUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISmartDartBoardUI_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISmartDartBoardUI_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISmartDartBoardUI_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISmartDartBoardUI_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISmartDartBoardUI_AddToScore(This,ringValue)	\
    (This)->lpVtbl -> AddToScore(This,ringValue)

#define ISmartDartBoardUI_ResetScore(This)	\
    (This)->lpVtbl -> ResetScore(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISmartDartBoardUI_AddToScore_Proxy( 
    ISmartDartBoardUI __RPC_FAR * This,
    /* [in] */ long ringValue);


void __RPC_STUB ISmartDartBoardUI_AddToScore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISmartDartBoardUI_ResetScore_Proxy( 
    ISmartDartBoardUI __RPC_FAR * This);


void __RPC_STUB ISmartDartBoardUI_ResetScore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISmartDartBoardUI_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DartBoard;

#ifdef __cplusplus

class DECLSPEC_UUID("0700D3F4-913F-11D2-9887-00600823CFFB")
DartBoard;
#endif

EXTERN_C const CLSID CLSID_SmartDartBoard;

#ifdef __cplusplus

class DECLSPEC_UUID("76FFDC16-93C7-11D2-9889-00600823CFFB")
SmartDartBoard;
#endif
#endif /* __CONTROLSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
