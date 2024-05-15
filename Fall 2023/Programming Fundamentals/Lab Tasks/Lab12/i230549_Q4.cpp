#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    
    int *ptr = new int[size];
    int *newArray = new int[size];
    int count = 0;
    
    for(int i = 0; i < size; ++i)
    {
        cout << "Enter number " << i + 1 << " : ";
        cin >> ptr[i];
    }
    
    for(int i = 0; i < size; ++i)
    {
        if(*(ptr + i) % 2 == 0)
        {
            newArray[count] = *(ptr + i);
            count++;
        }
    }

    for(int i = 0; (newArray[i] % 2) == 0; ++i)
    {
        int temp;
        for(int j = 0; j < size - i - 1; ++j)
        {
            if(newArray[j] % 2 == 0)
            {
                if(newArray[j] < newArray[j + 1])
                {
                    temp = newArray[j];
                    newArray[j] = newArray[j + 1];
                    newArray[j + 1] = temp;
                }
            }
        }
    }

    
    for(int i = 0; i < size; ++i)
    {
        if(*(ptr + i) % 2 != 0)
        {
            newArray[count] = *(ptr + i);
            count++;
        }
    }

    for(int i = 0; i < size; ++i)
    {
        int temp;
        for(int j = 0; j < size - i - 1; ++j)
        {
            if(newArray[i] % 2 == 0)
            {
                if(newArray[j] < newArray[j + 1])
                {
                    temp = newArray[j + 1];
                    newArray[j + 1] = newArray[j];
                    newArray[j] = temp;
                }
            }
        }
    }

    for(int i = 0; i < size; ++i)
    {
        cout << newArray[i] << " ";
    }
    return 0;
}
