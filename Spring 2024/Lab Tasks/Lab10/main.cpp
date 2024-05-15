#include<iostream>
#include "../lab10_project/Line.h"
#include "../lab10_project/University.h"
using namespace std;

int main()
{
	// QUESTION 1

	cout << "------Question1------" << endl;

	Line l1;
	cout << "Slope: " << l1.findSlope() << endl;
	cout << "Length " << l1.findLength();

	Point MP = l1.findMidPoint();
	cout << endl;

	cout << "Midpoint: " << "(" << MP.getX_Coordinate() << "," << MP.getY_Coordinate() << ")" << endl;

	// QUESTION 2

	cout << "------Question2------" << endl;


	Professor *p = new Professor;

	p->setdesignation("Assistant Professor");
	p->setname("Ali");
	p->setemployeeID(2);

	Department D;

	D.addProfessor(p);
	D.setname("CS");
	D.setdeptID(5);

	University FAST;

	FAST.addDepartment(D);

	FAST.Display();
	D.Display();

	cout << endl <<"-----Updating professor-----" << endl;

	D.updateProfessor(5, "Professor");
	D.Display();

	cout << endl << "-----Updating department-----" << endl;

	FAST.updateDepartment(1, "FSM");
	FAST.Display();

	cout << endl << "-----Deleting professor-----" << endl;

	D.deleteProfessor(5);
	FAST.Display();

	cout << endl << "-----Deleting department-----" << endl;

	FAST.deleteDepartment("FSM");
	FAST.Display();

	return 0;
}
