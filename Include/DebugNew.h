/*******************************************************************************

    Copyright (C) Streamlet. All rights reserved.

    File Name:   DebugNew.h
    Author:      Streamlet
    Create Time: 2009-03-22
    Description: Help to detect memory leak

    Version history:
        2007-12-29 Created by a staff of Kingsoft
        2009-03-22 Modified by Streamlet


*******************************************************************************/

#ifndef __DEBUGNEW_H_33164B60_A660_4B88_AEA3_270C97F24B12_INCLUDED__
#define __DEBUGNEW_H_33164B60_A660_4B88_AEA3_270C97F24B12_INCLUDED__


#ifdef  __cplusplus

    #ifdef _DEBUG

        #include <crtdbg.h>

        // Overload operator new
        inline void * __cdecl operator new(size_t nSize, const char * lpszFileName, int nLine)
        {
            int nFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
            nFlag |= _CRTDBG_LEAK_CHECK_DF;
            _CrtSetDbgFlag(nFlag);

            return ::operator new(nSize, _NORMAL_BLOCK, lpszFileName, nLine);
        };

        #define DEBUG_NEW new(__FILE__, __LINE__)
        #define new DEBUG_NEW

        // Overload operator delete (, or the compiler will give warning.)
        inline void __cdecl operator delete(void *pData, const char * lpszFileName, int nLine)
        {
            ::operator delete(pData);
        }

        #include <assert.h>

    #endif  // #ifdef _DEBUG

#endif  // #ifdef  __cplusplus

       
#endif // #ifndef __DEBUGNEW_H_33164B60_A660_4B88_AEA3_270C97F24B12_INCLUDED__
