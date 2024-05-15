#include <iostream>
using namespace std;

main()
{
    int num, remainder;

    cout << "Enter a number: ";
    cin >> num;

    remainder = num & 7;

    cout << num << " % 8 " << "= " << remainder;
}