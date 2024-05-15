#pragma once
class Polynomial
{
private:

	int a;
	int b;
	int c;

public:

	Polynomial();

	Polynomial(int a, int b, int c);

	Polynomial(const Polynomial &copy);

	int geta();

	int getb();

	int getc();

	void seta(int a);

	void setb(int b);

	void setc(int c);

	const Polynomial operator=(const Polynomial obj);

	bool operator==(const Polynomial& right);

	Polynomial operator+(const Polynomial& obj);

	Polynomial operator-(const Polynomial& obj);

	Polynomial operator*(int x);

	void operator~();
};

