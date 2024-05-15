#pragma once

class Complex
{
    double real;
    double imaginary;

public:

    Complex();

    Complex(double r, double i);

    void setReal(double r);

    void setImaginary(double i);

    double getReal();

    double getImaginary();

    void display();

    Complex addComplex(Complex& c1);

    Complex subComplex(Complex& c1);

    Complex mulComplex(Complex& c1);
};

