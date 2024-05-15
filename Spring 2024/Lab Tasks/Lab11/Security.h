#pragma once
#include "../Project_Lab11/NonFaculty.h"
class Security : public NonFaculty
{
private:
	string GunMade;
	string LicenseNumber;

public:
	//
	Security()
	{
		GunMade = "N/A";
		LicenseNumber = "N/A";
	}

	Security(string Name, int CNIC, int DOB, int Age, unsigned int Contact, string Duty, string StartTiming, string EndTiming, string p_GunMade, string p_LicenceNumber) : NonFaculty(Name, CNIC, DOB, Age, Contact, Duty, StartTiming, EndTiming)
	{
		GunMade = p_GunMade;
		LicenseNumber = p_LicenceNumber;
	}

	void print()
	{
		NonFaculty::print();
		cout << "GunMade: " << GunMade << endl;
		cout << "Licence Number: " << LicenseNumber << endl;

	}
};

