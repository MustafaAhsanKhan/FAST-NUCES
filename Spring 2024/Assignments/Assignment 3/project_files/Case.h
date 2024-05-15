#pragma once
#include <iostream>
using namespace std;

class Case
{
private:
	string formFactor;
	string Color;

public:
	// Constructors
	Case();

	Case(string p_FF, string p_Color);

	// Getters
	string getFF();

	string getColor();

	// Setters
	void setFF(string p_FF);

	void setColor(string p_Color);
};