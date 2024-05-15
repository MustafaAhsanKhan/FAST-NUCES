#include "Employee.h"

// Contructors
Employee::Employee()
{
	EmployeeNumber = 0;
	HoursWorked = 0;
}

Employee::Employee(string p_Name, string p_Address, int p_EmployeeNumber, int p_HoursWorked) : Person(p_Name, p_Address)
{
	EmployeeNumber = p_EmployeeNumber;
	HoursWorked = p_HoursWorked;
}

// Getters
int Employee::getEmployeeNumber()
{
	return EmployeeNumber;
}

int Employee::getHoursWorked()
{
	return HoursWorked;
}

// Setters
void Employee::setEmployeeNumber(int p_EmployeeNumber)
{
	EmployeeNumber = p_EmployeeNumber;
}

void Employee::setHoursWorked(int p_HoursWorked)
{
	HoursWorked = p_HoursWorked;
}

void Employee::print()
{
	Person::print();
	cout << "EmployeeNumber: " << EmployeeNumber << endl;
	cout << "Hours worked: " << HoursWorked << endl;
}