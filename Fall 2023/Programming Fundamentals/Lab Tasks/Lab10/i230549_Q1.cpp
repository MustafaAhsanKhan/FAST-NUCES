#include <iostream>
using namespace std;

int main()
{
    float arr[10], temp;
    float sum, avg;
    sum = 0;


        for(int i = 0; i < 10; ++i)
        {
            cout << "Enter integer " << i + 1 << ": ";
            cin >> arr[i];
            sum = sum + arr[i];
        }
        avg = sum / 10;
        cout << "avg is " << avg << endl;

        return 0;
}