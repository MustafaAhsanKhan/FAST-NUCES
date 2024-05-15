#pragma once
#include <iostream>
using namespace std;

class Professor
{
private:
	string name;
	int employeeID;
	string designation;

public:
	Professor();
	
	// Getters
	string getname();

	int getemployeeID();

	string getdesignation();

	// Setters
	void setname(string name);

	void setemployeeID(int ID);

	void setdesignation(string desg);

};

