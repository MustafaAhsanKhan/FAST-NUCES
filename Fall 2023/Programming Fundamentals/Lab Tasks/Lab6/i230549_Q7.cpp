#include <iostream>
using namespace std;

int main()
{
    float input;
    char unit;

    cout << "Enter your value to be converted: ";
    cin >> input;
    cout << "Enter the unit: ";
    cin >> unit;

    switch(unit)
    {
        case 'P': cout << "The value in kilograms is " << input * 0.453592 << endl;
                  break;
        case 'p': cout << "The value in kilograms is " << input * 0.453592 << endl;
                  break;
        case 'I': cout << "The value in centimeters is " << input * 2.54 << endl;
                  break;
        case 'i': cout << "The value in centimeters is " << input * 2.54 << endl;
                  break;
        default: cout << "Invalid unit" << endl;
                 break;
    }
    return 0;
}