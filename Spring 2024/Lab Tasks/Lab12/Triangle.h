#pragma once
#include "Shape.h"
class Triangle : public Shape
{
private:
	float base;
	float height;

public:
	Triangle()
	{
		base = 0;
		height = 0;
	}
	Triangle(float b, float h, string type) : Shape(type)
	{
		base = b;
		height = h;
	}
	virtual void area()
	{
		cout << "The area of the triangle is: " << (base * height) / 2 << endl;
	}
};

