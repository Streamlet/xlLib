/*******************************************************************************

    Copyright (C) Streamlet. All rights reserved.

    File Name:   Encoding.cpp
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



// UTF-8 definition: (Unicode: UTF-8)
// U-00000000 - U-0000007F: 0xxxxxxx
// U-00000080 - U-000007FF: 110xxxxx 10xxxxxx
// U-00000800 - U-0000FFFF: 1110xxxx 10xxxxxx 10xxxxxx
// (The followings are so-called "UCS-4")
// U-00010000 - U-001FFFFF: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
// U-00200000 - U-03FFFFFF: 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
// U-04000000 - U-7FFFFFFF: 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
// For multi-bytes chars, how many "1"s at the beginning of the first byte suggests how many bytes the whole char used.
// Replace these "xxxx"s with bits in Unicode.

bool CEncoding::WCharToUTF8Char(wchar_t wChar, char *pUTF8CharBuf, unsigned long *lpdwSize)
{
	assert(pUTF8CharBuf != NULL && lpdwSize != NULL);

	unsigned long cbNeeded = 0;
	wchar_t firstByte;	// The mask used to get binary bits from the Unicode char to fill the first byte of UTF-8 char.
	char utfFirstByte;	// The mask used to turn the several bits at the beginning of the UTF-8 char to 1. See the UTF-8 definition.

	if (wChar <= 0x7f)				// 0000 0000 - 0111 1111, ASCII, use only one byte.
	{
		cbNeeded = 1;
		firstByte = 0x7f;			// 0111 1111
		utfFirstByte = (char)0x00;	// 0000 0000
	}
	else if (wChar <= 0x7ff)		// 1000 0000 - 0111 1111 1111, totally 11 bits valid in maximum.
	{
		cbNeeded = 2;
		firstByte = 0x1f;			// 0001 1111, 5 bits will be filled in the first byte, the rest 6 bits in the second byte.
		utfFirstByte = (char)0xc0;	// 1100 0000
	}
	else if (wChar <= 0xffff)		// 1000 0000 0000 - 1111 1111 1111 1111, 16 bits
	{
		cbNeeded = 3;
		firstByte = 0x0f;			// 0000 1111, 4 bits will be filled in the first byte, the rest 16 bits in the following two bytes.
		utfFirstByte = (char)0xe0;	// 1110 0000
	}
	// To support the UCS-4 encoding. Solved in the same way as foregoings.
	else if (wChar <= 0x001fffff)
	{
		cbNeeded = 4;
		firstByte = 0x07;
		utfFirstByte = (char)0xf0;
	}
	else if (wChar <= 0x03ffffff)
	{
		cbNeeded = 5;
		firstByte = 0x03;
		utfFirstByte = (char)0xf8;
	}
	else if (wChar <= 0x7fffffff)
	{
		cbNeeded = 6;
		firstByte = 0x01;
		utfFirstByte = (char)0xfc;
	}
	else	// Not Unicode char
	{
		return false;
	}

	if (cbNeeded > *lpdwSize)
	{
		*lpdwSize = cbNeeded;

		return false;
	}

	for (unsigned long i = cbNeeded - 1; i > 0; i--)
	{
		// Get the lowest 6 bits of wChar, fill them in the last byte of the UTF-8 char, and turn the highest 2 bits to 10.
		pUTF8CharBuf[i] = (wChar & 0x3f) | 0x80;
		wChar >>= 6;
	}

	// When the loop ends, there less than 6 bits left, which is to fill in the first byte of the UTF-8 char.
	// Use the mask to get the rest bits, and turn the highest several bits to 1...10, using the other mask.
	pUTF8CharBuf[0] = ((wChar & firstByte) | utfFirstByte);

	*lpdwSize = cbNeeded;

	return true;
}

bool CEncoding:: WStringToUTF8String(const wchar_t *lpwszString, char *lpszUTF8StringBuf, unsigned long *lpdwSize)
{
	assert(lpwszString != NULL && lpszUTF8StringBuf != NULL && lpdwSize != NULL);

	unsigned long cbUsed = 0;
	unsigned long cbCurChar = *lpdwSize;

	while (*lpwszString != L'\0')
	{
		bool bRet = WCharToUTF8Char(*lpwszString, &lpszUTF8StringBuf[cbUsed], &cbCurChar);

		cbUsed += cbCurChar;
		cbCurChar = *lpdwSize - cbUsed;
		lpwszString++;
		
		if (!bRet)
		{
			cbCurChar = 0;	// Once the buffer is not large enough, set this variable to zero to prevent the conversion of next char.
		}

	}

	if (cbUsed >= *lpdwSize)	// '=' is here because the ending null char is not set yet.
	{
		lpszUTF8StringBuf[*lpdwSize - 1] = '\0';
		*lpdwSize = cbUsed + 1;

		return false;
	}

	lpszUTF8StringBuf[cbUsed] = '\0';
	*lpdwSize = cbUsed + 1;

	return true;
}


bool CEncoding::UTF8CharToWChar(const char *pUTF8Char, unsigned long * lpdwSize, wchar_t *pwChar)
{
	assert(pUTF8Char != NULL && pwChar != NULL);

	unsigned long cbSize;
	char firstByte;

	if ((*pUTF8Char & 0xfe) == 0xfc)		// 1111 110x
	{
		cbSize = 6;
		firstByte = 0x01;
	}
	else if ((*pUTF8Char & 0xfc) == 0xf8)	// 1111 10xx
	{
		cbSize = 5;
		firstByte = 0x03;
	}
	else if ((*pUTF8Char & 0xf8) == 0xf0)	// 1111 0xxx
	{
		cbSize = 4;
		firstByte = 0x07;
	}
	else if ((*pUTF8Char & 0xf0) == 0xe0)	// 1110 xxxx
	{
		cbSize = 3;
		firstByte = 0x0f;
	}
	else if ((*pUTF8Char & 0xe0) == 0xc0)	// 110x xxxx
	{
		cbSize = 2;
		firstByte = 0x1f;
	}
	else if (((*pUTF8Char & 0x80) == 0x00)	// 0xxx xxxx
			&& *pUTF8Char != '\0')
	{
		cbSize = 1;
		firstByte = 0x7f;
	}
	else	// Not UTF-8 char
	{
		return false;
	}

	unsigned long cbUsed = 0;

	*pwChar = L'\0';

	for (int i = cbSize - 1; i >= 1; i--)
	{
		// Get the lowest 6 bits of the UTF-8 char byte.
		// Add these bits to the lowest bits of the unused bits in pwChar.
		*pwChar |= (pUTF8Char[i] & 0x3f) << cbUsed;
		cbUsed += 6;
	}

	// Solve the first byte of UTF-8 char
	*pwChar |= (pUTF8Char[0] & firstByte) << cbUsed;

	if (lpdwSize != NULL)
	{
		*lpdwSize = cbSize;
	}

	return true;
}

bool CEncoding::UTF8StringToWString(const char *lpszUTF8String, wchar_t *lpwszWStringBuf, unsigned long *lpdwSize)
{
	assert(lpszUTF8String != NULL && lpwszWStringBuf != NULL && lpdwSize != NULL);

	unsigned long ccUsed = 0, cbCurChar;

	while (*lpszUTF8String != '\0')
	{
		if (ccUsed < *lpdwSize)
		{
			UTF8CharToWChar((const char *)lpszUTF8String, &cbCurChar, &lpwszWStringBuf[ccUsed]);
		}

		ccUsed++;
		lpszUTF8String += cbCurChar;
	}

	if (ccUsed >= *lpdwSize)	// '=' is here because the ending null char is not set yet.
	{
		lpwszWStringBuf[*lpdwSize - 1] = L'\0';
		*lpdwSize = ccUsed + 1;

		return false;
	}

	lpwszWStringBuf[ccUsed] = L'\0';
	*lpdwSize = ccUsed + 1;

	return true;
}


