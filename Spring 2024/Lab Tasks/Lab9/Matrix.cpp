#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
	rows = 0;
	columns = 0;
	matrix = NULL;
}

Matrix::Matrix(int r, int c)
{
	rows = r;
	columns = c;
	matrix = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[columns];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& other)
{
	rows = other.rows;
	columns = other.columns;
	matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[columns];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}

	
}

Matrix Matrix::operator=(Matrix& right)
{
	if (rows == right.rows && columns == right.columns)
	{
		Matrix new_matrix(right.rows, right.columns);
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				new_matrix.matrix[i][j] = right.matrix[i][j];
			}
		}

		return new_matrix;
		
	}
}

bool Matrix::Matrix::operator==(Matrix& right)
{
	if (rows == right.rows && columns == right.columns)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				if (matrix[i][j] != right.matrix[i][j])
				{
					return 0;  // FALSE
				}
			}
		}
		return 1;  // TRUE
	}
	return 0;  // FALSE
}

Matrix& Matrix::operator+(int x)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			matrix[i][j] = matrix[i][j] + x;
		}
	}
	return *this;
}

Matrix& Matrix::operator-(int x)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			matrix[i][j] = matrix[i][j] - x;
		}
	}
	return *this;
}

Matrix& Matrix::operator+(Matrix& right)
{
	if (rows == right.rows && columns == right.columns)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				matrix[i][j] = matrix[i][j] + right.matrix[i][j];
			}
		}
		return *this;
	}
}

Matrix& Matrix::operator-(Matrix& right)
{
	if (rows == right.rows && columns == right.columns)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				matrix[i][j] = matrix[i][j] - right.matrix[i][j];
			}
		}
		return *this;
	}
}

ostream& operator<<(ostream& out, const Matrix& mat)
{
	for (int i = 0; i < mat.rows; ++i)
	{
		for (int j = 0; j < mat.columns; ++j)
		{
			out << mat.matrix[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}