#include "Battery.h"

// Constructors
Battery::Battery()
{
	Capacity = 0;
}

Battery::Battery(int p_Capacity = 0)
{
	Capacity = p_Capacity;
}

// Getters
int Battery::getCapacity()
{
	return Capacity;
}

// Setters
void Battery::setCapacity(int p_Capacity)
{
	Capacity = p_Capacity;
}