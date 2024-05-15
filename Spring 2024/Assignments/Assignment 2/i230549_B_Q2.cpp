#include "../Assignment2_project_final/i230549_B_Q2.h"
#include <iostream>
using namespace std;

/*

****Assignment 2****
Name: Mustafa Ahsan Khan
ID: i23-0549
Section: CS-B

*/

void String::initializestr(const char* str)
{
	length = 0;
	for (int i = 0; *(str + i) != '\0'; ++i)  // Finding out the length of the string
	{
		++length;
	}

	str_class = new char[length + 1]; // Allocating memory

	for (int i = 0; i <= length; ++i)
	{
		*(str_class + i) = *(str + i);  // Copying the string
	}
}

String::String() // default constructor
{
	str_class = NULL;
	length = 0;
}

String::String(const char* str) // initializes the string with constant c-string
{
	initializestr(str);
}

String::String(const String& copy_to) // copy constructor to initialize the string from the existing string
{
	length = 0;
	initializestr(copy_to.str_class);
}

String::String(int x) // initializes a string of predefined size
{
	str_class = NULL;

	length = 0;
	str_class = new char[x + 1];

	*(str_class + 0) = '\0';
}

char* String::getdata() //returns the string inside the object
{
	return str_class;
}


// Binary Operators // Sub-script Operators
const char String::operator[](int i) const // returns the character at index [x]
{
	if (i >= 0)
	{
		return *(str_class + i);
	}
	else
	{
		return *(str_class + (length + i));
	}
}


//NOTE: in above [] operator functions if i=negative int value, print ith character from end //of string e.g. in case of “LOOP” if i=-1 OR i=3, it should return ‘P’ similarly i=-4 OR i=0, //return ‘L’
// Arithmetic Operators

String String::operator+(const String& str)  // appends a String at the end of the String
{
	String final_string;
	int string_length = 0;

	for (int i = 0; *(str.str_class + i) != '\0'; ++i)  // Finding out the length of the string
	{
		string_length++;
	}

	final_string.str_class = new char[length + string_length + 2];  // Memory allocation

	final_string.str_class[length + string_length + 1] = '\0';

	for (int i = 0; i < length + 1; i++)
	{
		final_string.str_class[i] = str_class[i];  // Copying the c-string
	}
	
	for (int i = length, j = 0; i < string_length + length + 1; i++, j++)
	{
		*(final_string.str_class + i) = *(str.str_class + j);  // Concatenating the string to the end
		if (i + 1 == string_length + length + 1)
		{
			*(final_string.str_class + i + 1) = '\0';
		}
	}


	delete[] str_class;  // Deallocating memory

	length = length + string_length;  // Updating length

	str_class = new char[length + 2];  // Memory allocation

	this->str_class[length + 1] = '\0';

	for(int i = 0; i <= length +1  ; i++)
	{
		this->str_class[i] = final_string.str_class[i];  // Copying the final string
	}

	return* this;
}

String String::operator+(const char& str)  // appends a char at the end of the String
{
	String final_string;

	final_string.str_class = new char[length + 2];  // Memory allocation // 1 for char and 1 for '\0'

	for (int i = 0; i < length; ++i)
	{
		final_string.str_class[i] = str_class[i];  // Copying the string
	}

	*(final_string.str_class + length) = str;  // Adding the char at the end
	*(final_string.str_class + length + 1) = '\0';  // Null character

	delete[] str_class;  // Deallocating memory

	str_class = new char[length + 2];  // Memory allocation

	for (int i = 0; i <= length + 1; ++i)
	{
		str_class[i] = final_string.str_class[i];  // Copying the final string
	}

	return *this;
}

String String::operator+(const char* str)  // appends a String at the end of the String
{
	String final_string;
	int string_length = 0;

	for (int i = 0; *(str + i) != '\0'; ++i)  // Finding out the length of the string
	{
		string_length++;
	}

	final_string.str_class = new char[length + string_length + 2];  // Memory allocation

	final_string.str_class[length + string_length + 1] = '\0';

	for (int i = 0; i < length + 1; i++)
	{
		final_string.str_class[i] = str_class[i];  // Copying the string
	}

	for (int i = length, j = 0; i < string_length + length + 1; i++, j++)
	{
		*(final_string.str_class + i) = *(str + j);  // Concatenating the string to the end
		if (i + 1 == string_length + length + 1)
		{
			*(final_string.str_class + i + 1) = '\0';
		}
	}


	delete[] str_class;  // Deallocating memory

	length = length + string_length;

	str_class = new char[length + 2];  // Memory allocation

	this->str_class[length + 1] = '\0';

	for (int i = 0; i <= length + 1; i++)
	{
		this->str_class[i] = final_string.str_class[i];  // Copying the final string
	}

	return*this;
}

String String::operator-(const String& substr) //removes the substr from the String
{
	bool flag;
	if (substr.length == 0 || substr.length > length)  // substring is empty or longer than original string
	{
		return *this;  // Return original string

	}


	char* final_str = new char[length + 1]; // Allocate memory

	int final_str_length = 0; // Length of the resulting string

	
	for (int i = 0; i < length; ++i)  // Loop for current string
	{
	
		if (str_class[i] == substr.str_class[0])  // First character matched
		{
			flag = true;
			for (int j = 1; j < substr.length; ++j)
			{
				if (str_class[i + j] != substr.str_class[j])  // Any character didnt match
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				i = i + (substr.length - 1);  // Moving to the end of the found substring

				continue;
			}
		}
		
		final_str[final_str_length] = str_class[i];  // Characters other than the substring

		++final_str_length;
	}

	final_str[final_str_length] = '\0';  // Null characters

	str_class = final_str;

	length = length - substr.length;  // Updating length

	return *this;
}

String String::operator-(const char& str) //removes all occurrences of char from the String
{
	char* final_string = new char[length + 1];  // Memory allocation
	int index = 0;

	for (int i = 0; *(str_class + i) != '\0'; ++i)
	{
		if (*(str_class + i) != str)  // Character not found
		{
			*(final_string + index) = *(str_class + i);  // Appending the final string
			++index;
		}
	}

	str_class = final_string;
	str_class[index] = '\0';

	length = index;  // Updating length

	return *this;
}

String String::operator-(const char* str) //removes the str from the String
{
	int str_length = 0;
	bool flag;
	for (int i = 0; str[i] != '\0'; ++i)  // Finding the length of the string
	{
		++str_length;
	}

	if (str_length == 0 || str_length > length)  // substring is empty or longer than original string
	{
		return *this;
	}


	char* result_str = new char[length + 1]; // Memory allocation

	int result_length = 0; // Length of the resulting string


	for (int i = 0; i < length; ++i)  // Loop for current string
	{
		if (str_class[i] == str[0])  // First character matched
		{
			flag = true;

			for (int j = 0; j < str_length; ++j)
			{
				if (str[j] != str_class[i + j])  // Any character didnt match
				{
					flag = false;
					break;
				}
			}
			
			if (flag)
			{
				i = i + (str_length - 1);  // Moving to the end of the found substring
				continue;
			}
		}

		
		result_str[result_length] = str_class[i];  // Characters other than substring
		++result_length;
		
	}

	
	result_str[result_length] = '\0';  // NULL character

	
	str_class = result_str;

	length = length - str_length;  // Updating length

	return *this;
}

// Assignment Operators

String& String::operator=(const String& copy_to) // copies one String to another
{
	length = 0;
	initializestr(copy_to.str_class);

	return *this;
}

String& String::operator=(char* copy_to) // copies one c-string to another
{
	length = 0;
	initializestr(copy_to);

	return *this;
}

// Logical Operators
bool String::operator==(const String& str) const // returns true if two Strings are equal
{

	int char_length = 0;

	for (int i = 0; *(str.str_class + i) != '\0'; ++i)  // Calculating length
	{
		++char_length;
	}

	if (length != char_length)  // Length is not the same
	{
		return false;
	}

	for (int i = 0; i <= length; ++i)  // Comparing each character
	{
		if (*(str_class + i) != *(str.str_class + i))
		{
			return false;
		}
	}
	return true;
}

bool String::operator==(const char* str) const // returns true if the c-string is equal to the String
{
	int char_length = 0;

	for (int i = 0; *(str + i) != '\0'; ++i)  // Calculating length
	{
		++char_length;
	}

	if (length != char_length)  // Length is not the same
	{
		return false;
	}

	for (int i = 0; i <= length; ++i)  // Comparing each character
	{
		if (*(str_class + i) != *(str + i))
		{
			return false;
		}
	}
	return true;
}

// Unary Operators // Boolean Not Operator
bool String::operator!() // returns true if the String is empty
{
	if (str_class[0] == '\0')
	{
		return true;
	}
	return false;
}
// Function-Call Operators
//If something is not found then return -1

int String::operator()(char str) const // returns the first index of the character being searched
{
	for (int i = 0; *(str_class + i) != '\0'; ++i)
	{
		if (str == *(str_class + i))  // Character found
		{
			return i;
		}
	}
	return -1;
}

int String::operator()(const String& str) const // returns the first index of the String being searched
{
	bool flag;
	//int str_length = 0;
	//for (int i = 0; str.str_class[i] != '\0'; ++i)  // Calculating length
	//{
	//	++str_length;
	//}
	//++str_length;

	// Iterate over the current string
	for (int i = 0; i < length; ++i)
	{
		// Check if the current position matches the start of the substring
		flag = true;
		for (int j = 0; j < str.length; ++j)
		{
			if (str.str_class[j] != str_class[i + j])
			{
				flag = false;
				break;
			}
		}
		// If the substring is found, skip it
		if (flag)
		{
			return i;
		}
	}

	return -1;
}

int String::operator()(const char* str) const // returns the index of the c-string being searched
{
	// Calculate the length of the input string
	int str_length = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		++str_length;
	}
	//++str_length;

	// Iterate over the current string
	for (int i = 0; i < length; ++i)
	{
		// Check if the current position matches the start of the substring
		bool flag = true;
		for (int j = 0; j < str_length; ++j)
		{
			if (str[j] != str_class[i + j])
			{
				flag = false;
				break;
			}
		}
		// If the substring is found, skip it
		if (flag)
		{
			return i;
		}
	}

	return -1;
}

// Conversion Operator

String::operator int() const // returns the length of string
{
	return length;
}

String::~String() // destructor
{
	delete[] str_class;  // Deallocating memory
	str_class = NULL;
}

ostream& operator<<(ostream& output, const String& str) // outputs the string
{
	if (str.str_class != NULL)
	{
		output << str.str_class << '\n';
		return output;
	}
}

istream& operator>>(istream& input, String& str) // inputs the string
{

	char buffer[1024]; // Input size of 1024 characters
	input >> buffer;

	str.initializestr(buffer);

	return input;
}