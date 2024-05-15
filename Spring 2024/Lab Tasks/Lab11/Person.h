#pragma once
#include <iostream>
using namespace std;

class Person
{
protected:
	string Name;
	string Address;

public:
	// Constructors
	Person();

	Person(string p_Name, string p_Address);

	// Getters
	string getName();

	string getAddress();

	// Setters
	void setName(string p_Name);

	void setAddress(string p_Address);

	void print();
};