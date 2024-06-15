#pragma once
#include "Employee.h"
class Faculty : Employee
{
protected:
	string designation;
	string department;


public:
	Faculty()
	{
		designation = " ";
		department = " ";
	}
	Faculty(string p_designaition, string p_department, int e, float g, float h, float m, float n, string name, string address) : Employee(e, g, h, m, n, name, address)
	{
		designation = p_designaition;
		department = p_department;
	}
	

	void display()
	{
		Employee::calcSalary();
		Employee::display();
		cout << "Designation: " << designation << endl;
		cout << "Department: " << department << endl;
	}
};

