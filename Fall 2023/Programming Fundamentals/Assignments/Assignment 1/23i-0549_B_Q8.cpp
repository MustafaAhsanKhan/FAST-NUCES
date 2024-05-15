#include <iostream>
#include <iomanip>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    float gallons, total;

    cout << "Enter the number of gallons: ";
    cin >> gallons;

    bool less100 = gallons >= 0 && gallons <= 100;  // gallons less than 100
    bool B100_350 = gallons > 100 && gallons <= 350;  // gallons between 100 and 350
    bool B350_600 = gallons > 350 && gallons <= 600;  // gallons between 350 and 600
    bool A600 = gallons > 600; // gallons above 600

    total = less100 * (gallons * 0.45) + B100_350 * ((45) + ((gallons - 100) * 0.85)) + B350_600 * ((257.5) + ((gallons - 350) * 1.45)) + A600 * ((620) + ((gallons - 600) * 2.60));
    total = total * 1.14;  // additional service charges calculation
    cout << setprecision(2) << fixed << "$" << total << endl;  // set precision to 2 decimal places

    return 0;
}