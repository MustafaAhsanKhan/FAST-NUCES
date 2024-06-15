#pragma once
#include <iostream>

using namespace std;

int findMaxElement(int** matrix, int rows, int columns)
{
	int max = INT_MIN;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if(*(*(matrix + i) + j) > max)
			{
				max = *(*(matrix + i) + j);
			}
		}
	}

	return max;
}

int calDiagonal(int** p, int sizeA, int sizeB)
{
	int sum = 0;

	for (int i = 0; i < sizeA; ++i)
	{
		for (int j = 0; j < sizeB; ++j)
		{
			if (i == j)
			{
				sum = sum + *(*(p + i) + j);
			}
		}
	}

	return sum;
}

int countNegatives(int** grid, int rows, int columns)
{
	int neg_nums = 0;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (*(*(grid + i) + j) < 0)
			{
				++neg_nums;
			}
		}
	}

	return neg_nums;
}

int** setZeroes(int** matrix, int rows, int columns)
{
	int** NewArray = new int* [rows];

	for (int i = 0; i < rows; ++i)
	{
		*(NewArray + i) = new int[columns];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			NewArray[i][j] = matrix[i][j];
		}

	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (*(*(matrix + i) + j) == 0)
			{
				for (int k = 0; k < rows; ++k)
				{
					*(*(NewArray + k) + j) = 0;
				}

				for (int k = 0; k < columns;++k)
				{
					*(*(NewArray + i) + k) = 0;
				}
			}
		}
	}

	return NewArray;
}

int** construct2DArray(int* original, int m, int n)
{
	int** NewArray = new int* [m];

	for (int i = 0; i < m; ++i)
	{
		*(NewArray + i) = new int [n];
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			NewArray[i][j] = *(original++);
		}
		
	}

	return NewArray;
}