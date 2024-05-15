#include <iostream>
#include <ctime>

using namespace std;

int* sumArray(int** arr)
{
    int* sum = new int[5];

    for(int i = 0; i < 5; ++i)
    {
        sum[i] = 0;
        for(int j = 0; j < 6; ++j)
        {
            sum[i] = sum[i] + arr[i][j];
        }
    }
    return sum;
}

int main()
{
    srand(time(0));
    int array1[6], array2[6], array3[6], array4[6], array5[6];
    int* p[5];

    p[0] = array1;
    p[1] = array2;
    p[2] = array3;
    p[3] = array4;
    p[4] = array5;

    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            p[i][j] = rand() % 15;
        }
    }

    int* sum = sumArray(p);

    for(int i = 0; i < 5; ++i)
    {
        cout << "Sum of array " << i + 1 << " = " << sum[i] << endl;
    }

    return 0;
}