/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Aug 15 22:56:35 1998
 */
/* Compiler settings for D:\ATLBook\src\Chapter 08\primesvr for VB\primesvr.idl:
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

#ifndef __primesvr_h__
#define __primesvr_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPrimeNumbers_FWD_DEFINED__
#define __IPrimeNumbers_FWD_DEFINED__
typedef interface IPrimeNumbers IPrimeNumbers;
#endif 	/* __IPrimeNumbers_FWD_DEFINED__ */


#ifndef __IPrimeNumberWords_FWD_DEFINED__
#define __IPrimeNumberWords_FWD_DEFINED__
typedef interface IPrimeNumberWords IPrimeNumberWords;
#endif 	/* __IPrimeNumberWords_FWD_DEFINED__ */


#ifndef __PrimeNumbers_FWD_DEFINED__
#define __PrimeNumbers_FWD_DEFINED__

#ifdef __cplusplus
typedef class PrimeNumbers PrimeNumbers;
#else
typedef struct PrimeNumbers PrimeNumbers;
#endif /* __cplusplus */

#endif 	/* __PrimeNumbers_FWD_DEFINED__ */


#ifndef __PrimeNumberWords_FWD_DEFINED__
#define __PrimeNumberWords_FWD_DEFINED__

#ifdef __cplusplus
typedef class PrimeNumberWords PrimeNumberWords;
#else
typedef struct PrimeNumberWords PrimeNumberWords;
#endif /* __cplusplus */

#endif 	/* __PrimeNumberWords_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPrimeNumbers_INTERFACE_DEFINED__
#define __IPrimeNumbers_INTERFACE_DEFINED__

/* interface IPrimeNumbers */
/* [unique][helpstring][uuid][dual][object] */ 


EXTERN_C const IID IID_IPrimeNumbers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E64EDDDD-2B2C-11D2-983C-00600823CFFB")
    IPrimeNumbers : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CalcPrimes( 
            /* [in] */ long min,
            /* [in] */ long max) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pnCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long n,
            /* [retval][out] */ long __RPC_FAR *pnPrime) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum) = 0;
        
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [in] */ long n,
            /* [retval][out] */ long __RPC_FAR *pnPrime);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IPrimeNumbers __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
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

#define IPrimeNumbers_get__NewEnum(This,ppunkEnum)	\
    (This)->lpVtbl -> get__NewEnum(This,ppunkEnum)

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


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IPrimeNumbers_get_Item_Proxy( 
    IPrimeNumbers __RPC_FAR * This,
    /* [in] */ long n,
    /* [retval][out] */ long __RPC_FAR *pnPrime);


void __RPC_STUB IPrimeNumbers_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IPrimeNumbers_get__NewEnum_Proxy( 
    IPrimeNumbers __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);


void __RPC_STUB IPrimeNumbers_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPrimeNumbers_INTERFACE_DEFINED__ */


#ifndef __IPrimeNumberWords_INTERFACE_DEFINED__
#define __IPrimeNumberWords_INTERFACE_DEFINED__

/* interface IPrimeNumberWords */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPrimeNumberWords;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("56CD9686-3398-11D2-9848-00600823CFFB")
    IPrimeNumberWords : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CalcPrimes( 
            /* [in] */ long min,
            /* [in] */ long max) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pnCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long n,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrPrimeWord) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPrimeNumberWordsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPrimeNumberWords __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPrimeNumberWords __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPrimeNumberWords __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPrimeNumberWords __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPrimeNumberWords __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPrimeNumberWords __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPrimeNumberWords __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalcPrimes )( 
            IPrimeNumberWords __RPC_FAR * This,
            /* [in] */ long min,
            /* [in] */ long max);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IPrimeNumberWords __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pnCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IPrimeNumberWords __RPC_FAR * This,
            /* [in] */ long n,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrPrimeWord);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IPrimeNumberWords __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);
        
        END_INTERFACE
    } IPrimeNumberWordsVtbl;

    interface IPrimeNumberWords
    {
        CONST_VTBL struct IPrimeNumberWordsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrimeNumberWords_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPrimeNumberWords_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPrimeNumberWords_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPrimeNumberWords_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPrimeNumberWords_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPrimeNumberWords_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPrimeNumberWords_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPrimeNumberWords_CalcPrimes(This,min,max)	\
    (This)->lpVtbl -> CalcPrimes(This,min,max)

#define IPrimeNumberWords_get_Count(This,pnCount)	\
    (This)->lpVtbl -> get_Count(This,pnCount)

#define IPrimeNumberWords_get_Item(This,n,pbstrPrimeWord)	\
    (This)->lpVtbl -> get_Item(This,n,pbstrPrimeWord)

#define IPrimeNumberWords_get__NewEnum(This,ppunkEnum)	\
    (This)->lpVtbl -> get__NewEnum(This,ppunkEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPrimeNumberWords_CalcPrimes_Proxy( 
    IPrimeNumberWords __RPC_FAR * This,
    /* [in] */ long min,
    /* [in] */ long max);


void __RPC_STUB IPrimeNumberWords_CalcPrimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IPrimeNumberWords_get_Count_Proxy( 
    IPrimeNumberWords __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pnCount);


void __RPC_STUB IPrimeNumberWords_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IPrimeNumberWords_get_Item_Proxy( 
    IPrimeNumberWords __RPC_FAR * This,
    /* [in] */ long n,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrPrimeWord);


void __RPC_STUB IPrimeNumberWords_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IPrimeNumberWords_get__NewEnum_Proxy( 
    IPrimeNumberWords __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunkEnum);


void __RPC_STUB IPrimeNumberWords_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPrimeNumberWords_INTERFACE_DEFINED__ */



#ifndef __PRIMESVRLib_LIBRARY_DEFINED__
#define __PRIMESVRLib_LIBRARY_DEFINED__

/* library PRIMESVRLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_PRIMESVRLib;

EXTERN_C const CLSID CLSID_PrimeNumbers;

#ifdef __cplusplus

class DECLSPEC_UUID("E64EDDDE-2B2C-11D2-983C-00600823CFFB")
PrimeNumbers;
#endif

EXTERN_C const CLSID CLSID_PrimeNumberWords;

#ifdef __cplusplus

class DECLSPEC_UUID("56CD9687-3398-11D2-9848-00600823CFFB")
PrimeNumberWords;
#endif
#endif /* __PRIMESVRLib_LIBRARY_DEFINED__ */

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
