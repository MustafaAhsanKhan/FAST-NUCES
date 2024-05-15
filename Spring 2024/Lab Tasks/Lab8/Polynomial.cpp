#include "../project_lab8/Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial()
{
	a = 0;
	b = 0;
	c = 0;
}

Polynomial::Polynomial(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

Polynomial::Polynomial(const Polynomial& copy)
{
	a = copy.a;
	b = copy.b;
	c = copy.c;
}

int Polynomial::geta()
{
	return a;
}

int Polynomial::getb()
{
	return b;
}

int Polynomial::getc()
{
	return c;
}

void Polynomial::seta(int a)
{
	this->a = a;
}

void Polynomial::setb(int b)
{
	this->b = b;
}

void Polynomial::setc(int c)
{
	this->c = c;
}

const Polynomial Polynomial::operator=(const Polynomial obj)
{
	a = obj.a;
	b = obj.b;
	c = obj.c;

	return *this;
}

bool Polynomial::operator==(const Polynomial& right)
{
	if (a == right.a)
	{
		if (b == right.b)
		{
			if (c == right.c)
			{
				return 1;
			}
		}
	}
	return 0;
}

Polynomial Polynomial::operator+(const Polynomial& obj)
{
	Polynomial temp;
	temp.a = a + obj.a;
	temp.b = b + obj.b;
	temp.c = c + obj.c;

	return temp;
}

Polynomial Polynomial::operator-(const Polynomial& obj)
{
	Polynomial temp;
	temp.a = a - obj.a;
	temp.b = b - obj.b;
	temp.c = c - obj.c;

	return temp;
}

Polynomial Polynomial::operator*(int x)
{
	Polynomial temp;
	temp.a = a * x;
	temp.b = b * x;
	temp.c = c * x;

	return temp;
}

void Polynomial::operator~()
{
	if (a > 0)
	{
		cout << a << "x^2";
	}
	else
	{
		cout << a << "x^2 ";
	}

	if (b > 0)
	{
		cout <<  " + " << b << "x";
	}
	else
	{
		cout << " " << b << "x ";
	}

	if (c > 0)
	{
		cout << "+ " << c;
	}
	else
	{
		cout << " " << c;
	}
}