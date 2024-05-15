#include "Department.h"

Department::Department()
{
	name = "N/A";
	deptID = -1;
	prof = NULL;
}

string Department::getname()
{
	return name;
}

int Department::getdeptID()
{
	return deptID;
}

void Department::setname(string name)
{
	this->name = name;
}

void Department::setdeptID(int ID)
{
	deptID = ID;
}

bool Department::addProfessor(Professor* p)
{
	prof = p;
	return 1;
}

bool Department::deleteProfessor(int id)
{
	prof->setname("N/A");
	prof->setemployeeID(-1);
	prof->setdesignation("N/A");
	prof = NULL;

	return 1;
}

bool Department::updateProfessor(int id, string newDesignation)
{
	if (prof != NULL)
	{
		prof->setemployeeID(id);
		prof->setdesignation(newDesignation);
		return 1;
	}
	return 0;
}

void Department::Display()
{
	if (prof != NULL)
	{
		cout << "Professor Name: " << prof->getname() << endl;
		cout << "Professor employeeID: " << prof->getemployeeID() << endl;
		cout << "Professor designation: " << prof->getdesignation() << endl;
	}
}