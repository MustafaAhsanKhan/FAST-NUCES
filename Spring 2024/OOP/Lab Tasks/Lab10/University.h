#pragma once
#include <iostream>
#include "../lab10_project/Department.h"
using namespace std;
class University
{
private:
	string name;
	Department* dept;

public:
	University();

	bool addDepartment(Department D);

	bool deleteDepartment(string name);

	bool updateDepartment(int id, string name);

	void Display();
};