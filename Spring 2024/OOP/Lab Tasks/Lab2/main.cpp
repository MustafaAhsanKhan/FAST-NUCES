#include <iostream>
#include <string>
#include "../i230549_B_LAB02/header.h"
using namespace std;

int main()
{
    /*Q1
    cout << assignAndDisplayValues(3, 7);
    */
    

    /*Q2
    int arr[] = { 95, 63, 76, 40, 85 };
    char* arr1 = calculateGrades(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << *(arr1 + i) << " ";
    }
    */

	/*Q3
    int sort_arr[] = { 6, 3, 1, 2, 7, 5, 9, 4 };
    int* sort_arr1 = sortArray(sort_arr, 8);

	for (int i = 0; i < 8; ++i)
	{
		cout << *(sort_arr1 + i) << " ";
	}
    */
	

    //Q4
    /*
    int capacity = 1;
    int* arr = new int[capacity];  // Creating the initial array with 1 space
    int index = 0;

    int num;
    while (1)
    {
        cout << "Enter an integer (enter -1 to exit): ";
        cin >> num;

        if (num == -1)
        {
            break;  // Finishing entering values
        }

        if (index == capacity)  // No more space in array
        {
            arr = resizeArray(arr, capacity);  // Resizing array
        }

        arr[index] = num;
        index++;
    }

    cout << "Final array: ";
    for (int i = 0; i < index; ++i)  // Printing final array
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    */
    

    //Q5
    int arr[] = { 1,2,3,4,5,6,7,8  };
    
    cout << "Original array: " << endl;
    for (int i = 0; i < 8; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int* arr1 = rotateArray(arr, 8, 4, 1);  // Array, array size, n, m

    for (int i = 0; i < 8; ++i)
    {
        cout << arr1[i] << " ";
    }
    

    return 0;

}
