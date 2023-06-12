//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlStringTest.cpp
//    Author:      Streamlet
//    Create Time: 2011-04-30
//    Description: 
//
//------------------------------------------------------------------------------


#include "../../../../Include/xl/AppHelper/xlUnitTest.h"
#include "../../../../Include/xl/Common/String/xlString.h"

#ifdef _UNICODE
#define _T(s) L ## s
#else
#define _T(s) s
#endif

namespace
{
    using namespace xl;

    XL_TEST_CASE()
    {
        String a;
        XL_TEST_ASSERT(a == _T(""));

        String b(_T("123"));
        XL_TEST_ASSERT(b == _T("123"));

        String c(b);
        XL_TEST_ASSERT(c == _T("123"));

        String d(_T("123"), 3);
        XL_TEST_ASSERT(d == _T("123"));

        String e(_T("123"), 4);
        XL_TEST_ASSERT(e == _T("123"));

        String f(_T("1\00023"), 3);
        XL_TEST_ASSERT(f.Length() == 3 && f[0] == _T('1') && f[1] == _T('\0') && f[2] == _T('2'));
    }

    XL_TEST_CASE()
    {
        String a(_T("123"));
        String b(_T("456"));

        b = a;
        XL_TEST_ASSERT(b == a);
    }

    XL_TEST_CASE()
    {
        XL_TEST_ASSERT(String(_T("")) == _T(""));
        XL_TEST_ASSERT(String(_T("123")) != _T(""));
        XL_TEST_ASSERT(String(_T("")) != _T("123"));
        XL_TEST_ASSERT(String(_T("123")) == _T("123"));
        XL_TEST_ASSERT(String(_T("123")) <= _T("123"));
        XL_TEST_ASSERT(String(_T("123")) >= _T("123"));
        XL_TEST_ASSERT(String(_T("123")) < _T("223"));
        XL_TEST_ASSERT(String(_T("123")) <= _T("223"));
        XL_TEST_ASSERT(String(_T("123")) > _T("023"));
        XL_TEST_ASSERT(String(_T("123")) >= _T("023"));
    }

    XL_TEST_CASE()
    {
        XL_TEST_ASSERT(String(_T("")) + String(_T("")) == _T(""));
        XL_TEST_ASSERT(String(_T("a")) + String(_T("")) == _T("a"));
        XL_TEST_ASSERT(String(_T("")) + String(_T("b")) == _T("b"));
        XL_TEST_ASSERT(String(_T("a")) + String(_T("b")) == _T("ab"));

        XL_TEST_ASSERT((String(_T("")) += String(_T(""))) == _T(""));
        XL_TEST_ASSERT((String(_T("a")) += String(_T(""))) == _T("a"));
        XL_TEST_ASSERT((String(_T("")) += String(_T("b"))) == _T("b"));
        XL_TEST_ASSERT((String(_T("a")) += String(_T("b"))) == _T("ab"));
    }

    XL_TEST_CASE()
    {
        String a(_T("123"));

        XL_TEST_ASSERT(a[0] == _T('1'));
        XL_TEST_ASSERT(a[1] == _T('2'));
        XL_TEST_ASSERT(a[2] == _T('3'));
        XL_TEST_ASSERT(a[3] == _T('\0'));

        a[0] = _T('4');
        a[1] = _T('5');
        a[2] = _T('6');

        XL_TEST_ASSERT(a[0] == _T('4'));
        XL_TEST_ASSERT(a[1] == _T('5'));
        XL_TEST_ASSERT(a[2] == _T('6'));
    }

    XL_TEST_CASE()
    {
        String a(_T("123"));
#ifdef _UNICODE
        XL_TEST_ASSERT((const wchar_t *)a == &a[0]);
#else
        XL_TEST_ASSERT((const char *)a == &a[0]);
#endif
    }

    XL_TEST_CASE()
    {
        String a;
        XL_TEST_ASSERT(a.Length() == 0);
        XL_TEST_ASSERT(a.Empty());

        a = _T("1");
        XL_TEST_ASSERT(a.Length() == 1);
        XL_TEST_ASSERT(!a.Empty());

        a = _T("12");
        XL_TEST_ASSERT(a.Length() == 2);
        XL_TEST_ASSERT(!a.Empty());

        a = _T("123");
        XL_TEST_ASSERT(a.Length() == 3);
        XL_TEST_ASSERT(!a.Empty());
    }

    XL_TEST_CASE()
    {
        String a(_T("Hello!"));

        XL_TEST_ASSERT(a.ToLower() == _T("hello!"));
        XL_TEST_ASSERT(a.ToUpper() == _T("HELLO!"));

        XL_TEST_ASSERT(a == _T("Hello!"));
        a.MakeLower();
        XL_TEST_ASSERT(a == _T("hello!"));
        a.MakeUpper();
        XL_TEST_ASSERT(a == _T("HELLO!"));
    }

    XL_TEST_CASE()
    {
        String a(_T("123"));

        a.AppendBack(_T('a'));
        XL_TEST_ASSERT(a == _T("123a"));

        a.AppendFront(_T('a'));
        XL_TEST_ASSERT(a == _T("a123a"));

        a.AppendBack(_T('b'), 3);
        XL_TEST_ASSERT(a == _T("a123abbb"));

        a.AppendFront(_T('b'), 3);
        XL_TEST_ASSERT(a == _T("bbba123abbb"));

        a.Clear();
        XL_TEST_ASSERT(a == _T(""));
    }

    XL_TEST_CASE()
    {
        String a(_T("12345"));

        XL_TEST_ASSERT(a.Left(0) == _T(""));
        XL_TEST_ASSERT(a.Left(1) == _T("1"));
        XL_TEST_ASSERT(a.Left(2) == _T("12"));
        XL_TEST_ASSERT(a.Left(3) == _T("123"));
        XL_TEST_ASSERT(a.Left(4) == _T("1234"));
        XL_TEST_ASSERT(a.Left(5) == _T("12345"));
        XL_TEST_ASSERT(a.Right(0) == _T(""));
        XL_TEST_ASSERT(a.Right(1) == _T("5"));
        XL_TEST_ASSERT(a.Right(2) == _T("45"));
        XL_TEST_ASSERT(a.Right(3) == _T("345"));
        XL_TEST_ASSERT(a.Right(4) == _T("2345"));
        XL_TEST_ASSERT(a.Right(5) == _T("12345"));
        XL_TEST_ASSERT(a.SubString(0, 0) == _T(""));
        XL_TEST_ASSERT(a.SubString(0, 1) == _T("1"));
        XL_TEST_ASSERT(a.SubString(0, 2) == _T("12"));
        XL_TEST_ASSERT(a.SubString(0, 3) == _T("123"));
        XL_TEST_ASSERT(a.SubString(0, 4) == _T("1234"));
        XL_TEST_ASSERT(a.SubString(0, 5) == _T("12345"));
        XL_TEST_ASSERT(a.SubString(1, 0) == _T(""));
        XL_TEST_ASSERT(a.SubString(1, 1) == _T("2"));
        XL_TEST_ASSERT(a.SubString(1, 2) == _T("23"));
        XL_TEST_ASSERT(a.SubString(1, 3) == _T("234"));
        XL_TEST_ASSERT(a.SubString(1, 4) == _T("2345"));
        XL_TEST_ASSERT(a.SubString(2, 0) == _T(""));
        XL_TEST_ASSERT(a.SubString(2, 1) == _T("3"));
        XL_TEST_ASSERT(a.SubString(2, 2) == _T("34"));
        XL_TEST_ASSERT(a.SubString(2, 3) == _T("345"));
        XL_TEST_ASSERT(a.SubString(3, 0) == _T(""));
        XL_TEST_ASSERT(a.SubString(3, 1) == _T("4"));
        XL_TEST_ASSERT(a.SubString(3, 2) == _T("45"));
        XL_TEST_ASSERT(a.SubString(4, 0) == _T(""));
        XL_TEST_ASSERT(a.SubString(4, 1) == _T("5"));
        XL_TEST_ASSERT(a.SubString(5, 0) == _T(""));

        XL_TEST_ASSERT(a.Left(10) == _T("12345"));
    }

    XL_TEST_CASE()
    {
        String a(_T("123abc456abc789"));

        XL_TEST_ASSERT(a.IndexOf(_T("abc")) == 3);
        XL_TEST_ASSERT(a.IndexOf(_T("abc"), 3) == 3);
        XL_TEST_ASSERT(a.IndexOf(_T("abc"), 4) == 9);
        XL_TEST_ASSERT(a.IndexOf(_T("abc"), 9) == 9);
        XL_TEST_ASSERT(a.IndexOf(_T("abc"), 10) == -1);

        XL_TEST_ASSERT(a.LastIndexOf(_T("abc")) == 9);
        XL_TEST_ASSERT(a.LastIndexOf(_T("abc"), 11) == 9);
        XL_TEST_ASSERT(a.LastIndexOf(_T("abc"), 10) == 3);
        XL_TEST_ASSERT(a.LastIndexOf(_T("abc"), 5) == 3);
        XL_TEST_ASSERT(a.LastIndexOf(_T("abc"), 4) == -1);
    }

    XL_TEST_CASE()
    {
        String a(_T("123abc456abc789"));

        XL_TEST_ASSERT(a.Replace(_T("abc"), _T("")) == _T("123456789"));
        XL_TEST_ASSERT(a.Replace(_T("abc"), _T("@")) == _T("123@456@789"));
        XL_TEST_ASSERT(a.Replace(_T(""), _T("@")) == _T("123abc456abc789"));
        XL_TEST_ASSERT(a.Replace(_T("abc"), _T("@"), 1) == _T("123@456abc789"));
        XL_TEST_ASSERT(a == _T("123abc456abc789"));
    }

    XL_TEST_CASE()
    {
        String a(_T("123|456||789|"));

        Array<String> v = a.Split(_T("|"));

        XL_TEST_ASSERT(v.Size() == 5);
        XL_TEST_ASSERT(v[0] == _T("123"));
        XL_TEST_ASSERT(v[1] == _T("456"));
        XL_TEST_ASSERT(v[2] == _T(""));
        XL_TEST_ASSERT(v[3] == _T("789"));
        XL_TEST_ASSERT(v[4] == _T(""));

        v = a.Split(_T("|"), 3);

        XL_TEST_ASSERT(v.Size() == 3);
        XL_TEST_ASSERT(v[0] == _T("123"));
        XL_TEST_ASSERT(v[1] == _T("456"));
        XL_TEST_ASSERT(v[2] == _T("|789|"));

        String b(_T("123|456"));

        v = b.Split(_T("|"), 3);

        XL_TEST_ASSERT(v.Size() == 2);
        XL_TEST_ASSERT(v[0] == _T("123"));
        XL_TEST_ASSERT(v[1] == _T("456"));
    }
}
