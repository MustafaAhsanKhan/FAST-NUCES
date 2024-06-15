#pragma once
#include "../Project_Lab11/Person.h"

class Employee : public Person
{
protected:
	int EmployeeNumber;
	int HoursWorked;  // 5+ night hours // 1000 bonus

public:
	// Contructors
	Employee();

	Employee(string p_Name, string p_Address, int p_EmployeeNumber, int p_HoursWorked);

	// Getters
	int getEmployeeNumber();

	int getHoursWorked();

	// Setters
	void setEmployeeNumber(int p_EmployeeNumber);

	void setHoursWorked(int p_HoursWorked);

	void print();
};