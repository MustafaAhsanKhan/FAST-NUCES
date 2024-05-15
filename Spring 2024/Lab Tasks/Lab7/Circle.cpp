#include "Circle.h"
#include <iostream>
using namespace std;

int Circle::countOfCircles = 0;
Circle::Circle()
{
    radius = 0;
    ++countOfCircles;
}

Circle::Circle(int rad)
{
    radius = rad;
    ++countOfCircles;
}

int Circle::getrad()
{
    return radius;
}

void Circle::setrad(int rad)
{
    radius = rad;
}

int Circle::getcountOfCircles()
{
    return countOfCircles;
}

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

double Circle::getPerimeter()
{
    return 2 * 3.14 * radius;
}

Circle::~Circle()
{
    --countOfCircles;
}