#include <iostream>
using namespace std;

void calculate10(int num)
{
    int one, zero, temp;
    one = 0;
    zero = 0;
    
    for(int i = 31; i >=0; --i)
    {
    	temp = (num >> i) & 1;
    	if(temp == 1)
    	{
    	    one = one + 1;
    	}
    	else
    	{
    	    zero = zero + 1;
    	}
    }
    cout << "The number of 1s are: " << one << endl;
    cout << "The number of 0s are: " << zero << endl;
}

int main()
{
    int num1;
    
    cout << "Enter your number: ";
    cin >> num1;
    
    calculate10(num1);
    return 0;
}
