#include <iostream>
using namespace std;

bool CheckEvenOdd(int num)
{
    if(num % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num, even, odd;
    bool flag;
    even = 0;
    odd = 0;
    num = 0;

    while(num != -1)
    {
        cout << "Enter a list of numbers, terminated by -1 " << endl;
        cout << "Enter number: ";
        cin >> num;

        if(num == -1)
        {
            break;
        }
        flag = CheckEvenOdd(num);

        if(flag)
        {
            even = even + 1;
        }
        else
        {
            odd = odd + 1;
        }
    }

    cout << "Number of even numbers: " << even << endl;
    cout << "Number of odd numbers: " << odd << endl;
    return 0;
}