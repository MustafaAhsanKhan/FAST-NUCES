#include "PhysicalMemory.h"

// Constructors
PhysicalMemory::PhysicalMemory()
{
	Capacity = 0;
}

PhysicalMemory::PhysicalMemory(int p_Capacity = 0)
{
	Capacity = p_Capacity;
}

// Getters
int PhysicalMemory::getCapacity() const
{
	return Capacity;
}

// Setters
void PhysicalMemory::setCapacity(int p_Capacity)
{
	Capacity = p_Capacity;
}