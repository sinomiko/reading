/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Dec 14 23:47:45 1998
 */
/* Compiler settings for D:\ATLBook\src\Chapter 11\Container\Controls\Controls.idl:
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

const IID IID_IDartBoard = {0x0700D3F3,0x913F,0x11D2,{0x98,0x87,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const IID LIBID_CONTROLSLib = {0x0700D3E7,0x913F,0x11D2,{0x98,0x87,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const IID DIID__IDartBoardEvents = {0x0700D3F5,0x913F,0x11D2,{0x98,0x87,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const IID IID_ISmartDartBoard = {0x76FFDC15,0x93C7,0x11D2,{0x98,0x89,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const IID IID_ISmartDartBoardUI = {0x76FFDC17,0x93C7,0x11D2,{0x98,0x89,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const CLSID CLSID_DartBoard = {0x0700D3F4,0x913F,0x11D2,{0x98,0x87,0x00,0x60,0x08,0x23,0xCF,0xFB}};


const CLSID CLSID_SmartDartBoard = {0x76FFDC16,0x93C7,0x11D2,{0x98,0x89,0x00,0x60,0x08,0x23,0xCF,0xFB}};


#ifdef __cplusplus
}
#endif

