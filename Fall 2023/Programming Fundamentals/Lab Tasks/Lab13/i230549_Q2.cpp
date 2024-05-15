#include <iostream>
using namespace std;

string checkVowels(char arr[], int size)
{
    char vowel_arr[50] = {};
    bool found;
    int k;
    k = 0;
    found = 0;
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] == 'a' || arr[i] == 'e'|| arr[i] == 'i' || arr[i] == 'o' ||arr[i] == 'u')
        {
            for(int j = 0; j < size; ++j)
            {
                found = 0;
                if(vowel_arr[j] == arr[i]) // if that vowel is already found in the word and stored
                {
                    found = 1;
                    break;
                }
            }
            if(found == 0)
            {
                vowel_arr[k] = arr[i];  // storing that vowel in the new array
                k = k + 1;
            }
        }
    }

    return vowel_arr;
}

bool countChar(char arr[], int size, char chr)
{
    int count;
    count = 0;

    for(int i = 0; i < size; ++i)
    {
        if(arr[i] == chr)
        {
            count = count + 1;
        }
    }
    if(count > 0)
    {
        cout << "Number of occurences of " << chr << " : " << count << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char arr[50], chr;
    string vowel_string;
    int size;
    bool exists;
    size = 0;

    cout << "Enter your word: ";
    gets(arr);

    while(arr[size] != '\0')  // We get the size of the word from this
    {
        arr[size] = tolower(arr[size]);
        size = size + 1;
    }

    vowel_string = checkVowels(arr, size);

    cout << "The vowels in the array are: " << vowel_string << endl;

    cout << "Enter character to find: ";
    cin >> chr;
    chr = tolower(chr);

    exists = countChar(arr, size, chr);

    if(exists)
    {
        cout << "The character " << chr << " does exist";
    }
    else
    {
        cout << "The character " << chr << " does not exist";
    }
}