#pragma once
#include <iostream>
using namespace std;

class Circle
{
private:

    int radius;
    static int countOfCircles;

public:

    Circle();

    Circle(int rad);

    int getrad();

    void setrad(int rad);

    static int getcountOfCircles();

    double getArea();

    double getPerimeter();

    ~Circle();
};

