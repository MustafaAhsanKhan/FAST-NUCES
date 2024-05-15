#pragma once
#include <iostream>
using namespace std;

class ShoppingItem
{
private:
	string name;
	int quantity;
	int price;

public:

	ShoppingItem()
	{
		name = "";
		quantity = 0;
		price = 0;
	}

	ShoppingItem(string n, int q, int p)
	{
		name = n;
		quantity = q;
		price = p;
	}

	string getName()
	{
		return name;
	}

	int getQuantity()
	{
		return quantity;
	}

	int getPrice()
	{
		return price;
	}

	void setName(string n)
	{
		name = n;
	}

	void setQuantity(int x)
	{
		quantity = x;
	}

	void setPrice(int x)
	{
		price = x;
	}

	void InputItem(string n, int q, int p)
	{
		name = n;
		quantity = q;
		price = p;
	}

	void Display()
	{
		cout << "The name is:" << name << endl;
		cout << "The quantity is: " << quantity << endl;
		cout << "The price is: " << price << endl;
	}
};

