#include <iostream>
using namespace std;

int main()
{
    int row = 1, blank, size;

    cout << "Enter the size: ";
    cin >> size;

    for(row = 1; row <= size; ++row)  // Upper Diamond
    {
        for(blank = size; blank > row; --blank) // outer spaces
        {
            cout << " ";
        }
             
        cout << "*";  // left side printing

        for(blank = 1; blank <= ((row - 1) * 2) - 1; ++blank) // inner spaces
        {
            cout << " ";
        }

        if(row == 1) // right side printing
            cout << endl;
        else
        {  
            cout << "*" << endl;
        }
    }
    for(row = size - 1; row >= 1; --row)  // Lower Diamond
    {
        for(blank = size; blank > row; --blank) // outer spaces
        {
            cout << " ";
        }
             
        cout << "*";  // left side printing

        for(blank = 1; blank <= ((row - 1) * 2) - 1; ++blank) // inner spaces
        {
            cout << " ";
        }

        if(row == 1) // right side printing
            cout << endl;
        else
        {  
            cout << "*" << endl;
        }
    }
}