/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Mar 24 19:55:47 1999
 */
/* Compiler settings for P:\WISEOWL\ATLBook\ATLINTERNALS\ATLInternals.idl:
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

#ifndef __ATLInternals_h__
#define __ATLInternals_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IClimbableObject_FWD_DEFINED__
#define __IClimbableObject_FWD_DEFINED__
typedef interface IClimbableObject IClimbableObject;
#endif 	/* __IClimbableObject_FWD_DEFINED__ */


#ifndef __IListener_FWD_DEFINED__
#define __IListener_FWD_DEFINED__
typedef interface IListener IListener;
#endif 	/* __IListener_FWD_DEFINED__ */


#ifndef __INamedObject_FWD_DEFINED__
#define __INamedObject_FWD_DEFINED__
typedef interface INamedObject INamedObject;
#endif 	/* __INamedObject_FWD_DEFINED__ */


#ifndef __ISpeaker_FWD_DEFINED__
#define __ISpeaker_FWD_DEFINED__
typedef interface ISpeaker ISpeaker;
#endif 	/* __ISpeaker_FWD_DEFINED__ */


#ifndef ___IClimbableObjectEvents_FWD_DEFINED__
#define ___IClimbableObjectEvents_FWD_DEFINED__
typedef interface _IClimbableObjectEvents _IClimbableObjectEvents;
#endif 	/* ___IClimbableObjectEvents_FWD_DEFINED__ */


#ifndef ___ISpeakerEvents_FWD_DEFINED__
#define ___ISpeakerEvents_FWD_DEFINED__
typedef interface _ISpeakerEvents _ISpeakerEvents;
#endif 	/* ___ISpeakerEvents_FWD_DEFINED__ */


#ifndef __Demagogue_FWD_DEFINED__
#define __Demagogue_FWD_DEFINED__

#ifdef __cplusplus
typedef class Demagogue Demagogue;
#else
typedef struct Demagogue Demagogue;
#endif /* __cplusplus */

#endif 	/* __Demagogue_FWD_DEFINED__ */


#ifndef __EarPolitic_FWD_DEFINED__
#define __EarPolitic_FWD_DEFINED__

#ifdef __cplusplus
typedef class EarPolitic EarPolitic;
#else
typedef struct EarPolitic EarPolitic;
#endif /* __cplusplus */

#endif 	/* __EarPolitic_FWD_DEFINED__ */


#ifndef __SoapBox_FWD_DEFINED__
#define __SoapBox_FWD_DEFINED__

#ifdef __cplusplus
typedef class SoapBox SoapBox;
#else
typedef struct SoapBox SoapBox;
#endif /* __cplusplus */

#endif 	/* __SoapBox_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IClimbableObject_INTERFACE_DEFINED__
#define __IClimbableObject_INTERFACE_DEFINED__

/* interface IClimbableObject */
/* [unique][helpstring][dual][uuid][object] */ 

#define	DISPID_CLIMBON	( 1 )

#define	DISPID_CLIMBOFF	( 2 )


EXTERN_C const IID IID_IClimbableObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95CD372D-FC5C-11D1-8CC3-00A0C9C8E50D")
    IClimbableObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClimbOn( 
            IUnknown __RPC_FAR *pClimber) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClimbOff( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClimbableObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IClimbableObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IClimbableObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IClimbableObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IClimbableObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IClimbableObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IClimbableObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IClimbableObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClimbOn )( 
            IClimbableObject __RPC_FAR * This,
            IUnknown __RPC_FAR *pClimber);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClimbOff )( 
            IClimbableObject __RPC_FAR * This);
        
        END_INTERFACE
    } IClimbableObjectVtbl;

    interface IClimbableObject
    {
        CONST_VTBL struct IClimbableObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClimbableObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClimbableObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClimbableObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClimbableObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IClimbableObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IClimbableObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IClimbableObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IClimbableObject_ClimbOn(This,pClimber)	\
    (This)->lpVtbl -> ClimbOn(This,pClimber)

#define IClimbableObject_ClimbOff(This)	\
    (This)->lpVtbl -> ClimbOff(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IClimbableObject_ClimbOn_Proxy( 
    IClimbableObject __RPC_FAR * This,
    IUnknown __RPC_FAR *pClimber);


void __RPC_STUB IClimbableObject_ClimbOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IClimbableObject_ClimbOff_Proxy( 
    IClimbableObject __RPC_FAR * This);


void __RPC_STUB IClimbableObject_ClimbOff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClimbableObject_INTERFACE_DEFINED__ */


#ifndef __IListener_INTERFACE_DEFINED__
#define __IListener_INTERFACE_DEFINED__

/* interface IListener */
/* [unique][helpstring][dual][uuid][object] */ 

typedef 
enum SpeakerRole
    {	Defendant	= 0,
	Plaintiff	= Defendant + 1
    }	SpeakerRole;

#define	DISPID_LISTENTO	( 1 )

#define	DISPID_STOPLISTENING	( 2 )


EXTERN_C const IID IID_IListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AE491FB0-FBE7-11D1-8CC3-00A0C9C8E50D")
    IListener : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ListenTo( 
            SpeakerRole role,
            IUnknown __RPC_FAR *pSpeaker) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopListening( 
            SpeakerRole role) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IListener __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IListener __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IListener __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IListener __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IListener __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IListener __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IListener __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ListenTo )( 
            IListener __RPC_FAR * This,
            SpeakerRole role,
            IUnknown __RPC_FAR *pSpeaker);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopListening )( 
            IListener __RPC_FAR * This,
            SpeakerRole role);
        
        END_INTERFACE
    } IListenerVtbl;

    interface IListener
    {
        CONST_VTBL struct IListenerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IListener_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IListener_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IListener_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IListener_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IListener_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IListener_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IListener_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IListener_ListenTo(This,role,pSpeaker)	\
    (This)->lpVtbl -> ListenTo(This,role,pSpeaker)

#define IListener_StopListening(This,role)	\
    (This)->lpVtbl -> StopListening(This,role)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IListener_ListenTo_Proxy( 
    IListener __RPC_FAR * This,
    SpeakerRole role,
    IUnknown __RPC_FAR *pSpeaker);


void __RPC_STUB IListener_ListenTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IListener_StopListening_Proxy( 
    IListener __RPC_FAR * This,
    SpeakerRole role);


void __RPC_STUB IListener_StopListening_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IListener_INTERFACE_DEFINED__ */


#ifndef __INamedObject_INTERFACE_DEFINED__
#define __INamedObject_INTERFACE_DEFINED__

/* interface INamedObject */
/* [unique][helpstring][dual][uuid][object] */ 

#define	DISPID_NAME	( 1 )


EXTERN_C const IID IID_INamedObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("450D6780-FC73-11d1-8CC3-00A0C9C8E50D")
    INamedObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INamedObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INamedObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INamedObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INamedObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INamedObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INamedObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INamedObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INamedObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            INamedObject __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            INamedObject __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } INamedObjectVtbl;

    interface INamedObject
    {
        CONST_VTBL struct INamedObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INamedObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INamedObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INamedObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INamedObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INamedObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INamedObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INamedObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INamedObject_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define INamedObject_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INamedObject_get_Name_Proxy( 
    INamedObject __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB INamedObject_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INamedObject_put_Name_Proxy( 
    INamedObject __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB INamedObject_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INamedObject_INTERFACE_DEFINED__ */


#ifndef __ISpeaker_INTERFACE_DEFINED__
#define __ISpeaker_INTERFACE_DEFINED__

/* interface ISpeaker */
/* [unique][helpstring][dual][uuid][object] */ 

#define	DISPID_VOLUME	( 1 )

#define	DISPID_SPEECH	( 2 )

#define	DISPID_SPEAK	( 3 )


EXTERN_C const IID IID_ISpeaker;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AE491FAD-FBE7-11D1-8CC3-00A0C9C8E50D")
    ISpeaker : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Speech( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Speech( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Speak( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpeakerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISpeaker __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISpeaker __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISpeaker __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISpeaker __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISpeaker __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISpeaker __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISpeaker __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Volume )( 
            ISpeaker __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Volume )( 
            ISpeaker __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Speech )( 
            ISpeaker __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Speech )( 
            ISpeaker __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Speak )( 
            ISpeaker __RPC_FAR * This);
        
        END_INTERFACE
    } ISpeakerVtbl;

    interface ISpeaker
    {
        CONST_VTBL struct ISpeakerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeaker_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISpeaker_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISpeaker_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISpeaker_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISpeaker_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISpeaker_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISpeaker_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISpeaker_get_Volume(This,pVal)	\
    (This)->lpVtbl -> get_Volume(This,pVal)

#define ISpeaker_put_Volume(This,newVal)	\
    (This)->lpVtbl -> put_Volume(This,newVal)

#define ISpeaker_get_Speech(This,pVal)	\
    (This)->lpVtbl -> get_Speech(This,pVal)

#define ISpeaker_put_Speech(This,newVal)	\
    (This)->lpVtbl -> put_Speech(This,newVal)

#define ISpeaker_Speak(This)	\
    (This)->lpVtbl -> Speak(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISpeaker_get_Volume_Proxy( 
    ISpeaker __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISpeaker_get_Volume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISpeaker_put_Volume_Proxy( 
    ISpeaker __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISpeaker_put_Volume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISpeaker_get_Speech_Proxy( 
    ISpeaker __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISpeaker_get_Speech_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISpeaker_put_Speech_Proxy( 
    ISpeaker __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISpeaker_put_Speech_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISpeaker_Speak_Proxy( 
    ISpeaker __RPC_FAR * This);


void __RPC_STUB ISpeaker_Speak_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISpeaker_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ATLInternals_0212 */
/* [local] */ 

#define	DISPID_ONCLIMB	( 1 )

#define	DISPID_ONWHISPER	( 1 )

#define	DISPID_ONTALK	( 2 )

#define	DISPID_ONYELL	( 3 )



extern RPC_IF_HANDLE __MIDL_itf_ATLInternals_0212_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ATLInternals_0212_v0_0_s_ifspec;


#ifndef __ATLINTERNALSLib_LIBRARY_DEFINED__
#define __ATLINTERNALSLib_LIBRARY_DEFINED__

/* library ATLINTERNALSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ATLINTERNALSLib;

#ifndef ___IClimbableObjectEvents_DISPINTERFACE_DEFINED__
#define ___IClimbableObjectEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IClimbableObjectEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IClimbableObjectEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("95CD372F-FC5C-11D1-8CC3-00A0C9C8E50D")
    _IClimbableObjectEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IClimbableObjectEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IClimbableObjectEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IClimbableObjectEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IClimbableObjectEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IClimbableObjectEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IClimbableObjectEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IClimbableObjectEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IClimbableObjectEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IClimbableObjectEventsVtbl;

    interface _IClimbableObjectEvents
    {
        CONST_VTBL struct _IClimbableObjectEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IClimbableObjectEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IClimbableObjectEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IClimbableObjectEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IClimbableObjectEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IClimbableObjectEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IClimbableObjectEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IClimbableObjectEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IClimbableObjectEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___ISpeakerEvents_DISPINTERFACE_DEFINED__
#define ___ISpeakerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ISpeakerEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ISpeakerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AE491FAF-FBE7-11D1-8CC3-00A0C9C8E50D")
    _ISpeakerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ISpeakerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ISpeakerEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ISpeakerEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ISpeakerEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ISpeakerEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ISpeakerEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ISpeakerEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ISpeakerEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ISpeakerEventsVtbl;

    interface _ISpeakerEvents
    {
        CONST_VTBL struct _ISpeakerEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISpeakerEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ISpeakerEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ISpeakerEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ISpeakerEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ISpeakerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ISpeakerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ISpeakerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISpeakerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Demagogue;

#ifdef __cplusplus

class DECLSPEC_UUID("95CD3731-FC5C-11D1-8CC3-00A0C9C8E50D")
Demagogue;
#endif

EXTERN_C const CLSID CLSID_EarPolitic;

#ifdef __cplusplus

class DECLSPEC_UUID("95CD3734-FC5C-11D1-8CC3-00A0C9C8E50D")
EarPolitic;
#endif

EXTERN_C const CLSID CLSID_SoapBox;

#ifdef __cplusplus

class DECLSPEC_UUID("95CD372E-FC5C-11D1-8CC3-00A0C9C8E50D")
SoapBox;
#endif
#endif /* __ATLINTERNALSLib_LIBRARY_DEFINED__ */

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
