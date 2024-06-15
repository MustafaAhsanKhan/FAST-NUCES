#pragma once
class ControlUnit
{
private:
	float Clock;

public:
	// Constructors
	ControlUnit();

	ControlUnit(float pClock);

	// Getters
	float getClock() const;

	// Setters
	void setClock(float pClock);
};