#include <iostream>
#include <ctime>
using namespace std;

int computeMax(int num1, int num2, int num3)
{
    if(num1 > num2 && num1 > num3)
    {
        cout << "The maximum number is: " << num1;
    }
    if(num2 > num1 && num2 > num3)
    {
        cout << "The maximum number is: " << num2;
    }
    if(num3 > num1 && num3 > num2)
    {
        cout << "The maximum number is: " << num3;
    }
    if(num1 == num2 && num1 == num3)
    {
        cout << "All the numbers are equal";
    }
}

int main()
{
    int x, y ,z;

    cout << "Enter the value of num1: ";
    cin >> x;
    cout << "Enter the value of num1: ";
    cin >> y;
    cout << "Enter the value of num1: ";
    cin >> z;

    computeMax(x, y , z);  // Calling function
}