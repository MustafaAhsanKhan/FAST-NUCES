#include <iostream>
#include <iomanip>
using namespace std;

double evaluate(int x, int y, double pi=3.142, double epsilon=8.85418)
{
    double F;
    int r;
    cout << "Enter the value of r: ";
    cin >> r;

    F = abs(x * y) / (4.0 * pi * epsilon * r * r);
    return F;
}

double evaluate(double x, double y, double pi=3.142, double epsilon=8.85418)
{
    double F;
    int r;
    cout << "Enter the value of r: ";
    cin >> r;


    F = abs((int)(x * y)) / (4.0 * pi * epsilon * r * r);
    return F;
}

int main()
{   
    cout << "********FOR INTEGER********" << endl;
    int q1, q2;
    double q3, q4, result;

    cout << "Enter the value of q1: ";
    cin >> q1;
    cout << "Enter the value of q2: ";
    cin >> q2;

    result = evaluate(q1, q2);
    cout << fixed << setprecision(3) << "F = " << result << endl;

    cout << "********FOR DOUBLE********" << endl;

    cout << "Enter the value of q3: ";
    cin >> q3;
    cout << "Enter the value of q4: ";
    cin >> q4;

    result = evaluate(q3, q4);
    cout << fixed << setprecision(4)<< "F = " << result;

    return 0;
}