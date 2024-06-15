#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	float height;
	float width;

public:
	Rectangle()
	{
		height = 0;
		width = 0;
	}
	Rectangle(float h, float w, string type) : Shape(type)
	{
		height = h;
		width = w;
	}
	virtual void area()
	{
		cout << "The area of the rectangle is: " << height * width << endl;
	}
};