/*******************************************************************************

    Copyright (C) Streamlet. All rights reserved.

    File Name:   Encoding.h
    Author:      Streamlet
    Create Time: 2009-03-25
    Description: Do conversion works between Unicode and UTF-8.

    Version history:



*******************************************************************************/

#ifndef __ENCODING_H_975D00DD_0135_449E_9EB2_08FB0861A28E_INCLUDED__
#define __ENCODING_H_975D00DD_0135_449E_9EB2_08FB0861A28E_INCLUDED__

#ifndef NULL
#define NULL 0
#endif

class CEncoding
{
public:

	/// @brief Convert wide char (Unicode) to UTF-8 char.
	/// @param wChar Source Unicode char to convert.
	/// @param pUTF8CharBuf [out] Buffer for outputtingUTF-8 chars, 6 bytes needed in maximum.
	/// @param lpdwSize [in, out] The size of the given buffer, in bytes. When the function returns, its value will be set to bytes used.
	///                           If the buffer is too small, the function fails, and this variable receives the required buffer size.
	/// @return If the conversion succeeds, it returns true, otherwise false.
	static bool WCharToUTF8Char(wchar_t wChar, char *pUTF8CharBuf, unsigned long *lpdwSize);

	/// @brief Convert Unicode string to UTF-8 string.
	/// @param lpwszString [in] Source Unicode char string.
	/// @param lpszUTF8StringBuf [out] Buffer for outputtingUTF-8 char string.
	/// @param lpdwSize [in, out] The size of the given buffer, in bytes. When the function returns, its value will be set to bytes used.
	///                           If the buffer is too small, the function fails, and this variable receives the required buffer size.
	/// @return If the conversion succeeds, it returns true, otherwise false.
	static bool WStringToUTF8String(const wchar_t *lpwszString, char *lpszUTF8StringBuf, unsigned long *lpdwSize);

	/// @brief Convert UTF-8 char to Unicode char.
	/// @param pUTF8Char [in] Source UTF-8 char. It should contains the right data of a UTF-8 char.
	/// @param lpdwSize [out] The size of the solved UTF-8 character, in bytes. It can be NULL if it is no need to know the size.
	/// @param pwChar [out] Buffer for outputting, exactly one WCHAR is needed here.
	/// @return If the conversion succeeds, it returns TRUE, otherwise FALSE.
	static bool UTF8CharToWChar(const char *pUTF8Char, unsigned long *lpdwSize, wchar_t *pwChar);

	/// @brief Convert UTF-8 char string to Unicode char string.
	/// @param lpszUTF8String [in] Source UTF-8 char string.
	/// @param lpwszWStringBuf [out] Buffer for outputting Unicode string.
	/// @param lpdwSize [in, out] The size of the given buffer, in characters. When the function returns, its value will be set to characters used.
	///                           If the buffer is too small, the function fails, and this variable receives the required buffer size.
	/// @return If the conversion succeeds, it returns TRUE, otherwise FALSE.
	static bool UTF8StringToWString(const char *lpszUTF8String, wchar_t *lpwszWStringBuf, unsigned long *lpdwSize);

private:
	CEncoding();
};



#endif // #ifndef __ENCODING_H_975D00DD_0135_449E_9EB2_08FB0861A28E_INCLUDED__
