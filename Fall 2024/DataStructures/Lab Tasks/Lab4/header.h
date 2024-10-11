#pragma once

#include <iostream>
using namespace std;

struct StudentRecord
{
	int studentID;
	string name;
	float GPA;
};

void selectionSortStudents(StudentRecord arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        bool flag = false;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j].GPA < arr[min].GPA)
            {
                min = j;
                flag = true;
            }
        }
        // Swap the found minimum element with the first element
        if (flag)
        {
            StudentRecord temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void bubbleSort(int studentIDs[], int grades[], int numStudents)
{
    for (int i = 0; i < numStudents; ++i)
    {
        for (int j = 0; j < numStudents - i - 1; ++j)
        {
            if (grades[j] > grades[j + 1])
            {
                int temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;

                temp = studentIDs[j];
                studentIDs[j] = studentIDs[j + 1];
                studentIDs[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int studentIDs[], int grades[], int numStudents, int studentID)
{
    int start = 0;
    int end = numStudents - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (studentID == studentIDs[mid])
        {
            return grades[mid];
        }
        else if (studentID > studentIDs[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

void selectionSortPuzzel(int puzzle[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        bool flag = false;
        for (int j = i + 1; j < size; j++)
        {
            if (puzzle[j] < puzzle[min])
            {
                min = j;
                flag = true;
            }
        }
        // Swap the found minimum element with the first element
        if (flag)
        {
            int temp = puzzle[min];
            puzzle[min] = puzzle[i];
            puzzle[i] = temp;
        }
    }
}

void bubbleSortPuzzel(int puzzle[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (puzzle[j] > puzzle[j + 1])
            {
                int temp = puzzle[j];
                puzzle[j] = puzzle[j + 1];
                puzzle[j + 1] = temp;
            }
        }
    }
}

int linearSearchString(string arr[], int n, string target)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}