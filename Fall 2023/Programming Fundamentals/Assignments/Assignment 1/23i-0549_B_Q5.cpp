#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    int day, month, year;

    cout << "Enter the date in the format 10/6/60 which represents 10th June 1960" << endl;  // explaining the format to the user
    cout << "Enter the day: ";
    cin >> day;

    cout << "Enter the month: ";
    cin >> month;

    cout << "Enter the year: ";
    cin >> year;

    bool magic_date = (year == (day * month));

    magic_date ? cout << "Yes, it is a magic date" << endl : cout << "No, it is not a magic date" << endl;

    return 0;
}