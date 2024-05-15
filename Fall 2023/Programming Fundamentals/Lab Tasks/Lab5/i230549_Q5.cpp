#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, m, n, mask;

    cout << "Enter an integer: ";
    cin >> num;

    cout << "Enter the starting bit position (m): ";
    cin >> m;

    cout << "Enter the ending bit position (n) ";
    cin >> n;

    mask = (pow(2, (n - m) + 1) - 1);
    mask = mask << m;
    mask = ~mask;
    num = num & mask;

    cout << num;
}