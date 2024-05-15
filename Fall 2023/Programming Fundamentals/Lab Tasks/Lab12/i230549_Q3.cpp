#include <iostream>
using namespace std;

int* removeDuplicates(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if(*(arr + i) == *(arr + j))
            {
                *(arr + i) = INT32_MAX;
            }
        }
    }
    
    return arr;
}

int main()
{ 
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    
    int* array = new int[size];
    int* newArray = new int[size];

    for(int i = 0; i < size; ++i)
    {
        cout << "Enter number " << i + 1 << " : ";
        cin >> array[i];
    }

    newArray = removeDuplicates(array, size);

    for(int i = 0; i < size; ++i)
    {
        if(newArray[i] != INT32_MAX)
        {
            cout << *(newArray + i) << " ";
        }
    }

    return 0;
}
