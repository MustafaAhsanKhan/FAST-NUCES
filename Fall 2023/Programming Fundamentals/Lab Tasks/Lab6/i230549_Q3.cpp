#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    cout << "Enter your number: ";
    cin >> num;

    if (num % 2 == 0)
        cout << "It is even ";
    else
        cout << "It is odd ";

    if (num > 0)
        cout << "and positive";
    else if (num < 0)
        cout << "and negative";
    else if (num == 0)
        cout << "and zero";

    return 0;
}