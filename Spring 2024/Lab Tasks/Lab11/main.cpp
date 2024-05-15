#include <iostream>
using namespace std;

#include "../Project_Lab11/ProductionWorker.h"
#include "../Project_Lab11/HOD.h"
#include "../Project_Lab11/Teacher.h"
#include "../Project_Lab11/Security.h"

int main()
{
	cout << "-----QUESTION1-----" << endl;
	ProductionWorker worker1("ABC", "House 3", 1, 10, 1, 1200);
	worker1.calculateSalary();
	worker1.print_details();

	cout << "-----QUESTION2-----" << endl;

	HOD sirG("John Doe", 1234567890, 1980, 42, 123456, 3, 1, "Computer Science", "Professor", 1, "Department of Computer Science");
	cout << "Printing HOD Details" << endl;
	sirG.print();
	cout << endl;

	Teacher teacherG("Jane Smith", 9876543210, 1990, 32, 2345678, 4, 2, "Physics", "Lecturer", "Bacherlor of Science in Physics");
	cout << "Printing Teacher Details" << endl;
	teacherG.print();
	cout << endl << endl;

	cout << "Printing Security Details" << endl;
	Security guard("Bob Jones", 11111111, 1975, 47, 345678, "Security Guard", "8:00 AM", "5:00 PM", "abc", "123");
	guard.print();

	return 0;
}