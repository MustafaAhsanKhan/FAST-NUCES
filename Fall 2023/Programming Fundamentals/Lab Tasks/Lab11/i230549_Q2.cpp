#include <iostream>
#include <iomanip>
using namespace std;

void concatenateWithTriangle(string triangle, int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int k = 0; k < i; ++k)
        {
            cout << " ";
        }

        for(int j = 0; j < size - i; ++j)
        {
            cout << triangle[i];
        }
        cout << endl;
    }
}

int main()
{
    string triangle;
    char ch;
    int size;

    cout << "Enter size of triangle: ";
    cin >> size;

    for(int i = 0; i < size; ++i)
    {
        cout << "What character should be printed in line<" << i + 1 << ">: ";
        cin >> ch;
        triangle = triangle + ch;  // Concatenating the string
    }

    concatenateWithTriangle(triangle, size);

    return 0;
}