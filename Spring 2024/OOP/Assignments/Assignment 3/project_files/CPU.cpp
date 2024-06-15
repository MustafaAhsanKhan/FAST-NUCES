#include "CPU.h"
#include <iostream>

// Constructor
CPU::CPU()
{
	alu = new ALU;
	cu = new ControlUnit;
}
CPU::CPU(ALU* p_alu = NULL, ControlUnit* p_cu = NULL)
{
	alu = p_alu;
	cu = p_cu;
}

// Getters
ALU* CPU::getALU() const
{
	return alu;
}
ControlUnit* CPU::getCU() const
{
	return cu;
}

// Setters
void CPU::setALU(ALU* p_alu)
{
	alu = p_alu;
}
void CPU::setCU(ControlUnit* p_cu)
{
	cu = p_cu;
}

// Destructor
CPU::~CPU()
{
	delete alu;
	delete cu;
}