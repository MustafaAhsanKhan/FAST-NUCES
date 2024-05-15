#include "Employee.h"
#include "Developer.h"
#include "Driver.h"

#include <iostream>
using namespace std;

int main()
{
	Employee* emp = new Driver(150, 1);
	cout << "Driver salary : " << endl;
	cout << emp->getSalary() << endl;

	emp = new Developer(1500, 1);
	cout << "Developer salary : " << endl;
	cout << emp->getSalary() << endl;

	delete emp;

	return 0;
}