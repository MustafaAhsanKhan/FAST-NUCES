#pragma once

#include <iostream>
using namespace std;

//Question 1

// Function to remove duplicates from an array

template <typename T>

T* removeDuplicates(T* arr, int size)
{
	T* newArr = new T[1];
	int temp = 0;

	for (int i = 0; i < size; ++i)
	{
		bool flag = false;
		for (int j = 0; j < temp; ++j)
		{
			if (arr[i] == newArr[j])
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			newArr = increaseSize(newArr, temp);
			newArr[temp] = arr[i];
			temp++;
		}
	}

	return newArr;
}

// Function to increase the size of a dynamic array by 1
template <typename T>

T* increaseSize(T* arr, int size)
{
	T* newArr = new T[size + 1];
	for (int i = 0; i < size; ++i)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;
	return newArr;
}

template <typename T>

T* unionSets(T* set1, int size1, T* set2, int size2)
{
	T* newSet = new T[size1 + size2];
	int temp = 0;
	bool flag = false;

	for (int i = 0; i < size1; ++i)
	{
		newSet[i] = set1[i];
	}

	for (int i = 0; i < size2; ++i)
	{
		newSet[size1 + i] = set2[i];
	}

	newSet = removeDuplicates(newSet, size1 + size2);

	return newSet;
}

template <typename T>

T* intersectionSets(T* set1, int size1, T* set2, int size2)
{
	// Intersection of two sets
	T* newSet = new T[1];
	int temp = 0;

	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			if (set1[i] == set2[j])
			{
				newSet = increaseSize(newSet, temp);
				newSet[temp] = set1[i];
				temp++;
			}
		}
	}

	newSet = removeDuplicates(newSet, temp);

	return newSet;
}

template <typename T>

bool areDisjoint(T* set1, int size1, T* set2, int size2)
{
	bool flag = true;

	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			if (set1[i] == set2[j])
			{
				flag = false;
			}
		}
	}

	return flag;
}

template <typename T>

bool elementExists(T* set, int size, T element)
{
	bool flag = false;

	for (int i = 0; i < size; ++i)
	{
		if (set[i] == element)
		{
			flag = true;
			break;
		}
	}

	return flag;
}

// Question 2

template <typename T>

T* RemoveDups(T* arr, int size)
{
	T* newArr = new T[1];
	int temp = 0;

	for (int i = 0; i < size; ++i)
	{
		bool flag = false;
		for (int j = 0; j < temp; ++j)
		{
			if (arr[i] == newArr[j])
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			newArr = increaseSize(newArr, temp);
			newArr[temp] = arr[i];
			temp++;
		}
	}

	return newArr;
}

// Question 3

template <class T>

class Calculator
{
private:
	T num1;
	T num2;

public:
	Calculator(T num1, T num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	}

	T add()
	{
		return num1 + num2;
	}

	T multiply()
	{
		return num1 * num2;
	}

	T subtract()
	{
		return num1 - num2;
	}

	T divide()
	{
		if (num2 != 0)
		{
			return num1 / num2;
		}
		else
		{
			return 0;
		}
	}

	T power()
	{
		return pow(num1, num2);
	}

	T square()
	{
		return num1 * num1;
	}

};

// Question 4

template <class T>

class Container
{
private:
	T* values;
	int capacity;
	int counter;

public:
	Container(int capacity)
	{
		this->capacity = capacity;
		values = new T[capacity];
		counter = 0;
	}

	bool isFull()
	{
		return counter == capacity;
	}

	void insert(T value)
	{
		if (!isFull())
		{
			values[counter] = value;
			counter++;
		}
	}

	bool search(T value)
	{
		bool flag = false;

		for (int i = 0; i < counter; ++i)
		{
			if (values[i] == value)
			{
				flag = true;
			}
		}

		return flag;
	}

	void remove(T value)
	{
		for (int i = 0; i < counter; ++i)
		{
			if (values[i] == value)
			{
				for (int j = i; j < counter - 1; ++j)
				{
					values[j] = values[j + 1];
				}
				counter--;
				break;
			}
		}
	}

	void print()
	{
		for (int i = 0; i < counter; ++i)
		{
			cout << values[i] << " ";
		}
		cout << endl;
	}
};