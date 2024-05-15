#include <iostream>
using namespace std;

int main()
{
    int rows, cols, num;
    int ** array;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    array = new int* [rows];

    for(int i = 0; i < rows; ++i)
    {
        array[i] = new int [cols];
    }

    cout << "Enter the matrix elements" << endl;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            cin >> array[i][j];
        }
    }

    cout << "Enter number to find: ";
    cin >> num;
    bool found;
    found = 0;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(num == array[i][j])
            {
                cout << "The value " << num << " is found at position (" << i << ", " << j << ")";
                found = 1;
                break; 
            }
        }
        if(found == 1)
        {
            break;
        }
    }
}