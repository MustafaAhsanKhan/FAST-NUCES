
#pragma once
#include <iostream>
using namespace std;

class NetworkCard
{
private:
	string Type;
	int Speed;
	double Price;

public:
	// Constructors
	NetworkCard();

	NetworkCard(string p_Type, int p_Speed, double p_Price);

	// Getters
	string getType() const;
	
	int getSpeed() const;

	double getPrice() const;

	// Setters
	void setType(string p_Type);

	void setSpeed(int p_Speed);

	void setPrice(double p_Price);
};

