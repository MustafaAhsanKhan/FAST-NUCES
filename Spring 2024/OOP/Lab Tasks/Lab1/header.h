#pragma once
#include <iostream>
#include <cmath>
using namespace std;

int sumArray(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum = sum + arr[i];
	}
	return sum;
}

double squareRoot(const double a)
{
	if (a < 0)
	{
		return -1.0;
	}
	else
	{
		return pow(a, 0.5);
	}
}