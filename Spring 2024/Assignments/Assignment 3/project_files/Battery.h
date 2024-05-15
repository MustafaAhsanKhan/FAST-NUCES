#pragma once
class Battery
{
private:
	int Capacity;

public:
	// Constructors
	Battery();

	Battery(int p_Capacity);

	// Getters
	int getCapacity();

	// Setters
	void setCapacity(int p_Capacity);
};