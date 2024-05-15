#include <iostream>
using namespace std;

int main()
{
    cout << "Name: Mustafa Ahsan Khan"<< endl <<
    "Roll Number: 23i-0549" << endl;

    float miles, gallons;

    cout << "Enter Miles driven: ";
    cin >> miles;

    cout << "Enter number of gallons used: ";
    cin >> gallons;

    cout << "MPG: " << (miles / gallons);
}