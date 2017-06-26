/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Nov 22 21:26:27 1998
 */
/* Compiler settings for D:\ATLBook\src\Chapter 05\this\this.idl:
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

const IID IID_IBalloonMan = {0xCB693B56,0x80E2,0x11D2,{0x98,0x7D,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const IID IID_IBalloon = {0xCB693B58,0x80E2,0x11D2,{0x98,0x7D,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const IID IID_ISmartProxy = {0xCB693B5E,0x80E2,0x11D2,{0x98,0x7D,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const IID LIBID_THISLib = {0xCB693B4A,0x80E2,0x11D2,{0x98,0x7D,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const CLSID CLSID_BalloonMan = {0xCB693B57,0x80E2,0x11D2,{0x98,0x7D,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const CLSID CLSID_SmartProxy = {0xCB693B5F,0x80E2,0x11D2,{0x98,0x7D,0x00,0x60,0x08,0x23,0xCF,0xFB}};


#ifdef __cplusplus
}
#endif

