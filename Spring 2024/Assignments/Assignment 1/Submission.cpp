/*
        Name: Mustafa Ahsan Khan
        Roll#: 23i-0549
        Section: CS-B

*/

#include<iostream>
using namespace std;

// DON'T CHANGE THE PROTOTYPES OF FUNCTION 

//----------------------- Q1 -----------------------

char* resizeArray(char* array, int& capacity)
{
    int newCapacity = capacity * 2;
    char* newArray = new char[newCapacity];

    for (int i = 0; i < capacity; ++i)
    {
        newArray[i] = array[i];
    }

    delete[] array;
    capacity = newCapacity;
    return newArray;
}

char* BaseConverter(float number, int base)
{
    cout << int(number) << endl;
    int capacity = 2;
    int index = 0;
    int remainder = 0;
    float decimal_part = 0;
    float whole_part = 0;
    bool neg_flag = 0;
    bool whole_part_present = 0;
    char* converted_number = new char[capacity];
    converted_number[0] = '0';
    converted_number[1] = '\0';

    if (base < 2)
    {
        cout << "Invalid base to convert to";
        return converted_number;
    }

    if (number == 0)
    {
        return converted_number;
    }

    if (number < 0)  // Converting to positive using r's complement
    {
        neg_flag = 1;
        number = number * -1;
    }
    whole_part = (int)number;
    decimal_part = number - (int)number;

    while (whole_part > 0)  // Until the whole conversion is done
    {
        whole_part_present = 1;
        remainder = (int)whole_part % base;

        if (remainder < 10)
        {
            *(converted_number + index) = '0' + remainder;
        }
        else
        {
            *(converted_number + index) = 'A' + (remainder - 10);
        }

        index++;

        whole_part = int(whole_part / base);

        if (index == capacity)
        {
            converted_number = resizeArray(converted_number, capacity);  // Dynamically resizing the character array
        }
    }

    int i = 0, j = index - 1;
    while (i < j)  // Reversing the char array
    {
        char temp;
        temp = *(converted_number + i);
        *(converted_number + i) = *(converted_number + j);
        *(converted_number + j) = temp;
        i++;
        j--;
    }

    if (decimal_part < 1 && decimal_part > 0)  // Conversion for decimal part
    {
        if (whole_part_present == 0)
        {
            *(converted_number + index) = '0';
            ++index;
        }
        *(converted_number + index) = '.';
        ++index;

        if (index == capacity)
        {
            converted_number = resizeArray(converted_number, capacity);  // Dynamically resizing the character array
        }

        decimal_part = decimal_part * base;
        if (decimal_part < 10)
        {
            *(converted_number + index) = '0' + (int)decimal_part;
        }
        else
        {
            *(converted_number + index) = 'A' + ((int)decimal_part - 10);
        }

        if (index == capacity)
        {
            converted_number = resizeArray(converted_number, capacity);  // Dynamically resizing the character array
        }

        index++;
    }

    converted_number[index] = '\0';

    if (neg_flag == 1)
    {

        for (int i = 0; i < index; ++i)
        {
            if (*(converted_number + i) >= 65)
            {
                *(converted_number + i) = ((base - 10) + 64) - *(converted_number + i);  // R-1's complement
            }
            else
            {
                *(converted_number + i) = ((base - 1) + 48) - *(converted_number + i);  // R-1's complement
            }

            if (base > 10)
            {
                *(converted_number + i) += (*(converted_number + i) >= 10) ? 55 : 48;
            }
            else
            {
                *(converted_number + i) += '0';
            }
        }

        int carry = 1; // Initialize carry to 1
        for (int i = index - 1; i >= 0; --i)
        {
            if (base < 10)
            {
                if (*(converted_number + i) < ((base - 1) + '0') && carry == 1)
                {
                    *(converted_number + i) = *(converted_number + i) + 1;
                    carry = 0;
                }
                else if (*(converted_number + i) == ((base - 1) + '0') && carry == 1)
                {
                    *(converted_number + i) = '0';
                }
                else
                {
                    break;
                }
            }

            if (base > 10)
            {
                if (*(converted_number + i) < ((base - 1) + 'A') && carry == 1)
                {
                    *(converted_number + i) = *(converted_number + i) + 1;
                    carry = 0;
                }
                else if (*(converted_number + i) == ((base - 1) + 'A') && carry == 1)
                {
                    *(converted_number + i) = '0';
                }
                else
                {
                    break;
                }
            }
        }

    }

    return converted_number;
}

//----------------------- Q2 -----------------------

char*** AllocateBook(int& totalPages)
{
    int lines = 10;
    int characters = 40;

    char*** book = new char** [totalPages];
    for (int i = 0; i < totalPages; ++i)
    {
        book[i] = new char* [lines]; // Allocate memory for the second dimension
        for (int j = 0; j < lines; ++j)
        {
            book[i][j] = new char[characters]; // Allocate memory for the third dimension
        }
    }
    return book;
}

char*** IncreaseTotalPages(char*** oldBook, int& oldPages)
{
    int lines = 10;
    int characters = 40;
    int index = 0;
    oldPages = oldPages + 1;

    // Allocate memory for the new array
    char*** newBook = AllocateBook(oldPages);

    // Copy old contents to new array
    for (int i = 0; i < oldPages - 1; ++i) {
        for (int j = 0; j < lines; ++j)
        {
            for (int k = 0; k < characters; ++k)
            {
                newBook[i][j][k] = oldBook[i][j][k];
            }
        }
    }

    // Delete old array
    for (int i = 0; i < oldPages - 1; ++i)
    {
        for (int j = 0; j < lines; ++j)
        {
            delete[] oldBook[i][j];
        }
        delete[] oldBook[i];
    }
    delete[] oldBook;

    return newBook;
}

void makeBook(char* text, char***& book, int& totalPages)
{
    int lines = 10;
    int characters = 40;
    int index = 0;
    totalPages = 1;

    book = AllocateBook(totalPages);

    for (int i = 0; i < totalPages; ++i)
    {
        if (i == totalPages - 1 && text[index] != '\0')
        {
            book = IncreaseTotalPages(book, totalPages);
        }
        for (int j = 0; j < lines; ++j)
        {
            for (int k = 0; k < characters; ++k)
            {
                index = i * (lines * characters) + j * characters + k;
                book[i][j][k] = text[index];
            }
        }
    }

    //cout << totalPages;

    // book[0][10][40]
}
void cut(char***& book, int& totalPages, int FromPage, int ToPage, int FromLine, int ToLine, int FromWord, int ToWord, char*& clipboard)
{
    int lines = 10;
    int characters = 40;
    int Index = 0;

    int clipboardSize = (ToPage - FromPage + 1) * (ToLine - FromLine + 1) * (ToWord - FromWord + 1);

    clipboard = new char[clipboardSize];

    for (int i = FromPage; i <= ToPage; ++i)
    {
        for (int j = FromLine; j <= ToLine; ++j)
        {
            for (int k = FromWord; k <= ToWord; ++k)
            {
                clipboard[Index++] = book[i][j][k];
                book[i][j][k] = 0;
            }
        }
    }
}

void copy(char***& book, int& totalPages, int FromPage, int ToPage, int FromLine, int ToLine, int FromWord, int ToWord, char*& clipboard)
{
    int lines = 10;
    int characters = 40;
    int Index = 0;

    int clipboardSize = (ToPage - FromPage + 1) * (ToLine - FromLine + 1) * (ToWord - FromWord + 1);

    clipboard = new char[clipboardSize];

    for (int i = FromPage; i <= ToPage; ++i)
    {
        for (int j = FromLine; j <= ToLine; ++j)
        {
            for (int k = FromWord; k <= ToWord; ++k)
            {
                clipboard[Index++] = book[i][j][k];
            }
        }
    }
}

void paste(char***& book, int& totalPages, char* clipboard, int atPage, int atLine, int afterWord)
{

}

void Delete(char***& book, int& totalPages, int page) // For page deletion
{

}

void Delete(char***& book, int& totalPages, int page, int line) //For line deletion
{

}

void DeleteText(char***& book, int& totalPages, char* text) //For text deletion
{

}

void insert(char***& book, int& totalPages, int position) // insert empty page after position
{
    book = IncreaseTotalPages(book, totalPages);
}

void insert(char***& book, int& totalPages, int page, int position) // insert empty line on page
{

}

void insertText(char***& book, int& totalPages, int page, int line, int word, char* text)// Insert text after the word.
{
    int lines = 10;
    int characters = 40;
    int index = 0;
    int book_index = 5;

    for (int i = 0; i < totalPages; ++i)
    {
        if (book_index == totalPages - 1 && text[index] != '\0')
        {
            book = IncreaseTotalPages(book, totalPages);
            cout << "Page added";
            cout << totalPages;
        }
        for (int j = 0; j < lines; ++j)
        {
            for (int k = 0; k < characters; ++k)
            {
                if (book[i][j][k] == '\0' && text[index] != '\0')
                {
                    book[i][j][k] = '1';
                }
                index = i * (lines * characters) + j * characters + k;
                book[book_index][j][k] = text[index];
            }
        }
        ++book_index;
    }
}

void removeDoubleSpaces(char***& book, int& totalPages)
{

}

void concatenateBooks(char***& book1, int totalPages1, char***& book2, int totalPages2, char***& newBook, int& newPages)
{

}

char* toString(char***& book, int totalPages) //return book with format given below
{
    char* final_book = new char[totalPages * 10 * 40];  // Pages * Lines * characters

    int lines = 10;
    int characters = 40;
    for (int i = 0; i < totalPages; ++i)
    {
        for (int j = 0; j < lines; ++j)
        {
            for (int k = 0; k < characters; ++k)
            {
                int index = i * (lines * characters) + j * characters + k;
                final_book[index] = book[i][j][k];
            }
        }
    }

    return final_book;
}


//----------------------- Q3 -----------------------

bool royalHarmony(int**& board, int row, int column, int queens)
{
    return 1;
}

//----------------------- Q4 -----------------------

void pattern1_spaces(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << " ";
        pattern1_spaces(n - 1);
    }
}

void pattern1_lower_even(int start, int end)
{
    if (start == 0)
    {
        return;
    }
    else
    {
        pattern1_spaces(2 * start - 2);
        cout << "*" << endl;
        pattern1_lower_even(start - 1, end);
    }
}

void RecursivePattern1(int start, int end)
{
    if (start == (end / 2) + 1)
    {
        if (end % 2 == 0)
        {
            pattern1_lower_even(start - 2, end);
        }
        else
        {
            pattern1_lower_even(start - 1, end);
        }

        return;
    }
    else
    {
        pattern1_spaces(2 * (start - 1));
        cout << "*" << endl;
        RecursivePattern1(start + 1, end);
    }
}

void pattern2_stars_upper(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << "*";
        pattern2_stars_upper(n - 1);
    }
}

void pattern2_spaces_upper(int spaces)
{
    if (spaces == 0)
    {

        return;
    }
    else
    {
        cout << " ";
        pattern2_spaces_upper(spaces - 1);
    }
}

void pattern2_lower(int n, int spaces)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        pattern2_stars_upper(spaces - n + 1);
        pattern2_spaces_upper(2 * n - 2);
        pattern2_stars_upper(spaces - n + 1);

        cout << endl;
        pattern2_lower(n - 1, spaces);
    }
}

void RecursivePattern2(int n1, int n2)
{
    if (n1 == 0)
    {
        pattern2_lower(n2, n2);
        return;
    }
    else
    {
        pattern2_stars_upper(n1);
        pattern2_spaces_upper(2 * (n2 - n1));
        pattern2_stars_upper(n1);

        cout << endl;
        RecursivePattern2(n1 - 1, n2);
    }
}

void temp_spaces_upper(int spaces)
{
    if (spaces == 0)
    {
        return;
    }
    else
    {
        cout << " ";
        temp_spaces_upper(spaces - 1);
    }
}

void pattern3_stars_upper(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << "." << " ";
        pattern3_stars_upper(n - 1);
    }
}

void pattern3_spaces_upper(int spaces)
{
    if (spaces == 0)
    {
        return;
    }
    else
    {
        cout << "*" << " ";
        pattern3_spaces_upper(spaces - 1);
    }
}

void pattern3_lower(int n, int spaces)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        temp_spaces_upper(2 * (spaces - n));
        cout << "#";
        pattern3_stars_upper(spaces - n + 1);
        pattern3_spaces_upper(2 * n - 2);
        cout << "|" << " ";
        pattern3_spaces_upper(2 * n - 2);
        pattern3_stars_upper(spaces - n + 1);
        cout << "#";

        cout << endl;
        pattern3_lower(n - 1, spaces);
    }
}

void RecursivePattern3(int n1, int n2)
{
    if (n1 == 0)
    {
        pattern3_lower(n2 - 1, n2);
        return;
    }
    else
    {
        temp_spaces_upper(2 * n1 - 2);
        cout << "#";
        pattern3_stars_upper(n1);
        pattern3_spaces_upper(2 * (n2 - n1));
        cout << "|" << " ";
        pattern3_spaces_upper(2 * (n2 - n1));
        pattern3_stars_upper(n1);
        cout << "#";

        cout << endl;
        RecursivePattern3(n1 - 1, n2);
    }
}


//----------------------- Q5 -----------------------

struct SavingAccount
{
    char* name;
    float annualInterestRate;
    double savingBalance;
    char* accountNum;
};

void OpenCustomerAccount(SavingAccount* savers[], int& accountsOpen, char* name, float interestRate, double balance) // a function to create a new account and assign it an account number.
{
    if (accountsOpen >= 100)
    {
        return;
    }

    savers[accountsOpen] = new SavingAccount;

    savers[accountsOpen]->name = new char[100];
    savers[accountsOpen]->accountNum = new char[5];

    savers[accountsOpen]->name = name;
    savers[accountsOpen]->annualInterestRate = interestRate;
    savers[accountsOpen]->savingBalance = balance;
    savers[accountsOpen]->accountNum[0] = 'S';
    savers[accountsOpen]->accountNum[1] = 'A';
    savers[accountsOpen]->accountNum[2] = (char)((accountsOpen / 10) + '0');
    savers[accountsOpen]->accountNum[3] = (char)((accountsOpen % 10) + '0');
    savers[accountsOpen]->accountNum[4] = '\0';

    accountsOpen = accountsOpen + 1;
}

float calculateMonthlyInterest(SavingAccount* saver) // that calculates the monthly interest by multiplying the balance by annualInterestRate divided by 12
{
    float monthly_interest = 0;

    monthly_interest = saver->savingBalance * (saver->annualInterestRate / 12);

    return monthly_interest;
}

void modifyInterestRate(SavingAccount* saver, float newValue)
{
    saver->annualInterestRate = newValue;
}

int SearchCustomer(SavingAccount* savers[], int accountsOpen, char* accountNum) // a function that searches for an account using an account number. If the customer is found it returns the array index otherwise return -1
{
    if (accountNum[2] != '\0')
    {
        return -1;
    }
    for (int i = 0; i <= accountsOpen; ++i)
    {
        if (accountNum[0] == (char)((i / 10) + '0') && accountNum[1] == (char)((i % 10) + '0'))
        {
            return i;
        }
    }
    return -1;
}

bool UpdateAccountBalance(SavingAccount* savers[], int accountsOpen, char* accountNumVal, double balanceVal) // a function that updates a customer?s balance
{
    int index = SearchCustomer(savers, accountsOpen, accountNumVal);

    if (index != -1)
    {
        savers[index]->savingBalance = balanceVal;
        return 1;
    }
    else
    {
        return 0;
    }
}