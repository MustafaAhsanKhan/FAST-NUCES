#include<iostream>
using namespace std;
int main()
{
    int row, row2, space1, space2;

    cout << "Enter the rows of the upside-down triangle: ";
    cin >> row;

    for(int i = row; i>= 1; --i)
    {
        for(space1 = i; space1 < row; ++space1)
        {
            cout<<" ";
        }
        for(int j = 1; j <= (2 * i - 1); ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << "Enter the Number of Rows(odd numbers only): ";
    cin >> row2;
    space2 = row2 - 1;
        for(int i = 1; i <= row2; ++i)
        {
            for(int j = 1; j <= space2; ++j)
            {
                cout<<" ";
            }
            space2 = space2 - 1;
            for(int j = 1; j <= (2 * i - 1); ++j)
            {
                cout << "*";
            }
            cout << endl;
        }
        space2 = 1;
        for(int i = 1; i <= (row2 - 1); ++i)
        {
            for(int j = 1; j <= space2; ++j)
            {
                cout << " ";
            }
            space2 = space2 + 1;
            for(int j = 1; j <= (2 * (row2 - i) - 1); ++j)
            {
                cout << "*";
            }
            cout << endl;
        }
        cout << endl;
    
    return 0;
}  
