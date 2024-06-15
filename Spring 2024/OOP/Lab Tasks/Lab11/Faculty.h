#pragma once
#include "../Project_Lab11/Staff.h"

class Faculty : protected Staff
{
protected:
	int PayScale;
	int RoomNumber;
	string Subject;
	string Rank;

public:
	// Constructors
	Faculty()
	{
		PayScale = 0;
		RoomNumber = 0;
		Subject = "N/A";
		Rank = "N/A";
	}

	Faculty(string Name, int CNIC, int DOB, int Age, unsigned int Contact, int p_PayScale, int p_RoomNumber, string p_Subject, string p_Rank) : Staff(Name, CNIC, DOB, Age, Contact)
	{
		PayScale = p_PayScale;
		RoomNumber = p_RoomNumber;
		Subject = p_Subject;
		Rank = p_Rank;
	}

	// Getters
	int getPayScale()
	{
		return PayScale;
	}

	int getRoomNumber()
	{
		return RoomNumber;
	}

	string getSubject()
	{
		return Subject;
	}

	string getRank()
	{
		return Rank;
	}

	void print()
	{
		Staff::print();
		cout << "Pay Scale: " << PayScale << endl;
		cout << "Room Number: " << RoomNumber << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Rank: " << Rank << endl;
	}
};

