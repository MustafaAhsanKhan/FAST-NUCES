#include <iostream>
using namespace std;

int main()
{
    cout << "Name: Mustafa Ahsan Khan"<< endl <<
    "Roll Number: 23i-0549" << endl;

    int num;
    cout << "Enter a 4 digit number: ";
    cin >> num;

    cout << "The sum is " << ((num / 1000) + (num % 10));

}