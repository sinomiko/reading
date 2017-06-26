/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.01.75 */
/* at Fri Aug 14 01:49:20 1998
 */
/* Compiler settings for composition.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
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

const IID IID_IAcePowell = {0xADF259F7,0x5967,0x11D1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}};


const IID IID_IArtist = {0x2CEA24D0,0x5980,0x11d1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}};


const IID IID_ICowboy = {0x2CEA24D1,0x5980,0x11d1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}};


const IID IID_ICowboyEx = {0x6B438A90,0x59EE,0x11d1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}};


const IID LIBID_COMPOSITIONLib = {0xADF259EA,0x5967,0x11D1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}};


const CLSID CLSID_AcePowell = {0xADF259F8,0x5967,0x11D1,{0x96,0x87,0x00,0x60,0x08,0x19,0xB0,0x80}};


#ifdef __cplusplus
}
#endif

