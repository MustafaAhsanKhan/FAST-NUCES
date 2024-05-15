#include "pch.h"
#include "../23i0539_B_LAB01/header.h"

TEST(ArrayTest1, sumArray) {
	int arr1[6] = { 7,2,8,4,5,9 };
	EXPECT_EQ(35, sumArray(arr1, 6));
	EXPECT_TRUE(true);
}

TEST(ArrayTest2, sumArray) {
	int arr2[7] = { -1,-2,-7,3,-11,4,0 };
	EXPECT_EQ(-14, sumArray(arr2, 7));
	EXPECT_TRUE(true);
}

TEST(SQRT_PositiveNos, squareRoot) {
	EXPECT_EQ(6, squareRoot(36));
	EXPECT_EQ(18, squareRoot(324));
	EXPECT_EQ(25.4, squareRoot(645.16));
	EXPECT_TRUE(true);
}

TEST(SQRT_NegativeNos, squareRoot) {
	EXPECT_EQ(-1, squareRoot(-15.0));
	EXPECT_EQ(-1, squareRoot(-0.2));
	EXPECT_TRUE(true);
}