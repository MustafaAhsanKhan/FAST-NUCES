#include "ALU.h"
ALU::ALU()
{
    noOfAdders = 1;
    noOfSubtractors = 1;
    noOfRegisters = 8;
    sizeOfRegisters = 32;
}

// Overloaded constructor
ALU::ALU(int adders = 1, int subtractors = 1, int registers = 8, int regSize = 32)
{
    noOfAdders = adders;
    noOfSubtractors = subtractors;
    noOfRegisters = registers;
    sizeOfRegisters = regSize;
}

// Getters
int ALU::getNoOfAdders() const
{
    return noOfAdders;
}

int ALU::getNoOfSubtractors() const
{
    return noOfSubtractors;
}

int ALU::getNoOfRegisters() const
{
    return noOfRegisters;
}

int ALU::getSizeOfRegisters() const
{
    return sizeOfRegisters;
}

// Setters
void ALU::setNoOfAdders(int adders)
{
    noOfAdders = adders;
}

void ALU::setNoOfSubtractors(int subtractors)
{
    noOfSubtractors = subtractors;
}

void ALU::setNoOfRegisters(int registers)
{
    noOfRegisters = registers;
}

void ALU::setSizeOfRegisters(int regSize)
{
    sizeOfRegisters = regSize;
}