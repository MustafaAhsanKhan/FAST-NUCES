#pragma once
#include <iostream>
using namespace std;

class Staff
{
protected:
	string Name;
	int CNIC;
	int DOB;
	int Age;
	unsigned int Contact;

public:
	// Constructors
	Staff()
	{
		Name = "N/A";
		CNIC = 0;
		DOB = 0;
		Age = 0;
		Contact = 0;
	}

	Staff(string p_Name, int p_CNIC, int p_DOB, int p_Age, unsigned int p_Contact)
	{
		Name = p_Name;
		CNIC = p_CNIC;
		DOB = p_DOB;
		Age = p_Age;
		Contact = p_Contact;
	}

	// Getters
	string getName()
	{
		return Name;
	}

	int getCNIC()
	{
		return CNIC;
	}

	int getDOB()
	{
		return DOB;
	}

	int getAge()
	{
		return Age;
	}

	unsigned int getContact()
	{
		return Contact;
	}

	void print()
	{
		cout << "Name: " << Name << endl;
		cout << "CNIC: " << CNIC << endl;
		cout << "DOB: " << DOB << endl;
		cout << "Age: " << Age << endl;
		cout << "Contact: " << Contact << endl;;
	}
};