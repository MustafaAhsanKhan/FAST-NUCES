#include "../Assignment2_project_final/i230549_B_Q1.h"
#include <iostream>
using namespace std;

/*

****Assignment 2****
Name: Mustafa Ahsan Khan
ID: i23-0549
Section: CS-B

*/

Shop::Shop()
{
    start = NULL;
}

//Copy Constructor
Shop::Shop(const Shop& other)
{
    start = NULL;
    int name_length = 0;
    int temp;

    if (other.start != NULL)
    {
        start = new Container;

        temp = 0;
        while (*(other.start->name + temp) != '\0')  // Finding length of the c-string
        {
            ++name_length;
            ++temp;
        }
        temp = 0;

        start->name = new char[name_length + 1]; // Memory allocation

        for (int i = 0; i <= name_length; ++i)
        {
            start->name[i] = other.start->name[i]; // copying name
        }

        start->containerno = other.start->containerno; // copying container no


        Container* current_cont = start;  // Start of linked list
        Container* old_cont = other.start;

        while (old_cont->link != NULL)
        {
            old_cont = old_cont->link;  // Next container

            current_cont->link = new Container;


            current_cont = current_cont->link;  // Next container
            name_length = 0;

            while (*(other.start->name + temp) != '\0')  // Finding length of the c-string
            {
                ++name_length;
                ++temp;
            }
            temp = 0;


            current_cont->name = new char[name_length + 2];  // Memory allocation


            for (int i = 0; i <= name_length; ++i)  // Copying name
            {
                current_cont->name[i] = old_cont->name[i];
            }
            current_cont->name[++name_length] = '\0';

            current_cont->containerno = old_cont->containerno;  // Copying container number

            current_cont->link = NULL;

        }

    }
}

void Shop::add_Container(char* name, int containerindex)
{
    Container* new_Cont = new Container;

    new_Cont->containerno = containerindex;
    new_Cont->name = name;
    new_Cont->link = NULL;

    if (start == NULL)
    {
        start = new_Cont;

    }
    else
    {
        Container* cont = start;

        while (cont->link != NULL)  // Looping till the end of the chain
        {
            cont = cont->link;  // Next link
        }

        cont->link = new_Cont;  // Adding the new container
    }
}

void Shop::print_Shop()
{
    Container* current_cont = start;
    while (current_cont != NULL)  // Looping till the end of the chain
    {
        cout << current_cont->name << "-" << current_cont->containerno << '\n';  // Printing the values
        current_cont = current_cont->link;  // Next link
    }
} //It prints all the articles with their container number in the chain.

void Shop::delete_Chain(int containerindex)
{
    Container* current_cont = start;

    Container* behind_c = NULL;


    while (current_cont != NULL && current_cont->containerno != containerindex)  // While Container index not found
    {
        behind_c = current_cont;
        current_cont = current_cont->link;

    }

    // If the container is found, remove it from the chain
    if (current_cont != NULL)
    {
        if (behind_c != NULL)
        {
            behind_c->link = current_cont->link;  // Joining the chain
        }
        else
        {
            start = current_cont->link;  // Changing the start pointer
        }

        delete current_cont;  // Deleting the chain segment
        current_cont = NULL;
    }
}

void Shop::Sort_Chain()
{
    bool swaps;
    Container* current_ptr;
    Container* prev_ptr = NULL;
    int tempNo;
    char* tempName;


    if (start == NULL || start->link == NULL)  // 0 or 1 elements in the list
    {
        return;
    }

    do
    {
        swaps = false;
        current_ptr = start;

        while (current_ptr->link != prev_ptr)  // Both pointers are apart
        {
            if (current_ptr->containerno > current_ptr->link->containerno)  // left is smaller than right
            {
                // Swapping
                tempNo = current_ptr->containerno;
                current_ptr->containerno = current_ptr->link->containerno;
                current_ptr->link->containerno = tempNo;

                tempName = current_ptr->name;
                current_ptr->name = current_ptr->link->name;
                current_ptr->link->name = tempName;

                swaps = true;
            }
            current_ptr = current_ptr->link;  // Next container
        }
        prev_ptr = current_ptr;  // Next container
    }
    while(swaps);

} //It sort all the elements in the chain based upon their containerindex.
void Shop::update_name_at_containerNumber(int containerindex, char* name)
{
    Container* temp = start;  // Copying start

    if (temp != NULL)
    {
        if (temp->containerno == containerindex)  // Container found at first index
        {
            temp->name = name;  // Updating name
            return;
        }

        while (temp->link != NULL)  // Finding the container
        {
            if (temp->link->containerno == containerindex)  // Container found
            {
                temp->link->name = name;  // Updating name
                return;
            }
            temp = temp->link;  // Next link
        }
    }
}

void Shop::remove_Duplicate()
{
    Container* current_cont = start;  // Copying start

    bool flag = true;  // Flag for name comparison

   
    while (current_cont != NULL)  // traversing the chain
    {
        Container* next_cont = current_cont->link;
        Container* behind_c = current_cont;


        while (next_cont != NULL)  // To compare the current container with all following containers
        {
            flag = true;

            for (int i = 0; (current_cont->name[i]) != '\0'; ++i)  // Comparing name
            {
                if (current_cont->name[i] != next_cont->name[i] || next_cont->name[i] == '\0')  // Name not equal
                {
                    flag = false;
                    break;
                }
            }

            if (flag == true && current_cont->containerno == next_cont->containerno)  // Duplicate found  // Name and container number are same
            {
                behind_c->link = next_cont->link;  // Joining the chain

                delete next_cont;

                next_cont = behind_c->link;  // Joining the chain
            }
            else
            {
   
                behind_c = next_cont;  // next link

                next_cont = next_cont->link;  // Next link
            }
        }

        current_cont = current_cont->link;  // Next container to compare
    }
}
//It removes all the containers with same article in the chain.
void Shop::findContainer(int containerindex)
{
    Container* current_cont = start;


    while (current_cont != NULL)  // Traversing the list
    {
        if (current_cont->containerno == containerindex)  // Container found
        {
            cout << current_cont->name << '\n';  // Outputting the name
            break;
        }
        current_cont = current_cont->link;  // Next link
    }
}
// It prints article name in the selected container.
void Shop::findContainer(int containerindex1, int containerindex2)
{
    Container* current_cont = start;

    
    while (current_cont != NULL)  // Traversing the list
    {
        if (current_cont->containerno >= containerindex1 && current_cont->containerno <= containerindex2)  // The container is in the range
        {
            cout << current_cont->name << '\n';  // Outputting the name
        }
        current_cont = current_cont->link;  // Next link
    }
}
// It prints article name in the container number range. The range is inclusive
Shop::~Shop()
{
    Container* current_cont = start;
    Container* next_cont;

    
    while (current_cont != NULL)  // Traversing the list
    {
        next_cont = current_cont->link;  // Next link
        
        delete current_cont; // Deallocate memory
        current_cont = next_cont;  // Next link
    }

    start = NULL; // Set start pointer to null to indicate empty chain
}