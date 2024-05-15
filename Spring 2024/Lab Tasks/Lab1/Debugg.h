#pragma once
#pragma once
#include<iostream>
using namespace std;
void calculator(char o, float num1, float num2)
{

    float result;

    switch (o)
    {
    case '+':
        result = num1 + num2;
        num1 = num1 * 10;
        cout << num1 << " + " << num2 << " = " << result << endl;
        /*
        num1: 1000.0
        num2: 6.0
        result: 106
        */

        break; // insert a breakpoint here
    case '-':
        result = num1 + num2;
        num2 = num2 + 10;
        cout << num1 << " - " << num2 << " = " << result << endl;
        /*
        num1: 15.0
        num2: 13.0
        result: 18.0
        */

        break; // insert a breakpoint here
    case '*':
        result = num1 * num2;
        num1 = num1 - 10;
        cout << num1 << " * " << num2 << " = " << result << endl;
        /*
        num1: -5.00
        num2: 6.00
        result: 30.0
        */

        break; // insert a breakpoint here
    case '/':
        result = num1 / num2;
        num2 = num2 - 10;
        cout << num1 << " / " << num2 << " = " << result << endl;
        /*
        num1: 25.0
        num2: -5.0
        result: 5
        */

        break; // insert a breakpoint here
    default:
        cout << "Error! operator is not correct";
        break;
    }
}