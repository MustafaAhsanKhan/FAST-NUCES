#pragma once
#include "../assignment3_project/MainMemory.h"
#include "../assignment3_project/Port.h"

class MotherBoard
{
private:
    MainMemory* mm;
    Port* ports; // Array of Ports
    int numPorts; // Number of Ports

public:
    // Constructors
    MotherBoard();

    MotherBoard(MainMemory* memory, int numPorts);

    MotherBoard(MainMemory* memory, const Port* ports, int numPorts);

    // Getters
    MainMemory* getMainMemory() const;

    Port* getPorts() const;

    int getNumPorts() const;

    // Setters
    void setMainMemory(MainMemory* memory);

    void setPorts(const Port* ports, int numPorts);

    // Destructor
    ~MotherBoard();
};