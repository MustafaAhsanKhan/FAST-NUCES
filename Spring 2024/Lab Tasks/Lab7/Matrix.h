#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:

    int rows;
    int columns;
    int** arr;

public:

    Matrix();

    Matrix(int r, int c, int** p);

    Matrix(Matrix& copy);

    int getRows();

    int getColumns();

    int** getMatrix();

    void setRow(int r);

    void setColumn(int c);

    void setMatrix(int** mat);

    void multiplyMatrix(int k);

    void addMatrix(int k);

    void display();
};

