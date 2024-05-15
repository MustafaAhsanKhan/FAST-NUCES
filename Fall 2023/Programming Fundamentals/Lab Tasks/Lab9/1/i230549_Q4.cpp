#include <iostream>
#include <cmath>
using namespace std;


int factorial(int num)
{
    int fact;
    fact = 1;

    if(num == 0)
    {
        return 1;
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
    }

    return fact;
}

double sin_x(int x, int n)
{
    double answer;
    int exponent;
    answer = x;
    exponent = 1;

    for(int i = 1; i <= n; ++i)
    {
        exponent = exponent + 2;
        if (i % 2 == 0)
        {
            answer = answer + (pow(x, exponent) / factorial(exponent));
        }
        else
        {
            answer = answer - (pow(x, exponent) / factorial(exponent));
        }
    }
    return answer;
}

int main()
{
    int x, n;
    double answer;

    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value on n: ";
    cin >> n;

    answer = sin_x(x, n);

    cout << "Sin(" << x << ") = " << answer;

    return 0;
}