#include <iostream>
using namespace std;

int main()
{
    int num, temp;

    cout << "Enter a number: ";
    cin >> num;

    temp = (num << 1) + num;
    cout << "3 * " << num << " = " << temp;
    return 0;
}