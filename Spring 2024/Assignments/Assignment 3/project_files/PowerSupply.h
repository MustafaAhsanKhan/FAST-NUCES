#pragma once
#include <iostream>
using namespace std;

class PowerSupply
{
private:
	int Wattage;
	string efficiencyRating;
	double Price;

public:
	// Constructors
	PowerSupply();

	PowerSupply(int p_Wattage, string p_ER, double p_Price);

	// Getters
	int getWattage();

	string getER();

	double getPrice();

	// Setters
	void setWattage(int p_Wattage);

	void setER(string p_ER);

	void setPrice(double p_Price);

};