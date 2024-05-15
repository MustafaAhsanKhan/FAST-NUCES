#pragma once
#include <iostream>
using namespace std;

bool isPalindrome(string str, int start, int length)
{

    if (start == length / 2)
    {
        return 1;
    }
    if (str[start] == str[length - start - 1])
    {
        if (start <= length / 2)
        {
            return isPalindrome(str, start + 1, length);
        }
    }
    else
    {
        return 0;
    }

}

int fibonacci(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

}

int DecimalToOcta(int n)
{
    int count = 0;
    if (n == 0)
    {
        return count;
    }
    else
    {
        int remainder = n % 8;
        
        if (remainder >= 5)
        {
            count++;
        }
        return count + DecimalToOcta(n / 8);
    }
}

void pattern_stars(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << "*" << " ";
        pattern_stars(n - 1);
    }
}

void pattern_Q4(int n, int spaces)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        pattern_stars(spaces - n + 1);
        cout << endl;
        return pattern_Q4(n - 1, spaces);
    }
}

void pattern2_stars_upper(int n)
{
    if (n < 0)
    {
        return;
    }
    else
    {
        cout << " ";
        pattern2_stars_upper(n - 1);
    }
}

void pattern2_spaces_upper(int spaces)
{
    if (spaces == 0)
    {

        return;
    }
    else
    {
        cout << "*";
        pattern2_spaces_upper(spaces - 1);
    }
}

void pattern2_lower(int n, int spaces)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        pattern2_stars_upper(spaces - n + 1);
        pattern2_spaces_upper(2 * n - 1);

        cout << endl;
        pattern2_lower(n - 1, spaces);
    }
}

void pattern_Q5(int n, int spaces)
{
    if (n == spaces / 2)
    {
        pattern2_lower((spaces - 1) / 2, spaces - 3);
        return;
    }
    else
    {
        pattern2_stars_upper(n - 3);
        pattern2_spaces_upper(2 * (spaces - n) + 1);

        cout << endl;
        pattern_Q5(n - 1, spaces);
    }
}