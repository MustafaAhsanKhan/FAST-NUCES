#include <iostream>
using namespace std;

int largest(int array[])
{
    int larger;
    larger = array[0];

    for(int i = 1; i < 5; ++i)
    {
        if(array[i] > larger)
        {
            larger = array[i];
        }
    }
    return larger;
}

int smallest(int array[])
{
    int smaller;
    smaller = array[0];

    for(int i = 1; i < 5; ++i)
    {
        if(array[i] < smaller)
        {
            smaller = array[i];
        }
    }
    return smaller;
}

int main()
{
    int array[5];
    int larger, smaller, temp;

    for(int i = 0; i < 5; ++i)
    {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> array[i];
        //array[i] = temp;
    }

    larger = largest(array);
    smaller = smallest(array);

    cout << "The largest number in the array is: " << larger << endl;
    cout << "The smallest number in the array is: " << smaller << endl;
    return 0;
}