#include <iostream>
using namespace std;

int main()
{
    int rows1, cols1;
    int ** array1;

    int rows2, cols2;
    int ** array2;

    cout << "Enter the number of rows of matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns of matrix 1: ";
    cin >> cols1;

    cout << "Enter the number of rows of matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns of matrix 2: ";
    cin >> cols2;

    if(rows1 != rows2 || cols1 != cols2)
    {
        cout << "Addition is not possible as order of matrices is not the same";
        return 0;
    }

    array1 = new int* [rows1];

    for(int i = 0; i < rows1; ++i)
    {
        array1[i] = new int [cols1];
    }

    array2 = new int* [rows2];

    for(int i = 0; i < rows2; ++i)
    {
        array2[i] = new int [cols2];
    }
    cout << "Enter the matrix elements for matrix 1" << endl;

    for(int i = 0; i < rows1; ++i)
    {
        for(int j = 0; j < cols1; ++j)
        {
            cin >> array1[i][j];
        }
    }

    cout << "Enter the matrix elements for matrix 2" << endl;

    for(int i = 0; i < rows2; ++i)
    {
        for(int j = 0; j < cols2; ++j)
        {
            cin >> array2[i][j];
        }
    }

    cout << "The sum of matrices is" << endl;

    for(int i = 0; i < rows1; ++i)
    {
        for(int j = 0; j < cols1; ++j)
        {
            cout << array1[i][j] + array2[i][j] << " ";
        }
        cout << endl;
    }
}
