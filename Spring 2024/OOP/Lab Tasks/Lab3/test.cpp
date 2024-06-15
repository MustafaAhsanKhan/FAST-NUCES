#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
using namespace std;
// question 1
TEST(FindMaxElementTest, SquareMatrix)
{
    int rows = 3;
    int columns = 3;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[columns];
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = i * columns + j; // Populate with sequential values
        }
    }

    // Find the maximum element
    int maxElement = findMaxElement(matrix, rows, columns);

    // Check the result
    EXPECT_EQ(maxElement, 8); // In a 3x3 matrix, 8 is the maximum element

    // Deallocate memory
     for (int i = 0; i < rows; ++i) {
         delete[] matrix[i];
     }
     delete[] matrix;
}
// question 2
TEST(sumOfDiagonal, case1) {
    int* a1 = new int[5] {10, 11, 12, 2, 3};
    int* a2 = new int[5] {4, 6, 2, 7, 8};
    int* a3 = new int[5] {9, 11, 3, 6, 9};
    int* a4 = new int[5] {5, 7, 3, 2, 5};
    int* a5 = new int[5] {9, 7, 4, 8, 7};

    int* A[5] = { a1,a2,a3,a4,a5 };

    ASSERT_EQ(calDiagonal(A, 5, 5), 28);
}
TEST(sumOfDiagonal, case2) {

    int* a1 = new int[3] {10, 11, 12 };
    int* a2 = new int[3] {7, 9, 6};
    int* a3 = new int[3] {19, 2, 21};
    int* A[3] = { a1,a2,a3 };
    ASSERT_EQ(calDiagonal(A, 3, 3), 40);

}
// question 3
TEST(CountNegativesTest, EmptyMatrix)
{
    int* a1 = new int[5] {4, 3, 2, -1};
    int* a2 = new int[5] {3, 2, 1, -1};
    int* a3 = new int[5] {1, 1, -1, -2};
    int* a4 = new int[5] {-1,-1,-2,-3};

    int* A[5] = { a1,a2,a3,a4};

    int result = countNegatives(A, 4, 4);

    EXPECT_EQ(result, 8); 
}
// Question 4
TEST(SetZeroesTest, ExampleMatrix)
{
    int m = 3;
    int n = 4;
    int** matrix = new int* [m]
        {
            new int[4] {1, 2, 3, 0},
                new int[4] {4, 5, 0, 2},
                new int[4] { 0, 3, 1, 5 }
        };

    int** p=setZeroes(matrix, m, n);

    // Check if the matrix has been modified as expected
    EXPECT_EQ(p[0][0], 0);
    EXPECT_EQ(p[0][1], 0);
    EXPECT_EQ(p[0][2], 0);
    EXPECT_EQ(p[0][3], 0);
    EXPECT_EQ(p[1][0], 0);
    EXPECT_EQ(p[1][1], 0);
    EXPECT_EQ(p[1][2], 0);
    EXPECT_EQ(p[1][3], 0);
    EXPECT_EQ(p[2][0], 0);
    EXPECT_EQ(p[2][1], 0);
    EXPECT_EQ(p[2][2], 0);
    EXPECT_EQ(p[2][3], 0);

    // Deallocate memory
     for (int i = 0; i < m; ++i) {
         delete[] matrix[i];
     }
     delete[] matrix;
}
// Question 5
TEST(Construct2DArrayTest, PossibleConstruction)
{
    int m = 2;
    int n = 3;
    int original[] = { 1, 2, 3, 4, 5, 6 };
    int expected[][3] = { {1, 2, 3}, {4, 5, 6} };

    int** result = construct2DArray(original, m, n);

    ASSERT_NE(result, nullptr);

    // Check if the constructed 2D array matches the expected values
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            EXPECT_EQ(result[i][j], expected[i][j]);
        }
    }

    // Deallocate memory
    for (int i = 0; i < m; ++i)
    {
        delete[] result[i];
    }
    delete[] result;
}
