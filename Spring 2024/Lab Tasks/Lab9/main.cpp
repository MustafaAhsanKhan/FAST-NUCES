#include "../lab9_project/Matrix.h"
#include "../lab9_project/Fraction.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "**********QUESTION 1**********" << endl;

	Matrix M1(3, 3);

	M1 = M1 + 1;

	cout << M1;

	Matrix M2 = M1 + 5;

	cout << M2;

	M2 = M2 - 1;

	cout << M2;

	Matrix M3 = M1 + M2;

	cout << M3;

	Matrix M4 = M3 - M2;

	cout << M4;

	cout << "**********QUESTION 2**********" << endl;

	Fraction F1(5, 3);
	Fraction F2(1, 2);

	cout << F1;
	cout << endl;
	cout << F2;
	cout << endl;

	F1 + F2;

	cout << F1 << endl;

	if (F1 > F2)
	{
		cout << "Fraction 1 is greater";
	}
	else if (F1 < F2)
	{
		cout << "Fraction 1 is smaller";
	}
	else if (F1 == F2)
	{
		cout << "Both fractions are equal";
	}

	return 0;
}