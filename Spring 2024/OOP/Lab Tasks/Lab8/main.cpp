#include <iostream>
using namespace std;
#include "../project_lab8/Money.h"
#include "../project_lab8/Polynomial.h"

int main()
{
	cout << "---------Question 1---------" << endl;
	Money M1(12, 95);
	Money M2(3, 98);

	cout << "M1: " << endl;
	~M1;
	cout << endl;
	cout << "M2: " << endl;
	~M2;
	cout << endl;

	Money M3 = M1 + M2;

	cout << "M1 + M2: " << endl;
	~M3;
	cout << endl;

	Money M4 = M1 - M2;  // Not working

	cout << "M1 - M2: " << endl;
	~M4;
	cout << endl;

	Money M5(2, 10);

	Money M6 = M5++;

	cout << "M5: " << endl;
	~M5;
	cout << endl;
	cout << "M6: " << endl;
	~M6;
	cout << endl;

	cout << "M1 != M2" << endl << (M1 != M2) << endl;

	cout << "---------Question 2---------" << endl;

	Polynomial P1(2, 1, -1);
	Polynomial P2(5, -7, 3);

	cout << "P1:" << endl;
	~P1;
	cout << endl << "P2:" << endl;;
	~P2;

	cout << endl << "P1 + P2:" << endl;
	Polynomial temp = (P1 + P2);
	~temp;

	cout << endl << "P1 - P2:" << endl;
	temp = (P1 - P2);
	~temp;

	cout << endl << "P1 * 5:" << endl;
	temp = (P1 * 5);
	~temp;

	cout << endl << "P1 == P2:" << endl <<(P1 == P2) << endl;

}