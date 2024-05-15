#include <iostream>
#include <ctime>
#include <cmath>
#include <unistd.h>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 2

int main()
{
    int score1 = 0, score2 = 0,
    Rno1, Rno2,
    i = 1, 
    rollnum1_sum, rollnum2_sum,
    Player1_roll1, Player1_roll2, Player2_roll1, Player2_roll2,
    player1_Lindex, player2_Lindex;
    string player1, player2,
    extra;

    cout << "Player 1 enter your full name: ";
    getline(cin, player1);
    cout << "Player 1 enter your roll number: ";
    cin >> Rno1;
    getline(cin, extra);
    cout << "Player 2 enter your full name: ";
    getline(cin, player2);
    cout << "Player 2 enter your roll number: ";
    cin >> Rno2;
    player1_Lindex = toupper(player1.at(player1.length() - 1)) - 64;  // Selecting the right most lettter of the name and storing its index
    player2_Lindex = toupper(player2.at(player2.length() - 1)) - 64;

    rollnum1_sum = (Rno1 % 10) + (Rno1 / 10 % 10);  // Adding the last 2 digits of the roll numbers
    rollnum2_sum = (Rno2 % 10) + (Rno2 / 10 % 10);

    srand(time(0));  // random seed
    for (i; i <= 5; i++)  // ROUNDS
    {
        cout << "****************************" << endl;
        cout << "ROUND " << i << endl << endl;
        
        Player1_roll1 = (rand() % 6 + 1);  // Random number generator (between 1 and 6)
        cout << "Player 1 rolled a " << Player1_roll1 << endl;
        sleep(1);
        Player1_roll2 = (rand() % 6 + 1);
        cout << "Player 1 rolled a " << Player1_roll2 << endl;
        sleep(1);
        cout << endl << endl;
        score1 = score1 + Player1_roll1 + Player1_roll2;

        Player2_roll1 = (rand() % 6 + 1);
        cout << "Player 2 rolled a " << Player2_roll1 << endl;
        sleep(1);
        Player2_roll2 = (rand() % 6 + 1);
        cout << "Player 2 rolled a " << Player2_roll2 << endl;
        sleep(1);
        cout << endl << endl;
        score2 = score2 + Player2_roll1 + Player2_roll2;
        

        // First Bonus
        if(score1 == rollnum1_sum)
        {
            score1 = score1 + (Rno1 % 10);
        }

        if(score2 == rollnum2_sum)
        {
            score2 = score2 + (Rno2 % 10);
        }

        // Second Bonus
        if(score1 == player1_Lindex)
        {
            score1 = score1 + 5;
        }

        if(score2 == player2_Lindex)
        {
            score2 = score2 + 5;
        }

        // Third Bonus
        if(Player1_roll1 == Player1_roll2  == 2)
        {
            cout << "Player 1 got an extra roll!!" << endl;

            Player1_roll1 = (rand() % 6 + 1);  // Random number generator (between 1 and 6)
            cout << "Player 1 rolled a " << Player1_roll1 << endl;
            sleep(1);
            Player1_roll2 = (rand() % 6 + 1);
            cout << "Player 1 rolled a " << Player1_roll2 << endl;
            sleep(1);
            cout << endl << endl;
            score1 = score1 + Player1_roll1 + Player1_roll2;

            // First Bonus
            if(score1 == rollnum1_sum)
            {
                score1 = score1 + (Rno1 % 10);
            }

            // Second Bonus
            if(score1 == player1_Lindex)
            {
                score1 = score1 + 5;
            }

        }

        if(Player2_roll1 == Player2_roll2  == 2)
        {
            cout << "Player 2 got an extra roll!!" << endl;

            Player2_roll1 = (rand() % 6 + 1);
            cout << "Player 2 rolled a " << Player2_roll1 << endl;
            sleep(1);
            Player2_roll2 = (rand() % 6 + 1);
            cout << "Player 2 rolled a " << Player2_roll2 << endl;
            sleep(1);
            cout << endl << endl;
            score2 = score2 + Player2_roll1 + Player2_roll2;

            // First Bonus
            if(score2 == rollnum2_sum)
            {
                score2 = score2 + (Rno2 % 10);
            }

            // Second Bonus
            if(score2 == player2_Lindex)
            {
                score2 = score2 + 5;
            }
        }
        cout << "Player 1 total score is: " << score1 << endl;
        cout << "Player 2 total score is: " << score2 << endl << endl;
    }

    if(score1 > score2)
    {
        cout << "Player 1 WINS" << endl;
    }

    if(score2 > score1)
    {
        cout << "Player 2 WINS" << endl;
    }

    if(score1 == score2)  // score tied
    {
        cout << "The score is drawn we will roll until we get a winner" << endl;

        while(score1 == score2)  // re-rolling
        {
            cout << "****************************" << endl;
            cout << "ROUND " << i << endl << endl;
            
            Player1_roll1 = (rand() % 6 + 1);  // Random number generator (between 1 and 6)
            cout << "Player 1 rolled a " << Player1_roll1 << endl;
            sleep(1);
            Player1_roll2 = (rand() % 6 + 1);
            cout << "Player 1 rolled a " << Player1_roll2 << endl;
            sleep(1);
            cout << endl << endl;
            score1 = score1 + Player1_roll1 + Player1_roll2;

            Player2_roll1 = (rand() % 6 + 1);
            cout << "Player 2 rolled a " << Player2_roll1 << endl;
            sleep(1);
            Player2_roll2 = (rand() % 6 + 1);
            cout << "Player 2 rolled a " << Player2_roll2 << endl;
            sleep(1);
            cout << endl << endl;
            score2 = score2 + Player2_roll1 + Player2_roll2;

            cout << "Player 1 total score is: " << score1 << endl;
            cout << "Player 2 total score is: " << score2 << endl << endl;

            i = i + 1;
        }

        if(score1 > score2)
        {
            cout << "Player 1 WINS" << endl;
        }

        if(score2 > score1)
        {
            cout << "Player 2 WINS" << endl;
        }
    }

    return 0;
}