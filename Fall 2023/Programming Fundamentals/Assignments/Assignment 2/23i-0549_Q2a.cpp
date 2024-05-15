#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 2

int main()
{
    int i, j, k, step, blank, width, inside_gap, steps;
    cout << "Enter steps: ";
    cin >> steps;
    inside_gap = 0;
    blank = (steps * 5) - 1;

    // blank is outer spaces
    // inside_gap is inner spaces

    for(step = 0; step <= steps - 1; ++step)
    {
        for(k = 0; k < blank; ++k)
        {
            cout << " ";
        }

        width = 6;

        for(i = 0; i < width; ++i)
        {
            cout << "*";
        }
        for(j = 0; j < inside_gap; ++j)
        {
            cout << " ";
        }
        cout << "*" << endl;
        
        width = 1;
        inside_gap = inside_gap + 5;

        for(int x = 1; x <= 2; ++x)
        {
            for(k = 0; k < blank; ++k)
            {
                cout << " ";
            }
            
            for(i = 0; i < width; ++i)
            {
                cout << "*";
            }
            for(j = 0; j < inside_gap; ++j)
            {
                cout << " ";
            }
            cout << "*" << endl;
        }

        blank = blank - 5;

    }
    for(i = 0; i <= inside_gap + 5; ++ i)
    {
        cout << "*";
    }
    return 0;
}