#pragma once
#include "Person.h"
class Employee : public Person
{
protected:
	int Emp_no;
	float gross_pay;
	float house_rent;
	float medical_allowance;
	float net_pay;

public:
	Employee()
	{
		Emp_no = 0;
		gross_pay = 0;
		house_rent = 0;
		medical_allowance = 0;
		net_pay = 0;
	}
	Employee(int e, float g, float h, float m, float n, string name, string address) : Person(name, address)
	{
		Emp_no = e;
		gross_pay = g;
		house_rent = h;
		medical_allowance = m;
		net_pay = n;
	}
	void calcSalary()
	{
		net_pay = gross_pay - (((house_rent/100) *gross_pay) - ((medical_allowance/100) * gross_pay));
	}

	void display()
	{
		Person::display();
		cout << "Employee Number: " << Emp_no << endl;
		cout << "Gross Pay: " << gross_pay << endl;
		cout << "Net Pay: " << net_pay << endl;
		cout << "House Rent: " << house_rent << endl;
		cout << "Medical Allowance: " << medical_allowance << endl;
	}
};