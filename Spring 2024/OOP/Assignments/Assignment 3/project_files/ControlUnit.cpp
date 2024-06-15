#include "ControlUnit.h"

// Constructors
ControlUnit::ControlUnit()
{
	Clock = 0;
}

ControlUnit::ControlUnit(float pClock = 0)
{
	Clock = pClock;
}

// Getters
float ControlUnit::getClock() const
{
	return Clock;
}

// Setters
void ControlUnit::setClock(float pClock)
{
	Clock = pClock;
}