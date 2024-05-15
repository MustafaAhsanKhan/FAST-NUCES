#include <iostream>
using namespace std;

int main()
{
    int num;
    bool prime = 1;
    cout << "Enter your number: ";
    cin >> num;

    while(num >= 0)
    {
        if(num == 1 || num == 0)
        {
            cout << "Number is not prime" << endl;
        }
        else
        {   for(int i = 2; i <= num/2; ++i)
            {   if (num % i == 0)
                {   
                    prime = 0;
                    break;
                }
            }   
        }
        if(prime)
        {
            cout << "Number is prime" << endl;
        }
        else
        {
            cout << "Number is not prime" << endl;
        }
        cout << "Enter your number: ";
        cin >> num;
        prime = 1;
    }

    
}