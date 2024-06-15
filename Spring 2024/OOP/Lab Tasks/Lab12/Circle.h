#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	float radius;

public:
	Circle()
	{
		radius = 0;
	}
	Circle(float radius, string type) : Shape(type)
	{
		this->radius = radius;
	}
	virtual void area()
	{
		cout << "The area of circle is: " << 3.14 * radius * radius << endl;
	}
};

