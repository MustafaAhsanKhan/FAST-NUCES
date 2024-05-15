#include <iostream>
using namespace std;

int main()
{
    float input, numerator, denominator, series_sum;
    series_sum = 0;

    cout << "Enter a positive integer (or negative number to exit): ";
    cin >> input;
    for(;input >= 0;)
    {
        denominator = input;

        for(numerator = 1; numerator <= input; ++numerator)
        {
            series_sum = series_sum + (numerator/denominator);
            cout << numerator << " / " << denominator << endl;
            denominator = denominator - 1;
        }
        cout << "Sum = " << series_sum << endl;
        cout << "Enter a positive integer (or negative number to exit) ";
        cin >> input;
    }
    return 0;
}