#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 3

int array[100][100] = {};
int rows, cols;

void draw(int n, int m)
{
    system("cls");
    cout << "Initialising the board.....";
    for(int i = 0; i < n; ++i)  // Filling the array with random values
    {
        for(int j = 0; j < m; ++j)
        {
            array[i][j] = rand() % (m);
            usleep(5000);
        }
    }
    system("cls");

    cout << endl;
    cout << "************GAIN AND WIN************";

    // Printing the Board
    for(int i = 0; i < n; ++i)  // Rows
    {
        cout << endl << endl;
        for(int j = 0; j < m; ++j)  // Columns
        {
            if(array[i][j] < 10)
            {
                cout << " | " << array[i][j] << " | " << "    ";
            }
            if(array[i][j] >= 10 && array[i][j] < 100)
            {
                cout << " |" << array[i][j] << " | " << "    ";
            }
        }
    }
    cout << endl;
}
int jumps, score;

void play(int s)
{
    int q, k;
    score = 0;
    k = 0;
    jumps = 0;
    cout << "The value at (" << s << ", 0) is: " << array[s][0] << endl;
    q = array[s][0];
    cout << "q has been set to: " << q << endl << endl;

    while(score <= 100)
    {
        if(k == rows)
        {
            k = 0;
        }
        usleep(500000);
        cout << "Player moved to (" << k << ", " << q << ")" << endl;  // Showing new position

        if(array[k][q] == 0)
        {
            score = 0;
            cout << "SCORE RESET TO 0" << endl << endl;
        }
        else
        {
            score = score + array[k][q];  // Totalling score
            cout << "Current Score: " << score << endl << endl;
        }
        jumps = jumps + 1;
        q = array[k][q];
        k = k + 1;
    }
}

void showOutput()
{
    cout << "Number of jumps made: " << jumps << endl;
    cout << "Final score: " << score;
}

int main()
{
    srand(time(0));
    int s;

    cout << "1 < rows(n) < 100   1 < columns(m) < 100" << endl;
    do
    {
        cout << endl;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
    }
    while((rows < 2 || rows > 99) || (cols < 2 || cols > 99));  // Input validation
    cout << endl;

    cout << "Value for s can be between 0 and " << rows << endl;
    do
    {
        cout << endl;
        cout << "Enter the value of s: ";
        cin >> s;
    }
    while(s < 0 || s > rows);
    if(s == rows)
    {
        s = s - 1;
    }
    draw(rows, cols);
    play(s);
    showOutput();
}