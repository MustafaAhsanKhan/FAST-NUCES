#include <iostream>
#include <iomanip>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment1

int main()
{
    int N1, N2, N3, N4, N5;
    cout << "Enter number 1: ";
    cin >> N1;

    cout << "Enter number 2: ";
    cin >> N2;

    cout << "Enter number 3: ";
    cin >> N3;

    cout << "Enter number 4: ";
    cin >> N4;

    cout << "Enter number 5: ";
    cin >> N5;

    cout << "N1: " << setw(N1) << setfill('*') << "" << endl;
    cout << "N2: " << setw(N2) << setfill('*') << "" << endl;
    cout << "N3: " << setw(N3) << setfill('*') << "" << endl;
    cout << "N4: " << setw(N4) << setfill('*') << "" << endl;
    cout << "N5: " << setw(N5) << setfill('*') << "" << endl;

    return 0;

}