#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 2

int main()
{
    unsigned int Input, gate1, gate2, gate3, gate4, temp, original;
    int num1, num2, remainder, multiple, divided, j;
    char op, hex_char;
    string hexadecimal = "";
    multiple = 0;
    divided = 0;
    temp = 0;
    cout << "Enter your number: ";
    cin >> Input;
    while(Input < 0)  // Input validation
    {
        cout << "Only enter non negative integers: ";
        cin >> Input;
    }

    gate1 = Input << 22 >> 22;  // Shifting of bits to seperate the gates
    gate2 = Input << 12 >> 22;
    gate3 = Input << 2 >> 22;
    gate4 = Input >> 30;

    cout << "The binary representation is: ";  // Displaying the input number in Binary
    for(int i = 31; i >= 0; --i)
    {
        cout << ((Input >> i) & 1);
    }
    cout << endl;

    switch(gate4)  // Using a switch with gate4 to perform the 4 operations
    {
        case 0: original = (gate1) | (gate2 << 10) | (gate3 << 20) | (gate4 << 30);  // Operation 1
                cout << "Original Form is: " << original;
                break;

        case 1: if (Input == 0)  // Operation 2
                {
                    cout << "Hexadecimal representation: 0";
                    return 0;
                }

                while (Input > 0)  // converting to hexadecimal
                {
                    remainder = Input % 16;

                    if (remainder < 10) 
                    {
                        hex_char = '0' + remainder;
                    } 
                    else 
                    {
                        hex_char = 'A' + (remainder - 10);
                    }

                    hexadecimal = hex_char + hexadecimal;
                    Input = Input / 16;
                }

                cout << "Hexadecimal representation: " << hexadecimal << endl;
                return 0;
                break;

        case 2: temp = gate1;  // Operation 3
                gate1 = gate2;
                gate2 = temp;
                cout << "Voila, gates 1 and 2 have been swapped" << endl;
                cout << "Gate1: ";
                for(int i = 9; i >= 0; --i)  // Displaying Gate1
                {
                    cout << ((gate1 >> i) & 1);
                }
                cout << endl;
                cout << "Gate2: ";
                for(int i = 9; i >= 0; --i)  // Displaying Gate2
                {
                    cout << ((gate2 >> i) & 1);
                }
                break;
        case 3: cout<<"Enter first number: ";  // Operation 4  // User Input
	            cin>>num1;
	            cout<<"Enter second number: ";
	            cin>>num2;
	            cout<<"Enter operator: ";
	            cin>>op;
	
                switch(op)
                {	
                case '*': for(int i = 1; i <= num2; ++i)  // Multiplication
                          {
                              multiple = multiple + num1;
                          }
                          cout << num1 << " * " << num2 << " = " << multiple;
                          break;
                case '/': divided = num1;
                          for(j = -1; (divided >= 0); ++j)  // Division
                          {
                              divided = divided - num2;
                          }
                          cout << num1 << " / " << num2 << " = " << j;
                          break;
                }
    }
    return 0;
}