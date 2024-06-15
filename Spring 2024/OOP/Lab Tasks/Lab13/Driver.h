#pragma once
#include "Employee.h"

class Driver : public Employee
{
private:
	int salary;

public:
	Driver(int salary, int Emp_no) : Employee(Emp_no)
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