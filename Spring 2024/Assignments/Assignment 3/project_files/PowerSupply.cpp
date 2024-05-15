#include "PowerSupply.h"

// Constructors
PowerSupply::PowerSupply()
{
	Wattage = 0;
	efficiencyRating = "N/A";
	Price = 0;
}

PowerSupply::PowerSupply(int p_Wattage = 0, string p_ER = "N/A", double p_Price = 0)
{
	Wattage = p_Wattage;
	efficiencyRating = p_ER;
	Price = p_Price;
}

// Getters
int PowerSupply::getWattage()
{
	return Wattage;
}

string PowerSupply::getER()
{
	return efficiencyRating;
}

double PowerSupply::getPrice()
{
	return Price;
}

// Setters
void PowerSupply::setWattage(int p_Wattage)
{
	Wattage = p_Wattage;
}

void PowerSupply::setER(string p_ER)
{
	efficiencyRating = p_ER;
}

void PowerSupply::setPrice(double p_Price)
{
	Price = p_Price;
}