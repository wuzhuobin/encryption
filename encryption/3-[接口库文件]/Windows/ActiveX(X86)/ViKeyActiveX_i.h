

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Mar 01 13:27:56 2016
 */
/* Compiler settings for .\ViKeyActiveX.idl:
    Oicf, W1, Zp8, env=Win64 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __ViKeyActiveX_i_h__
#define __ViKeyActiveX_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IViKeyInterface_FWD_DEFINED__
#define __IViKeyInterface_FWD_DEFINED__
typedef interface IViKeyInterface IViKeyInterface;
#endif 	/* __IViKeyInterface_FWD_DEFINED__ */


#ifndef __ViKeyInterface_FWD_DEFINED__
#define __ViKeyInterface_FWD_DEFINED__

#ifdef __cplusplus
typedef class ViKeyInterface ViKeyInterface;
#else
typedef struct ViKeyInterface ViKeyInterface;
#endif /* __cplusplus */

#endif 	/* __ViKeyInterface_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IViKeyInterface_INTERFACE_DEFINED__
#define __IViKeyInterface_INTERFACE_DEFINED__

/* interface IViKeyInterface */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IViKeyInterface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28F05B29-2474-42BC-BCC1-43151D8C3FB4")
    IViKeyInterface : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyFind( 
            /* [retval][out] */ DWORD *pdwCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyGetHID( 
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pdwHID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyLogoff( 
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeySetUserPassWordAttempt( 
            /* [in] */ WORD Index,
            /* [in] */ BYTE wAttempt,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeySetAdminPassWordAttempt( 
            /* [in] */ WORD Index,
            /* [in] */ BYTE wAttempt,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyGetUserPassWordAttempt( 
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyGetAdminPassWordAttempt( 
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeySetNewPassword( 
            /* [in] */ WORD Index,
            /* [in] */ DWORD PasswordFactor,
            /* [out] */ WORD *P1,
            /* [out] */ WORD *P2,
            /* [out] */ WORD *P3,
            /* [out] */ WORD *P4,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyReadData( 
            /* [in] */ WORD Index,
            /* [in] */ WORD Addr,
            /* [in] */ WORD Length,
            /* [retval][out] */ BSTR *buffer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyWriteData( 
            /* [in] */ WORD Index,
            /* [in] */ WORD Addr,
            /* [in] */ WORD Length,
            /* [in] */ BSTR buffer,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IViKeyRandom( 
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeySeed( 
            /* [in] */ WORD Index,
            /* [in] */ DWORD lp1,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IViKeyDecraseModule( 
            /* [in] */ WORD Index,
            /* [in] */ WORD ModuleIndex,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IViKeyGetModule( 
            /* [in] */ WORD Index,
            /* [in] */ WORD ModuleIndex,
            /* [in] */ WORD *pValue,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IViKeySetModule( 
            /* [in] */ WORD Index,
            /* [in] */ WORD ModuleIndex,
            /* [in] */ WORD Value,
            /* [in] */ WORD Mode,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IViKeyCheckModule( 
            /* [in] */ WORD Index,
            /* [in] */ WORD ModuleIndex,
            /* [out] */ WORD *IsZero,
            /* [out] */ WORD *CanDecrase,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeySetMD5Key( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pMD5Key,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyHmacMD5( 
            /* [in] */ WORD Index,
            WORD Length,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pMd5Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IViKeyGetError( 
            /* [retval][out] */ DWORD *pError) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetVersion( 
            /* [retval][out] */ BSTR *pVersion) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeySetAutoRun( 
            /* [in] */ WORD Index,
            BYTE Mode,
            /* [in] */ BSTR pText,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeySetSoftIDString( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyGetSoftIDString( 
            /* [in] */ WORD Index,
            /* [retval][out] */ BSTR *pText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyUserLogin( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pUserPw,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyAdminLogin( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pAdminPw,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyGetCurrentPcChkData( 
            /* [in] */ WORD Index,
            /* [retval][out] */ BSTR *pText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeySetPcChkData( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyClearPcChkData( 
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyIsThisPc( 
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyResetPassword( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pNewUserPassWord,
            /* [in] */ BSTR pNewAdminPassWord,
            /* [retval][out] */ DWORD *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikey3DesEncrypt( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikey3DesDecrypt( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyDesEncrypt( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVikeyDesDecrypt( 
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IViKeyInterfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IViKeyInterface * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IViKeyInterface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IViKeyInterface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IViKeyInterface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IViKeyInterface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IViKeyInterface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IViKeyInterface * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyFind )( 
            IViKeyInterface * This,
            /* [retval][out] */ DWORD *pdwCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyGetHID )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pdwHID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyLogoff )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeySetUserPassWordAttempt )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BYTE wAttempt,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeySetAdminPassWordAttempt )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BYTE wAttempt,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyGetUserPassWordAttempt )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyGetAdminPassWordAttempt )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeySetNewPassword )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ DWORD PasswordFactor,
            /* [out] */ WORD *P1,
            /* [out] */ WORD *P2,
            /* [out] */ WORD *P3,
            /* [out] */ WORD *P4,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyReadData )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ WORD Addr,
            /* [in] */ WORD Length,
            /* [retval][out] */ BSTR *buffer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyWriteData )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ WORD Addr,
            /* [in] */ WORD Length,
            /* [in] */ BSTR buffer,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IViKeyRandom )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeySeed )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ DWORD lp1,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IViKeyDecraseModule )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ WORD ModuleIndex,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IViKeyGetModule )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ WORD ModuleIndex,
            /* [in] */ WORD *pValue,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IViKeySetModule )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ WORD ModuleIndex,
            /* [in] */ WORD Value,
            /* [in] */ WORD Mode,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IViKeyCheckModule )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ WORD ModuleIndex,
            /* [out] */ WORD *IsZero,
            /* [out] */ WORD *CanDecrase,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeySetMD5Key )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pMD5Key,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyHmacMD5 )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            WORD Length,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pMd5Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IViKeyGetError )( 
            IViKeyInterface * This,
            /* [retval][out] */ DWORD *pError);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IGetVersion )( 
            IViKeyInterface * This,
            /* [retval][out] */ BSTR *pVersion);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeySetAutoRun )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            BYTE Mode,
            /* [in] */ BSTR pText,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeySetSoftIDString )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyGetSoftIDString )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [retval][out] */ BSTR *pText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyUserLogin )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pUserPw,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyAdminLogin )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pAdminPw,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyGetCurrentPcChkData )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [retval][out] */ BSTR *pText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeySetPcChkData )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyClearPcChkData )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyIsThisPc )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyResetPassword )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pNewUserPassWord,
            /* [in] */ BSTR pNewAdminPassWord,
            /* [retval][out] */ DWORD *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikey3DesEncrypt )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikey3DesDecrypt )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyDesEncrypt )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IVikeyDesDecrypt )( 
            IViKeyInterface * This,
            /* [in] */ WORD Index,
            /* [in] */ BSTR pText,
            /* [retval][out] */ BSTR *pResult);
        
        END_INTERFACE
    } IViKeyInterfaceVtbl;

    interface IViKeyInterface
    {
        CONST_VTBL struct IViKeyInterfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViKeyInterface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IViKeyInterface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IViKeyInterface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IViKeyInterface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IViKeyInterface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IViKeyInterface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IViKeyInterface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IViKeyInterface_IVikeyFind(This,pdwCount)	\
    ( (This)->lpVtbl -> IVikeyFind(This,pdwCount) ) 

#define IViKeyInterface_IVikeyGetHID(This,Index,pdwHID)	\
    ( (This)->lpVtbl -> IVikeyGetHID(This,Index,pdwHID) ) 

#define IViKeyInterface_IVikeyLogoff(This,Index,pResult)	\
    ( (This)->lpVtbl -> IVikeyLogoff(This,Index,pResult) ) 

#define IViKeyInterface_IVikeySetUserPassWordAttempt(This,Index,wAttempt,pResult)	\
    ( (This)->lpVtbl -> IVikeySetUserPassWordAttempt(This,Index,wAttempt,pResult) ) 

#define IViKeyInterface_IVikeySetAdminPassWordAttempt(This,Index,wAttempt,pResult)	\
    ( (This)->lpVtbl -> IVikeySetAdminPassWordAttempt(This,Index,wAttempt,pResult) ) 

#define IViKeyInterface_IVikeyGetUserPassWordAttempt(This,Index,pResult)	\
    ( (This)->lpVtbl -> IVikeyGetUserPassWordAttempt(This,Index,pResult) ) 

#define IViKeyInterface_IVikeyGetAdminPassWordAttempt(This,Index,pResult)	\
    ( (This)->lpVtbl -> IVikeyGetAdminPassWordAttempt(This,Index,pResult) ) 

#define IViKeyInterface_IVikeySetNewPassword(This,Index,PasswordFactor,P1,P2,P3,P4,pResult)	\
    ( (This)->lpVtbl -> IVikeySetNewPassword(This,Index,PasswordFactor,P1,P2,P3,P4,pResult) ) 

#define IViKeyInterface_IVikeyReadData(This,Index,Addr,Length,buffer)	\
    ( (This)->lpVtbl -> IVikeyReadData(This,Index,Addr,Length,buffer) ) 

#define IViKeyInterface_IVikeyWriteData(This,Index,Addr,Length,buffer,pResult)	\
    ( (This)->lpVtbl -> IVikeyWriteData(This,Index,Addr,Length,buffer,pResult) ) 

#define IViKeyInterface_IViKeyRandom(This,Index,pResult)	\
    ( (This)->lpVtbl -> IViKeyRandom(This,Index,pResult) ) 

#define IViKeyInterface_IVikeySeed(This,Index,lp1,pResult)	\
    ( (This)->lpVtbl -> IVikeySeed(This,Index,lp1,pResult) ) 

#define IViKeyInterface_IViKeyDecraseModule(This,Index,ModuleIndex,pResult)	\
    ( (This)->lpVtbl -> IViKeyDecraseModule(This,Index,ModuleIndex,pResult) ) 

#define IViKeyInterface_IViKeyGetModule(This,Index,ModuleIndex,pValue,pResult)	\
    ( (This)->lpVtbl -> IViKeyGetModule(This,Index,ModuleIndex,pValue,pResult) ) 

#define IViKeyInterface_IViKeySetModule(This,Index,ModuleIndex,Value,Mode,pResult)	\
    ( (This)->lpVtbl -> IViKeySetModule(This,Index,ModuleIndex,Value,Mode,pResult) ) 

#define IViKeyInterface_IViKeyCheckModule(This,Index,ModuleIndex,IsZero,CanDecrase,pResult)	\
    ( (This)->lpVtbl -> IViKeyCheckModule(This,Index,ModuleIndex,IsZero,CanDecrase,pResult) ) 

#define IViKeyInterface_IVikeySetMD5Key(This,Index,pMD5Key,pResult)	\
    ( (This)->lpVtbl -> IVikeySetMD5Key(This,Index,pMD5Key,pResult) ) 

#define IViKeyInterface_IVikeyHmacMD5(This,Index,Length,pText,pMd5Result)	\
    ( (This)->lpVtbl -> IVikeyHmacMD5(This,Index,Length,pText,pMd5Result) ) 

#define IViKeyInterface_IViKeyGetError(This,pError)	\
    ( (This)->lpVtbl -> IViKeyGetError(This,pError) ) 

#define IViKeyInterface_IGetVersion(This,pVersion)	\
    ( (This)->lpVtbl -> IGetVersion(This,pVersion) ) 

#define IViKeyInterface_IVikeySetAutoRun(This,Index,Mode,pText,pResult)	\
    ( (This)->lpVtbl -> IVikeySetAutoRun(This,Index,Mode,pText,pResult) ) 

#define IViKeyInterface_IVikeySetSoftIDString(This,Index,pText,pResult)	\
    ( (This)->lpVtbl -> IVikeySetSoftIDString(This,Index,pText,pResult) ) 

#define IViKeyInterface_IVikeyGetSoftIDString(This,Index,pText)	\
    ( (This)->lpVtbl -> IVikeyGetSoftIDString(This,Index,pText) ) 

#define IViKeyInterface_IVikeyUserLogin(This,Index,pUserPw,pResult)	\
    ( (This)->lpVtbl -> IVikeyUserLogin(This,Index,pUserPw,pResult) ) 

#define IViKeyInterface_IVikeyAdminLogin(This,Index,pAdminPw,pResult)	\
    ( (This)->lpVtbl -> IVikeyAdminLogin(This,Index,pAdminPw,pResult) ) 

#define IViKeyInterface_IVikeyGetCurrentPcChkData(This,Index,pText)	\
    ( (This)->lpVtbl -> IVikeyGetCurrentPcChkData(This,Index,pText) ) 

#define IViKeyInterface_IVikeySetPcChkData(This,Index,pText,pResult)	\
    ( (This)->lpVtbl -> IVikeySetPcChkData(This,Index,pText,pResult) ) 

#define IViKeyInterface_IVikeyClearPcChkData(This,Index,pResult)	\
    ( (This)->lpVtbl -> IVikeyClearPcChkData(This,Index,pResult) ) 

#define IViKeyInterface_IVikeyIsThisPc(This,Index,pResult)	\
    ( (This)->lpVtbl -> IVikeyIsThisPc(This,Index,pResult) ) 

#define IViKeyInterface_IVikeyResetPassword(This,Index,pNewUserPassWord,pNewAdminPassWord,pResult)	\
    ( (This)->lpVtbl -> IVikeyResetPassword(This,Index,pNewUserPassWord,pNewAdminPassWord,pResult) ) 

#define IViKeyInterface_IVikey3DesEncrypt(This,Index,pText,pResult)	\
    ( (This)->lpVtbl -> IVikey3DesEncrypt(This,Index,pText,pResult) ) 

#define IViKeyInterface_IVikey3DesDecrypt(This,Index,pText,pResult)	\
    ( (This)->lpVtbl -> IVikey3DesDecrypt(This,Index,pText,pResult) ) 

#define IViKeyInterface_IVikeyDesEncrypt(This,Index,pText,pResult)	\
    ( (This)->lpVtbl -> IVikeyDesEncrypt(This,Index,pText,pResult) ) 

#define IViKeyInterface_IVikeyDesDecrypt(This,Index,pText,pResult)	\
    ( (This)->lpVtbl -> IVikeyDesDecrypt(This,Index,pText,pResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IViKeyInterface_INTERFACE_DEFINED__ */



#ifndef __ViKeyActiveXLib_LIBRARY_DEFINED__
#define __ViKeyActiveXLib_LIBRARY_DEFINED__

/* library ViKeyActiveXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ViKeyActiveXLib;

EXTERN_C const CLSID CLSID_ViKeyInterface;

#ifdef __cplusplus

class DECLSPEC_UUID("31569F34-BDD5-4112-BEBB-A6AC7ECBB10A")
ViKeyInterface;
#endif
#endif /* __ViKeyActiveXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


