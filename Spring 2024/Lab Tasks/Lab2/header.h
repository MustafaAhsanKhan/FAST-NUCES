#pragma once
#include <iostream>
using namespace std;

string assignAndDisplayValues(int a, int b)
{
    int *ptrA = &a;
    int *ptrB = &b;

    string s1 = "Value of 'a' through pointer ptrA: ";
    s1 += (char)(*ptrA + 48);

    string s2 = "\nValue of 'b' through pointer ptrB: ";
    s2 += (char)(*ptrB + 48);
    s2 += '\n';

    return (s1 + s2);
}

char* calculateGrades(int arr[], int size)
{
    char* grades = new char[size];

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] >= 91 && arr[i] <= 100)
        {
            grades[i] = 'A';
        }
        else if (arr[i] >= 76 && arr[i] <= 90)
        {
            grades[i] = 'B';
        }
        else if (arr[i] >= 60  && arr[i] <= 75)
        {
            grades[i] = 'C';
        }
        else if (arr[i] >= 51 && arr[i] <= 59)
        {
            grades[i] = 'D';
        }
        else
        {
            grades[i] = 'F';
        }
    }

    return grades;
    delete[] arr;
}

int* sortArray(int* arr, int size)
{
    int temp;
    int even, odd;
    bool swapped;
    even = 0;
    odd = 0;

    for (int i = 0; i < size - 1; i++) 
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if ((*(arr + j)) % 2 == 0) 
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                swapped = true;
            }
        }

        if (swapped == false)  // No elements were swapped
        {
            break;
        }
    }

    for (int i = 0; i < size; ++i)
    {
        if (*(arr + i) % 2 == 0)
        {
            even++;
        }
    }

    odd = size - even;

    for (int i = 0; i < odd - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < odd - i - 1; j++)
        {
            if ((*(arr + j)) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                swapped = true;
            }
        }

        if (swapped == false)  // No elements were swapped
        {
            break;
        }
    }

    for (int i = odd; i < size; i++)
    {
        for (int j = odd; j < size - 1; j++)
        {
            if ((*(arr + j)) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }

	return arr;
}

int* resizeArray(int* arr, int& capacity)
{
    int newCapacity = capacity + 1;

    int* newArray = new int[newCapacity];  // Creating a new array with more spaces

    for (int i = 0; i < capacity; ++i)
    {
        newArray[i] = arr[i];  // Copying elements into the new resized array
    }

    delete[] arr;

    capacity = newCapacity;
    return newArray;
}

int* rotateArray(int* arr, int sizeofArray, int n, int m)
{
    int segment_size = sizeofArray / m;
    int* temparr = new int[sizeofArray];

    for(int segment_num = 0; segment_num < m; ++segment_num)
    {
        for (int j = 0; j < segment_size; ++j)
        {
            temparr[((j + n) % segment_size) + (segment_size * segment_num)] = arr[j + (segment_size * segment_num)];  // To shift to the right
            //temparr[(j + n) % segment_size] = arr[j];  // To shift to the right
            //temparr[j] = arr[(j + n) % segment_size];  // To shift to the left
        }
    }

    return temparr;
}