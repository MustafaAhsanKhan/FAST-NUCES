#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    unsigned int number, constant, gate1, gate2, gate3, key;

    cout << "Enter a 32 bit positive integer: ";
    cin >> number;

    constant = number >> 24;  // shifting bits to seperate bytes
    gate3 = number << 8 >> 24;
    gate2 = number << 16 >> 24;
    gate1 = number << 24 >> 24;

    key = constant ^ gate3 ^ gate2 ^ gate1;  // rearranged equation to get the key bit
    
    cout << "The key is: ";
    cout << ((key >> 7) & 1);  // right shifting bits and using bitwise AND with 1 to output each bit
    cout << ((key >> 6) & 1);
    cout << ((key >> 5) & 1);
    cout << ((key >> 4) & 1);
    cout << ((key >> 3) & 1);
    cout << ((key >> 2) & 1);
    cout << ((key >> 1) & 1);
    cout << ((key) & 1) << endl;

    return 0;
}