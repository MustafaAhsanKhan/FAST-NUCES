#pragma once
class PhysicalMemory
{
private:
	int Capacity;

public:
	// Constructors
	PhysicalMemory();

	PhysicalMemory(int p_Capacity);

	// Getters
	int getCapacity() const;

	// Setters
	void setCapacity(int p_Capacity);
};

