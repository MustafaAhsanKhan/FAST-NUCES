#pragma once
#include <iostream>
using namespace std;

class GraphicsCard
{
private:
	string Brand;
	int memorySize;
	double Price;

public:
	// Constructors
	GraphicsCard();

	GraphicsCard(string p_Brand, int p_memorySize, double p_Price);

	// Getters
	string getBrand() const;

	int getmemorySize() const;

	double getPrice() const;

	// Setters
	void setBrand(string p_Brand);

	void setmemorySize(int p_memorySize);

	void setPrice(double p_Price);
};

