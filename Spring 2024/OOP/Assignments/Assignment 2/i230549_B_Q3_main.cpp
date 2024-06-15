#include <iostream>
using namespace std;
#include "../Assignment2_project_final/i230549_B_Q3.h"

/*

****Assignment 2****
Name: Mustafa Ahsan Khan
ID: i23-0549
Section: CS-B

*/

int main()
{
	CAList tt, tt2, tt3, tt4;
	tt["OOP"] = "Dr.Ali";
	tt["OOP"] = "Mr.Shehryar";
	tt["OOP"] = "Ms.Hida";
	tt["OOP"] = "Mr.Shams";
	tt["DLD"] = "Mr.Amir";
	tt["DLD"] = "Mr.Shams";
	tt["DLD"] = "Dr.Mehwish";

	cout << "---------------tt---------------" << endl << tt << endl;

	tt2["Algo"] = "Mr.Owais";
	tt2["OOP"] = "Mr.Shehryar";
	tt2["Pak Stds"] = "Mr.Ajmal";
	tt2["Pak Stds"] += "Ms.Gul";
	tt2["Pak Stds"] = "Ms.Memoona";
	tt2["Islamiat"] = "Dr.Tayab";
	tt2["Islamiat"] += "Ms.Sobia";
	tt2["Islamiat"] = "Mr.Usman";
	tt2["Islamiat"] += "Ms.Gul";
	tt2["Islamiat"] += "Mr.Anas";

	cout << "---------------tt2---------------" << endl << tt2 << endl;

	tt3 = tt + tt2;

	tt3.removeDuplicates();

	cout << "---------------Addition---------------" << endl << tt3 << endl;

	cout << "---------------Subtraction---------------" << endl;

	tt4 = tt - tt2;

	cout << tt4;

	return 0;
}