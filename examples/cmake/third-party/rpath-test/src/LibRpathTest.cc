#include <LibRpathTest.h>

RPathTest::printClass::printClass()
{
}

RPathTest::printClass::~printClass()
{
}

double RPathTest::printClass::doSomething()
{
    double x = 0.2;
    return x;
}

RPathTest::doubleprintClass::doubleprintClass():
        printClass()
{
}

RPathTest::doubleprintClass::~doubleprintClass()
{
}

double RPathTest::doubleprintClass::doSomething()
{
    double x = 0.4;
    return x;
}