#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float x, result, left, right;
    cout << "Enter the value for x: ";
    cin >> x;
    
    left = ((pow(x, 3)) + (5 * pow(x, 2)) - (4 * x) + (3)) / ((2 * pow(x, 4)) + (7 * pow(x, 3)) - (3 * pow(x, 2)) + (6));
    
    right = pow((((pow(x, 2)) - (3 * x) + (2)) / ((4 * pow(x, 3)) - (5 * pow(x, 2)) + (8))), 1/3);
    
    result = left - right;
    
    cout << "The result is: " << result;
    return 0;
}
