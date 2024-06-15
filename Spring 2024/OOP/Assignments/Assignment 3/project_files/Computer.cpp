#include "Computer.h"

// Constructors
Computer::Computer()
{
	mb = NULL;
	cpu = NULL;
	Apple_cpu = NULL;
}

Computer::Computer(MotherBoard* p_mb = NULL, CPU* p_cpu = NULL)
{
	mb = p_mb;
	cpu = p_cpu;
	Apple_cpu = NULL;
}

// Getters
MotherBoard* Computer::getMotherboard() const
{
	return mb;
}

CPU* Computer::getCPU() const
{
	return cpu;
}

AppleCPU* Computer::getAppleCPU() const
{
	return Apple_cpu;
}

// Setters
void Computer::setMB(MotherBoard* p_mb)
{
	mb = p_mb;
}

void Computer::setCPU(CPU* p_cpu)
{
	cpu = p_cpu;
}

void Computer::setCPU(AppleCPU* p_Applecpu)
{
	Apple_cpu = p_Applecpu;
}