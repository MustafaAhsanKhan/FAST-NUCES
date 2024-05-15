#include <iostream>
#include <ctime>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 3

int lives = 6;


string word_bank[] = {"hangman", "programming", "computer", "challenge", "developer", "algorithm"};  // add more words

string get_word()  // Choosing a random word from the word bank
{
    return word_bank[rand() % sizeof(word_bank) / sizeof(word_bank[0])];  // change to 100
}

void draw_hangman(int a)  // Drawing the hangman figure based on lives left
{
    if(a == 6)
    {
        cout << "  +---+  " << endl
             << "  |   |  " << endl
             << "      |  " << endl
             << "      |  " << endl
             << "      |  " << endl
             << "      |  " << endl
             << "=========" << endl;
    }

    if(a == 5)
    {
        cout << "  +---+  " << endl
             << "  |   |  " << endl
             << "  0   |  " << endl
             << "      |  " << endl
             << "      |  " << endl
             << "      |  " << endl
             << "=========" << endl;
    }

    if(a == 4)
    {
        cout << "  +---+  " << endl
             << "  |   |  " << endl
             << "  0   |  " << endl
             << "  |   |  " << endl
             << "      |  " << endl
             << "      |  " << endl
             << "=========" << endl;
    }

    if(a == 3)
    {
        cout << "  +---+  " << endl
             << "  |   |  " << endl
             << "  0   |  " << endl
             << " /|   |  " << endl
             << "      |  " << endl
             << "=========" << endl;
    }

    if(a == 2)
    {
        cout << "  +---+  " << endl
             << "  |   |  " << endl
             << "  0   |  " << endl
             << " /|\\  |  " << endl
             << "      |  " << endl
             << "=========" << endl;
    }

    if(a == 1)
    {
        cout << "  +---+  " << endl
             << "  |   |  " << endl
             << "  0   |  " << endl
             << " /|\\  |  " << endl
             << " /    |  " << endl
             << "=========" << endl;
    }

    if(a == 0)
    {
        cout << "  +---+  " << endl
             << "  |   |  " << endl
             << "  0   |  " << endl
             << " /|\\  |  " << endl
             << " / \\  |  " << endl
             << "=========" << endl;
    }
}

void hangman_game()
{
    string secret_word;
    int word_length, j;
    char guess;
    bool al_guessed, correct_guess;

    secret_word = get_word();  // Choosing a random word from the word bank
    word_length = secret_word.length();
    string word_status(word_length, '_');  // Creates a string of length of the secret word and initialises it with underscores
    string guessed_letters(word_length + 10, '_');  // A string that stores users previous guesses

    j = 0;

    while(lives > 0)
    {
        draw_hangman(lives); 
        al_guessed = 1;  
        
        cout << "The word is: " << word_status << endl;
        cout << "Enter your guess: ";
        cin >> guess;

        while(al_guessed == 1)  // Checking if user has already guessed that letter
        {
            al_guessed = 0;
            for(int i = 0; i < word_length + 10; ++i)
            {
                if(guess == guessed_letters[i])
                {
                    al_guessed = 1;
                }
            }
            
            if(al_guessed == 1)
            {
                cout << "You have already guessed this letter" << endl;
                cout << "Guess a letter: ";
                cin >> guess;
            }
        }


        guessed_letters[j] = guess;  // storing the users guess(correct or wrong)
        j = j + 1;
        cout << "Guessed letters: " << guessed_letters << endl;

        correct_guess = 0;

        for(int i = 0; i < word_length; ++i)  // checking if the guess matches any letters in the secret word
        {
            if(guess == secret_word[i])
            {
                word_status[i] = guess;
                correct_guess = 1;
            }
        }
        

        if(correct_guess == 0)
        {
            lives = lives - 1;
        }

        if(word_status == secret_word)
        {
            cout << "Congratulations, you guessed the word: " << secret_word << endl;
            break;
        }

        cout << "Lives remaining: " << lives << endl;
    }

    if(lives == 0)
    {
        draw_hangman(lives);
        cout << "You ran out of lives, the word was: " << secret_word << endl;
    }
}

int main()
{   
    srand(time(0));
    cout << "Welcome to Hangman" << endl;

    hangman_game();

    cout << "Thank you for playing";
}