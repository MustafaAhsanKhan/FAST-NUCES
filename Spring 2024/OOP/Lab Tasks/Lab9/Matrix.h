#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
	int rows;
	int columns;
	int** matrix;

public:

	Matrix();

	Matrix(int r, int c);

	Matrix(const Matrix& other);

	Matrix operator=(Matrix& right);

	bool operator==(Matrix& right);

	Matrix& operator+(int x);

	Matrix& operator-(int x);

	Matrix& operator+(Matrix& right);

	Matrix& operator-(Matrix& right);

	friend ostream& operator<<(ostream& out, const Matrix& mat);

	~Matrix();

};
ostream& operator<<(ostream& out, const Matrix& mat);