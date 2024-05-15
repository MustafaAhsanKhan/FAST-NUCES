#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 3

void order(int array[], int size)
{
    int temp;
    
    for(int i = 0; i < size; ++i)  // Bubble sort in Ascending order
    {
        for(int j = 0; j < size - 1 - i; ++j)
        {
            if(array[j] > array[j + 1])
            { 
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    
    
    for(int i = 0; i < size; ++i)  // Sorting array into evens first then odds
    {
        if(array[i] % 2 == 0 || array[i] < 0)  // Ignoring even and negative elements
        {
            continue;
        }
        
        for(int j = i + 1; j < size; ++j)
        {
            if(array[j] % 2 == 0)  // Shifting odd elements to the right side
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }


    cout << endl << "FINAL ARRAY" << endl; 
    cout << "[";
    for(int i = 0; i < size; i++)  // Printing sorted array (even/odd)
    {
        if(i == size - 1)
        {
            cout << array[i];
        }
        else
        {
            cout << array[i] << ", ";
        }
    }
    cout << "]";
}

// Functions for Array 1

void replace_1(int arr[], int size1, int temp)
{
    bool flag;
    flag = 0;
    for(int j = 0; j < size1; ++j)
    {
        if(arr[j] == temp)
        {
            if(flag == 0 && j < size1)
            {
                flag = 1;
                continue;
            }
            else
            {
                arr[j] = -1;
            }
        }
    }
}

void replace_12(int arr[], int size1, int size2, int temp)
{
    bool flag;
    flag = 0;
    for(int j = 0; (j < size1 + size2); ++j)
    {
        if(arr[j] == temp)
        {
            if(flag == 0 && j < size1)
            {
                flag = 1;
                continue;
            }
            else
            {
                arr[j] = -12;
            }
        }
    }
}

void replace_13(int arr[], int size1, int size2, int size3, int temp)
{
    bool flag;
    flag = 0;
    for(int j = 0; (j < size1 + size2 + size3); ++j)
    {
        if(arr[j] == temp)
        {
            if(flag == 0 && j < size1)
            {
                flag = 1;
                continue;
            }
            else
            {
                arr[j] = -13;
            }
        }
    }
}

void replace_123(int arr[], int size1, int size4, int temp)
{
    bool flag;
    flag = 0;
    for(int j = 0; j < size4; ++j)
    {
        if(arr[j] == temp)
        {
            if(flag == 0 && j < size1)
            {
                flag = 1;
                continue;
            }
            else
            {
                arr[j] = -123;
            }
        }
    }
}

// Functions for Array 2

void replace_2(int arr[], int size1, int size2, int temp)
{
    bool flag;
    flag = 0;
    for(int j = size1; j < size1 + size2; ++j)
    {
        if(arr[j] == temp)
        {
            if(flag == 0 && j < size1 + size2)
            {
                flag = 1;
                continue;
            }
            else
            {
                arr[j] = -2;
            }
        }
    }
}

void replace_23(int arr[], int size1, int size2, int size3, int temp)
{
    bool flag;
    flag = 0;
    for(int j = size1; j < size1 + size2 + size3; ++j)
    {
        if(arr[j] == temp)
        {
            if(flag == 0 && j < size1 + size2)
            {
                flag = 1;
                continue;
            }
            else
            {
                arr[j] = -23;
            }
        }
    }
}

// Functions for Array 3

void replace_3(int arr[], int size1, int size2, int size3, int temp)
{
    bool flag;
    flag = 0;
    for(int j = size1 + size2; j < size1 + size2 + size3; ++j)
    {
        if(arr[j] == temp)
        {
            if(flag == 0 && j < size1 + size2 + size3)
            {
                flag = 1;
                continue;
            }
            else
            {
                arr[j] = -3;
            }
        }
    }
}


int main()
{
    int array1[1000], array2[1000], array3[1000], resultant_array[1000], temp;
    int size1, size2, size3, size4, k;

    cout << "Enter size of array1: ";
    cin >> size1;

    cout << "Enter values for array 1" << endl;

    for(int i = 0; i < size1; ++i)  // Array 1
    {
        cout << i <<"th index: ";
        cin >> array1[i];
        while(array1[i] < 0)
        {
            cout << "Input only positive numbers" << endl;
            cout << i <<"th index: ";
            cin >> array1[i];
        }
        resultant_array[i] = array1[i]; 
    }
    k = size1;
    
    cout << "Enter size of array2: ";
    cin >> size2;

    cout << "Enter values for array 2" << endl;

    for(int i = 0; i < size2; ++i)  // Array 2
    {
        cout << i <<"th index: ";
        cin >> array2[i];
        while(array2[i] < 0)
        {
            cout << "Input only positive numbers" << endl;
            cout << i <<"th index: ";
            cin >> array2[i];
        }
        resultant_array[k] = array2[i];
        k = k + 1;
    }

    cout << "Enter size of array3: ";
    cin >> size3;

    cout << "Enter values for array 3" << endl;

    for(int i = 0; i < size3; ++i)  // Array 3
    {
        cout << i <<"th index: ";
        cin >> array3[i];
        while(array3[i] < 0)
        {
            cout << "Input only positive numbers" << endl;
            cout << i <<"th index: ";
            cin >> array3[i];
        }
        resultant_array[k] = array3[i];
        k = k + 1;
    }

    size4 = size1 + size2 + size3;

    // Checking values of Array1
    
    bool only_1, present_12, present_13;

    for(int i = 0; i < size1; ++i)
    {
        only_1 = 0;
        present_12 = 0;
        present_13 = 0;
        temp = resultant_array[i];
        if(temp < 0)
        {
            continue;
        }
        for(int j = i + 1; j < size4; ++j)
        {
            if(resultant_array[j] == temp)
            {
                if(j < size1)
                {
                    only_1 = 1;
                }
                if((j >= size1) && (j < size1 + size2))
                {
                    present_12 = 1;
                    only_1 = 0;
                }
                if((j >= size1 + size2) && (j < size4))
                {
                    present_13 = 1;
                    only_1 = 0;
                }
            }
        }
        if(only_1 == 1)
        {
            replace_1(resultant_array, size1, temp);
        }
        if(present_12 == 1 && present_13 == 0)
        {
            replace_12(resultant_array, size1, size2, temp);
        }
        if(present_12 == 0 && present_13 == 1)
        {
            replace_13(resultant_array, size1, size2, size3, temp);
        }
        if(present_12 == 1 && present_13 == 1)
        {
            replace_123(resultant_array, size1, size4, temp);
        }
    }

    // Checking values of Array 2
    
    bool only_2, present_23;

    for(int i = size1; i < size1 + size2; ++i)
    {
        only_2 = 0;
        present_23 = 0;
        temp = resultant_array[i];
        if(temp < 0)
        {
            continue;
        }
        for(int j = i + 1; j < size4; ++j)
        {
            if(resultant_array[j] == temp)
            {
                if(j < size1 + size2)
                {
                    only_2 = 1;
                }
                if((j >= size1 + size2) && (j < size4))
                {
                    present_23 = 1;
                    only_2 = 0;
                }
            }
        }
        if(only_2 == 1)
        {
            replace_2(resultant_array, size1, size2, temp);
        }
        if(present_23 == 1)
        {
            replace_23(resultant_array, size1, size2, size3, temp);
        }
    }

    // Checking values of Array 3

    bool only_3;

    for(int i = size1 + size2; i < size4; ++i)
    {
        only_3 = 0;
        temp = resultant_array[i];
        if(temp < 0)
        {
            continue;
        }
        for(int j = i + 1; j < size4; ++j)
        {
            if(resultant_array[j] == temp)
            {
                only_3 = 1;
            }
        }
        if(only_3 == 1)
        {
            replace_3(resultant_array, size1, size2, size3, temp);
        }
    }
    


    order(resultant_array, size4);

    return 0;
}