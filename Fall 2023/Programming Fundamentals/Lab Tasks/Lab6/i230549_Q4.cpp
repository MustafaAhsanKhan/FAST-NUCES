#include <iostream>
using namespace std;

int main()
{
    int age, marks; 
    char consent;
    bool eligible = 0;

    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your marks: ";
    cin >> marks;

    if (age >= 18 && age <= 30)
        {
            if (marks >= 60 && marks <= 100)
            {
                if (age < 21)
                    {
                        cout << "Enter parental consent Y or N: ";
                        cin >> consent;
                        if (consent == 'Y' || consent == 'y')
                        {
                            eligible = 1;
                        }
                    }
                else
                    {
                        eligible = 1;
                    }
            }
        }
    if (eligible)
        {
            cout << "Eligible to enroll in the course";
        }
    else
        {   
            cout << "Not eligible to enroll in the course";
        }
    
    return 0;

}