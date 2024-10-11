#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
#include "../Lab01/Calculator.h"
using namespace std;
// ques1
TEST(MostOccurredNumber, TypeInt) {
    int nums[] = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
    int size = sizeof(nums) / sizeof(nums[0]);
    int arr[] = { 1, 3, 2, 3, 4, 1, 3 };
    int size1 = sizeof(arr) / sizeof(arr[0]);

    ASSERT_EQ(4, findMostFrequentElement(nums, size)); 
    ASSERT_EQ(3, findMostFrequentElement(arr, size1));
}
TEST(MostOccurredNumber, TypeDouble) {
    double nums[] = { 1.1, 2.2, 1.1, 2.2, 3.3, 2.2, 2.2 };
    int size = sizeof(nums) / sizeof(nums[0]);
    ASSERT_EQ(2.2, findMostFrequentElement(nums, size));
}
// question 2
TEST(RearrangeMaxMin, TypeInt) {
    int nums[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(nums) / sizeof(nums[0]);
    int expected[] = { 50, 10, 40, 20, 30 }; // Manually computed expected output

    rearrangeArray(nums, size);

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(nums[i], expected[i]);
    }
}
//ques 3
TEST(SumOfArrays, TypeInt) {
    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 4, 5, 6 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int expected[] = { 5, 7, 9 };

    int* result = sumOfArrays(arr1, arr2, size);

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }

    delete[] result; // Clean up allocated memory
}
TEST(SumOfArrays, TypeDouble) {
    double arr1[] = { 1.1, 2.2, 2.2 };
    double arr2[] = { 4.4, 5.5, 6.6 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    double expected[] = { 5.5, 7.7, 8.8 };

    double* result = sumOfArrays(arr1, arr2, size);
    
    for (int i = 0; i < size; i++) {
         
        ASSERT_EQ(result[i], expected[i]);
    }

    // Clean up allocated memory
}
// ques 4

TEST(ArrayWave, CreateWave) {
    int nums[] = { 4, 5, 9, 12, 9, 22, 45, 7 };
    int size = sizeof(nums) / sizeof(nums[0]);

    int expected[] = { 5, 4, 12, 9, 22, 9, 45, 7 };
    Container<int> wave(nums, size);

    
    int *p=wave.sortInWaveForm();

   
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(p[i], expected[i]);
    }
}
