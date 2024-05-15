#pragma once
class ALU
{
private:
    int noOfAdders;
    int noOfSubtractors;
    int noOfRegisters;
    int sizeOfRegisters;

public:
    // Constructors
    ALU();

    ALU(int adders, int subtractors, int registers, int regSize);

    // Getters
    int getNoOfAdders() const;

    int getNoOfSubtractors() const;

    int getNoOfRegisters() const;

    int getSizeOfRegisters() const;

    // Setters
    void setNoOfAdders(int adders);

    void setNoOfSubtractors(int subtractors);

    void setNoOfRegisters(int registers);

    void setSizeOfRegisters(int regSize);
};