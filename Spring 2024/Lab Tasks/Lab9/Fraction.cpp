#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int num, int denom)
{
    numerator = num;
    denominator = denom;
}

Fraction::Fraction(Fraction& right)
{
    numerator = right.numerator;
    denominator = right.denominator;
}

bool Fraction::operator==(Fraction& right)
{
    if (numerator == right.numerator && denominator == right.denominator)
    {
        return 1;  // TRUE
    }
    return 0;  // FALSE
}

bool Fraction::operator>(Fraction& right)
{
    if (numerator * right.denominator > right.numerator * denominator)
    {
        return 1;
    }
    return 0;
}

bool Fraction::operator<(Fraction& right)
{
    if (numerator * right.denominator < right.numerator * denominator)
    {
        return 1;
    }
    return 0;
}

istream& operator>>(istream& in, Fraction& fraction)
{
    char slash;
    in >> fraction.numerator >> slash >> fraction.denominator;
    if (fraction.denominator != 0)
    {
        return in; 
    }
}


ostream& operator<<(ostream& out, const Fraction& fraction)
{
    out << fraction.numerator << '/' << fraction.denominator;
    return out;
}

Fraction Fraction::operator+(Fraction right)
{
    Fraction temp;

    temp.denominator = this->denominator * right.denominator;
    temp.numerator = this->numerator * right.denominator + right.numerator * this->denominator;

    *this = temp;
    return *this;
}