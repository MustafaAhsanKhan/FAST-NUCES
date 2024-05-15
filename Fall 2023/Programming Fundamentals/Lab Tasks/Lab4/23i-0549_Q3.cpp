#include <iostream>
using namespace std;

int main()
{
    cout << "Name: Mustafa Ahsan Khan"<< endl <<
    "Roll Number: 23i-0549" << endl;

    float radius, PI;
    PI = 3.1415;
    cout << "Enter radius of a circle: ";
    cin >> radius;

    cout << "Diameter: " << (radius * 2) << endl;
    cout << "Circumference: " << (2 * PI * radius) << endl;
    cout << "Area: " << (PI * radius * radius);


}