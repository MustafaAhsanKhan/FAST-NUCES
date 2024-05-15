#pragma once
#include <iostream>
using namespace std;

class Person
{
protected:
	string name;
	string address;

public:
	Person()
	{
		name = "";
		address = "";
	}
	Person(string name, string address)
	{
		this->name = name;
		this->address = address;
	}

	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Address: " << address << endl;
	}



};