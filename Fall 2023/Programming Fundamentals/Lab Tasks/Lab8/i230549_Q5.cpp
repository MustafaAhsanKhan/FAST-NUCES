#include <iostream>
using namespace std;

int main()
{
    int num, product, sum, j;
    sum = 0;

    cout << "Enter your number: ";
    cin >> num;
    while (num <= 0)
    {
        cout << "Number can not be negative" << endl;
        cout << "Enter your number: ";
        cin >> num;
    }

    while(num != 0)
    {
        product = 1;
        j = (num % 10);
        for(int i = 1; i <= j; ++i)
        {
            product = product * j;
        }
        sum = sum + product;
        num = num / 10;
    }
    cout << "Answer = " << sum;
    return 0;
}