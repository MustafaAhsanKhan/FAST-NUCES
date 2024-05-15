#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 2

int main()
{
    int row = 1, blank, i, j;
    bool flag;

    for(row = 0; row <= 7; ++row)  // Upper Diamond
    {
        if(row == 0)
        {
            for(blank = 8; blank > row; --blank)
            {
                cout << " ";
            }
            cout << "*" << endl;

            for(blank = 7; blank > row; --blank)
            {
                cout << " ";
            }
            cout << "-" << " " << "-" << endl;
            continue;
        }
        for(blank = 7; blank > row; --blank) // outer spaces
        {
            cout << " ";
        }
        if(row % 2 != 0) // left side printing
            cout << "*" << " " << "-";
        else
            cout << "-" << " " << "*";

        for(blank = 1; blank <= ((row - 1) * 2) - 1; ++blank) // inner spaces
        {
            cout << " ";
        }

        if(row == 1) // right side printing
            cout << " *" << endl;
        else
        {   if(row % 2 != 0)
                cout << "-" << " " << "*" << endl;
            else
            
                cout << "*" << " " << "-" <<endl;
        }
    }

    for(i = 1; i <= 5 ; ++i)  // upper half  // 1234321 pattern
    {
        if(flag)
        {
            cout << "*" << " " << "-" << " ";
        }
        else
        {
            cout << "-" << " " << "*" << " ";
        }
        for(j = 1; j <= 5 - i; ++j)
        {
            cout << ("*");
        }

        for(j = 1; j <= i; ++j)  // left side of pattern
        {
            cout << j;
        }

        for(j = i - 1; j >= 1; --j)  // right side of pattern
        {
            cout << j;
        }
        for(j = 1; j <= 5 - i; ++j)
        {
            cout << ("*");
        }
        if(flag)
        {
            cout << " " << "-" << " " << "*";
        }
        else
        {
            cout << " " << "*" << " " << "-";
        }
        cout << endl;
        flag = !flag;
    }

    for(i = 4; i >= 1; --i)  // lower half  // 1234321 pattern // swapped the condition and initial value to flip the pattern
    {   
        if(flag)
        {
            cout << "*" << " " << "-" << " ";
        }
        else
        {
            cout << "-" << " " << "*" << " ";
        }
        for(j = 1; j <= 5 - i; ++j)
        {
            cout << ("*");
        }

        for(j = 1; j <= i; ++j)  // left side of pattern
        {
            cout << j;
        }

        for(j = i - 1; j >= 1; --j)  // right side of pattern
        {
            cout << " ";
        }
        for(j = 1; j <= 5 - i; ++j)
        {
            cout << ("*");
        }
        if(flag)
        {
            cout << " " << "-" << " " << "*";
        }
        else
        {
            cout << " " << "*" << " " << "-";
        }
        cout << endl;
        flag = !flag;
    }

    for(row = 7; row >= 1; --row)  // Lower Diamond  // swapped the condition and initial value to flip the pattern
    {
        for(blank = 7; blank > row; --blank) // outer spaces
        {
            cout << " ";
        }
        if(row % 2 != 0) // left side printing
            cout << "*" << " " << "-";
        else
            cout << "-" << " " << "*";

        for(blank = 1; blank <= ((row - 1) * 2) - 1; ++blank) // inner spaces
        {
            cout << " ";
        }

        if(row == 1) // right side printing
            cout << " *" << endl;
        else
        {   if(row % 2 != 0)
                cout << "-" << " " << "*" << endl;
            else
            
                cout << "*" << " " << "-" <<endl;
        }
    }
    for(blank = 7; blank > row; --blank)
    {
        cout << " ";
    }
    cout << "-" << " " << "-" << endl;  
    
    for(blank = 8; blank > row; --blank)
    {
        cout << " ";
    }
    cout << "*" << endl;

    return 0;

}