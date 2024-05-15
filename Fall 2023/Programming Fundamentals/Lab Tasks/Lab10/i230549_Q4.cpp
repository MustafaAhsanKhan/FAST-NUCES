#include <iostream>
using namespace std;


bool is_palindrome(int array[])
{
    int reversed_array[5];
    bool flag;
    flag = 1;

    for(int i = 0, j = 4; i < 5; ++i, --j)
    {
        reversed_array[i] = array[j];
    }
    
    for(int i = 0; i < 5; ++i)
    {
        if(reversed_array[i] != array[i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int array[5];
    int temp;
    bool flag;

    for(int i = 0; i < 5; ++i)
    {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> temp;
        array[i] = temp;
    }

    flag = is_palindrome(array);

    if(flag)
    {
        cout << "The array is a palindrome";
    }
    else
    {
        cout << "The array isnt a palindrome";
    }
    return 0;
}