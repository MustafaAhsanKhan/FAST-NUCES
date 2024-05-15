#pragma once
#include <iostream>
using namespace std;
class MainMemory
{
private:
	int Capacity;
	string TechnologyType;

public:
	// Constructors
	MainMemory();

	MainMemory(int pCapacity, string pTechnologyType);

	// Getters
	int getCapacity() const;

	string getTechnologyType() const;

	// Setters
	void setCapacity(int pCapacity);

	void setTechnologyType(string pTechnologyType);
};