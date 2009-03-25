/*******************************************************************************

    Copyright (C) Streamlet. All rights reserved.

    File Name:   Main.cpp
    Author:      Streamlet
    Create Time: 2009-03-25
    Description: 

    Version history:



*******************************************************************************/


#include "Encoding.h"
#include <assert.h>
// DebugNew.h might be in conflict with some other codes, such as STL.
// If you use STL, do include STL header files before DebugNew.h.
#include "DebugNew.h"


int main()
{
    wchar_t wStr[100] = L"ºÃµÄ", wStr2[100] = L"";
    char utf8Str[100];
    unsigned long size = 100;

    CEncoding::WStringToUTF8String(wStr, utf8Str, &size);
    CEncoding::UTF8StringToWString(utf8Str, wStr2, &size);

    return 0;
}


