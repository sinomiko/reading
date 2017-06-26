// stdafx.cpp : source file that includes just the standard includes
//  stdafx.pch will be the pre-compiled header
//  stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

#ifdef _ATL_STATIC_REGISTRY
#include <statreg.h>
#include <statreg.cpp>
#endif

#include <atlimpl.cpp>

// {0D22FF22-28CC-11d2-ABDD-00A0C9C8E50D}
const GUID CATID_ATLINTERNALS_SAMPLES = 
{ 0xd22ff22, 0x28cc, 0x11d2, { 0xab, 0xdd, 0x0, 0xa0, 0xc9, 0xc8, 0xe5, 0xd } };

// { 0c539790-12e4-11cf-b661-00aa004cd6d8 }
const GUID SID_SApplicationObject = 
{ 0x0c539790, 0x12e4, 0x11cf, { 0xb6, 0x61, 0x00, 0xaa, 0x00, 0x4c, 0xd6, 0xd8 } };

const IID IID_ICategorizeProperties =
{ 0x4d07fc10, 0xf931, 0x11ce, { 0xb0, 0x01, 0x00, 0xaa, 0x00, 0x68, 0x84, 0xe5}};
