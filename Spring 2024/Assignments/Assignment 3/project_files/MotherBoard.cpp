#include "MotherBoard.h"

// Constructors
MotherBoard::MotherBoard()
{
    mm = NULL;
    ports = NULL;
    numPorts = 0;
}
MotherBoard::MotherBoard(MainMemory* memory = NULL, int numPorts = 0)
{
    mm = memory;
    this->numPorts = numPorts;
    ports = new Port[numPorts]; // Allocate memory for ports array
}
MotherBoard::MotherBoard(MainMemory* memory, const Port* ports, int numPorts)
{
    mm = memory;
    this->numPorts = numPorts;

    this->ports = new Port[numPorts]; // Allocate memory for ports array
    for (int i = 0; i < numPorts; ++i)
    {
        this->ports[i] = ports[i];
    }
}

// Getters
MainMemory* MotherBoard::getMainMemory() const
{
    return mm;
}
Port* MotherBoard::getPorts() const
{
    return ports;
}
int MotherBoard::getNumPorts() const
{
    return numPorts;
}

// Setters
void MotherBoard::setMainMemory(MainMemory* memory)
{
    mm = memory;
}
void MotherBoard::setPorts(const Port* ports, int numPorts)
{
    this->numPorts = numPorts;
    delete[] this->ports; // Deallocate previous memory

    this->ports = new Port[numPorts]; // Allocate new memory for ports array
    for (int i = 0; i < numPorts; ++i)
    {
        this->ports[i] = ports[i];
    }
}

// Destructor
MotherBoard::~MotherBoard()
{
    delete[] ports; // Deallocate memory for ports array
}