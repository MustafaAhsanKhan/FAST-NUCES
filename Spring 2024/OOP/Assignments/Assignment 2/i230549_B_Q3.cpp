#include "../Assignment2_project_final/i230549_B_Q3.h"
#include <iostream>
using namespace std;

/*

****Assignment 2****
Name: Mustafa Ahsan Khan
ID: i23-0549
Section: CS-B

*/

CAList::CAList()
{
    count_keys = 0;
    count_values = 1;

    arr = new string * [rows];  // Memory allocation

    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new string[cols];
    }
}

//CAList::CAList(const CAList& tt)
//{
//    count_keys = tt.count_keys;
//    count_values = tt.count_values;
//
//    
//    arr = new string * [rows];  // Memory allocation
//    for (int i = 0; i < rows; ++i)
//    {
//        arr[i] = new string[cols];
//    }
//
//    
//    for (int i = 0; i < rows; ++i)  // Deep copy
//    {
//        for (int j = 0; j < cols; ++j)
//        {
//            arr[i][j] = tt.arr[i][j];
//        }
//    }
//}

void CAList::removeDuplicates()
{

    bool flag;
    for (int i = 0; i < count_keys; ++i)
    {
        string unique_teachers[7] = { "" };  // Temp array to store unique teachers
        int count = 0;

        
        for (int j = 1; j < cols; ++j)  // Loop to check teachers
        {
            
            if (arr[i][j] != "")  // Field is not empty
            {
                flag = false;
                for (int k = 0; k < count; ++k)
                {
                    if (arr[i][j] == unique_teachers[k])  // Duplicate teacher
                    {
                        flag = true;
                        break;
                    }
                }
                
                if (!flag)
                {
                    unique_teachers[count++] = arr[i][j];  // Not a duplicate
                }
            }
        }

        
        for (int j = 1; j <= count; ++j)
        {
            arr[i][j] = unique_teachers[j - 1];  // Copying unique teachers back
        }

        
        for (int j = count + 1; j < cols; ++j)  // Empty other slots
        {
            arr[i][j] = "";
        }
    }
}


string& CAList::operator[](string str)
{
    bool found = false;
    if (count_keys != 7)
    {
        for (int i = 0; i < count_keys; ++i)  // Searching for the key
        {
            for (int j = 1; j < 7; ++j)
            {
                if (arr[i][0] == str)  // Key found
                {
                    found = true;
                    if (arr[i][j] == "")  // Checking for an empty slot
                    {
                        return arr[i][j];
                    }
                }
            }
            if (found == true)
            {
                return arr[i][6];  // Replacing the last entry
            }
        }


        if (found == false)
        {
            // Key not found, add new entry
            arr[count_keys][0] = str;
            count_values = 1;
            //count_keys;
            return arr[count_keys++][count_values];
        }
    }

}

//string& CAList::operator=(string str)
//{
//    string teacher = arr[count_keys][count_values];
//    cout << "test";
//    // Assign the retrieved teacher to the provided course
//    return (*this)[str] = teacher;
//}
//
//string& CAList::operator+=(string str)
//{
//    string teacher = arr[count_keys][count_values];
//    // Assign the retrieved teacher to the provided course
//    return (*this)[str] = teacher;
//}

CAList& CAList::operator=(const CAList& tt)
{
    if (this == &tt)
    {
        return *this; // Both are same
    }

    
    for (int i = 0; i < rows; ++i)  // Memory deallocation
    {
        delete[] arr[i];
    }
    delete[] arr;

    // Deep copy
    count_keys = tt.count_keys;
    count_values = tt.count_values;
    arr = new string * [rows];
    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new string[cols];
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = tt.arr[i][j];
        }
    }

    return *this;
}


CAList CAList::operator+(CAList& tt2)
{
    CAList new_tt;
    new_tt = *this;  // Making a copy
    bool found;  // For course
    int temp;  // For values
    

    for (int i = 0; i < tt2.count_keys; ++i)  // Looping through courses of tt2
    {
        found = false;
        for (int j = 0; j < new_tt.count_keys; ++j)  // if course already exits in newtt
        {
            if (tt2.arr[i][0]  == new_tt.arr[j][0])  // Course name is equal
            {
         
                for (int k = 1; k < cols; ++k)  // Add teachers from tt2 into new_tt
                {
                    if (tt2.arr[i][k] != "")
                    {
                        
                        temp = 1;
                        while (new_tt.arr[j][temp] != "" && temp < cols)  // Finding an empty slot
                        {
                            ++temp;
                        }
                        if (temp < cols)  // Space available
                        {
                            new_tt.arr[j][temp] = tt2.arr[i][k];  // empty slot found
                        }
                    }
                }
                found = true;  // One course completed
                break;
            }
        }
       

        if (!found)  // Course not found  // So adding it in new_tt
        {
            new_tt.arr[new_tt.count_keys][0] = tt2.arr[i][0];  // Adding the new course

            for (int k = 1; k < cols; ++k)
            {
                new_tt.arr[new_tt.count_keys][k] = tt2.arr[i][k];  // Adding the teachers
            }
            ++new_tt.count_keys;  // Course added
        }
    }

    return new_tt;
}

CAList CAList::operator-(CAList& tt2)
{
    CAList newtt;
    newtt = *this;  // Making a copy
    bool flag;  // To check if teachers exist

    for (int i = 0; i < tt2.count_keys; ++i)  // Looping through tt2
    {
        
        for (int j = 0; j < newtt.count_keys; ++j)  // Searching for the same course
        {
            if (newtt.arr[j][0] == tt2.arr[i][0])  // Course found
            {
                
                for (int k = 1; k < cols; ++k)  // Searching for same teachers
                {
                    if (tt2.arr[i][k] != "")
                    {
                        for (int l = 1; l < cols; ++l)
                        {

                            if (newtt.arr[j][l] == tt2.arr[i][k])  // Same teacher found
                            {
                                newtt.arr[j][l] = "";  // Removing that teacher

                            }
                        }
                    }
                }

                
                flag = false;
                for (int k = 1; k < cols; ++k)  // Checking if any teachers exist
                {

                    if (newtt.arr[j][k] != "")  // Atleast one exists
                    {
                        flag = true;

                        break;
                    }
                }

                if (!flag)  // All teachers subtracted
                {
                    newtt.arr[j][0] = newtt.arr[newtt.count_keys - 1][0];  // Move the last course to this position

                    for (int k = 1; k < cols; ++k)
                    {
                        newtt.arr[j][k] = newtt.arr[newtt.count_keys - 1][k];
                        newtt.arr[newtt.count_keys - 1][k] = "";  // Clearing all values of the last course

                    }
                    --newtt.count_keys; // Decrement the number of courses

                    --j; // To recheck the same position
                }

                break; // Move to the next course in tt2
            }
        }
    }

    return newtt;
}

ostream& operator<<(ostream& output, const CAList& tt)
{
    bool flag;
    for (int i = 0; i < tt.count_keys; ++i)
    {
        output << "[" << tt.arr[i][0] << ":{";
        flag = true; // Flag to track if it's the first teacher
        for (int j = 1; j < 7; ++j)
        {
            if (tt.arr[i][j] != "")
            {
                if (!flag)
                {
                    output << ",";
                }

                output << tt.arr[i][j];

                flag = false; // Set the flag to false after printing the first teacher
            }
        }
        output << "}" << "]";
        output << endl;
    }
    return output;
}

CAList::~CAList()
{
	for (int i = 0; i < rows; ++i)  // Deallocating the memory for arr virtual memory
	{
		delete[] arr[i];
	}
	delete[] arr;
}