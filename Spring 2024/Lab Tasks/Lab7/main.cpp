#include <iostream>
#include "Circle.h"
#include "Matrix.h"
#include "ShoppingList.h"
#include "ShoppingItem.h"
using namespace std;

int main()
{
	// QUESTION 1
	Circle C1;
	Circle* ptr1;

	ptr1 = &C1;

	cout << endl;

	ptr1->setrad(6);

	cout << "Area 1 is: " << ptr1->getArea();
	cout << endl;
	cout << "Perimeter 1 is: " << ptr1->getPerimeter();

	Circle C2;
	Circle* ptr2;

	ptr2 = &C2;

	cout << ptr2->getcountOfCircles();
	cout << endl;

	ptr2->setrad(10);

	cout << "Area 2 is: " << ptr2->getArea();
	cout << endl;
	cout << "Perimeter 2 is: " << ptr2->getPerimeter();

	Circle C3;
	Circle* ptr3;

	ptr3 = &C3;

	cout << ptr3->getcountOfCircles();
	cout << endl;

	ptr3->setrad(12.5);

	cout << "Area 3 is: " << ptr3->getArea();
	cout << endl;
	cout << "Perimeter 3 is: " << ptr3->getPerimeter();
	cout << endl;
	cout << ptr1->getcountOfCircles();
	cout << endl;

	// QUESTION 2

	int** arr = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		arr[i] = new int[3];

	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}

	}

	Matrix m1(3, 3, arr);

	Matrix m2(m1);

	Matrix m3(m1);

	m2.display();

	m2.multiplyMatrix(4);

	m2.display();

	m3.addMatrix(3);

	m3.display();

	// QUESTION 3

	ShoppingItem item1();
	ShoppingItem item2();
	ShoppingItem item3();
	ShoppingList list;
	list.AddItem("Pakoora", 4, 50);
	list.AddItem("Samosa", 8, 25);
	list.AddItem("Jalebi", 5, 50);

	list.Print();

	cout << list.TotalCost();

	return 0;
}