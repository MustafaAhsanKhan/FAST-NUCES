#pragma once
#include "../Project_Lab11/Staff.h"
class NonFaculty : public Staff
{
protected:
	string Duty;
	string StartTiming;
	string EndTiming;

public:
	// Constructors
	NonFaculty()
	{
		Duty = "N/A";
		StartTiming = "N/A";
		EndTiming = "N/A";
	}

	NonFaculty(string Name, int CNIC, int DOB, int Age, unsigned int Contact, string p_Duty, string p_StartTiming, string p_EndTiming) : Staff(Name,CNIC, DOB, Age, Contact)
	{
		Duty = p_Duty;
		StartTiming = p_StartTiming;
		EndTiming = p_EndTiming;
	}

	// Getters
	string getDuty()
	{
		return Duty;
	}

	string getStartTiming()
	{
		return StartTiming;
	}

	string getEndTiming()
	{
		return EndTiming;
	}

	void print()
	{
		Staff::print();
		cout << "Duty: " << Duty << endl;
		cout << "Start Timing: " << StartTiming << endl;
		cout << "End Timing: " << EndTiming << endl;
	}

};

