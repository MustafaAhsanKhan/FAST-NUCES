#pragma once
#pragma once
#include <iostream>
#include "ShoppingItem.h"
using namespace std;

class ShoppingList
{
private:
	ShoppingItem item_list[10];
	int countOfItems;

public:

	ShoppingList()
	{
		countOfItems = 0;
		for (int i = 0; i < 10; ++i)
		{
			item_list[i].setName("");
			item_list[i].setPrice(0);
			item_list[i].setPrice(0);
		}
		
	}

	void AddItem(string item, int q, int p)
	{
		if (countOfItems <= 10)
		{
			item_list[countOfItems].InputItem(item, q, p);
			++countOfItems;
		}
	}

	void Print()
	{
		for (int i = 0; i < countOfItems; ++i)
		{
			item_list[i].Display();
			cout << endl;
		}
	}

	int TotalCost()
	{
		int total = 0;
		for (int i = 0; i < countOfItems; ++i)
		{
			total = total + (item_list[i].getPrice() * item_list[i].getQuantity());
		}

		return total;
	}
};

