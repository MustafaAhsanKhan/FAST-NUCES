#pragma once
#include "../Project_Lab11/Employee.h"

class ProductionWorker : public Employee
{
private:
	int Shift;  // 1 is day shift // 2 is night shift
	double HourlyPay;
	double Salary;
	
public:
	// Contructors
	ProductionWorker();

	ProductionWorker(string p_Name, string p_Address, int p_EmployeeNumber, int p_HoursWorked, int p_Shift, double p_HourlyPay);

	// Getters
	int getShift();

	double getHourlyPay();

	double getSalary();

	void calculateSalary();

	// Setters
	void setShift(int p_Shift);

	void setHourlyPay(double p_HourlyPay);

	void setSalary(double p_Salary);

	void print_details();
};

