#include <iostream>
using namespace std;

void decreaseSort(int arr[6], int size)
{
    int temp;
        
    for(int i = 0; i < size; ++i)  // Bubble sort in Descending order
    {
        for(int j = 0; j < size - 1 - i; ++j)
        {
            if(arr[j] < arr[j + 1])
            { 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array (Decreasing Order)" << endl;

    for(int i = 0; i < 6; ++i)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int array[6];

    cout << "Enter values for the array" << endl;

    for(int i = 0; i < 6; ++i)  // Array
    {
        cout << i << "th element: ";
        cin >> array[i];
    }

    decreaseSort(array, 6);

    return 0;
}