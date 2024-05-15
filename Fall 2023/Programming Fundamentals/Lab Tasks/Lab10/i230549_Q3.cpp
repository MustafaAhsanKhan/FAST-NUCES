#include <iostream>

using namespace std;

void element_frequency(int array[])
{
    int temp, count;
    

    for(int i = 0; i < 10; ++i)
    {
        temp = array[i];
        count = 0;
        if(array[i] == INT32_MAX)
        {
            continue;
        }
        for(int j = i + 1; j < 10; ++j)
        {
            if(array[j] == temp)
            {
                count = count + 1;
                array[j] = INT32_MAX;
            }
        }
        cout << array[i] << " repeated " << count + 1 << " times" << endl;
    }
}

int main()
{
    int array[10];
    int temp;

    for(int i = 0; i < 10; ++i)
    {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> temp;
        array[i] = temp;
    }

    element_frequency(array);
    return 0;
} 