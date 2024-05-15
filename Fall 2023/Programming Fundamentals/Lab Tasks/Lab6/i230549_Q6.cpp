#include <iostream>
using namespace std;

int main()
{
    int player1, player2;

    cout <<"First player: ";
    cin >> player1;
    cout << "Second player: ";
    cin >> player2;

    switch(player1)
    {
        case 1:
                switch(player2)
            {
                    case 1: cout << "Draw";
                            break;
                    case 2: cout << "Player 2 wins";
                            break;
                    case 3: cout << "Player 1 wins";
                            break;
                    default: cout << "Invalid input";
                            break;
                break;
            }
            break;
        case 2: 
                switch(player2)
            {
                    case 1: cout << "Player 1 wins";
                            break;
                    case 2: cout << "Draw";
                            break;
                    case 3: cout << "Player 2 wins";
                            break;
                    default: cout << "Invalid input";
                            break;
                break;
            }
            break;
        case 3: 
                switch(player2)
            {
                    case 1: cout << "Player 2 wins";
                            break;
                    case 2: cout << "Player 1 wins";
                            break;
                    case 3: cout << "Draw";
                            break;
                    default: cout << "Invalid input";
                            break;
                break;
            }
            break;
        default: cout << "Invalid input";
                            break;
    }

}