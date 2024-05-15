#include "IntegerList.h"
#include <iostream>
using namespace std;

IntegerList::IntegerList()
{
    numElements = 0;
    list = NULL;
    index = 0;
}

IntegerList::IntegerList(int numElements)
{
    this->numElements = numElements;
    list = new int[numElements];
    index = 0;
}

IntegerList::~IntegerList()
{
    delete [] list;
}

bool IntegerList::isValid(int index)
{
    if ((index >= 0) && (index < (numElements)))
    {
        return true;
    }
    else
        return false;
}

bool IntegerList::addElement(int v)
{
    if (isValid(index))
    {
        list[index] = v;
        if (index == numElements - 1)
        {
            return true;
        }
        ++index;
        return true;
    }
    return false;
}

void IntegerList::removeElement()
{
    if (isValid(index)) {

        list[index] = 0;
        --index;
    }
    //return index - 1;
}

int IntegerList::getElement(int index)
{
    if (isValid(index))
    {
        return list[index];
    }
    return -1;
}

void IntegerList::displayElements()
{
    for (int i = 0; i < index; ++i)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}