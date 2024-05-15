#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"Enter Age: ";
    cin>>age;
    if(age >= 0 && age <= 12)
        cout<<"Ticket Price: $10"<<endl;

    else if (age >= 13 && age <= 64)
        cout<<"Ticket Price: $20"<<endl;

    else if (age >= 65)
        cout<<"Ticket Price: $15"<<endl;

    else
        cout<<"Age is Invalid"<<endl;

return 0;
}