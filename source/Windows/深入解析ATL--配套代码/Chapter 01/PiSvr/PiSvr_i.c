/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Nov 20 17:39:29 1998
 */
/* Compiler settings for D:\ATLBook\src\Chapter 01\PiSvr\PiSvr.idl:
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

const IID IID_ICalcPi = {0xDEC22F36,0xDD78,0x11D1,{0x97,0xFD,0x00,0x60,0x08,0x24,0x3C,0x8C}};


const IID IID_IAdvertiseMyself = {0x7B568195,0xF63B,0x11D1,{0x98,0x18,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const IID LIBID_PISVRLib = {0xDEC22F2A,0xDD78,0x11D1,{0x97,0xFD,0x00,0x60,0x08,0x24,0x3C,0x8C}};


const IID DIID__ICalcPiEvents = {0xDEC22F38,0xDD78,0x11D1,{0x97,0xFD,0x00,0x60,0x08,0x24,0x3C,0x8C}};


const CLSID CLSID_CalcPi = {0xDEC22F37,0xDD78,0x11D1,{0x97,0xFD,0x00,0x60,0x08,0x24,0x3C,0x8C}};


#ifdef __cplusplus
}
#endif

