#include <iostream>
using namespace std;

int main()
{
    float marks;

    cout << "Enter your marks: ";
    cin >> marks;

    if (marks >= 90)
        cout << "Grade A";
    if (marks >= 80 && marks <= 89)
        cout << "Grade B";
    if (marks >= 70 && marks <=79)
        cout << "Grade C";
    if (marks < 70)
        cout << "Grade D";

    return 0;
}