//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlWindow.h
//    Author:      Streamlet
//    Create Time: 2011-02-11
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __XLWINDOW_H_0646591E_8D6A_44AA_A773_084A53A0B190_INCLUDED__
#define __XLWINDOW_H_0646591E_8D6A_44AA_A773_084A53A0B190_INCLUDED__


#include <xl/Win32/GUI/xlWindowBase.h>

#pragma region WindowsAPIMacroRedefine

#ifdef GetWindowLong
#undef GetWindowLong
inline LONG WINAPI GetWindowLong(__in HWND hWnd, __in int nIndex)
{
#ifdef UNICODE
    return GetWindowLongW(hWnd, nIndex);
#else
    return GetWindowLongA(hWnd, nIndex);
#endif
}
#endif

#ifdef SetWindowLong
#undef SetWindowLong
inline LONG WINAPI SetWindowLong(__in HWND hWnd, __in int nIndex, __in LONG dwNewLong)
{
#ifdef UNICODE
    return SetWindowLongW(hWnd, nIndex, dwNewLong);
#else
    return SetWindowLongA(hWnd, nIndex, dwNewLong);
#endif
}
#endif

#ifdef GetWindowLongPtr
#undef GetWindowLongPtr
inline LONG_PTR WINAPI GetWindowLongPtr(__in HWND hWnd, __in int nIndex)
{
#ifdef UNICODE
    return GetWindowLongPtrW(hWnd, nIndex);
#else
    return GetWindowLongPtrA(hWnd, nIndex);
#endif
}
#endif

#ifdef SetWindowLongPtr
#undef SetWindowLongPtr
inline LONG_PTR WINAPI SetWindowLongPtr(__in HWND hWnd, __in int nIndex, __in LONG_PTR dwNewLong)
{
#ifdef UNICODE
    return SetWindowLongPtrW(hWnd, nIndex, dwNewLong);
#else
    return SetWindowLongPtrA(hWnd, nIndex, dwNewLong);
#endif
}
#endif

#ifdef SendMessage
#undef SendMessage
inline LRESULT WINAPI SendMessage(__in HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam)
{
#ifdef UNICODE
    return SendMessageW(hWnd, Msg, wParam, lParam);
#else
    return SendMessageA(hWnd, Msg, wParam, lParam);
#endif
}
#endif

#ifdef PostMessage
#undef PostMessage
inline BOOL WINAPI PostMessage(__in HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam)
{
#ifdef UNICODE
    return PostMessageW(hWnd, Msg, wParam, lParam);
#else
    return PostMessageA(hWnd, Msg, wParam, lParam);
#endif
}
#endif

#ifdef SendNotifyMessage
#undef SendNotifyMessage
inline BOOL WINAPI SendNotifyMessage(__in HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam)
{
#ifdef UNICODE
    return SendNotifyMessageW(hWnd, Msg, wParam, lParam);
#else
    return SendNotifyMessageA(hWnd, Msg, wParam, lParam);
#endif
}
#endif

#ifdef GetWindowTextLength
#undef GetWindowTextLength
inline int WINAPI GetWindowTextLength(__in HWND hWnd)
{
#ifdef UNICODE
    return GetWindowTextLengthW(hWnd);
#else
    return GetWindowTextLengthA(hWnd);
#endif
}
#endif

#ifdef GetWindowText
#undef GetWindowText
inline int WINAPI GetWindowText(__in HWND hWnd, __out_ecount(nMaxCount) LPWSTR lpString, __in int nMaxCount)
{
#ifdef UNICODE
    return GetWindowTextW(hWnd, lpString, nMaxCount);
#else
    return GetWindowTextA(hWnd, lpString, nMaxCount);
#endif
}
#endif

#ifdef SetWindowText
#undef SetWindowText
inline int WINAPI SetWindowText(__in HWND hWnd, __in_opt LPCWSTR lpString)
{
#ifdef UNICODE
    return SetWindowTextW(hWnd, lpString);
#else
    return SetWindowTextA(hWnd, lpString);
#endif
}
#endif

#ifdef MessageBox
#undef MessageBox
inline int WINAPI MessageBox(__in_opt HWND hWnd, __in_opt LPCWSTR lpText, __in_opt LPCWSTR lpCaption, __in UINT uType)
{
#ifdef UNICODE
    return MessageBoxW(hWnd, lpText, lpCaption, uType);
#else
    return MessageBoxA(hWnd, lpText, lpCaption, uType);
#endif
}
#endif

#ifdef WinHelp
#undef WinHelp
inline BOOL WINAPI WinHelp(__in_opt HWND hWndMain, __in_opt LPCWSTR lpszHelp, __in UINT uCommand, __in ULONG_PTR dwData)
{
#ifdef UNICODE
    return WinHelpW(hWndMain, lpszHelp, uCommand, dwData);
#else
    return WinHelpA(hWndMain, lpszHelp, uCommand, dwData);
#endif
}
#endif
#pragma endregion

namespace xl
{
    class Window : public WindowBase
    {
    public:
        Window() :
            WindowBase(),
            m_hFontCaption(nullptr),
            m_hFontSmallCaption(nullptr),
            m_hFontMenu(nullptr),
            m_hFontStatus(nullptr),
            m_hFontMessage(nullptr)
        {

        }

        ~Window()
        {

        }

    private:
        Window(const Window &);
        Window &operator =(const Window &);

    protected:
        static LPCTSTR GetClassName()
        {
            return _T("xlWindow");
        }
        
    public:
        bool Create(int nWidth = CW_USEDEFAULT,
                    int nHeight = CW_USEDEFAULT,
                    int x = CW_USEDEFAULT,
                    int y = CW_USEDEFAULT,
                    WindowBase *pParent = nullptr,
                    LPCTSTR lpszClassName = GetClassName(),
                    DWORD dwStyle = WS_OVERLAPPEDWINDOW | DS_SETFONT,
                    DWORD dwExStyle = 0,
                    HMENU hMenu = nullptr,
                    HINSTANCE hInstance = nullptr)
        {
            if (!WindowBase::Create(lpszClassName,
                                    nullptr,
                                    dwStyle,
                                    dwExStyle,
                                    x,
                                    y,
                                    nWidth,
                                    nHeight,
                                    pParent,
                                    hMenu,
                                    hInstance,
                                    nullptr))
            {
                return false;
            }

            ZeroMemory(&m_tagNONCLIENTMETRICSW, sizeof(m_tagNONCLIENTMETRICSW));
            m_tagNONCLIENTMETRICSW.cbSize = sizeof(m_tagNONCLIENTMETRICSW);

            SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICS), &m_tagNONCLIENTMETRICSW, 0);

//             m_hFontCaption      = CreateFontIndirect(&m_tagNONCLIENTMETRICSW.lfCaptionFont);
//             m_hFontSmallCaption = CreateFontIndirect(&m_tagNONCLIENTMETRICSW.lfSmCaptionFont);
//             m_hFontMenu         = CreateFontIndirect(&m_tagNONCLIENTMETRICSW.lfMenuFont);
//             m_hFontStatus       = CreateFontIndirect(&m_tagNONCLIENTMETRICSW.lfStatusFont);
            m_hFontMessage      = CreateFontIndirect(&m_tagNONCLIENTMETRICSW.lfMessageFont);

            SetFont(m_hFontMessage, FALSE);

            return true;
        }

        bool Destroy()
        {
//             DeleteObject(m_hFontCaption);
//             DeleteObject(m_hFontSmallCaption);
//             DeleteObject(m_hFontMenu);
//             DeleteObject(m_hFontStatus);
            DeleteObject(m_hFontMessage);

            if (!WindowBase::Destroy())
            {
                return false;
            }

            return true;
        }

    protected:
        NONCLIENTMETRICS m_tagNONCLIENTMETRICSW;
        HFONT m_hFontCaption;
        HFONT m_hFontSmallCaption;
        HFONT m_hFontMenu;
        HFONT m_hFontStatus;
        HFONT m_hFontMessage;

    public: // Attributes

        HWND GetHWND()
        {
            return m_hWnd;
        }

        DWORD GetStyle()
        {
            return (DWORD)::GetWindowLong(m_hWnd, GWL_STYLE);
        }

        DWORD SetStyle(DWORD dwStyle)
        {
            return (DWORD)::SetWindowLong(m_hWnd, GWL_STYLE, (LONG)dwStyle);
        }

        DWORD GetExStyle()
        {
            return (DWORD)::GetWindowLong(m_hWnd, GWL_EXSTYLE);
        }

        DWORD SetExStyle(DWORD dwExStyle)
        {
            return (DWORD)::SetWindowLong(m_hWnd, GWL_EXSTYLE, (LONG)dwExStyle);
        }

        LONG GetWindowLong(int nIndex)
        {
            return ::GetWindowLong(m_hWnd, nIndex);
        }

        LONG SetWindowLong(int nIndex, LONG dwNewLong)
        {
            return ::SetWindowLong(m_hWnd, nIndex, dwNewLong);
        }

        LONG_PTR GetWindowLongPtr(int nIndex)
        {
	        return ::GetWindowLongPtr(m_hWnd, nIndex);
        }

        LONG_PTR SetWindowLongPtr(int nIndex, LONG_PTR dwNewLong)
        {
	        return ::SetWindowLongPtr(m_hWnd, nIndex, dwNewLong);
        }

        WORD GetWindowWord(int nIndex)
        {
            return ::GetWindowWord(m_hWnd, nIndex);
        }

        WORD SetWindowWord(int nIndex, WORD wNewWord)
        {
            return ::SetWindowWord(m_hWnd, nIndex, wNewWord);
        }

    public: // Message Functions

        LRESULT SendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
        {
            return ::SendMessage(m_hWnd, uMsg, wParam, lParam);
        }

        BOOL PostMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
        {
            return ::PostMessage(m_hWnd, uMsg, wParam, lParam);
        }

        BOOL SendNotifyMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
        {
            return ::SendNotifyMessage(m_hWnd, wParam, wParam, lParam);
        }

    public: // Window Text Functions

        int GetWindowTextLength()
        {
            return ::GetWindowTextLength(m_hWnd);
        }

        int GetWindowText(LPTSTR lpszStringBuf, int nMaxCount)
        {
            return ::GetWindowText(m_hWnd, lpszStringBuf, nMaxCount);
        }

        BOOL SetWindowText(LPCTSTR lpszString)
        {
            return ::SetWindowText(m_hWnd, lpszString);
        }

    public: // Font Functions

        HFONT GetFont()
        {
            return (HFONT)::SendMessage(m_hWnd, WM_GETFONT, 0, 0);
        }

        void SetFont(HFONT hFont, BOOL bRedraw = TRUE)
        {
            ::SendMessage(m_hWnd, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(bRedraw, 0));
        }

    public: // Menu Functions (non-child windows only)

        HMENU GetMenu()
        {
            return (HMENU)::GetMenu(m_hWnd);
        }

        BOOL SetMenu(HMENU hMenu)
        {
            return ::SetMenu(m_hWnd, hMenu);
        }

        BOOL DrawMenuBar()
        {
            return ::DrawMenuBar(m_hWnd);
        }

        HMENU GetSystemMenu(BOOL bRevert)
        {
            return (HMENU)::GetSystemMenu(m_hWnd, bRevert);
        }

        BOOL HiliteMenuItem(HMENU hMenu, UINT uItemHilite, UINT uHilite)
        {
            return ::HiliteMenuItem(m_hWnd, hMenu, uItemHilite, uHilite);
        }

    public: // Window Size and Position Functions

        BOOL IsIconic()
        {
            return ::IsIconic(m_hWnd);
        }

        BOOL IsZoomed()
        {
            return ::IsZoomed(m_hWnd);
        }

        BOOL MoveWindow(int x, int y, int nWidth, int nHeight, BOOL bRepaint = TRUE)
        {
            return ::MoveWindow(m_hWnd, x, y, nWidth, nHeight, bRepaint);
        }

        BOOL MoveWindow(LPCRECT lpRect, BOOL bRepaint = TRUE)
        {
            return ::MoveWindow(m_hWnd, lpRect->left, lpRect->top, lpRect->right - lpRect->left, lpRect->bottom - lpRect->top, bRepaint);
        }

        BOOL SetWindowPos(HWND hWndInsertAfter, int x, int y, int nWidth, int nHeight, UINT nFlags)
        {
            return ::SetWindowPos(m_hWnd, hWndInsertAfter, x, y, nWidth, nHeight, nFlags);
        }

        BOOL SetWindowPos(HWND hWndInsertAfter, LPCRECT lpRect, UINT nFlags)
        {
            return ::SetWindowPos(m_hWnd, hWndInsertAfter, lpRect->left, lpRect->top, lpRect->right - lpRect->left, lpRect->bottom - lpRect->top, nFlags);
        }

        UINT ArrangeIconicWindows()
        {
            return ::ArrangeIconicWindows(m_hWnd);
        }

        BOOL BringWindowToTop()
        {
            return ::BringWindowToTop(m_hWnd);
        }

        BOOL GetWindowRect(LPRECT lpRect)
        {
            return ::GetWindowRect(m_hWnd, lpRect);
        }

        BOOL GetClientRect(LPRECT lpRect)
        {
            return ::GetClientRect(m_hWnd, lpRect);
        }

        BOOL GetWindowPlacement(WINDOWPLACEMENT FAR *lpwndpl)
        {
            return ::GetWindowPlacement(m_hWnd, lpwndpl);
        }

        BOOL SetWindowPlacement(const WINDOWPLACEMENT FAR *lpwndpl)
        {
            return ::SetWindowPlacement(m_hWnd, lpwndpl);
        }

    public: // Coordinate Mapping Functions

        BOOL ClientToScreen(LPPOINT lpPoint)
        {
            return ::ClientToScreen(m_hWnd, lpPoint);
        }

        BOOL ClientToScreen(LPRECT lpRect)
        {
            if(!::ClientToScreen(m_hWnd, (LPPOINT)lpRect))
            {
                return FALSE;
            }

            if(!::ClientToScreen(m_hWnd, (LPPOINT)lpRect) + 1)
            {
                return FALSE;
            }

            return TRUE;
        }

        BOOL ScreenToClient(LPPOINT lpPoint)
        {
            return ::ScreenToClient(m_hWnd, lpPoint);
        }

        BOOL ScreenToClient(LPRECT lpRect)
        {
            if(!::ScreenToClient(m_hWnd, (LPPOINT)lpRect))
            {
                return FALSE;
            }

            if(!::ScreenToClient(m_hWnd, (LPPOINT)lpRect) + 1)
            {
                return FALSE;
            }

            return TRUE;
        }

        int MapWindowPoints(HWND hWndTo, LPPOINT lpPoint, UINT nCount)
        {
            return ::MapWindowPoints(m_hWnd, hWndTo, lpPoint, nCount);
        }

        int MapWindowPoints(HWND hWndTo, LPRECT lpRect)
        {
            return ::MapWindowPoints(m_hWnd, hWndTo, (LPPOINT)lpRect, 2);
        }

    public: // Update and Painting Functions

        HDC BeginPaint(LPPAINTSTRUCT lpPaint)
        {
            return ::BeginPaint(m_hWnd, lpPaint);
        }

        void EndPaint(LPPAINTSTRUCT lpPaint)
        {
            ::EndPaint(m_hWnd, lpPaint);
        }

        HDC GetDC()
        {
            return ::GetDC(m_hWnd);
        }

        HDC GetWindowDC()
        {
            return ::GetWindowDC(m_hWnd);
        }

        int ReleaseDC(HDC hDC)
        {
            return ::ReleaseDC(m_hWnd, hDC);
        }

        void Print(HDC hDC, DWORD dwFlags)
        {
            ::SendMessage(m_hWnd, WM_PRINT, (WPARAM)hDC, dwFlags);
        }

        void PrintClient( HDC hDC, DWORD dwFlags)
        {
            ::SendMessage(m_hWnd, WM_PRINTCLIENT, (WPARAM)hDC, dwFlags);
        }

        BOOL Update()
        {
            return ::UpdateWindow(m_hWnd);
        }

        void SetRedraw(BOOL bRedraw = TRUE)
        {
            ::SendMessage(m_hWnd, WM_SETREDRAW, (WPARAM)bRedraw, 0);
        }

        BOOL GetUpdateRect(LPRECT lpRect, BOOL bErase = FALSE)
        {
            return ::GetUpdateRect(m_hWnd, lpRect, bErase);
        }

        int GetUpdateRgn(HRGN hRgn, BOOL bErase = FALSE)
        {
            return ::GetUpdateRgn(m_hWnd, hRgn, bErase);
        }

        BOOL Invalidate(BOOL bErase = TRUE)
        {
            return ::InvalidateRect(m_hWnd, NULL, bErase);
        }

        BOOL InvalidateRect(LPCRECT lpRect, BOOL bErase = TRUE)
        {
            return ::InvalidateRect(m_hWnd, lpRect, bErase);
        }

        BOOL ValidateRect(LPCRECT lpRect)
        {
            return ::ValidateRect(m_hWnd, lpRect);
        }

        void InvalidateRgn(HRGN hRgn, BOOL bErase = TRUE)
        {
            ::InvalidateRgn(m_hWnd, hRgn, bErase);
        }

        BOOL ValidateRgn(HRGN hRgn)
        {
            return ::ValidateRgn(m_hWnd, hRgn);
        }

        BOOL ShowWindow(int nCmdShow = SW_SHOW)
        {
            return ::ShowWindow(m_hWnd, nCmdShow);
        }

        BOOL IsWindowVisible()
        {
            return ::IsWindowVisible(m_hWnd);
        }

        BOOL ShowOwnedPopups(BOOL bShow = TRUE)
        {
            return ::ShowOwnedPopups(m_hWnd, bShow);
        }

        HDC GetDCEx(HRGN hRgnClip, DWORD flags)
        {
            return ::GetDCEx(m_hWnd, hRgnClip, flags);
        }

        BOOL LockWindowUpdate(BOOL bLock = TRUE)
        {
            return ::LockWindowUpdate(bLock ? m_hWnd : NULL);
        }

        BOOL RedrawWindow(LPCRECT lpRectUpdate = NULL,
                          HRGN hRgnUpdate = NULL,
                          UINT flags = RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE)
        {
            return ::RedrawWindow(m_hWnd, lpRectUpdate, hRgnUpdate, flags);
        }

    public: // Window State Functions

        BOOL IsWindowEnabled()
        {
            return ::IsWindowEnabled(m_hWnd);
        }

        BOOL EnableWindow(BOOL bEnable = TRUE)
        {
            return ::EnableWindow(m_hWnd, bEnable);
        }

        HWND SetActiveWindow()
        {
            return ::SetActiveWindow(m_hWnd);
        }

        HWND SetCapture()
        {
            return ::SetCapture(m_hWnd);
        }

        BOOL ReleaseCapture()
        {
            return ::ReleaseCapture();
        }

        HWND SetFocus()
        {
            return ::SetFocus(m_hWnd);
        }

    // Scrolling Functions

        int GetScrollPos(int nBar)
        {
            return ::GetScrollPos(m_hWnd, nBar);
        }

        BOOL GetScrollRange(int nBar, LPINT lpMinPos, LPINT lpMaxPos)
        {
            return ::GetScrollRange(m_hWnd, nBar, lpMinPos, lpMaxPos);
        }

        BOOL ScrollWindow(int xAmount, int yAmount, LPCRECT lpRect = NULL, LPCRECT lpClipRect = NULL)
        {
            return ::ScrollWindow(m_hWnd, xAmount, yAmount, lpRect, lpClipRect);
        }

        int ScrollWindowEx(int dx, int dy, LPCRECT lpRectScroll, LPCRECT lpRectClip,
                           HRGN hRgnUpdate, LPRECT lpRectUpdate, UINT uFlags)
        {
            return ::ScrollWindowEx(m_hWnd, dx, dy, lpRectScroll, lpRectClip, hRgnUpdate, lpRectUpdate, uFlags);
        }

        int SetScrollPos(int nBar, int nPos, BOOL bRedraw = TRUE)
        {
            return ::SetScrollPos(m_hWnd, nBar, nPos, bRedraw);
        }

        BOOL SetScrollRange(int nBar, int nMinPos, int nMaxPos, BOOL bRedraw = TRUE)
        {
            return ::SetScrollRange(m_hWnd, nBar, nMinPos, nMaxPos, bRedraw);
        }

        BOOL ShowScrollBar(UINT nBar, BOOL bShow = TRUE)
        {
            return ::ShowScrollBar(m_hWnd, nBar, bShow);
        }

        BOOL EnableScrollBar( UINT uSBFlags, UINT uArrowFlags = ESB_ENABLE_BOTH)
        {
            return ::EnableScrollBar(m_hWnd, uSBFlags, uArrowFlags);
        }

    public: // Alert Functions

        BOOL FlashWindow(BOOL bInvert)
        {
            return ::FlashWindow(m_hWnd, bInvert);
        }

        int MessageBox(LPCTSTR lpszText, LPCTSTR lpszCaption = _T(""), UINT nType = MB_OK)
        {
            return ::MessageBox(m_hWnd, lpszText, lpszCaption, nType);
        }

    public: // Clipboard Functions

        BOOL ChangeClipboardChain(HWND hWndNewNext)
        {
            return ::ChangeClipboardChain(m_hWnd, hWndNewNext);
        }

        HWND SetClipboardViewer()
        {
            return ::SetClipboardViewer(m_hWnd);
        }

        BOOL OpenClipboard()
        {
            return ::OpenClipboard(m_hWnd);
        }

    public: // Caret Functions

        BOOL CreateCaret(HBITMAP hBitmap)
        {
            return ::CreateCaret(m_hWnd, hBitmap, 0, 0);
        }

        BOOL CreateSolidCaret(int nWidth, int nHeight)
        {
            return ::CreateCaret(m_hWnd, (HBITMAP)0, nWidth, nHeight);
        }

        BOOL CreateGrayCaret(int nWidth, int nHeight)
        {
            return ::CreateCaret(m_hWnd, (HBITMAP)1, nWidth, nHeight);
        }

        BOOL HideCaret()
        {
            return ::HideCaret(m_hWnd);
        }

        BOOL ShowCaret()
        {
            return ::ShowCaret(m_hWnd);
        }

        void DragAcceptFiles(BOOL bAccept = TRUE)
        {
            ::DragAcceptFiles(m_hWnd, bAccept);
        }

    public: // Icon Functions

        HICON SetIcon(HICON hIcon, BOOL bBigIcon = TRUE)
        {
            return (HICON)::SendMessage(m_hWnd, WM_SETICON, bBigIcon, (LPARAM)hIcon);
        }

        HICON GetIcon(BOOL bBigIcon = TRUE)
        {
            return (HICON)::SendMessage(m_hWnd, WM_GETICON, bBigIcon, 0);
        }

    public: // Help Functions

        BOOL WinHelp(LPCTSTR lpszHelp, UINT nCmd = HELP_CONTEXT, DWORD dwData = 0)
        {
            return ::WinHelp(m_hWnd, lpszHelp, nCmd, dwData);
        }

        BOOL SetWindowContextHelpId(DWORD dwContextHelpId)
        {
            return ::SetWindowContextHelpId(m_hWnd, dwContextHelpId);
        }

        DWORD GetWindowContextHelpId()
        {
            return ::GetWindowContextHelpId(m_hWnd);
        }

    public: // Hot Key Functions

        int SetHotKey(WORD wVirtualKeyCode, WORD wModifiers)
        {
            return (int)::SendMessage(m_hWnd, WM_SETHOTKEY, MAKEWORD(wVirtualKeyCode, wModifiers), 0);
        }

        DWORD GetHotKey()
        {
            return (DWORD)::SendMessage(m_hWnd, WM_GETHOTKEY, 0, 0);
        }

    public: // Misc. Operations

        BOOL GetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo)
        {
            return ::GetScrollInfo(m_hWnd, nBar, lpScrollInfo);
        }

        int SetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, BOOL bRedraw = TRUE)
        {
            return ::SetScrollInfo(m_hWnd, nBar, lpScrollInfo, bRedraw);
        }

        int GetWindowRgn(HRGN hRgn)
        {
            return ::GetWindowRgn(m_hWnd, hRgn);
        }

        int SetWindowRgn(HRGN hRgn, BOOL bRedraw = FALSE)
        {
            return ::SetWindowRgn(m_hWnd, hRgn, bRedraw);
        }

        HDWP DeferWindowPos(HDWP hWinPosInfo, HWND hWndInsertAfter,
                            int x, int y, int nWidth, int nHeight, UINT uFlags)
        {
            return ::DeferWindowPos(hWinPosInfo, m_hWnd, hWndInsertAfter, x, y, nWidth, nHeight, uFlags);
        }

        DWORD GetWindowThreadID()
        {
            return ::GetWindowThreadProcessId(m_hWnd, NULL);
        }

        DWORD GetWindowProcessID()
        {
            DWORD dwProcessID;
            ::GetWindowThreadProcessId(m_hWnd, &dwProcessID);
            return dwProcessID;
        }

        BOOL IsWindow()
        {
            return ::IsWindow(m_hWnd);
        }

        BOOL IsWindowUnicode()
        {
            return ::IsWindowUnicode(m_hWnd);
        }

        BOOL ShowWindowAsync(int nCmdShow)
        {
            return ::ShowWindowAsync(m_hWnd, nCmdShow);
        }
    };

} // namespace xl

#endif // #ifndef __XLWINDOW_H_0646591E_8D6A_44AA_A773_084A53A0B190_INCLUDED__
