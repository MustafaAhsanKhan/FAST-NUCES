#include <iostream>
using namespace std;

int main()
{
    float floors, rooms, occupied, total_rooms, total_occupied;
    rooms = 0;
    occupied = 0;
    total_rooms = 0;
    total_occupied = 0;
    bool flag = 0;

    cout << "Enter the number of floors: ";
    cin >> floors;

    for(int i = 1; i <= floors; i++)
    {   
        while(!flag)
        {
            cout << "Enter number of rooms in floor " << i << " : ";
            cin >> rooms;

            cout << "Enter number of rooms occupied in floor " << i << " : ";
            cin >> occupied;
            if(occupied > rooms)
            {
                cout << "The number of occupied rooms cant be more than the number of rooms" << endl;
            }
            else
            {
                total_occupied = total_occupied + occupied;
                total_rooms = total_rooms + rooms;
                flag = 1;
            }
        }
        flag = 0;
    }

    cout << "Total rooms in the hotel are: " << total_rooms << endl;
    cout << "The number of occupied rooms are: " << total_occupied << endl;
    cout << "The number of un-occupied rooms are: " << (total_rooms - total_occupied) << endl;
    cout << "The percentage of occupied rooms is: " << (total_occupied / total_rooms) * 100 << endl;

    return 0;
}