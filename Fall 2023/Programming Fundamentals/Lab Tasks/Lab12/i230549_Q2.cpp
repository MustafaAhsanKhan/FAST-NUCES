#include <iostream>
using namespace std;

void replace_repeated(int *ptr, int size)
{
    int maxCount = 0, temp;
    for(int i = 0; i < size - 1; ++i)
    {
        int count = 0;
        for(int j = 0; j < size; ++j)
        {
            if(ptr[i] == ptr[j])
            {
                count++;
            }
        }
        if(count >= maxCount) 
        {    
            maxCount = count; 
            temp = ptr[i];
        }
    }
    cout << "Most Occurring: "<< temp << endl;
    
    cout << "Updated array: ";
    for(int i = 0; i < size; ++i)
    {
        if(ptr[i] == temp)
        {
            ptr[i] = 0;
        }
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;

    cout << "Enter size of the array: ";
    cin >> size;

    int *ptr = new int[size];
    
    for(int i = 0; i < size; ++i)
    {
        cout << "Enter number " << i + 1 << " : ";
        cin >> ptr[i];
    }
    replace_repeated(ptr, size);
    return 0;
}