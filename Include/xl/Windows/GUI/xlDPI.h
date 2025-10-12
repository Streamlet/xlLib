//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlDPI.h
//    Author:      Streamlet
//    Create Time: 2016-03-04
//    Description: 
//
//------------------------------------------------------------------------------

#ifndef __XLDPI_H_7D8F7574_55C0_4AAD_A5D1_347D8FF393CD_INCLUDED__
#define __XLDPI_H_7D8F7574_55C0_4AAD_A5D1_347D8FF393CD_INCLUDED__


#include "../../xlDef.h"
#include "../xlWin32Ver.h"
#include "../../Common/Meta/xlScopeExit.h"
#include <tchar.h>

namespace xl
{
    namespace Windows
    {
        class Dpi
        {
        public:
            inline Dpi() : m_nDpiX(0), m_nDpiY(0)
            {
                SetDpiAwareness();
                Update();
            }

            inline ~Dpi()
            {

            }

        public:
            inline bool Update()
            {
                HDC hDC = GetDC(nullptr);
                if (hDC == nullptr)
                {
                    return false;
                }

                m_nDpiX = GetDeviceCaps(hDC, LOGPIXELSX);
                m_nDpiY = GetDeviceCaps(hDC, LOGPIXELSY);

                ReleaseDC(nullptr, hDC);

                return true;
            }

        public:
            inline int TransformX(int x)
            {
                return x * m_nDpiX / 96;
            }

            inline int TransformY(int y)
            {
                return y * m_nDpiY / 96;
            }

            inline int RestoreX(int x)
            {
                return x * 96 / m_nDpiX;
            }

            inline int RestoreY(int y)
            {
                return y * 96 / m_nDpiY;
            }

        private:
            bool SetDpiAwareness()
            {
                typedef BOOL (WINAPI *FNSetProcessDPIAware)();
                HMODULE hUser32 = LoadLibrary(_T("user32.dll"));
                if (hUser32 == NULL)
                {
                    return false;
                }
                XL_ON_BLOCK_EXIT(FreeLibrary, hUser32);
                FNSetProcessDPIAware fnSetProcessDPIAware = (FNSetProcessDPIAware)GetProcAddress(hUser32, "SetProcessDPIAware");
                if (fnSetProcessDPIAware == NULL)
                {
                    return false;
                }
                return !!fnSetProcessDPIAware();
            }

        private:
            int m_nDpiX;
            int m_nDpiY;
        };

        __declspec(selectany) Dpi g_dpi;

#define XL_DPI_UPDATE() (xl::Windows::g_dpi.Update())
#define XL_DPI_X(x)     (xl::Windows::g_dpi.TransformX(x))
#define XL_DPI_Y(y)     (xl::Windows::g_dpi.TransformY(y))
#define XL_DPI_R_X(x)     (xl::Windows::g_dpi.RestoreX(x))
#define XL_DPI_R_Y(y)     (xl::Windows::g_dpi.RestoreY(y))

    } // namespace Windows
} // namespace xl

#endif // #ifndef __XLDPI_H_7D8F7574_55C0_4AAD_A5D1_347D8FF393CD_INCLUDED__
