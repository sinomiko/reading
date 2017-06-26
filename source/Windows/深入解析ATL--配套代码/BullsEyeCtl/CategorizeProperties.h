/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Sep 12 18:43:41 1998
 */
/* Compiler settings for D:\ATLInternals\CategorizeProperties.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
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

#ifndef __CategorizeProperties_h__
#define __CategorizeProperties_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ICategorizeProperties_FWD_DEFINED__
#define __ICategorizeProperties_FWD_DEFINED__
typedef interface ICategorizeProperties ICategorizeProperties;
#endif 	/* __ICategorizeProperties_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "oaidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_CategorizeProperties_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_CategorizeProperties_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CategorizeProperties_0000_v0_0_s_ifspec;

#ifndef __ICategorizeProperties_INTERFACE_DEFINED__
#define __ICategorizeProperties_INTERFACE_DEFINED__

/* interface ICategorizeProperties */
/* [unique][helpstring][uuid][local][object] */ 

typedef /* [public] */ int PROPCAT;

#define	PROPCAT_Nil	( -1 )

#define	PROPCAT_Misc	( -2 )

#define	PROPCAT_Font	( -3 )

#define	PROPCAT_Position	( -4 )

#define	PROPCAT_Appearance	( -5 )

#define	PROPCAT_Behavior	( -6 )

#define	PROPCAT_Data	( -7 )

#define	PROPCAT_List	( -8 )

#define	PROPCAT_Text	( -9 )

#define	PROPCAT_Scale	( -10 )

#define	PROPCAT_DDE	( -11 )


EXTERN_C const IID IID_ICategorizeProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D07FC10-F931-11CE-B001-00AA006884E5")
    ICategorizeProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MapPropertyToCategory( 
            /* [in] */ DISPID dispid,
            /* [out] */ PROPCAT __RPC_FAR *ppropcat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCategoryName( 
            /* [in] */ PROPCAT propcat,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR __RPC_FAR *pbstrName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICategorizePropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICategorizeProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICategorizeProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICategorizeProperties __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MapPropertyToCategory )( 
            ICategorizeProperties __RPC_FAR * This,
            /* [in] */ DISPID dispid,
            /* [out] */ PROPCAT __RPC_FAR *ppropcat);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCategoryName )( 
            ICategorizeProperties __RPC_FAR * This,
            /* [in] */ PROPCAT propcat,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR __RPC_FAR *pbstrName);
        
        END_INTERFACE
    } ICategorizePropertiesVtbl;

    interface ICategorizeProperties
    {
        CONST_VTBL struct ICategorizePropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICategorizeProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICategorizeProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICategorizeProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICategorizeProperties_MapPropertyToCategory(This,dispid,ppropcat)	\
    (This)->lpVtbl -> MapPropertyToCategory(This,dispid,ppropcat)

#define ICategorizeProperties_GetCategoryName(This,propcat,lcid,pbstrName)	\
    (This)->lpVtbl -> GetCategoryName(This,propcat,lcid,pbstrName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICategorizeProperties_MapPropertyToCategory_Proxy( 
    ICategorizeProperties __RPC_FAR * This,
    /* [in] */ DISPID dispid,
    /* [out] */ PROPCAT __RPC_FAR *ppropcat);


void __RPC_STUB ICategorizeProperties_MapPropertyToCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICategorizeProperties_GetCategoryName_Proxy( 
    ICategorizeProperties __RPC_FAR * This,
    /* [in] */ PROPCAT propcat,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR __RPC_FAR *pbstrName);


void __RPC_STUB ICategorizeProperties_GetCategoryName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICategorizeProperties_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
