#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment2

int main()
{
    int y, x, n, y_axis, x_axis, temp, space, j;

    cout << "The formula is f(x) = x^n + x^(n-1)" << endl;
    do  // Input validation
    {
        cout << "Enter values for x in the range [0,x]: ";
        cin >> x;
        cout << "Enter values for n in the range n > 0: ";
        cin >> n;
    }
    while((x <= 0) || (n <= 0));

    y_axis = pow(x, n) + pow(x, (n - 1));  // Finding maximum y value
    j = x;
    for(int i = 0; i <= y_axis; y_axis -= 1)  // Printing y-axis
    {
        temp = x;
        cout << setw(2) << setfill('0') << y_axis;
        while(temp >= 0)  // x values
        {   
            if((pow(temp, n) + pow(temp, (n - 1))) == y_axis)  // comparing to y-axis
            {
                space = 1;
                while(space < 3 + (5 * j))  // printing spaces
                {
                cout << " ";
                space = space + 1;
                }
                cout << "*";
                j = j - 1;
            }
            temp = temp - 1;
        }
        cout << endl;
    }
    for(int j = 0; j <= x; ++j)  // Printing x-axis
    {
        cout << "    " << j;
    }

    return 0;
}