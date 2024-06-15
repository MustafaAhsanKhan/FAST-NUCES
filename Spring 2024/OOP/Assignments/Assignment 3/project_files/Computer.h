#pragma once
#include "../assignment3_project/PhysicalMemory.h"
#include "../assignment3_project/MotherBoard.h"
#include "../assignment3_project/CPU.h"

class Computer
{
private:
	MotherBoard* mb;
	CPU* cpu;
	AppleCPU* Apple_cpu;

public:
	// Constructors
	Computer();

	Computer(MotherBoard* p_mb, CPU* p_cpu);

	// Getters
	MotherBoard* getMotherboard() const;

	CPU* getCPU() const;

	AppleCPU* getAppleCPU() const;

	// Setters
	void setMB(MotherBoard* p_mb);

	void setCPU(CPU* p_cpu);

	void setCPU(AppleCPU* p_Applecpu);
};

