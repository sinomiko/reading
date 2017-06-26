
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#ifndef __BullsEyeCtl_h__
#define __BullsEyeCtl_h__

/* Forward Declarations */ 

#ifndef __IBullsEye_FWD_DEFINED__
#define __IBullsEye_FWD_DEFINED__
typedef interface IBullsEye IBullsEye;
#endif 	/* __IBullsEye_FWD_DEFINED__ */


#ifndef ___IBullsEyeEvents_FWD_DEFINED__
#define ___IBullsEyeEvents_FWD_DEFINED__
typedef interface _IBullsEyeEvents _IBullsEyeEvents;
#endif 	/* ___IBullsEyeEvents_FWD_DEFINED__ */


#ifndef __BullsEye_FWD_DEFINED__
#define __BullsEye_FWD_DEFINED__

#ifdef __cplusplus
typedef class BullsEye BullsEye;
#else
typedef struct BullsEye BullsEye;
#endif /* __cplusplus */

#endif 	/* __BullsEye_FWD_DEFINED__ */


#ifndef __BullsEyePropPage_FWD_DEFINED__
#define __BullsEyePropPage_FWD_DEFINED__

#ifdef __cplusplus
typedef class BullsEyePropPage BullsEyePropPage;
#else
typedef struct BullsEyePropPage BullsEyePropPage;
#endif /* __cplusplus */

#endif 	/* __BullsEyePropPage_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "CategorizeProperties.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IBullsEye_INTERFACE_DEFINED__
#define __IBullsEye_INTERFACE_DEFINED__

/* interface IBullsEye */
/* [unique][helpstring][dual][uuid][object] */ 

#define	DISPID_ALTERNATECOLOR	( 1 )

#define	DISPID_BEEP	( 2 )

#define	DISPID_CENTERCOLOR	( 3 )

#define	DISPID_RINGCOUNT	( 4 )

#define	DISPID_RINGVALUE	( 5 )

#define	DISPID_APPLICATION	( 6 )

#define	DISPID_PARENT	( 7 )


EXTERN_C const IID IID_IBullsEye;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7DC59CC4-36C0-11D2-AC05-00A0C9C8E50D")
    IBullsEye : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BackStyle( 
            /* [in] */ long style) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BackStyle( 
            /* [retval][out] */ long __RPC_FAR *style) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AlternateColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AlternateColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Beep( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Beep( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CenterColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CenterColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RingCount( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RingCount( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RingValue( 
            /* [in] */ short sRingNumber,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RingValue( 
            /* [in] */ short sRingNumber,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DoClick( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AboutBox( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBullsEyeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBullsEye __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBullsEye __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IBullsEye __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColor )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackStyle )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ long style);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackStyle )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *style);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForeColor )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColor )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [requestedit][bindable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AlternateColor )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [requestedit][bindable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AlternateColor )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [requestedit][bindable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Beep )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [requestedit][bindable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Beep )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [requestedit][bindable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CenterColor )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [requestedit][bindable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CenterColor )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [requestedit][bindable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RingCount )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [requestedit][bindable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RingCount )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [requestedit][bindable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RingValue )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ short sRingNumber,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [requestedit][bindable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RingValue )( 
            IBullsEye __RPC_FAR * This,
            /* [in] */ short sRingNumber,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Application )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Parent )( 
            IBullsEye __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IBullsEye __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoClick )( 
            IBullsEye __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AboutBox )( 
            IBullsEye __RPC_FAR * This);
        
        END_INTERFACE
    } IBullsEyeVtbl;

    interface IBullsEye
    {
        CONST_VTBL struct IBullsEyeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBullsEye_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBullsEye_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBullsEye_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBullsEye_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IBullsEye_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IBullsEye_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IBullsEye_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IBullsEye_put_BackColor(This,clr)	\
    (This)->lpVtbl -> put_BackColor(This,clr)

#define IBullsEye_get_BackColor(This,pclr)	\
    (This)->lpVtbl -> get_BackColor(This,pclr)

#define IBullsEye_put_BackStyle(This,style)	\
    (This)->lpVtbl -> put_BackStyle(This,style)

#define IBullsEye_get_BackStyle(This,style)	\
    (This)->lpVtbl -> get_BackStyle(This,style)

#define IBullsEye_put_ForeColor(This,clr)	\
    (This)->lpVtbl -> put_ForeColor(This,clr)

#define IBullsEye_get_ForeColor(This,pclr)	\
    (This)->lpVtbl -> get_ForeColor(This,pclr)

#define IBullsEye_put_Enabled(This,vbool)	\
    (This)->lpVtbl -> put_Enabled(This,vbool)

#define IBullsEye_get_Enabled(This,pbool)	\
    (This)->lpVtbl -> get_Enabled(This,pbool)

#define IBullsEye_get_AlternateColor(This,pVal)	\
    (This)->lpVtbl -> get_AlternateColor(This,pVal)

#define IBullsEye_put_AlternateColor(This,newVal)	\
    (This)->lpVtbl -> put_AlternateColor(This,newVal)

#define IBullsEye_get_Beep(This,pVal)	\
    (This)->lpVtbl -> get_Beep(This,pVal)

#define IBullsEye_put_Beep(This,newVal)	\
    (This)->lpVtbl -> put_Beep(This,newVal)

#define IBullsEye_get_CenterColor(This,pVal)	\
    (This)->lpVtbl -> get_CenterColor(This,pVal)

#define IBullsEye_put_CenterColor(This,newVal)	\
    (This)->lpVtbl -> put_CenterColor(This,newVal)

#define IBullsEye_get_RingCount(This,pVal)	\
    (This)->lpVtbl -> get_RingCount(This,pVal)

#define IBullsEye_put_RingCount(This,newVal)	\
    (This)->lpVtbl -> put_RingCount(This,newVal)

#define IBullsEye_get_RingValue(This,sRingNumber,pVal)	\
    (This)->lpVtbl -> get_RingValue(This,sRingNumber,pVal)

#define IBullsEye_put_RingValue(This,sRingNumber,newVal)	\
    (This)->lpVtbl -> put_RingValue(This,sRingNumber,newVal)

#define IBullsEye_get_Application(This,pVal)	\
    (This)->lpVtbl -> get_Application(This,pVal)

#define IBullsEye_get_Parent(This,pVal)	\
    (This)->lpVtbl -> get_Parent(This,pVal)

#define IBullsEye_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)

#define IBullsEye_DoClick(This)	\
    (This)->lpVtbl -> DoClick(This)

#define IBullsEye_AboutBox(This)	\
    (This)->lpVtbl -> AboutBox(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propput] */ HRESULT STDMETHODCALLTYPE IBullsEye_put_BackColor_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IBullsEye_put_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_BackColor_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);


void __RPC_STUB IBullsEye_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IBullsEye_put_BackStyle_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ long style);


void __RPC_STUB IBullsEye_put_BackStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_BackStyle_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *style);


void __RPC_STUB IBullsEye_get_BackStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IBullsEye_put_ForeColor_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IBullsEye_put_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_ForeColor_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);


void __RPC_STUB IBullsEye_get_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IBullsEye_put_Enabled_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB IBullsEye_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_Enabled_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB IBullsEye_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_AlternateColor_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IBullsEye_get_AlternateColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBullsEye_put_AlternateColor_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB IBullsEye_put_AlternateColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_Beep_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IBullsEye_get_Beep_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBullsEye_put_Beep_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IBullsEye_put_Beep_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_CenterColor_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IBullsEye_get_CenterColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBullsEye_put_CenterColor_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB IBullsEye_put_CenterColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_RingCount_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IBullsEye_get_RingCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBullsEye_put_RingCount_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IBullsEye_put_RingCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_RingValue_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ short sRingNumber,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IBullsEye_get_RingValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBullsEye_put_RingValue_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [in] */ short sRingNumber,
    /* [in] */ long newVal);


void __RPC_STUB IBullsEye_put_RingValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_Application_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);


void __RPC_STUB IBullsEye_get_Application_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBullsEye_get_Parent_Proxy( 
    IBullsEye __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);


void __RPC_STUB IBullsEye_get_Parent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBullsEye_Refresh_Proxy( 
    IBullsEye __RPC_FAR * This);


void __RPC_STUB IBullsEye_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBullsEye_DoClick_Proxy( 
    IBullsEye __RPC_FAR * This);


void __RPC_STUB IBullsEye_DoClick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBullsEye_AboutBox_Proxy( 
    IBullsEye __RPC_FAR * This);


void __RPC_STUB IBullsEye_AboutBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBullsEye_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_BullsEyeCtl_0248 */
/* [local] */ 

#define	DISPID_ONRINGHIT	( 1 )

#define	DISPID_ONSCORECHANGED	( 2 )



extern RPC_IF_HANDLE __MIDL_itf_BullsEyeCtl_0248_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_BullsEyeCtl_0248_v0_0_s_ifspec;


#ifndef __BullsEyeLib_LIBRARY_DEFINED__
#define __BullsEyeLib_LIBRARY_DEFINED__

/* library BullsEyeLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_BullsEyeLib;

#ifndef ___IBullsEyeEvents_DISPINTERFACE_DEFINED__
#define ___IBullsEyeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IBullsEyeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IBullsEyeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19FF9872-36ED-11d2-AC05-00A0C9C8E50D")
    _IBullsEyeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IBullsEyeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IBullsEyeEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IBullsEyeEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IBullsEyeEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IBullsEyeEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IBullsEyeEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IBullsEyeEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IBullsEyeEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IBullsEyeEventsVtbl;

    interface _IBullsEyeEvents
    {
        CONST_VTBL struct _IBullsEyeEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IBullsEyeEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IBullsEyeEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IBullsEyeEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IBullsEyeEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IBullsEyeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IBullsEyeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IBullsEyeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IBullsEyeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BullsEye;

#ifdef __cplusplus

class DECLSPEC_UUID("7DC59CC5-36C0-11D2-AC05-00A0C9C8E50D")
BullsEye;
#endif

EXTERN_C const CLSID CLSID_BullsEyePropPage;

#ifdef __cplusplus

class DECLSPEC_UUID("7DC59CC8-36C0-11D2-AC05-00A0C9C8E50D")
BullsEyePropPage;
#endif
#endif /* __BullsEyeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


