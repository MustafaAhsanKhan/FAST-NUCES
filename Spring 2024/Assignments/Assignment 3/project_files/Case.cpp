#include "Case.h"

// Constructors
Case::Case()
{
	formFactor = "N/A";
	Color = "N/A";
}

Case::Case(string p_FF = "N/A", string p_Color = "N/A")
{
	formFactor = p_FF;
	Color = p_Color;
}

// Getters
string Case::getFF()
{
	return formFactor;
}

string Case::getColor()
{
	return Color;
}

// Setters
void Case::setFF(string p_FF)
{
	formFactor = p_FF;
}

void Case::setColor(string p_Color)
{
	Color = p_Color;
}