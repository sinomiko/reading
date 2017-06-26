/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Fri Aug 14 01:49:20 1998
 */
/* Compiler settings for composition.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __composition_h__
#define __composition_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAcePowell_FWD_DEFINED__
#define __IAcePowell_FWD_DEFINED__
typedef interface IAcePowell IAcePowell;
#endif 	/* __IAcePowell_FWD_DEFINED__ */


#ifndef __IArtist_FWD_DEFINED__
#define __IArtist_FWD_DEFINED__
typedef interface IArtist IArtist;
#endif 	/* __IArtist_FWD_DEFINED__ */


#ifndef __ICowboy_FWD_DEFINED__
#define __ICowboy_FWD_DEFINED__
typedef interface ICowboy ICowboy;
#endif 	/* __ICowboy_FWD_DEFINED__ */


#ifndef __ICowboyEx_FWD_DEFINED__
#define __ICowboyEx_FWD_DEFINED__
typedef interface ICowboyEx ICowboyEx;
#endif 	/* __ICowboyEx_FWD_DEFINED__ */


#ifndef __AcePowell_FWD_DEFINED__
#define __AcePowell_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcePowell AcePowell;
#else
typedef struct AcePowell AcePowell;
#endif /* __cplusplus */

#endif 	/* __AcePowell_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IAcePowell_INTERFACE_DEFINED__
#define __IAcePowell_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAcePowell
 * at Fri Aug 14 01:49:20 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IAcePowell;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("ADF259F7-5967-11D1-9687-00600819B080")
    IAcePowell : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IAcePowellVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAcePowell __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAcePowell __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAcePowell __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAcePowell __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAcePowell __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAcePowell __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAcePowell __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IAcePowellVtbl;

    interface IAcePowell
    {
        CONST_VTBL struct IAcePowellVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcePowell_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAcePowell_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAcePowell_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAcePowell_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAcePowell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAcePowell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAcePowell_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcePowell_INTERFACE_DEFINED__ */


#ifndef __IArtist_INTERFACE_DEFINED__
#define __IArtist_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IArtist
 * at Fri Aug 14 01:49:20 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][object] */ 



EXTERN_C const IID IID_IArtist;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("2CEA24D0-5980-11d1-9687-00600819B080")
    IArtist : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Draw( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IArtistVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IArtist __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IArtist __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IArtist __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Draw )( 
            IArtist __RPC_FAR * This);
        
        END_INTERFACE
    } IArtistVtbl;

    interface IArtist
    {
        CONST_VTBL struct IArtistVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IArtist_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IArtist_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IArtist_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IArtist_Draw(This)	\
    (This)->lpVtbl -> Draw(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IArtist_Draw_Proxy( 
    IArtist __RPC_FAR * This);


void __RPC_STUB IArtist_Draw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IArtist_INTERFACE_DEFINED__ */


#ifndef __ICowboy_INTERFACE_DEFINED__
#define __ICowboy_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICowboy
 * at Fri Aug 14 01:49:20 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][object] */ 



EXTERN_C const IID IID_ICowboy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("2CEA24D1-5980-11d1-9687-00600819B080")
    ICowboy : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Draw( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICowboyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICowboy __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICowboy __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICowboy __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Draw )( 
            ICowboy __RPC_FAR * This);
        
        END_INTERFACE
    } ICowboyVtbl;

    interface ICowboy
    {
        CONST_VTBL struct ICowboyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICowboy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICowboy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICowboy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICowboy_Draw(This)	\
    (This)->lpVtbl -> Draw(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICowboy_Draw_Proxy( 
    ICowboy __RPC_FAR * This);


void __RPC_STUB ICowboy_Draw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICowboy_INTERFACE_DEFINED__ */


#ifndef __ICowboyEx_INTERFACE_DEFINED__
#define __ICowboyEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICowboyEx
 * at Fri Aug 14 01:49:20 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][object] */ 



EXTERN_C const IID IID_ICowboyEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("6B438A90-59EE-11d1-9687-00600819B080")
    ICowboyEx : public ICowboy
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QuickDraw( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICowboyExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICowboyEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICowboyEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICowboyEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Draw )( 
            ICowboyEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuickDraw )( 
            ICowboyEx __RPC_FAR * This);
        
        END_INTERFACE
    } ICowboyExVtbl;

    interface ICowboyEx
    {
        CONST_VTBL struct ICowboyExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICowboyEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICowboyEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICowboyEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICowboyEx_Draw(This)	\
    (This)->lpVtbl -> Draw(This)


#define ICowboyEx_QuickDraw(This)	\
    (This)->lpVtbl -> QuickDraw(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICowboyEx_QuickDraw_Proxy( 
    ICowboyEx __RPC_FAR * This);


void __RPC_STUB ICowboyEx_QuickDraw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICowboyEx_INTERFACE_DEFINED__ */



#ifndef __COMPOSITIONLib_LIBRARY_DEFINED__
#define __COMPOSITIONLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: COMPOSITIONLib
 * at Fri Aug 14 01:49:20 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_COMPOSITIONLib;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_AcePowell;

class DECLSPEC_UUID("ADF259F8-5967-11D1-9687-00600819B080")
AcePowell;
#endif
#endif /* __COMPOSITIONLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
