#include "University.h"

University::University()
{
	name = "FAST";
	dept = NULL;
}

bool University::addDepartment(Department D)
{
	dept = new Department;
	dept->setdeptID(D.getdeptID());
	dept->setname(D.getname());
	return 1;
}

bool University::deleteDepartment(string name)
{
	if (dept->getname() == name)
	{
		dept = NULL;
		return 1;
	}
	return 0;
}

bool University::updateDepartment(int id, string name)
{
	dept->setdeptID(id);
	dept->setname(name);
	return 1;
}

void University::Display()
{
	cout << "University name: " << name;
	if (dept != NULL)
	{
		cout << endl << "Department name: " << dept->getname() << endl;
		cout << "Department ID: " << dept->getdeptID() << endl;
	}
}