/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0158 */
/* at Thu Dec 18 02:55:51 1997
 */
/* Compiler settings for D:\ATLBook\src\Chapter 03\Birds\Birds.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IPenguin = {0x941666C4,0x778E,0x11D1,{0x98,0x2D,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const IID LIBID_BIRDSLib = {0x941666B8,0x778E,0x11D1,{0x98,0x2D,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const CLSID CLSID_Penguin = {0x941666C5,0x778E,0x11D1,{0x98,0x2D,0x00,0x60,0x08,0x23,0xCF,0xFB}};


#ifdef __cplusplus
}
#endif

