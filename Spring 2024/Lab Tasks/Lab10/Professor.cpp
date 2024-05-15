#include "Professor.h"

Professor::Professor()
{
	name = "N/A";
	employeeID = -1;
	designation = "N/A";
}

// Getters
string Professor::getname()
{
	return name;
}

int Professor::getemployeeID()
{
	return employeeID;
}

string Professor::getdesignation()
{
	return designation;
}

// Setters
void Professor::setname(string name)
{
	this->name = name;
}

void Professor::setemployeeID(int ID)
{
	employeeID = ID;
}

void Professor::setdesignation(string desg)
{
	designation = desg;
}