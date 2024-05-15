#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    unsigned short binary, temp, gray_code;

    cout << "Enter a 16 bit positive integer: ";
    cin >> binary;

    temp = binary >> 1;  // right shifting the input by 1
    gray_code = binary ^ temp;  // using XOR to calculate gray code

    cout << "The gray code is: ";
    cout << ((gray_code >> 15) & 1);  // right shifting bits and using bitwise AND with 1 to output each bit
    cout << ((gray_code >> 14) & 1);
    cout << ((gray_code >> 13) & 1);
    cout << ((gray_code >> 12) & 1);
    cout << ((gray_code >> 11) & 1);
    cout << ((gray_code >> 10) & 1);
    cout << ((gray_code >> 9) & 1);
    cout << ((gray_code >> 8) & 1);
    cout << ((gray_code >> 7) & 1);
    cout << ((gray_code >> 6) & 1);
    cout << ((gray_code >> 5) & 1);
    cout << ((gray_code >> 4) & 1);
    cout << ((gray_code >> 3) & 1);
    cout << ((gray_code >> 2) & 1);
    cout << ((gray_code >> 1) & 1);
    cout << ((gray_code) & 1) << endl;

    return 0;
}
