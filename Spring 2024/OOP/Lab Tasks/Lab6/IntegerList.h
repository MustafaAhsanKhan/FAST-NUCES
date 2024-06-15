#pragma once

class IntegerList
{
    int* list;
    int numElements;
    int index;

public:

    IntegerList();

    IntegerList(int numElements);

    ~IntegerList();

    bool isValid(int index);

    bool addElement(int v);

    void removeElement();

    int getElement(int index);

    void displayElements();
};

