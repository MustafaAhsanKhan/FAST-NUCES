#include "Point.h"
#include <iostream>
using namespace std;

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int a, int b)
{
    x = a;
    y = b;
}

void Point::setx(int a)
{
    x = a;
}

void Point::sety(int b)
{
    y = b;
}

int Point::getx()
{
    return x;
}

int Point::gety()
{
    return y;
}

void Point::display()
{
    cout << x;
    cout << ",";
    cout << y;
}