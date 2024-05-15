#include <iostream>
#include <ctime>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 3

void DisplayMenu()  // Displays options
{
    cout << "--------Practice Arithmetic--------" << endl;
    cout << "1.Addition" << endl;
    cout << "2.Subtraction" << endl;
}

void PracticeAdd()  // addition function
{
    int num1, num2, correct, wrong, answer;
    char cont;
    cont = 'y';
    correct = 0;
    wrong = 0;

    srand(time(0));
    while(cont == 'y' || cont == 'Y')
    {
        num1 = (rand() % 100 + 1);
        num2 = (rand() % 100 + 1);

        cout << num1 << " + " << num2 << " ?  ";
        cin >> answer;

        if(answer == (num1 + num2))
        {
            correct = correct + 1;
            cout << "CORRECT" << endl << "Continue(y/n)?";
            cin >> cont;
        }
        else
        {
            wrong = wrong + 1;
            cout << "WRONG" << endl << "Continue(y/n)?";
            cin >> cont;
        }
    
    }
    cout << "No. of CORRECT answers = " << correct << endl;
    cout << "No. of WRONG answers = " << wrong << endl;
}

int Select(int a)
{
    return a;
}

void PracticeSub()  // subtraction function
{
    int num1, num2, correct, wrong, answer;
    char cont;
    cont = 'y';
    correct = 0;
    wrong = 0;

    while(cont == 'y' || cont == 'Y')
    {
        num1 = (rand() % 100 + 1);
        num2 = (rand() % 100 + 1);

        cout << num1 << " - " << num2 << " ?  ";
        cin >> answer;

        if(answer == (num1 - num2))
        {
            correct = correct + 1;
            cout << "CORRECT" << endl << "Continue(y/n)?";
            cin >> cont;
        }
        else
        {
            wrong = wrong + 1;
            cout << "WRONG" << endl << "Continue(y/n)?";
            cin >> cont;
        }

    }
    cout << "No. of CORRECT answers = " << correct << endl;
    cout << "No. of WRONG answers = " << wrong << endl;
}

int main()
{
    int choice;

    srand(time(0));
    DisplayMenu();

    do
    {
        cout << "Enter your choice (1/2): " ;
        cin >> choice;
    }
    while(choice != 1 && choice != 2);

    choice = Select(choice);

    switch(choice)
    {
        case 1: PracticeAdd();
                break;

        case 2: PracticeSub();
                break;
    }
    return 0;
}