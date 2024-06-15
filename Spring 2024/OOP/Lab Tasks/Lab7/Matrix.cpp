#include "Matrix.h"
#include <iostream>
using namespace std;


Matrix::Matrix()
{
    rows = 0;
    columns = 0;
    **arr = NULL;
}

Matrix::Matrix(int r, int c, int** p)
{
    rows = r;
    columns = c;
    arr = p;
}

Matrix::Matrix(Matrix& copy)
{
    columns = copy.columns;
    rows = copy.rows;

    arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = copy.arr[i][j];
        }
    }
}

int Matrix::getRows()
{
    return rows;
}

int Matrix::getColumns()
{
    return columns;
}

int** Matrix::getMatrix()
{
    return arr;
}

void Matrix::setRow(int r)
{
    rows = r;
}

void Matrix::setColumn(int c)
{
    columns = c;
}

void Matrix::setMatrix(int** mat)
{
    arr = mat;
}

void Matrix::multiplyMatrix(int k)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            arr[i][j] = k * arr[i][j];
        }
    }
}

void Matrix::addMatrix(int k)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            arr[i][j] = k + arr[i][j];
        }
    }
}

void Matrix::display()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}