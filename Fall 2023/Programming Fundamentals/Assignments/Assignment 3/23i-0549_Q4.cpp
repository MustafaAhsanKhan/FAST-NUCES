#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 3

int main()
{
    string str, find_word, replace_word, word, extra;
    char x;
    word = "";
    str = "x";
    while(str != "")
    {
        string words_array[500];
        cout << "Enter your paragraph: ";
        getline(cin, str);
        int i = 0;
        if(str == "")
        {
            break;
        }
        for(int j = 0; str[j] != '\0'; ++j)  // traverses the string and stores each word in an array
        {
            x = str[j];
            if (x == ' ')
            {
                words_array[i] = word;
                word = "";
                i = i + 1;
            }
            else
            {
                word = word + x;
            }
        }
        words_array[i] = word;

        cout << "Please enter the word to find: ";
        cin >> find_word;
        cout << "Please enter the replace word: ";
        cin >> replace_word;

        for(int j = 0; j <= i; ++j)
        {
            if(words_array[j] == find_word || words_array[j] == find_word)
            {
                words_array[j] = replace_word;
            }
        }

        cout << "Result:" << endl;

        for(int j = 0; j <= i; ++j)
        {
            cout << words_array[j] << " ";
        }
        cout << endl;
        cin.ignore();  // ignores the \n character  // still including the last word from the previous paragraph
    }
}