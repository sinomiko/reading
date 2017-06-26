/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Fri Aug 07 16:13:35 1998
 */
/* Compiler settings for primesvr.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __primesvr_h__
#define __primesvr_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IEnumPrimes_FWD_DEFINED__
#define __IEnumPrimes_FWD_DEFINED__
typedef interface IEnumPrimes IEnumPrimes;
#endif 	/* __IEnumPrimes_FWD_DEFINED__ */


#ifndef __IPrimeNumbers_FWD_DEFINED__
#define __IPrimeNumbers_FWD_DEFINED__
typedef interface IPrimeNumbers IPrimeNumbers;
#endif 	/* __IPrimeNumbers_FWD_DEFINED__ */


#ifndef __PrimeNumbers_FWD_DEFINED__
#define __PrimeNumbers_FWD_DEFINED__

#ifdef __cplusplus
typedef class PrimeNumbers PrimeNumbers;
#else
typedef struct PrimeNumbers PrimeNumbers;
#endif /* __cplusplus */

#endif 	/* __PrimeNumbers_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IEnumPrimes_INTERFACE_DEFINED__
#define __IEnumPrimes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumPrimes
 * at Fri Aug 07 16:13:35 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][object] */ 



EXTERN_C const IID IID_IEnumPrimes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("E64EDDDF-2B2C-11D2-983C-00600823CFFB")
    IEnumPrimes : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ long __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumPrimes __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumPrimesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumPrimes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumPrimes __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumPrimes __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumPrimes __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ long __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumPrimes __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumPrimes __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumPrimes __RPC_FAR * This,
            /* [out] */ IEnumPrimes __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IEnumPrimesVtbl;

    interface IEnumPrimes
    {
        CONST_VTBL struct IEnumPrimesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumPrimes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumPrimes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumPrimes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumPrimes_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumPrimes_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumPrimes_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumPrimes_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumPrimes_RemoteNext_Proxy( 
    IEnumPrimes __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ long __RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumPrimes_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPrimes_Skip_Proxy( 
    IEnumPrimes __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumPrimes_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPrimes_Reset_Proxy( 
    IEnumPrimes __RPC_FAR * This);


void __RPC_STUB IEnumPrimes_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumPrimes_Clone_Proxy( 
    IEnumPrimes __RPC_FAR * This,
    /* [out] */ IEnumPrimes __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IEnumPrimes_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumPrimes_INTERFACE_DEFINED__ */


#ifndef __IPrimeNumbers_INTERFACE_DEFINED__
#define __IPrimeNumbers_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPrimeNumbers
 * at Fri Aug 07 16:13:35 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][object] */ 



EXTERN_C const IID IID_IPrimeNumbers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("E64EDE01-2B2C-11D2-983C-00600823CFFB")
    IPrimeNumbers : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CalcPrimes( 
            /* [in] */ long min,
            /* [in] */ long max) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pnCount) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long n,
            /* [retval][out] */ long __RPC_FAR *pnPrime) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Enum( 
            /* [retval][out] */ IEnumPrimes __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPrimeNumbersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPrimeNumbers __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPrimeNumbers __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalcPrimes )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [in] */ long min,
            /* [in] */ long max);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pnCount);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [in] */ long n,
            /* [retval][out] */ long __RPC_FAR *pnPrime);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enum )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [retval][out] */ IEnumPrimes __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IPrimeNumbersVtbl;

    interface IPrimeNumbers
    {
        CONST_VTBL struct IPrimeNumbersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrimeNumbers_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPrimeNumbers_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPrimeNumbers_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPrimeNumbers_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPrimeNumbers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPrimeNumbers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPrimeNumbers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPrimeNumbers_CalcPrimes(This,min,max)	\
    (This)->lpVtbl -> CalcPrimes(This,min,max)

#define IPrimeNumbers_get_Count(This,pnCount)	\
    (This)->lpVtbl -> get_Count(This,pnCount)

#define IPrimeNumbers_get_Item(This,n,pnPrime)	\
    (This)->lpVtbl -> get_Item(This,n,pnPrime)

#define IPrimeNumbers_get_Enum(This,ppEnum)	\
    (This)->lpVtbl -> get_Enum(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPrimeNumbers_CalcPrimes_Proxy( 
    IPrimeNumbers __RPC_FAR * This,
    /* [in] */ long min,
    /* [in] */ long max);


void __RPC_STUB IPrimeNumbers_CalcPrimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IPrimeNumbers_get_Count_Proxy( 
    IPrimeNumbers __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pnCount);


void __RPC_STUB IPrimeNumbers_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IPrimeNumbers_get_Item_Proxy( 
    IPrimeNumbers __RPC_FAR * This,
    /* [in] */ long n,
    /* [retval][out] */ long __RPC_FAR *pnPrime);


void __RPC_STUB IPrimeNumbers_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IPrimeNumbers_get_Enum_Proxy( 
    IPrimeNumbers __RPC_FAR * This,
    /* [retval][out] */ IEnumPrimes __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IPrimeNumbers_get_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPrimeNumbers_INTERFACE_DEFINED__ */



#ifndef __PRIMESVRLib_LIBRARY_DEFINED__
#define __PRIMESVRLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: PRIMESVRLib
 * at Fri Aug 07 16:13:35 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_PRIMESVRLib;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_PrimeNumbers;

class DECLSPEC_UUID("E64EDE03-2B2C-11D2-983C-00600823CFFB")
PrimeNumbers;
#endif
#endif /* __PRIMESVRLib_LIBRARY_DEFINED__ */

/****************************************
 * Generated header for interface: __MIDL_itf_primesvr_0137
 * at Fri Aug 07 16:13:35 1998
 * using MIDL 3.01.75
 ****************************************/
/* [local] */ 


#ifdef __midl_proxy
static HRESULT STDMETHODCALLTYPE
IEnumPrimes_Next_Proxy(IEnumPrimes* This, ULONG celt, long* rgelt, ULONG* pceltFetched)
{
  ULONG cFetched;
  if( !pceltFetched && celt != 1 ) return E_INVALIDARG;
  return IEnumPrimes_RemoteNext_Proxy(This, celt, rgelt, pceltFetched ? pceltFetched : &cFetched);
}

static HRESULT STDMETHODCALLTYPE
IEnumPrimes_Next_Stub(IEnumPrimes* This, ULONG celt, long* rgelt, ULONG* pceltFetched)
{
  HRESULT hr = This->lpVtbl->Next(This, celt, rgelt, pceltFetched);
  if( hr == S_OK && celt == 1 ) *pceltFetched = 1;
  return hr;
}
#endif // __midl_proxy


extern RPC_IF_HANDLE __MIDL_itf_primesvr_0137_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_primesvr_0137_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* [local] */ HRESULT STDMETHODCALLTYPE IEnumPrimes_Next_Proxy( 
    IEnumPrimes __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ long __RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumPrimes_Next_Stub( 
    IEnumPrimes __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ long __RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
