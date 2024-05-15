#include "Person.h"

// Constructors
Person::Person()
{
	Name = "N/A";
	Address = "N/A";
}

Person::Person(string p_Name, string p_Address)
{
	Name = p_Name;
	Address = p_Address;
}

// Getters
string Person::getName()
{
	return Name;
}

string Person::getAddress()
{
	return Address;
}

// Setters
void Person::setName(string p_Name)
{
	Name = p_Name;
}

void Person::setAddress(string p_Address)
{
	Address = p_Address;
}

void Person::print()
{
	cout << "Name: " << Name << endl;
	cout << "Address: " << Address << endl;
}