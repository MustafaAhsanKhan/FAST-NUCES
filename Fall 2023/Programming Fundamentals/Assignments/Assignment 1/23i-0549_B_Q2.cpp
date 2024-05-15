#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    int num1, num2, num3;
    bool result;
    cout << boolalpha;  // converts boolean outputs 0 and 1 to false and true
    cout << "Input the first number: ";
    cin >> num1;
    cout << "Input the second number: ";
    cin >> num2;
    cout << "Input the third number: ";
    cin >> num3;

    int digit1 = num1 % 10;  // selecting the right-most digit
    int digit2 = num2 % 10;
    int digit3 = num3 % 10;

    result = (digit1 == digit2 && digit1 == digit3) ||
    (digit1 == digit2) ||
    (digit1 == digit3) ||   
    (digit2 == digit3);

    cout << "The result is: "<< result << endl;

    return 0;
}