#include <iostream>
using namespace std;

int main()
{
    int num, fact;
    fact = 1;

    cout << "Enter your number: ";
    cin >> num;

    if(num == 0)
    {
        cout << "Factorial of 0 = 1";
    }

    if(num < 0)
    {
        cout << "Invalid input";
    }

    if(num > 0)
    {
        for(int i = 1; i <= num; ++i)
        {
            fact = fact * i;
        }
        cout << "Factorial of " << num << " = " << fact;
    }
    
    return 0;
}