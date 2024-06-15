#include "../project_lab8/Money.h"
#include <iostream>
using namespace std;

Money::Money()
{
	dollars = 0;
	cents = 0;
}

Money::Money(int dollars, int cents)
{
	this->dollars = dollars;
	this->cents = cents;
}

Money Money::operator+(const Money& obj)
{
	Money temp;
	temp.dollars = dollars + obj.dollars;
	temp.cents = cents + obj.cents;

	while (temp.cents > 100)
	{
		temp.cents = temp.cents - 100;
		temp.dollars = temp.dollars + 1;
	}

	return temp;;
}

Money Money::operator-(const Money& obj)
{
	int temp_c1 = (dollars * 100) + cents;
	int temp_c2 = (obj.dollars * 100) + obj.cents;
	Money temp;

	int temp_c3 = temp_c1 - temp_c2;
	while (temp_c3 > 100)
	{
		temp_c3 = temp_c3 - 100;
		temp.dollars++;
	}

	temp.cents = temp_c3;

	return temp;
}

const Money Money::operator=(const Money obj)
{
	dollars = obj.dollars;
	cents = obj.cents;

	return *this;
}

Money& Money::operator++()
{
	cents++;
	if (cents >= 100)
	{
		cents = cents - 100;
		dollars++;
	}
	return *this;
}

Money Money::operator++(int x)
{
	Money temp(*this);
	
	cents++;
	if (cents >= 100)
	{
		cents = cents - 100;
		dollars++;
	}
	return temp;
}

Money& Money::operator--()
{
	if (cents == 0)
	{
		if (dollars == 0)
		{
			return *this;
		}
		dollars--;
		cents = 99;
	}
	else
	{
		cents--;
	}
	return *this;
}

Money Money::operator--(int x)
{
	Money temp(*this);

	if (cents == 0)
	{
		if (dollars == 0)
		{
			return temp;
		}
		dollars--;
		cents = 99;
	}
	else
	{
		cents--;
	}
	return temp;
}

bool Money::operator!=(const Money& right)
{
	if (dollars == right.dollars && cents == right.cents)
	{
		return 0;
	}
	return 1;
}

void Money::operator~()
{
	cout << "Dollars: " << dollars << " Cents: " << cents;
}