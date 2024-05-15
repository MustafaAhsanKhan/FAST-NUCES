#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int human_score, computer_score, human_choice, computer_choice, sum;
    bool cont;
    cont = 1;
    sum = 0;
    human_score = 0;
    computer_score = 0;

    srand(time(0));
    while(cont == 1)
    {
        cout << "The round has started, pick a number between 1 and 10 inclusive: ";
        cin >> human_choice;

        if(human_choice < 1 || human_choice > 10)
        {
            break;
        }

        computer_choice = (rand() % 10 + 1);

        cout << "The human chose: " << human_choice << endl;
        cout << "The computer chose: " << computer_choice << endl;

        sum = human_choice + computer_choice;

        if(sum % 2 == 0)
        {
            cout << "The sum was: " << sum << endl;
            cout << "The computer(EVENS) wins this round" << endl;
            computer_score = computer_score + 1;
        }
        else
        {
            cout << "The sum was: " << sum << endl;
            cout << "The human(ODDS) wins this round" << endl;
            human_score = human_score + 1;
        }
        sum = 0;

    }
    cout << "Total Computer Score: " << computer_score << endl;
    cout << "Total Human Score: " << human_score << endl;   
}