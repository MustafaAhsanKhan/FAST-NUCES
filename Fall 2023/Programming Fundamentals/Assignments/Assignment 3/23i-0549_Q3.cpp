#include <iostream>
#include <ctime>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 3

char word_bank[57][21] = {"apple", "banana", "cat", "dog", "elephant", "fish", "giraffe", "horse", "igloo", "jellyfish","kangaroo", "lion", "monkey", "narwhal", "octopus", "penguin", "quail", "rhinoceros", "snake", "tiger","umbrella", "violin", "walrus", "xylophone", "zebra","wizard", "witch", "magic", "potion", "spell", "enchanted", "fairytale", "mythology", "legend", "folklore","superhero", "villain","planet", "star", "galaxy", "black hole", "comet", "asteroid", "meteor", "constellation", "solar system", "universe","ocean", "mountain", "forest", "desert", "river", "lake", "beach", "valley", "island", "waterfall"};  // add more words

int get_index()  // Choosing a random index
{
    return rand() % 57;
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
    int word_length, name_length, j;
    int lives = 6;
    char guess;
    bool al_guessed, correct_guess, extra_life;
    extra_life = 1;

    secret_word = word_bank[get_index()];  // Choosing a random word from the word bank
    char word_status[21];
    char guessed_letters[50] = {};
    char secret_word_array[21];
    char name[1000];

    for(word_length = 0; (secret_word[word_length] != '\0'); ++word_length)  // Filling the arrays
    {
        secret_word_array[word_length] = secret_word[word_length];
        word_status[word_length] = '_';
    }
    j = 0;
    //cout << word_length;

    cout << "Enter your name: ";
    cin >> name;

    for(name_length = 0; (name[name_length] != '\0');)
    {
        ++name_length;
    }
    //cout << name_length;


    while(lives > 0)
    {
        draw_hangman(lives);
        al_guessed = 1;  
        
        cout << "The word is: ";
        for(int i = 0; i < word_length; ++i)
        {
            cout << word_status[i];
        }
        cout << endl;
        cout << "Enter your guess: ";
        cin >> guess;

        while(al_guessed == 1)  // Checking if user has already guessed that letter
        {
            al_guessed = 0;
            for(int i = 0; i < 50; ++i)
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
            if(guess == secret_word_array[i])
            {
                word_status[i] = guess;  // showing all instances
                correct_guess = 1;
            }
        }

        if(correct_guess == 1 && lives < 6 && extra_life == 1)  // giving an extra life, Name bonus
        {
            for(int i = 0; i < name_length; ++i)  // checking if the guess matches any letters in the name
            {
                if(guess == name[i])
                {
                    lives = lives + 1;
                    extra_life = 0;
                }
            }
        }
        

        if(correct_guess == 0)  // Incorrect guess
        {
            lives = lives - 1;
        }

        bool flag = 0;
        for(int k = 0; k < word_length; ++k)  // Checking the whole word
        {
            if(word_status[k] != secret_word_array[k])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
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