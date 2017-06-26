/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Aug 19 19:18:48 1998
 */
/* Compiler settings for D:\ATLBook\src\Chapter 05\fwdshims\fwdshims.idl:
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

#ifndef __fwdshims_h__
#define __fwdshims_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ICowboy_FWD_DEFINED__
#define __ICowboy_FWD_DEFINED__
typedef interface ICowboy ICowboy;
#endif 	/* __ICowboy_FWD_DEFINED__ */


#ifndef __IArtist_FWD_DEFINED__
#define __IArtist_FWD_DEFINED__
typedef interface IArtist IArtist;
#endif 	/* __IArtist_FWD_DEFINED__ */


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

#ifndef __ICowboy_INTERFACE_DEFINED__
#define __ICowboy_INTERFACE_DEFINED__

/* interface ICowboy */
/* [object][uuid] */ 


EXTERN_C const IID IID_ICowboy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10712B76-370D-11D2-984B-00600823CFFB")
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


#ifndef __IArtist_INTERFACE_DEFINED__
#define __IArtist_INTERFACE_DEFINED__

/* interface IArtist */
/* [object][uuid] */ 


EXTERN_C const IID IID_IArtist;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10712B77-370D-11D2-984B-00600823CFFB")
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



#ifndef __FWDSHIMSLib_LIBRARY_DEFINED__
#define __FWDSHIMSLib_LIBRARY_DEFINED__

/* library FWDSHIMSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_FWDSHIMSLib;

EXTERN_C const CLSID CLSID_AcePowell;

#ifdef __cplusplus

class DECLSPEC_UUID("10712B75-370D-11D2-984B-00600823CFFB")
AcePowell;
#endif
#endif /* __FWDSHIMSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
