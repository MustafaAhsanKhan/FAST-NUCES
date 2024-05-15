#include <iostream>
using namespace std;

int main()
{
    int n_terms, n1, n2, temp;
    temp = 0;
    n1 = 0;
    n2 = 1;
    
    cout << "Enter the number of terms: ";
    cin >> n_terms;

    for(int i = 1; i <= n_terms; ++i)
    {
        if(i == 1)
        {
            cout << n1 << " ";
            continue;
        }
        if(i == 2)
        {
            cout << n2 << " ";
            continue;
        }
        temp = n1 + n2;
        n1 = n2;
        n2 = temp;

        cout << temp << " ";
    }

    return 0;
}