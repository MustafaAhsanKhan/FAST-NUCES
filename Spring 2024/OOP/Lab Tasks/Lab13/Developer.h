#pragma once
#include "Employee.h"

class Developer : public Employee
{
private:
	int salary;
public:
	Developer(int salary, int Emp_no) : Employee(Emp_no)
	{
		this->salary = salary;
	}
	virtual int getSalary()
	{
		return salary;
	}
	void setSalary(int salary)
	{
		this->salary = salary;
	}
};