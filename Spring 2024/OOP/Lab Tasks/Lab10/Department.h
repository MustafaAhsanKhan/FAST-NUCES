#pragma once
#include <iostream>
using namespace std;
#include "../lab10_project/Professor.h"
class Department
{
private:
	string name;
	int deptID;
	Professor* prof;

public:
	Department();

	string getname();

	int getdeptID();

	void setname(string name);

	void setdeptID(int ID);

	bool addProfessor(Professor* p);

	bool deleteProfessor(int id);

	bool updateProfessor(int id, string newDesignation);

	void Display();
};

