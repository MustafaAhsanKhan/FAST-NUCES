#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
using namespace std;

// Question 1: Test for matchTables
TEST(MatchTablesTest, BasicTest) {
    const int rows = 3;
    const int cols = 3;
    int table1[rows][cols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int table2[rows][cols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    EXPECT_TRUE((matchTables<int, rows, cols>(table1, table2)));


    int table3[rows][cols] = { {1, 2, 3}, {4, 0, 6}, {7, 8, 9} };
    EXPECT_FALSE((matchTables<int, rows, cols>(table1, table3)));

}
// Question 4: Test for spiralOrder
TEST(SpiralOrderTest, BasicTest) {
    const int rows = 3;
    const int cols = 3;
    int matrix[rows][cols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int size;
    int* result = spiralOrder<int,rows,cols>(matrix, size);

    int expected[] = { 1, 2, 3, 6, 9, 8, 7, 4, 5 };
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }
    delete[] result;
}