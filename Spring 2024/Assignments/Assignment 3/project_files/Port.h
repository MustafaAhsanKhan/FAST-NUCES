#pragma once
#include <iostream>
using namespace std;

class Port
{
private:
    string type;
    int baudRate;

public:
    // Constructors
    Port();

    Port(const string& portType, int rate);

    // Getters
    string getType() const;

    int getBaudRate() const;

    // Setters
    void setType(const string& portType);

    void setBaudRate(int rate);
};