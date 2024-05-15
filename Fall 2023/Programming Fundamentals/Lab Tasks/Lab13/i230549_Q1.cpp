#include <iostream>
using namespace std;

int main()
{
    char arr[100] = {};
    int size;
    bool palindrome;
    palindrome = 1;
    size = 0;

    cout << "Enter your word: ";
    cin >> arr;

    while(arr[size] != '\0')  // We get the size of the word from this
    {
        arr[size] = tolower(arr[size]);
        size = size + 1;
    }

    for(int i = 0; i < size / 2 ; ++i)  // Checks until the middle letter
    {
        if(arr[i] != arr[size - 1 - i])
        {
            palindrome = 0;
        }
    }

    if(palindrome)
    {
        cout << "The entered word was a palindrome";
    }
    else
    {
        cout << "The entered word is not a palindrome";
    }
}
