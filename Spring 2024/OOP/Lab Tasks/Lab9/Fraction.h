#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

public:

	Fraction();

	Fraction(int num, int denom);

	Fraction(Fraction& right);

	bool operator==(Fraction& right);

	bool operator>(Fraction& right);

	bool operator<(Fraction& right);

	friend istream& operator>>(istream& in, Fraction& fraction);

	friend ostream& operator<<(ostream& out, const Fraction& fraction);

	Fraction operator+(Fraction right);
};
istream& operator>>(istream& in, Fraction& fraction);

ostream& operator<<(ostream& out, const Fraction& fraction);
