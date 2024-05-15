#include "Port.h"

// Constructors
Port::Port()
{
    type = "N/A";
    baudRate = 9600; // Default baud rate
}
Port::Port(const string& portType = "N/A", int rate = 9600)
{
    type = portType;
    baudRate = rate;
}

// Getters
string Port::getType() const
{
    return type;
}
int Port::getBaudRate() const
{
    return baudRate;
}

// Setters
void Port::setType(const string& portType)
{
    type = portType;
}
void Port::setBaudRate(int rate)
{
    baudRate = rate;
}