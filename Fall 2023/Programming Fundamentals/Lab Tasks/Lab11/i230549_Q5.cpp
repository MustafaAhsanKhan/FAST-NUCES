#include <iostream>
using namespace std;

void Spiral(int arr[4][4])
{
    cout << "Spiral array" << endl;
    for(int i = 0; i < 3; ++i)
    {
        cout << arr[0][i] << " ";
    }

    for(int i = 0; i < 4; ++i)
    {
        cout << arr[i][3] << " ";
    }

    for(int i = 2; i >= 0; --i)
    {
        cout << arr[3][i] << " ";
    }

    for(int i = 2; i >= 2; --i)
    {
        cout << arr[i][0] << " ";
    }

    for(int i = 0; i < 3; ++i)
    {
        cout << arr[1][i] << " ";
    }

    cout << arr[2][2] << " " << arr[2][1];
}

int main()
{
    int array[4][4];

    cout << "Enter values for the array" << endl;

    for(int i = 0; i < 4; ++i)  // Array
    {
        for(int j = 0; j < 4; ++j)
        {
            cout << i << "th row " << j << "th column: ";
            cin >> array[i][j];
        }
    }

    Spiral(array);

    return 0;
}