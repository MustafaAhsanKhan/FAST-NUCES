#pragma once
#include <iostream>
using namespace std;

class Money
{
private:
	int dollars;
	int cents;

public:

	Money();

	Money(int dollars, int cents);

	Money operator+(const Money& obj);

	Money operator-(const Money& obj);

	const Money operator=(const Money obj);

	Money& operator++();

	Money operator++(int x);

	Money& operator--();

	Money operator--(int x);

	bool operator!=(const Money& right);

	void operator~();
};