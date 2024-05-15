#include <iostream>
using namespace std;

int main()
{
    int array[10];
    int temp;
    bool flag;

    for(int i = 0; i < 10; ++i)
    {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> temp;
        array[i] = temp;
    }
    cout << "Leaders in the array: ";
    for(int i = 9; i >= 0; --i)
    {
        flag = 0;
        for(int j = i; j < 10; j++)
        {
            if(array[i] < array[j])
            {
                flag = 1;
                break;
            }
            
        }
        if(flag == 0)
        {
            cout << array[i] << " ";
        }
    }
    return 0;
}