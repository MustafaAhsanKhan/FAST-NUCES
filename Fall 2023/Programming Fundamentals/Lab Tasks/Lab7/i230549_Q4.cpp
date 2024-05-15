#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int num, guess, i;
    i = 10;

    srand(time(0));
    num = rand() % 100 + 1;

    cout << "I am thinking of a number between 1 and 100" << endl;
    while(i > 0)
    {
        cout << "Guess what number i am thinking of: ";
        cin >> guess;

        if(guess == num)
        {
            cout << "You guessed correctly congratulations" << endl;
            break;
        }

        if(guess > num)
        {
            cout << "Too high" << endl;
            cout << "You have " << i - 1 << " tries left" << endl;
            i = i - 1;
        }

        if(guess < num)
        {
            cout << "Too low" << endl;
            cout << "You have " << i - 1 << " tries left" << endl;
            i = i - 1;
        }
    }
}