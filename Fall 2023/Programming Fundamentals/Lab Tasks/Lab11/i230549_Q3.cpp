#include <iostream>
using namespace std;

void removeDuplicates(int arr[8], int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[i] == arr[j])
            {
                arr[j] = INT32_MAX;  // Replacing duplicates with maximum integer value
            }
        }
    }

    cout << "Updated array" << endl;
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] != INT32_MAX)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int array[8];

    cout << "Enter values for the array" << endl;

    for(int i = 0; i < 8; ++i)  // Array
    {
        cout << i << "th element: ";
        cin >> array[i];
    }

    removeDuplicates(array, 8);

    return 0;
}