#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Name: Mustafa Ahsan Khan"<< endl <<
    "Roll Number: 23i-0549" << endl;

    float a, b, c, root1, root2;

    cout << "Enter coefficient a: ";
    cin >> a;

    cout << "Enter coefficient b: ";
    cin >> b;

    cout << "Enter coefficient b: ";
    cin >> c;

    root1 = ((-b) + sqrt(pow(b,2) - (4 * a * c))) / (2 * a);
    root2 = ((-b) - sqrt(pow(b,2) - (4 * a * c))) / (2 * a);

    cout << "Roots are:" << endl;
    cout << "x1: " << root1 <<endl;
    cout << "x2: " << root2 <<endl;
}