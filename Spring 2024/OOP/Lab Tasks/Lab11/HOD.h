#pragma once
#include "../Project_Lab11/Faculty.h"
class HOD : public Faculty
{
private:
	int DeptID;
	string Department;

public:
	// Constructors
	HOD()
	{
		DeptID = 0;
		Department = "N/A";
	}

	HOD(string Name, int CNIC, int DOB, int Age, unsigned int Contact, int PayScale, int RoomNumber, string Subject, string Rank, int p_DeptID, string p_Department) : Faculty(Name, CNIC, DOB, Age, Contact, PayScale, RoomNumber, Subject, Rank)
	{
		DeptID = p_DeptID;
		Department = p_Department;
	}

	// Getters
	int getDeptID()
	{
		return DeptID;
	}

	string getDepartment()
	{
		return Department;
	}

	void print()
	{
		Faculty::print();
		cout << "Department ID: " << DeptID << endl;
		cout << "Department: " << Department << endl;
	}
};

