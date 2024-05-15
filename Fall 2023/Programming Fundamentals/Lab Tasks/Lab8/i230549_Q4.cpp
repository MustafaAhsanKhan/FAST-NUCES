#include <iostream>
using namespace std;

int main()
{
    bool prime;
    prime = 1;

    for(int num = 100; num <= 999; ++num)
    {
        for(int j = 2; j <= num/2; ++j)
        {   if (num % j == 0)
            {   
                prime = 0;
                break;
            }
        }

        if((num % 10 == num /100) && (prime == 1))
        {
            cout << num << " ";
        }
        prime = 1;
    }

}