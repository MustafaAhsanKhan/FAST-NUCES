#pragma once
class Employee
{
protected:
	int Emp_no;

public:
	Employee(int p_emp_no)
	{
		Emp_no = p_emp_no;
	}
	virtual int getSalary() = 0;
};