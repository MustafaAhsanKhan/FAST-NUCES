#include <iostream>
#include <string>

using namespace std;
int main()
{   
    int length;
    cout << "Enter your sentence length: ";
    cin >> length;
    cin.ignore(1);

    char* ptr = new char[length];

    cin.getline(ptr, length + 1);

    cout << ptr;
    
    return 0;
}