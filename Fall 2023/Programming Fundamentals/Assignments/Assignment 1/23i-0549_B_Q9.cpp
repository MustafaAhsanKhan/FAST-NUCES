#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    int num1, num2, num3, num4, max, second_max;
    max = -2147483648;  // storing the minimum value of INT data type
    second_max = -2147483648;
    
    cout << "Input the first number: ";
    cin >> num1;
    cout << "Input the second number: ";
    cin >> num2;
    cout << "Input the third number: ";
    cin >> num3;
    cout << "Input the fourth number: ";
    cin >> num4;
    cout << "****************************" << endl;
    
    max = num1 > max ? num1 : max;
    max = num2 > max ? num2 : max;
    max = num3 > max ? num3 : max;
    max = num4 > max ? num4 : max;

    second_max = num1 > second_max && num1 < max ? num1 : second_max;
    second_max = num2 > second_max && num2 < max ? num2 : second_max;
    second_max = num3 > second_max && num3 < max ? num3 : second_max;
    second_max = num4 > second_max && num4 < max ? num4 : second_max;


    cout << "The largest number is: " << max << endl;
    cout << "The second largest number is: " << second_max << endl;
    return 0;
}