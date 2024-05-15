#include "MainMemory.h"

// Constructors
MainMemory::MainMemory()
{
	Capacity = 0;
	TechnologyType = "N/A";
}
MainMemory::MainMemory(int pCapacity = 0, string pTechnologyType = "N/A")
{
	Capacity = pCapacity;
	TechnologyType = pTechnologyType;  // Semiconductor, Silicon
}

// Getters
int MainMemory::getCapacity() const
{
	return Capacity;
}
string MainMemory::getTechnologyType() const
{
	return TechnologyType;
}

// Setters
void MainMemory::setCapacity(int pCapacity)
{
	Capacity = pCapacity;
}
void MainMemory::setTechnologyType(string pTechnologyType)
{
	TechnologyType = pTechnologyType;
}