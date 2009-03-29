/*******************************************************************************

    Copyright (C) Streamlet. All rights reserved.

    File Name:   Main.cpp
    Author:      Streamlet
    Create Time: 2009-03-27
    Description: 

    Version history:



*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "xlArray.h"
#include <assert.h>
// DebugNew.h might be in conflict with some other codes, such as STL.
// If you use STL, do include STL header files before DebugNew.h.
#include "DebugNew.h"

using namespace xl;

template <typename T>
ostream &operator<<(ostream &out, const Array<T> &arr)
{
    out << "Array[" << arr.Size() << "]: { ";

    for (int i = 0; i < arr.Size(); ++i)
    {
        out << arr[i] << "  ";
    }

    out << "\b}";

    return out;
}

int main()
{
    Array<int> a;

    a.PushBack(10);
    a.PushBack(12);
    a.PushBack(2);
    a.PushBack(3);
    a.PushBack(4);
    cout << a << endl;

    a.DeleteAt(2);
    cout << a << endl;
    a.SetSize(1);
    cout << a << endl;
    a.SetSize(5);
    cout << a << endl;
    a.SetSize(4);
    cout << a << endl;

    Array<int> b = a;
    cout << b << endl;
    
    Array<int> c;
    cout << c << endl;

    c.PushBack(0);
    cout << c << endl;

    c.AppendFront(a);
    cout << c << endl;

    c.AppendBack(a, 2);
    cout << c << endl;

    a.AppendFront(b, 3, 6);
    cout << a << endl;

    Array<Array<int> > aa;
    aa.PushBack(a);
    aa.PushBack(b);
    cout << aa << endl;
    aa.PopFront();
    cout << aa << endl;



    return 0;
};

