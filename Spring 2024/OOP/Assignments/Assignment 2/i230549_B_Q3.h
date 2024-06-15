#pragma once
#include <iostream>
using namespace std;

/*

****Assignment 2****
Name: Mustafa Ahsan Khan
ID: i23-0549
Section: CS-B

*/

class CAList
{
private:
	const int rows = 7;  // Keys
	const int cols = 7;  // Values  // first column is for the key field

	int count_keys;
	int count_values;

	string** arr;

public:

	CAList();

	//CAList(const CAList& tt);

	void removeDuplicates();

	string& operator[](string str);

	//string& operator=(string str);

	//string& operator+=(string str);

	CAList& operator=(const CAList& tt);

	CAList operator+(CAList& tt2);

	CAList operator-(CAList& tt2);

	friend ostream& operator<<(ostream& output, const CAList& tt);

	~CAList();
};

ostream& operator<<(ostream& output, const CAList& tt);