#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
using namespace std;
// question 1
TEST(RecursiveFunction3, palindrome)
{
    const string word = "madam";
    const string word1 = "repaper";
    const string word2 = "home";
   
    // Check the result
    EXPECT_EQ(true, isPalindrome(word, 0, word.length()));
   
    // Check the result
    EXPECT_EQ(true, isPalindrome(word1, 0, word1.length()));

    EXPECT_EQ(false, isPalindrome(word2, 0, word2.length()));
}
// question 2
TEST(RecursiveFunction4, fibonacci)
{
    EXPECT_EQ(3, fibonacci(4));
    EXPECT_EQ(8, fibonacci(6));
    EXPECT_EQ(34, fibonacci(9));
}
// question 3
TEST(RecursiveFunction6, DecimalToOcta)
{
    EXPECT_EQ(2, DecimalToOcta(55));
    EXPECT_EQ(0, DecimalToOcta(92));
}

