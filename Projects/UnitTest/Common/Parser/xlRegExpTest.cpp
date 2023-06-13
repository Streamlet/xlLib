//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlRegExpTest.cpp
//    Author:      Streamlet
//    Create Time: 2012-06-02
//    Description:
//
//------------------------------------------------------------------------------

#include "../../../../Include/xl/Common/Parser/xlRegExp.h"
#include "../../../../Include/xl/AppHelper/xlUnitTest.h"

#ifdef _UNICODE
#define _T(s) L##s
#else
#define _T(s) s
#endif

namespace
{
    using namespace xl;

    XL_TEST_CASE()
    {
        RegExp r;

        XL_TEST_ASSERT(!r.Parse(_T("")));
        XL_TEST_ASSERT(!r.Parse(_T("||")));
        XL_TEST_ASSERT(!r.Parse(_T("()")));
        XL_TEST_ASSERT(!r.Parse(_T("|")));
        XL_TEST_ASSERT(!r.Parse(_T("(|)")));
        XL_TEST_ASSERT(!r.Parse(_T("(||)")));
        XL_TEST_ASSERT(!r.Parse(_T("()|()")));
        XL_TEST_ASSERT(!r.Parse(_T("(")));
        XL_TEST_ASSERT(!r.Parse(_T(")")));
    }

    XL_TEST_CASE()
    {
        RegExp r;
        int nPos = 0;

        XL_TEST_ASSERT(r.Parse(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("ab")));
        XL_TEST_ASSERT(r.Match(_T("ab"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(!r.Match(_T("b")));

        XL_TEST_ASSERT(r.Parse(_T("(a)")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("ab")));
        XL_TEST_ASSERT(r.Match(_T("ab"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(!r.Match(_T("b")));

        XL_TEST_ASSERT(r.Parse(_T("ab|c")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("b")));
        XL_TEST_ASSERT(r.Match(_T("c")));
        XL_TEST_ASSERT(r.Match(_T("ab")));
        XL_TEST_ASSERT(!r.Match(_T("bc")));
        XL_TEST_ASSERT(!r.Match(_T("ac")));

        XL_TEST_ASSERT(r.Parse(_T("a(b|c)")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("b")));
        XL_TEST_ASSERT(!r.Match(_T("c")));
        XL_TEST_ASSERT(r.Match(_T("ab")));
        XL_TEST_ASSERT(r.Match(_T("ac")));
        XL_TEST_ASSERT(!r.Match(_T("bc")));
    }

    XL_TEST_CASE()
    {
        RegExp r;

        XL_TEST_ASSERT(r.Parse(_T("\\|")));
        XL_TEST_ASSERT(r.Match(_T("|")));

        XL_TEST_ASSERT(r.Parse(_T("\\(")));
        XL_TEST_ASSERT(r.Match(_T("(")));

        XL_TEST_ASSERT(r.Parse(_T("\\)")));
        XL_TEST_ASSERT(r.Match(_T(")")));

        XL_TEST_ASSERT(r.Parse(_T("\\\\")));
        XL_TEST_ASSERT(r.Match(_T("\\")));

        // XL_TEST_ASSERT(r.Parse(_T("\\")));
        // XL_TEST_ASSERT(r.Match(_T("\\")));

        XL_TEST_ASSERT(r.Parse(_T("\\|(\\(|\\))")));
        XL_TEST_ASSERT(r.Match(_T("|(")));
        XL_TEST_ASSERT(r.Match(_T("|)")));
    }

    XL_TEST_CASE()
    {
        RegExp r;
        int nPos = 0;

        // an integer from 0 to 255
        // 3 digit:
        //   0-199: (0|1)(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)
        // 200-249: 2(0|1|2|3|4)(0|1|2|3|4|5|6|7|8|9)
        // 250-255: 25(0|1|2|3|4|5)
        // 2 digit: (0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)
        // 1 digit: (0|1|2|3|4|5|6|7|8|9)
        XL_TEST_ASSERT(r.Parse(_T("(0|1)(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("2(0|1|2|3|4)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("25(0|1|2|3|4|5)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)")));
        XL_TEST_ASSERT(r.Match(_T("0")));
        XL_TEST_ASSERT(r.Match(_T("1")));
        XL_TEST_ASSERT(r.Match(_T("2")));
        XL_TEST_ASSERT(r.Match(_T("3")));
        XL_TEST_ASSERT(r.Match(_T("4")));
        XL_TEST_ASSERT(r.Match(_T("5")));
        XL_TEST_ASSERT(r.Match(_T("6")));
        XL_TEST_ASSERT(r.Match(_T("7")));
        XL_TEST_ASSERT(r.Match(_T("8")));
        XL_TEST_ASSERT(r.Match(_T("9")));
        XL_TEST_ASSERT(r.Match(_T("10")));
        XL_TEST_ASSERT(r.Match(_T("20")));
        XL_TEST_ASSERT(r.Match(_T("30")));
        XL_TEST_ASSERT(r.Match(_T("40")));
        XL_TEST_ASSERT(r.Match(_T("50")));
        XL_TEST_ASSERT(r.Match(_T("60")));
        XL_TEST_ASSERT(r.Match(_T("70")));
        XL_TEST_ASSERT(r.Match(_T("80")));
        XL_TEST_ASSERT(r.Match(_T("90")));
        XL_TEST_ASSERT(r.Match(_T("100")));
        XL_TEST_ASSERT(r.Match(_T("199")));
        XL_TEST_ASSERT(r.Match(_T("200")));
        XL_TEST_ASSERT(r.Match(_T("249")));
        XL_TEST_ASSERT(r.Match(_T("250")));
        XL_TEST_ASSERT(r.Match(_T("251")));
        XL_TEST_ASSERT(r.Match(_T("252")));
        XL_TEST_ASSERT(r.Match(_T("253")));
        XL_TEST_ASSERT(r.Match(_T("254")));
        XL_TEST_ASSERT(r.Match(_T("255")));
        XL_TEST_ASSERT(!r.Match(_T("256")));
        XL_TEST_ASSERT(!r.Match(_T("260")));
        XL_TEST_ASSERT(!r.Match(_T("300")));
        XL_TEST_ASSERT(r.Match(_T("256"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("260"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("300"), &nPos) && nPos == 2);

        // IPv4 address
        XL_TEST_ASSERT(r.Parse(_T("(")
                               _T("(0|1)(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("2(0|1|2|3|4)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("25(0|1|2|3|4|5)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)")
                               _T(")\\.(")
                               _T("(0|1)(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("2(0|1|2|3|4)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("25(0|1|2|3|4|5)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)")
                               _T(")\\.(")
                               _T("(0|1)(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("2(0|1|2|3|4)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("25(0|1|2|3|4|5)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)")
                               _T(")\\.(")
                               _T("(0|1)(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("2(0|1|2|3|4)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("25(0|1|2|3|4|5)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)|")
                               _T("(0|1|2|3|4|5|6|7|8|9)")
                               _T(")")));
        XL_TEST_ASSERT(r.Match(_T("192.168.1.1")));
        XL_TEST_ASSERT(r.Match(_T("0.0.0.0")));
        XL_TEST_ASSERT(r.Match(_T("255.255.255.255")));
        XL_TEST_ASSERT(!r.Match(_T("0.0.0.256")));
        XL_TEST_ASSERT(r.Match(_T("0.0.0.256"), &nPos) && nPos == 8);
    }

    XL_TEST_CASE()
    {
        RegExp r;
        XL_TEST_ASSERT(!r.Parse(_T("[]")));
        XL_TEST_ASSERT(!r.Parse(_T("[^]")));
        XL_TEST_ASSERT(!r.Parse(_T("[(]")));
        XL_TEST_ASSERT(!r.Parse(_T("[|]")));

        XL_TEST_ASSERT(r.Parse(_T("[1-3a]")));
        XL_TEST_ASSERT(r.Match(_T("1")));
        XL_TEST_ASSERT(r.Match(_T("2")));
        XL_TEST_ASSERT(r.Match(_T("3")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("0")));
        XL_TEST_ASSERT(!r.Match(_T("4")));
        XL_TEST_ASSERT(!r.Match(_T("b")));

        XL_TEST_ASSERT(r.Parse(_T("[^1-3a]")));
        XL_TEST_ASSERT(!r.Match(_T("1")));
        XL_TEST_ASSERT(!r.Match(_T("2")));
        XL_TEST_ASSERT(!r.Match(_T("3")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("0")));
        XL_TEST_ASSERT(r.Match(_T("4")));
        XL_TEST_ASSERT(r.Match(_T("b")));
    }

    XL_TEST_CASE()
    {
        RegExp r;
        int nPos = 0;

        // an integer from 0 to 255
        // 3 digit:
        //   0-199: [01][0-9][0-9]
        // 200-249: 2[0-4][0-9]
        // 250-255: 25[0-5]
        // 2 digit: [0-9][0-9]
        // 1 digit: [0-9]
        XL_TEST_ASSERT(r.Parse(_T("[01][0-9][0-9]|2[0-4][0-9]|25[0-5]|[0-9][0-9]|[0-9]")));
        XL_TEST_ASSERT(r.Match(_T("0")));
        XL_TEST_ASSERT(r.Match(_T("1")));
        XL_TEST_ASSERT(r.Match(_T("2")));
        XL_TEST_ASSERT(r.Match(_T("3")));
        XL_TEST_ASSERT(r.Match(_T("4")));
        XL_TEST_ASSERT(r.Match(_T("5")));
        XL_TEST_ASSERT(r.Match(_T("6")));
        XL_TEST_ASSERT(r.Match(_T("7")));
        XL_TEST_ASSERT(r.Match(_T("8")));
        XL_TEST_ASSERT(r.Match(_T("9")));
        XL_TEST_ASSERT(r.Match(_T("10")));
        XL_TEST_ASSERT(r.Match(_T("20")));
        XL_TEST_ASSERT(r.Match(_T("30")));
        XL_TEST_ASSERT(r.Match(_T("40")));
        XL_TEST_ASSERT(r.Match(_T("50")));
        XL_TEST_ASSERT(r.Match(_T("60")));
        XL_TEST_ASSERT(r.Match(_T("70")));
        XL_TEST_ASSERT(r.Match(_T("80")));
        XL_TEST_ASSERT(r.Match(_T("90")));
        XL_TEST_ASSERT(r.Match(_T("100")));
        XL_TEST_ASSERT(r.Match(_T("199")));
        XL_TEST_ASSERT(r.Match(_T("200")));
        XL_TEST_ASSERT(r.Match(_T("249")));
        XL_TEST_ASSERT(r.Match(_T("250")));
        XL_TEST_ASSERT(r.Match(_T("251")));
        XL_TEST_ASSERT(r.Match(_T("252")));
        XL_TEST_ASSERT(r.Match(_T("253")));
        XL_TEST_ASSERT(r.Match(_T("254")));
        XL_TEST_ASSERT(r.Match(_T("255")));
        XL_TEST_ASSERT(!r.Match(_T("256")));
        XL_TEST_ASSERT(!r.Match(_T("260")));
        XL_TEST_ASSERT(!r.Match(_T("300")));
        XL_TEST_ASSERT(r.Match(_T("256"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("260"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("300"), &nPos) && nPos == 2);

        // IPv4 address
        XL_TEST_ASSERT(r.Parse(_T("(")
                               _T("[01][0-9][0-9]|2[0-4][0-9]|25[0-5]|[0-9][0-9]|[0-9]")
                               _T(")\\.(")
                               _T("[01][0-9][0-9]|2[0-4][0-9]|25[0-5]|[0-9][0-9]|[0-9]")
                               _T(")\\.(")
                               _T("[01][0-9][0-9]|2[0-4][0-9]|25[0-5]|[0-9][0-9]|[0-9]")
                               _T(")\\.(")
                               _T("[01][0-9][0-9]|2[0-4][0-9]|25[0-5]|[0-9][0-9]|[0-9]")
                               _T(")")));
        XL_TEST_ASSERT(r.Match(_T("192.168.1.1")));
        XL_TEST_ASSERT(r.Match(_T("0.0.0.0")));
        XL_TEST_ASSERT(r.Match(_T("255.255.255.255")));
        XL_TEST_ASSERT(!r.Match(_T("0.0.0.256")));
        XL_TEST_ASSERT(r.Match(_T("0.0.0.256"), &nPos) && nPos == 8);
    }

    XL_TEST_CASE()
    {
        RegExp r;
        int nPos = 0;

        XL_TEST_ASSERT(!r.Parse(_T("?")));
        XL_TEST_ASSERT(!r.Parse(_T("+")));
        XL_TEST_ASSERT(!r.Parse(_T("*")));
        XL_TEST_ASSERT(!r.Parse(_T("??")));
        XL_TEST_ASSERT(!r.Parse(_T("+?")));
        XL_TEST_ASSERT(!r.Parse(_T("*?")));

        XL_TEST_ASSERT(r.Parse(_T("a?")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 1);

        XL_TEST_ASSERT(r.Parse(_T("a??")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Parse(_T("a??")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a+")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 3);

        XL_TEST_ASSERT(r.Parse(_T("a+?")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 1);

        XL_TEST_ASSERT(r.Parse(_T("a*")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 3);

        XL_TEST_ASSERT(r.Parse(_T("a*?")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("w1+")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("w")));
        XL_TEST_ASSERT(r.Match(_T("w1")));
        XL_TEST_ASSERT(r.Match(_T("w11")));
        XL_TEST_ASSERT(r.Match(_T("w111")));
        XL_TEST_ASSERT(r.Match(_T("w1111")));
        XL_TEST_ASSERT(r.Match(_T("w11111")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(!r.Match(_T("w"), &nPos));
        XL_TEST_ASSERT(r.Match(_T("w1"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("w11"), &nPos) && nPos == 3);
        XL_TEST_ASSERT(r.Match(_T("w111"), &nPos) && nPos == 4);
        XL_TEST_ASSERT(r.Match(_T("w1111"), &nPos) && nPos == 5);
        XL_TEST_ASSERT(r.Match(_T("w11111"), &nPos) && nPos == 6);

        XL_TEST_ASSERT(r.Parse(_T("w1+?")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("w")));
        XL_TEST_ASSERT(r.Match(_T("w1")));
        XL_TEST_ASSERT(r.Match(_T("w11")));
        XL_TEST_ASSERT(r.Match(_T("w111")));
        XL_TEST_ASSERT(r.Match(_T("w1111")));
        XL_TEST_ASSERT(r.Match(_T("w11111")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(!r.Match(_T("w"), &nPos));
        XL_TEST_ASSERT(r.Match(_T("w1"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("w11"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("w111"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("w1111"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("w11111"), &nPos) && nPos == 2);
    }

    XL_TEST_CASE()
    {
        RegExp r;
        int nPos = 0;

        XL_TEST_ASSERT(!r.Parse(_T("{0,1}")));
        XL_TEST_ASSERT(!r.Parse(_T("{,1}")));
        XL_TEST_ASSERT(!r.Parse(_T("{1,}")));
        XL_TEST_ASSERT(!r.Parse(_T("{0,}")));

        XL_TEST_ASSERT(r.Parse(_T("a{0,1}"))); // Equal to a?
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 1);

        XL_TEST_ASSERT(r.Parse(_T("a{,1}"))); // Equal to a?
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 1);

        XL_TEST_ASSERT(r.Parse(_T("a{0,1}?"))); // Equal to a??
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Parse(_T("a??")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{,1}?"))); // Equal to a??
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Parse(_T("a??")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{1,}"))); // Equal to a+
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 3);

        XL_TEST_ASSERT(r.Parse(_T("a{1,}?"))); // Equal to a+?
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 1);

        XL_TEST_ASSERT(r.Parse(_T("a{0,}"))); // Equal to a*
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 3);

        XL_TEST_ASSERT(r.Parse(_T("a{,}"))); // Equal to a*
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 3);

        XL_TEST_ASSERT(r.Parse(_T("a{0,}?"))); // Equal to a*?
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{,}?"))); // Equal to a*?
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);
    }

    XL_TEST_CASE()
    {
        RegExp r;
        int nPos = 0;

        XL_TEST_ASSERT(r.Parse(_T("a{1,2}")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 2);

        XL_TEST_ASSERT(r.Parse(_T("a{1,2}?")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 1);

        XL_TEST_ASSERT(r.Parse(_T("a{0,2}")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 2);

        XL_TEST_ASSERT(r.Parse(_T("a{0,2}?")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{,2}")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 1);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 2);

        XL_TEST_ASSERT(r.Parse(_T("a{,2}?")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{2,}")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(!r.Match(_T("a"), &nPos));
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 3);

        XL_TEST_ASSERT(r.Parse(_T("a{2,}?")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(!r.Match(_T("a"), &nPos));
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 2);

        XL_TEST_ASSERT(r.Parse(_T("a{2,2}")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(!r.Match(_T("a"), &nPos));
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 2);

        XL_TEST_ASSERT(r.Parse(_T("a{2,2}?")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(!r.Match(_T("a"), &nPos));
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 2);

        XL_TEST_ASSERT(r.Parse(_T("a{2}")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(!r.Match(_T("a"), &nPos));
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 2);

        XL_TEST_ASSERT(r.Parse(_T("a{2}?")));
        XL_TEST_ASSERT(!r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(!r.Match(_T(""), &nPos));
        XL_TEST_ASSERT(!r.Match(_T("a"), &nPos));
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 2);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 2);

        XL_TEST_ASSERT(r.Parse(_T("a{0,0}")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{0,0}?")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{0}")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{0}?")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{}")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        XL_TEST_ASSERT(r.Parse(_T("a{}?")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("aa")));
        XL_TEST_ASSERT(!r.Match(_T("aaa")));
        XL_TEST_ASSERT(r.Match(_T(""), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("a"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aa"), &nPos) && nPos == 0);
        XL_TEST_ASSERT(r.Match(_T("aaa"), &nPos) && nPos == 0);

        // IPv4 address
        XL_TEST_ASSERT(r.Parse(_T("(([01][0-9][0-9]|2[0-4][0-9]|25[0-5]|[0-9][0-9]|[0-9])\\.){3}")
                               _T("([01][0-9][0-9]|2[0-4][0-9]|25[0-5]|[0-9][0-9]|[0-9])")));
        XL_TEST_ASSERT(r.Match(_T("192.168.1.1")));
        XL_TEST_ASSERT(r.Match(_T("0.0.0.0")));
        XL_TEST_ASSERT(r.Match(_T("255.255.255.255")));
        XL_TEST_ASSERT(!r.Match(_T("0.0.0.256")));
        XL_TEST_ASSERT(r.Match(_T("0.0.0.256"), &nPos) && nPos == 8);
    }

    XL_TEST_CASE()
    {
        RegExp r;

        XL_TEST_ASSERT(r.Parse(_T(".")));
        XL_TEST_ASSERT(!r.Match(_T("\n")));
        XL_TEST_ASSERT(r.Match(_T(".")));
        XL_TEST_ASSERT(r.Match(_T("\r")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("A")));
        XL_TEST_ASSERT(r.Match(_T("0")));

        XL_TEST_ASSERT(r.Parse(_T(".*")));
        XL_TEST_ASSERT(r.Match(_T("")));
        XL_TEST_ASSERT(r.Match(_T("1234567890")));
        XL_TEST_ASSERT(r.Match(_T("abcdefg")));
        XL_TEST_ASSERT(!r.Match(_T("\n")));
        XL_TEST_ASSERT(!r.Match(_T("1234567890\n")));
        XL_TEST_ASSERT(!r.Match(_T("abcdefg\n")));

        XL_TEST_ASSERT(r.Parse(_T("[.\n]")));
        XL_TEST_ASSERT(r.Match(_T("\n")));
        XL_TEST_ASSERT(r.Match(_T(".")));
        XL_TEST_ASSERT(r.Match(_T("\r")));
        XL_TEST_ASSERT(r.Match(_T("a")));
        XL_TEST_ASSERT(r.Match(_T("A")));
        XL_TEST_ASSERT(r.Match(_T("0")));

        XL_TEST_ASSERT(r.Parse(_T("[^.\n]")));
        XL_TEST_ASSERT(!r.Match(_T("\n")));
        XL_TEST_ASSERT(!r.Match(_T(".")));
        XL_TEST_ASSERT(!r.Match(_T("\r")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("A")));
        XL_TEST_ASSERT(!r.Match(_T("0")));

        XL_TEST_ASSERT(r.Parse(_T("[^.]")));
        XL_TEST_ASSERT(r.Match(_T("\n")));
        XL_TEST_ASSERT(!r.Match(_T(".")));
        XL_TEST_ASSERT(!r.Match(_T("\r")));
        XL_TEST_ASSERT(!r.Match(_T("a")));
        XL_TEST_ASSERT(!r.Match(_T("A")));
        XL_TEST_ASSERT(!r.Match(_T("0")));
    }

    XL_TEST_CASE()
    {
        RegExp r;

        // \d \D \f \n \r \s \S \t \v \w\ W

        XL_TEST_ASSERT(r.Parse(_T("\\d*")));
        XL_TEST_ASSERT(r.Match(_T("0123456789")));
        XL_TEST_ASSERT(!r.Match(_T("\x29")));
        XL_TEST_ASSERT(!r.Match(_T("\x3a")));
        XL_TEST_ASSERT(r.Parse(_T("[\\d]*")));
        XL_TEST_ASSERT(r.Match(_T("0123456789")));
        XL_TEST_ASSERT(!r.Match(_T("\x29")));
        XL_TEST_ASSERT(!r.Match(_T("\x3a")));
        XL_TEST_ASSERT(r.Parse(_T("[^\\D]*")));
        XL_TEST_ASSERT(r.Match(_T("0123456789")));
        XL_TEST_ASSERT(!r.Match(_T("\x29")));
        XL_TEST_ASSERT(!r.Match(_T("\x3a")));

        XL_TEST_ASSERT(r.Parse(_T("\\t")));
        XL_TEST_ASSERT(r.Match(_T("\x09")));
        XL_TEST_ASSERT(!r.Match(_T("\x08")));
        XL_TEST_ASSERT(!r.Match(_T("\x0a")));
        XL_TEST_ASSERT(r.Parse(_T("\\n")));
        XL_TEST_ASSERT(r.Match(_T("\x0a")));
        XL_TEST_ASSERT(!r.Match(_T("\x09")));
        XL_TEST_ASSERT(!r.Match(_T("\x0b")));
        XL_TEST_ASSERT(r.Parse(_T("\\v")));
        XL_TEST_ASSERT(r.Match(_T("\x0b")));
        XL_TEST_ASSERT(!r.Match(_T("\x0a")));
        XL_TEST_ASSERT(!r.Match(_T("\x0c")));
        XL_TEST_ASSERT(r.Parse(_T("\\f")));
        XL_TEST_ASSERT(r.Match(_T("\x0c")));
        XL_TEST_ASSERT(!r.Match(_T("\x0b")));
        XL_TEST_ASSERT(!r.Match(_T("\x0d")));
        XL_TEST_ASSERT(r.Parse(_T("\\r")));
        XL_TEST_ASSERT(r.Match(_T("\x0d")));
        XL_TEST_ASSERT(!r.Match(_T("\x0c")));
        XL_TEST_ASSERT(!r.Match(_T("\x0e")));

        XL_TEST_ASSERT(r.Parse(_T("\\s*")));
        XL_TEST_ASSERT(r.Match(_T("\x09\x0a\x0b\x0c\x0d")));
        XL_TEST_ASSERT(!r.Match(_T("\x08")));
        XL_TEST_ASSERT(!r.Match(_T("\x0e")));
        XL_TEST_ASSERT(r.Parse(_T("[^\\S]*")));
        XL_TEST_ASSERT(r.Match(_T("\x09\x0a\x0b\x0c\x0d")));
        XL_TEST_ASSERT(!r.Match(_T("\x08")));
        XL_TEST_ASSERT(!r.Match(_T("\x0e")));
        XL_TEST_ASSERT(r.Parse(_T("\\w*")));
        XL_TEST_ASSERT(r.Match(_T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_")));
        XL_TEST_ASSERT(!r.Match(_T("\x60")));
        XL_TEST_ASSERT(!r.Match(_T("\x7b")));
        XL_TEST_ASSERT(!r.Match(_T("\x40")));
        XL_TEST_ASSERT(!r.Match(_T("\x5b")));
        XL_TEST_ASSERT(!r.Match(_T("\x29")));
        XL_TEST_ASSERT(!r.Match(_T("\x3a")));
        XL_TEST_ASSERT(!r.Match(_T("\x5e")));
        XL_TEST_ASSERT(!r.Match(_T("\x60")));
        XL_TEST_ASSERT(r.Parse(_T("[^\\W]*")));
        XL_TEST_ASSERT(r.Match(_T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_")));
        XL_TEST_ASSERT(!r.Match(_T("\x60")));
        XL_TEST_ASSERT(!r.Match(_T("\x7b")));
        XL_TEST_ASSERT(!r.Match(_T("\x40")));
        XL_TEST_ASSERT(!r.Match(_T("\x5b")));
        XL_TEST_ASSERT(!r.Match(_T("\x29")));
        XL_TEST_ASSERT(!r.Match(_T("\x3a")));
        XL_TEST_ASSERT(!r.Match(_T("\x5e")));
        XL_TEST_ASSERT(!r.Match(_T("\x60")));
    }

    XL_TEST_CASE()
    {
        RegExp r;

        // \xHH \uHHHH

        XL_TEST_ASSERT(!r.Parse(_T("\\x")));
        XL_TEST_ASSERT(!r.Parse(_T("\\x4")));
        XL_TEST_ASSERT(r.Parse(_T("\\x41")));
        XL_TEST_ASSERT(r.Parse(_T("\\x413")));
        XL_TEST_ASSERT(r.Match(_T("A3")));

        XL_TEST_ASSERT(r.Parse(_T("\\x41\\x42\\x43\\x44\\x45\\x46\\x47")));
        XL_TEST_ASSERT(r.Match(_T("ABCDEFG")));

        XL_TEST_ASSERT(r.Parse(_T("[\\x41\\x42]")));
        XL_TEST_ASSERT(r.Match(_T("A")));
        XL_TEST_ASSERT(r.Match(_T("B")));
        XL_TEST_ASSERT(!r.Match(_T("C")));

#ifdef _UNICODE
        XL_TEST_ASSERT(!r.Parse(_T("\\u")));
        XL_TEST_ASSERT(!r.Parse(_T("\\u5")));
        XL_TEST_ASSERT(!r.Parse(_T("\\u59")));
        XL_TEST_ASSERT(!r.Parse(_T("\\u597")));
        XL_TEST_ASSERT(r.Parse(_T("\\u597d")));
        XL_TEST_ASSERT(r.Parse(_T("\\u597de")));
        XL_TEST_ASSERT(r.Match(_T("ºÃe")));

        XL_TEST_ASSERT(r.Parse(_T("\\u4f60\\u597d")));
        XL_TEST_ASSERT(r.Match(_T("ÄãºÃ")));

        XL_TEST_ASSERT(r.Parse(_T("[\\u4f60\\u597d]")));
        XL_TEST_ASSERT(r.Match(_T("Äã")));
        XL_TEST_ASSERT(r.Match(_T("ºÃ")));
        XL_TEST_ASSERT(!r.Match(_T("Éµ")));
#endif
    }

    XL_TEST_CASE()
    {
        RegExp r;

        XL_TEST_ASSERT(r.Parse(_T("(a)")));
        XL_TEST_ASSERT(r.Parse(_T("(?:a)")));
        XL_TEST_ASSERT(r.Parse(_T("(?=a)")));
        XL_TEST_ASSERT(r.Parse(_T("(?!a)")));
        XL_TEST_ASSERT(r.Parse(_T("(?<=a)")));
        XL_TEST_ASSERT(r.Parse(_T("(?<!a)")));
        XL_TEST_ASSERT(r.Parse(_T("(?<a>a)")));
    }

    XL_TEST_CASE()
    {
        RegExp r;

        XL_TEST_ASSERT(r.Parse(_T("http://([a-zA-Z0-9\\-]+\\.)+[a-zA-Z]+/")));
        XL_TEST_ASSERT(r.Match(_T("http://streamlet.org/")));
        XL_TEST_ASSERT(r.Match(_T("http://w-1.streamlet.org/")));
        XL_TEST_ASSERT(r.Match(_T("http://w-1.w-2.streamlet.org/")));
        XL_TEST_ASSERT(r.Match(_T("http://w-1.w-2.w-3.streamlet.org/")));
        XL_TEST_ASSERT(!r.Match(_T("http://org/")));
        XL_TEST_ASSERT(!r.Match(_T("http://streamlet.o-g/")));
    }
}
