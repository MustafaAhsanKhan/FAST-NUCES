#include <iostream>
#include <cmath>
#include <ctime>
#include <unistd.h>
using namespace std;

int MovePlayer(int &currentPosition, int diceRoll)
{
    currentPosition = currentPosition + diceRoll;
    cout << "The new position is: " << currentPosition << endl;
    return 0;
}

int MovePlayerUP(int &currentPosition)
{
    currentPosition = currentPosition + 7;  // Ladder
    return 0;
}

int MovePlayerDOWN(int &currentPosition)
{
    currentPosition = currentPosition - 5;  // Snake
    return 0;
}

void DisplayBoard()
{
    int num = 100;
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            cout << "[" << num << "]" << " ";
            num = num - 1;
        }
        cout << endl;
    }
}

int CheckForLadder(int &square)
{
    if(square == 3 || square == 8 || square == 18 || square == 25)  // There are ladders at these squares
    {
        MovePlayerUP(square);
        cout << "(CLIMB UP)" << endl;;
    }
    return 0;
}

int CheckForSnake(int &square)
{
    if(square == 24 || square == 34 || square == 44 || square == 60)  // There are snakes at these points
    {
        MovePlayerDOWN(square);
        cout << "(SLIDE DOWN)" << endl;;
    }
    return 0;
}

int main()
{
    int roll;
    int currentPosition;
    currentPosition = 0;
    cout << "Welcome to the Snake and ladder game! " << endl << endl;
    DisplayBoard();
    srand(time(0));

    while(currentPosition < 100)
    {
        sleep(1);

        roll = (rand() % 6) + 1;  // Random roll from 1-6

        MovePlayer(currentPosition, roll);

        CheckForLadder(currentPosition);
        CheckForSnake(currentPosition);
    }

    cout << "YOU WIN";
}