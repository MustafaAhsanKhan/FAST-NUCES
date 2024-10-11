#pragma once
#include <iostream>
using namespace std;

// Question 1
template <typename T, int rows, int cols>
bool matchTables(const T table1[rows][cols], const T table2[rows][cols])
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (table1[i][j] != table2[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

// Question 2
template <typename T, int numMatches>
void inputPlayerData(T runs[][numMatches], int numPlayers) {}

template <typename T, int numMatches>
void computeStatistics(const T runs[][numMatches], int numPlayers, T totalRuns[], T avgRuns[])
{
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			totalRuns[i] += runs[i][j];
		}
	}

	for (int i = 0; i < 12; ++i)
	{
		avgRuns[i] = totalRuns[i] / 10;
	}

	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Player " << i << " total is: " << totalRuns[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Player " << i << " average is: " << avgRuns[i] << endl;
	}
	cout << endl;
}

template <typename T>
void sortPlayersByTotalRuns(T totalRuns[], int playerIndices[], int numPlayers)
{
	for (int i = 0; i < numPlayers; ++i)
	{
		playerIndices[i] = i;
	}

	for (int i = 0; i < numPlayers; ++i)
	{
		for (int j = 0; j < numPlayers - 1; ++j)
		{
			if (totalRuns[i] > totalRuns[j])
			{
				int temp = totalRuns[i];
				totalRuns[i] = totalRuns[j];
				totalRuns[j] = temp;

				temp = playerIndices[i];
				playerIndices[i] = playerIndices[j];
				playerIndices[j] = temp;
			}
		}
	}
}

template <typename T>
void printTop10Players(const T totalRuns[], const int playerIndices[], int numPlayers)
{

	cout << "The top 10 players are: " << endl << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "Player " << playerIndices[i] << " with " << totalRuns[i] << " runs" << endl;
	}
}


//Question 3
template <typename T, int numSemesters>
void computeCGPAsAndFindLowest(const T gpaArray[][numSemesters], int numStudents)
{
	int student = 0;
	double min_GPA = 1000;
	for (int i = 0; i < numStudents; ++i)
	{
		double total_GPA = 0;
		for (int j = 0; j < numSemesters; ++j)
		{
			total_GPA += gpaArray[i][j];
		}

		if ((total_GPA / numSemesters * 1.0) < min_GPA)
		{
			min_GPA = total_GPA / (numSemesters * 1.0);
			student = i;
		}
	}

	cout << "The student with the lowest GPA is student " << student + 1 << " with CGPA " << min_GPA;
}

// Question 4
template <typename T, int rows, int cols>
T* spiralOrder(T matrix[rows][cols], int& size)
{
	int x = 0;
	int y = 0;

	int dx = 1;
	int dy = 0;
	size = rows * cols;
	T* result = new T[rows * cols];

	// We will update dx and dy when we reach the side/corner of the matrix
	// The formula used to update dx and dy is:
	// temp = dx
	// dx = -dy
	// dy = dx

	for (int i = 0; i < rows * cols; ++i)
	{
		result[i] = matrix[y][x];
		matrix[y][x] = INT32_MIN;

		if (!(0 <= x + dx && x + dx < cols && 0 <= y + dy && y + dy < rows) || matrix[y + dy][x + dx] == INT32_MIN)
		{
			int temp = dx;
			dx = -dy;
			dy = temp;
		}

		x += dx;
		y += dy;
	}

	return result;
}