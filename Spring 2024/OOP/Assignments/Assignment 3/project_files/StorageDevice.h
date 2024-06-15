#pragma once
#include <iostream>
using namespace std;

class StorageDevice
{
private:
	string Type;
	int Capacity;
	double Price;

public:
	// Constructors
	StorageDevice();

	StorageDevice(string p_Type, int p_Capacity, double p_Price);

	// Getters
	string getType() const;

	int getCapacity() const;

	double getPrice() const;

	// Setters
	void setType(string p_Type);

	void setCapacity(int p_Capacity);

	void setPrice(double p_Price);
};

