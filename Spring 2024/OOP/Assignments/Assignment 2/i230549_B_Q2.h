#pragma once
#include <iostream>
using namespace std;

/*

****Assignment 2****
Name: Mustafa Ahsan Khan
ID: i23-0549
Section: CS-B

*/

class String
{
    // think about the private data members

    char* str_class;
    int length;
    void initializestr(const char* str);
public:
    // provide definitions of following functions
    String(); // default constructor

    String(const char* str); // initializes the string with constant c-string

    String(const String&); // copy constructor to initialize the string from the existing string

    String(int x); // initializes a string of predefined size

    char* getdata(); //returns the string inside the object

    // Binary Operators // Sub-script Operators
    const char operator[](int i) const; // returns the character at index [x]
    //NOTE: in above [] operator functions if i=negative int value, print ith character from end //of string e.g. in case of “LOOP” if i=-1 OR i=3, it should return ‘P’ similarly i=-4 OR i=0, //return ‘L’
    // Arithmetic Operators

    String operator+(const String& str); // appends a String at the end of the String

    String operator+(const char& str); // appends a char at the end of the String

    String operator+(const char* str); // appends a String at the end of the String

    String operator-(const String& substr); //removes the substr from the String

    String operator-(const char& str); //removes all occurrences of char from the String

    String operator-(const char* str); //removes the str from the String

    // Assignment Operators
    String& operator=(const String& str); // copies one String to another

    String& operator=(char* str); // copies one c-string to another

    // Logical Operators
    bool operator==(const String& str) const; // returns true if two Strings are equal

    bool operator==(const char* str) const; // returns true if the c-string is equal to the String

    // Unary Operators // Boolean Not Operator
    bool operator!(); // returns true if the String is empty
    // Function-Call Operators
    //If something is not found then return -1

    int operator()(char str) const; // returns the first index of the character being searched

    int operator()(const String&) const; // returns the first index of the String being searched

    int operator()(const char* str) const; // returns the index of the c-string being searched

    // Conversion Operator
    operator int() const; // returns the length of string

    friend ostream& operator<<(ostream& output, const String& str); // outputs the string

    friend istream& operator>>(istream& input, String& str); // inputs the string

    ~String(); // destructor
};
ostream& operator<<(ostream& output, const String& str); // outputs the string

istream& operator>>(istream& input, String& str); // inputs the string