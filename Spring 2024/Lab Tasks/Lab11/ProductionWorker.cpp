#include "ProductionWorker.h"

// Contructors
ProductionWorker::ProductionWorker()
{
	Name = "N/A";
	Address = "N/A";
	EmployeeNumber = 0;
	HoursWorked = 0;
	Shift = 0;
	HourlyPay = 0;
	Salary = 0;
}

ProductionWorker::ProductionWorker(string p_Name, string p_Address, int p_EmployeeNumber, int p_HoursWorked, int p_Shift, double p_HourlyPay): Employee(p_Name, p_Address, p_EmployeeNumber, p_HoursWorked)
{
	Shift = p_Shift;
	HourlyPay = p_HourlyPay;
	Salary = 0;
}

// Getters
int ProductionWorker::getShift()
{
	return Shift;
}

double ProductionWorker::getHourlyPay()
{
	return HourlyPay;
}

double ProductionWorker::getSalary()
{
	return Salary;
}

void ProductionWorker::calculateSalary()
{
	Salary = HoursWorked * HourlyPay;
	if (Shift == 2 && HoursWorked > 5)
	{
		Salary += 1000;  // Bonus
	}
}

// Setters
void ProductionWorker::setShift(int p_Shift)
{
	Shift = p_Shift;
}

void ProductionWorker::setHourlyPay(double p_HourlyPay)
{
	HourlyPay = p_HourlyPay;
}

void ProductionWorker::setSalary(double p_Salary)
{
	Salary = p_Salary;
}

void ProductionWorker::print_details()
{
	Employee::print();

	if (Shift == 1)
	{
		cout << "Shift: Day" << endl;
	}
	else
	{
		cout << "Shift: Night" << endl;
	}
	cout << "Pay Rate: " << HourlyPay << endl;
	cout << "Salary: " << Salary << endl;
}