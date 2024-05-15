#pragma once
#include <iostream>
using namespace std;
class Shape
{
protected:
	string type;

public:
	Shape()
	{
		type = "";
	}
	Shape(string t)
	{
		type = t;
	}
	virtual void area()
	{
		cout << "Area = 0" << endl;
	}

	void display()
	{
		cout << "Type: " << type << endl;
	}
};