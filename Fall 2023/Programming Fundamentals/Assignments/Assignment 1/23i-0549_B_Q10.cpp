#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    int num1, num2;
    bool green, red, blue, orange, gray;

    cout << "The range is 1-36 " << endl;
    cout << "Input the first number: ";
    cin >> num1;
    cout << "Input the second number: ";
    cin >> num2;

    green = (num1 == 1 || num1 == 6 || num1 == 7 || num1 == 12 || num1 == 17 || num1 == 20 || num1 == 28 || num1 == 33) &&  // checking for green numbers
    (num2 == 1 || num2 == 6 || num2 == 7 || num2 == 12 || num2 == 17 || num2 == 20 || num2 == 28 || num2 == 33);
    
    red = (num1 == 2 || num1 == 11 || num1 == 13 || num1 == 18 || num1 == 19 || num1 == 24 || num1 == 29 || num1 == 32) &&  // checking for red numbers
    (num2 == 2 || num2 == 11 || num2 == 13 || num2 == 18 || num2 == 19 || num2 == 24 || num2 == 29 || num2 == 32);
    
    blue = (num1 == 3 || num1 == 10 || num1 == 14 || num1 == 23 || num1 == 25 || num1 == 30 || num1 == 31 || num1 == 36) &&  // checking for blue numberd
    (num2 == 3 || num2 == 10 || num2 == 14 || num2 == 23 || num2 == 25 || num2 == 30 || num2 == 31 || num2 == 36);
    
    orange = (num1 == 4 || num1 == 9 || num1 == 15 || num1 == 22 || num1 == 26 || num1 == 35) &&  // checking for orange numbers
    (num2 == 4 || num2 == 9 || num2 == 15 || num2 == 22 || num2 == 26 || num2 == 35);

    gray = (num1 == 5 || num1 == 8 || num1 == 16 || num1 == 21 || num1 == 27 || num1 == 34) &&  // checking for gray numbers
    (num2 == 5 || num2 == 8 || num2 == 16 || num2 == 21 || num2 == 27 || num2 == 34);

    green ? cout << "Both colors are Green": red ? cout << "Both colors are Red" : blue ? cout << "Both colors are Blue" : orange ? cout << "Both colors are Orange" : gray ? cout << "Both colors are Gray" : cout << "Both colors are not the same";

    return 0;
}