#include <iostream>
#include <iomanip>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 3

int FindSum(int a, int b, int c)  // to calculate Sum
{
    int total;
    total = a + b + c;
    return total;
}

float FindAvg(int a, int b, int c)  // to calculate Average
{
    float avg;
    avg = ((float(a + b + c)) / 3.0);
    return avg;
}

void ShowSum(int a)  // Output sum
{
    cout << fixed << setprecision(2) << "Sum = " << a << endl;
}

void ShowAvg(float a)  // Output average
{
    cout << "Average = " << a << endl;
}

int FindMax(int a, int b, int c)  // to find maximum of the 3 numbers
{
    if((a > b) && (a > c))
    {
        return a;
    }
    if((b > a) && (b > c))
    {
        return b;
    }
    if((c > a) && (c > b))
    {
        return c;
    }
    if((a == b) && (a == c))
    {
        cout << "All the numbers are equal" << endl;
        return a;
    }
}

void ShowMax(int a)  // Output maximum
{
    cout << "Maximum = " << a << endl;
}

void ShowMin(int a)  // Output minimum
{
    cout << "Minimum = " << a << endl;
}

int FindMin(int a, int b, int c)  // to find minimum of the 3 numbers
{
    if(a < b && a < c)
    {
        return a;
    }
    if(b < a && b < c)
    {
        return b;
    }
    if(c < a && c < b)
    {
        return c;
    }
    if(a == b && a == c)
    {
        return a;
    }
}


int main()
{
    int x, y ,z;
    int Sum, Max, Min;
    float Average;

    cout << "Enter 3 integer numbers: ";
    cin >> x >> y >> z;
    cout << endl;

    Sum = FindSum(x , y, z);
    Average = FindAvg(x, y, z);

    ShowSum(Sum);
    ShowAvg(Average);
    cout << endl;
    
    Max = FindMax(x, y, z);
    Min = FindMin(x, y, z);

    ShowMax(Max);
    ShowMin(Min);

    return 0;

}