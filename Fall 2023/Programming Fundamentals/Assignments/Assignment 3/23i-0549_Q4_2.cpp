#include <iostream>
#include <unistd.h>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 3

int main()
{
    char find_word[500], replace_word[500];
    char words_array[500];

    while(find_word != "")
    {
        cout << "Enter your paragraph" << endl;
        cin.getline(words_array, 500);
        cout << "Please enter the word to find: ";
        cin >> find_word;
        cout << "Please enter the replace word: ";
        cin >> replace_word;

        if(find_word == "")
        {
            break;
        }
        cout << words_array;


    }
}