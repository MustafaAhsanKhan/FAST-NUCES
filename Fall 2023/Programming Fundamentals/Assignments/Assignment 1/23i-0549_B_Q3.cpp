#include <iostream>
#include <cmath>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    float N, i;
    int b, p;
    const int c = 30 ;
    
    cout << "Enter your balance: ";
    cin >> b;
    
    cout << "Enter your monthly payment: ";
    cin >> p;

    cout << "Enter your yearly interest rate: ";
    cin >> i;

    i = i / 365;
    

    N = -(1.0 / c) * (log(1 + (b/p) * (1 - pow(1 + i, c)))) / log(1 + i);  // Formula
    

    cout << "How long it will take for you to pay off your credit card loan: " << N << endl;


    return 0;

}