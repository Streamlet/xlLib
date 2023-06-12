//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlBase64Test.cpp
//    Author:      Streamlet
//    Create Time: 2011-04-30
//    Description: 
//
//------------------------------------------------------------------------------


#include "../../../../Include/xl/AppHelper/xlUnitTest.h"
#include "../../../../Include/xl/Common/String/xlBase64.h"

#ifdef _UNICODE
#define _T(s) L ## s
#else
#define _T(s) s
#endif

namespace
{
    XL_TEST_CASE()
    {
        xl::String str;
        xl::Array<unsigned char> arr;

        xl::Base64::Encode("", 0, &str);
        xl::Base64::Decode(str, &arr);
        arr.PushBack(0);
        XL_TEST_ASSERT(str == _T(""));
        XL_TEST_ASSERT(xl::StringA((const char *)&arr[0]) == "");

        xl::Base64::Encode("a", 1, &str);
        xl::Base64::Decode(str, &arr);
        arr.PushBack(0);
        XL_TEST_ASSERT(str == _T("YQ=="));
        XL_TEST_ASSERT(xl::StringA((const char *)&arr[0]) == "a");

        xl::Base64::Encode("ab", 2, &str);
        xl::Base64::Decode(str, &arr);
        arr.PushBack(0);
        XL_TEST_ASSERT(str == _T("YWI="));
        XL_TEST_ASSERT(xl::StringA((const char *)&arr[0]) == "ab");

        xl::Base64::Encode("abc", 3, &str);
        xl::Base64::Decode(str, &arr);
        arr.PushBack(0);
        XL_TEST_ASSERT(str == _T("YWJj"));
        XL_TEST_ASSERT(xl::StringA((const char *)&arr[0]) == "abc");

        xl::Base64::Encode("abcd", 4, &str);
        xl::Base64::Decode(str, &arr);
        arr.PushBack(0);
        XL_TEST_ASSERT(str == _T("YWJjZA=="));
        XL_TEST_ASSERT(xl::StringA((const char *)&arr[0]) == "abcd");

        xl::Base64::Encode("abcde", 5, &str);
        xl::Base64::Decode(str, &arr);
        arr.PushBack(0);
        XL_TEST_ASSERT(str == _T("YWJjZGU="));
        XL_TEST_ASSERT(xl::StringA((const char *)&arr[0]) == "abcde");

        xl::Base64::Encode("abcdef", 6, &str);
        xl::Base64::Decode(str, &arr);
        arr.PushBack(0);
        XL_TEST_ASSERT(str == _T("YWJjZGVm"));
        XL_TEST_ASSERT(xl::StringA((const char *)&arr[0]) == "abcdef");

        xl::Base64::Encode("abcdefg", 7, &str);
        xl::Base64::Decode(str, &arr);
        arr.PushBack(0);
        XL_TEST_ASSERT(str == _T("YWJjZGVmZw=="));
        XL_TEST_ASSERT(xl::StringA((const char *)&arr[0]) == "abcdefg");
    }
}
