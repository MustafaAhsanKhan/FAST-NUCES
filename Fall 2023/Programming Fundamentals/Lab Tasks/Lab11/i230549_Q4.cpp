#include <iostream>
using namespace std;

void transpose(int arr[3][2])
{
    int arr2[2][3];

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            arr2[j][i] = arr[i][j];  // Making the transpose
        }
    }
    cout << endl;

    cout << "Original array" << endl;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Transpose of the array" << endl;
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int array[3][2];

    cout << "Enter values for the array" << endl;

    for(int i = 0; i < 3; ++i)  // Array
    {
        for(int j = 0; j < 2; ++j)
        {
            cout << i << "th row " << j << "th column: ";
            cin >> array[i][j];
        }
    }

    transpose(array);

    return 0;
}