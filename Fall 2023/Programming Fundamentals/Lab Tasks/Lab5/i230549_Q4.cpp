#include <iostream>
using namespace std;

int main()
{
    int num1, num2, temp;

    cout << "Enter num1: ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;

    temp = num1 - num2;

    temp = (temp >> 31) * -1;

    cout << "Maximum is: " << num1 + (num2 - num1) * temp << endl << "Minimum is: " << num2 + (num1 -num2) * temp;

}