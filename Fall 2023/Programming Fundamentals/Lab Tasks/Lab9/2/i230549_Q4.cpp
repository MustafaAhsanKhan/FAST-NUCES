#include <iostream>
#include <ctime>
using namespace std;

int choice_display()
{
    int op;

    cout << "Select an Operation: " << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl << endl;
    cout << "Enter the number corresponding to your choice: ";
    cin >> op;

    return op;
}

void add(int a, int b)
{
    cout << "Result: " << a + b;
}

void subtract(int a, int b)
{
    cout << "Result: " << a - b;
}

void multiply(int a, int b)
{
    cout << "Result: " << a * b;
}

void divide(int a, int b)
{
    cout << "Result: " << a / b;
}

int main()
{
    int num1, num2, op;

    cout << "Welcome to My Calculator!" << endl << endl;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << endl;

    op = choice_display();

    switch(op)
    {
        case 1: add(num1, num2);
                break;
        case 2: subtract(num1, num2);
                break;
        case 3: multiply(num1, num2);
                break;
        case 4: divide(num1, num2);
                break;
    }

}