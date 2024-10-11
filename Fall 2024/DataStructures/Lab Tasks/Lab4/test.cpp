#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
using namespace std;
// question 1
TEST(StudentSortTest, SortByGPA) {
    // Example student records
    StudentRecord students[] = {
        {101, "Alice", 3.5},
        {102, "Bob", 3.9},
        {103, "Charlie", 2.8},
        {104, "Diana", 3.2},
        {105, "Eve", 3.7}
    };
    int size = sizeof(students) / sizeof(students[0]);

    // Expected sorted student records
    StudentRecord expected[] = {
        {103, "Charlie", 2.8},
        {104, "Diana", 3.2},
        {101, "Alice", 3.5},
        {105, "Eve", 3.7},
        {102, "Bob", 3.9}
    };

    // Perform the sort
    selectionSortStudents(students, size);

    // Check if the array matches the expected result
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(students[i].studentID, expected[i].studentID);
        EXPECT_EQ(students[i].name, expected[i].name);
        EXPECT_FLOAT_EQ(students[i].GPA, expected[i].GPA);  // Use EXPECT_FLOAT_EQ for floating-point comparison
    }
}

//question 2
TEST(SortingTest, BubbleSortTest) {
    int studentIDs[] = { 101, 102, 103, 104, 105 };
    int grades[] = { 85, 92, 78, 90, 88 };
    int numStudents = sizeof(studentIDs) / sizeof(studentIDs[0]);

    // Expected sorted IDs and grades
    int expectedStudentIDs[] = { 103, 101, 105, 104, 102 };
    int expectedGrades[] = { 78, 85, 88, 90, 92 };

    // Call bubbleSort to sort the grades
    bubbleSort(studentIDs, grades, numStudents);

    // Check if the sorted IDs and grades match the expected result
    for (int i = 0; i < numStudents; i++) {
        EXPECT_EQ(studentIDs[i], expectedStudentIDs[i]);
        EXPECT_EQ(grades[i], expectedGrades[i]);
    }
}
// question 3
TEST(PuzzleSortTest, SortPuzzleRows) {
    int puzzle[2][8] = {
        {32, 30, 39, 34, 37, 35, 33},
        {50, 48, 54, 59, 47, 49, 52, 51}
    };

    // Expected sorted result
    int expectedPuzzle[2][8] = {
        {30, 32, 33, 34, 35, 37, 39},
        {47, 48, 49, 50, 51, 52, 54, 59}
    };

    // Sort the first row using insertion sort
    selectionSortPuzzel(puzzle[0], 7);


    // Sort the third row using bubble sort
    bubbleSortPuzzel(puzzle[1], 8);

    // Compare the sorted rows with the expected rows
    for (int i = 0; i < 7; i++) {
        EXPECT_EQ(puzzle[0][i], expectedPuzzle[0][i]);
    }

    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(puzzle[1][i], expectedPuzzle[1][i]);
    }
}
// question 4
TEST(LinearSearchTest, BasicTests) {
    // Test case 1: Target is found in the array
    const int numStrings1 = 5;
    string strings1[numStrings1] = { "apple", "banana", "cherry", "date", "elderberry" };
    int result1 = linearSearchString(strings1, numStrings1, "cherry");
    EXPECT_EQ(result1, 2);  // Expected index is 2

    // Test case 2: Target is not found in the array
    int result2 = linearSearchString(strings1, numStrings1, "fig");
    EXPECT_EQ(result2, -1); // Expected result is -1 since "fig" is not in the array
}