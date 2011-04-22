//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   Main.cpp
//    Author:      Streamlet
//    Create Time: 2011-04-23
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------


#include <xl/Containers/xlTuple.h>
#include <xl/Test/xlUnitTest.h>

using namespace xl;

XL_TEST_CASE()
{
    Tuple<int, int> a(1, 2);
    XL_TEST_ASSERT(a._0 == 1);
    XL_TEST_ASSERT(a._1 == 2);

    Tuple<int, int> b(3, 4);
    XL_TEST_ASSERT(b._0 == 3);
    XL_TEST_ASSERT(b._1 == 4);

    Tuple<int, int> c(b);
    XL_TEST_ASSERT(c._0 == 3);
    XL_TEST_ASSERT(c._1 == 4);

    Tuple<int, int> d;
    d = c;
    XL_TEST_ASSERT(d._0 == 3);
    XL_TEST_ASSERT(c._1 == 4);
}

XL_TEST_CASE()
{
    Tuple<int, int> a(1, 1), b(1, 1);
    XL_TEST_ASSERT(a == b);
    XL_TEST_ASSERT(!(a != b));
    XL_TEST_ASSERT(!(a < b));
    XL_TEST_ASSERT(!(a > b));
    XL_TEST_ASSERT(a <= b);
    XL_TEST_ASSERT(a >= b);

    a._0 = -1;
    XL_TEST_ASSERT(!(a == b));
    XL_TEST_ASSERT(a != b);
    XL_TEST_ASSERT(a < b);
    XL_TEST_ASSERT(!(a > b));
    XL_TEST_ASSERT(a <= b);
    XL_TEST_ASSERT(!(a >= b));

    a._0 = 2;
    XL_TEST_ASSERT(!(a == b));
    XL_TEST_ASSERT(a != b);
    XL_TEST_ASSERT(!(a < b));
    XL_TEST_ASSERT(a > b);
    XL_TEST_ASSERT(!(a <= b));
    XL_TEST_ASSERT(a >= b);
}

int main()
{
    return 0;
}
