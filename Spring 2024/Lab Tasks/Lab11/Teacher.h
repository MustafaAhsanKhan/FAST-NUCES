#pragma once
#include "../Project_Lab11/Faculty.h"

class Teacher : public Faculty
{
private:
	string Program;

public:
	// Constructors
	Teacher()
	{
		Program = "N/A";
	}

	Teacher(string Name, int CNIC, int DOB, int Age, unsigned int Contact, int PayScale, int RoomNumber, string Subject, string Rank, string p_Program) : Faculty(Name, CNIC, DOB, Age, Contact, PayScale, RoomNumber, Subject, Rank)
	{
		Program = p_Program;
	}

	// Getter
	string getProgram()
	{
		return Program;
	}

	void print()
	{
		Faculty::print();
		cout << "Teaching Program: " << Program;
	}
};

