#include <iostream>
#include <bitset>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    unsigned int number, constant, gate1, gate2, gate3;

    cout << "Enter a 32 bit positive integer: ";
    cin >> number;


    gate2 = number >> 8;
    gate3 = number >> 16;
    constant = number >> 24;

    bitset<32> binary(number);
    bitset<8> gate1_B(number);
    bitset<8> gate2_B(gate2);
    bitset<8> gate3_B(gate3);
    bitset<8> constant_B(constant);


    cout << binary << endl;
    cout << "Constant :" << constant_B << endl;
    cout << "GATE3: " << gate3_B << endl;
    cout << "GATE2: "  << gate2_B << endl;
    cout << "GATE1: " << gate1_B << endl;

    bitset<8> key(constant_B ^ gate3_B ^ gate2_B ^ gate1_B);

    cout << "The key is: " << key << endl;

    return 0;
}