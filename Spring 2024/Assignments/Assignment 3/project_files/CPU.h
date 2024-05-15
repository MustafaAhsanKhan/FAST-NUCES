#pragma once
#include "../assignment3_project/ALU.h"
#include "../assignment3_project/ControlUnit.h"
#include "../assignment3_project/GraphicsCard.h"
class CPU
{
protected:
	ALU* alu;
	ControlUnit* cu;

public:
	// Constructor
	CPU();

	CPU(ALU* p_alu, ControlUnit* p_cu);

	// Getters
	ALU* getALU() const;

	ControlUnit* getCU() const;

	// Setters
	void setALU(ALU* p_alu);

	void setCU(ControlUnit* p_cu);

	// Destructor
	~CPU();
};

class AppleCPU : public CPU
{
private:
	GraphicsCard iGPU;

public:
	// Contructor
	AppleCPU(ALU* p_alu, ControlUnit* p_cu)
	{
		alu = p_alu;
		cu = p_cu;
		iGPU.setBrand("Apple Silicon");
	}
	// Getter
	GraphicsCard& getiGPU()
	{
		return iGPU;
	}

	// Setter
	void setiGPU(GraphicsCard p_iGPU)
	{
		iGPU = p_iGPU;
	}
};

class IntelCPU : public CPU
{
private:
	GraphicsCard* iGPU;

public:
	// Constructor
	IntelCPU(ALU* p_alu, ControlUnit* p_cu)
	{
		alu = p_alu;
		cu = p_cu;
		iGPU = NULL;
	}

	// Getter
	GraphicsCard* getiGPU()
	{
		return iGPU;
	}

	// Setter
	void setiGPU(GraphicsCard* p_iGPU)
	{
		iGPU = p_iGPU;
	}
};


