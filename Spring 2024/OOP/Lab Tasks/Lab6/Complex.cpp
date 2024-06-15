#include "Complex.h"
#include <iostream>
using namespace std;

Complex::Complex()
{
    real = 0;
    imaginary = 0;
}

Complex::Complex(double r, double i)
{
    real = r;
    imaginary = i;
}

void Complex::setReal(double r)
{
    real = r;
}

void Complex::setImaginary(double i)
{
    imaginary = i;
}

double Complex::getReal()
{
    return real;
}

double Complex::getImaginary()
{
    return imaginary;
}

void Complex::display()
{
    cout << real << "+" << imaginary << "i";
}

Complex Complex::addComplex(Complex& c1)
{
    Complex c_temp;
    c_temp.real = real + c1.real;
    c_temp.imaginary = imaginary + c1.imaginary;

    return c_temp;
}

Complex Complex::subComplex(Complex& c1)
{
    Complex c_temp;
    c_temp.real = real - c1.real;
    c_temp.imaginary = imaginary - c1.imaginary;

    return c_temp;
}

Complex Complex::mulComplex(Complex& c1)
{
    Complex c_temp;
    c_temp.real = (real * c1.real) - (imaginary * c1.imaginary);
    c_temp.imaginary = (real * c1.imaginary) + (imaginary * c1.real);

    return c_temp;
}