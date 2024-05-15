#include <iostream>
using namespace std;

#include "Complex.h"
#include "Point.h"
#include "Line.h"
#include "IntegerList.h"

int main()
{
	cout << "Question 1" << endl;
	Complex c1(3, 2);
	Complex c2(1, 1);

	Complex c3 = c1.addComplex(c2);

	c3.display();
	cout << endl;

	c3 = c1.subComplex(c2);

	c3.display();
	cout << endl;

	c3 = c1.mulComplex(c2);

	c3.display();
	cout << endl;

	Complex c4, c5;

	c4.setReal(4);
	c4.setImaginary(-5);

	c5.setReal(-7);
	c5.setImaginary(2);

	Complex c6 = c4.addComplex(c5);

	c6.display();
	cout << endl;

	c6 = c4.subComplex(c5);

	c6.display();
	cout << endl;

	c6 = c4.mulComplex(c5);

	c6.display();
	cout << endl;

	cout << "Question 2" << endl;

	Line L1(1, 2, 5, 11);

	L1.displayLine();

	cout << endl;

	cout << L1.getSlope() << endl;

	Line L2(3, -4, -9, -7);

	L2.displayLine();

	cout << endl;

	cout << L2.getSlope() << endl;

	cout << "Question 3" << endl;

	IntegerList array1(5);

	array1.addElement(1);
	array1.addElement(7);
	array1.addElement(-6);
	array1.addElement(8);
	array1.addElement(9);

	array1.displayElements();

	array1.addElement(11);
	array1.removeElement();
	array1.removeElement();

	array1.displayElements();

	return 0;

}