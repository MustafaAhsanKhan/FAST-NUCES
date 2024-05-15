#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int integer;
	
	cout << "Input an integer: ";
	cin >> integer;
	
   	int evenBits = integer & 0b10101010;
    int oddBits = integer & 0b01010101;

    	evenBits >>= 1;
    	oddBits <<= 1;

	cout << (evenBits | oddBits) << endl;
    return 0;
}