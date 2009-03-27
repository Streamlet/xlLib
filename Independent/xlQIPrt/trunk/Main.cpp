/*******************************************************************************

    Copyright (C) Streamlet. All rights reserved.

    File Name:   Main.cpp
    Author:      Streamlet
    Create Time: 2009-03-22
    Description: 

    Version history:



*******************************************************************************/
#include <string>
using namespace std;

#include "DebugNew.h"
//#include <assert.h>

#include "xlQIPtr.h"
using namespace xl;


int main()
{

    QIPtr<int> a(new int);
    
    //*
    QIPtr<int> b = a;
    b = a;


    class sample1
    {
        int *a;
    public:
        sample1()
        {
            a = new int;
        }
        virtual ~sample1()
        {
            delete a;
        }
    };
    class sample2 : public sample1
    {
        int *b;
    public:
        sample2()
        {
            b = new int;
        }
        ~sample2()
        {
            delete b;
        }
    };
    QIPtr<sample1> x(new sample2);
    QIPtr<sample1> y;
    y = x;
    y = x;
    QIPtr<sample1> z;
    z = y;
    z = x;


    //*/
    return 0;
}

