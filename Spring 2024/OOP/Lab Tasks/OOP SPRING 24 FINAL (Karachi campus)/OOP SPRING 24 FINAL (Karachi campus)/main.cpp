#include "Event.h"
#include "Concert.h"
#include "Conference.h"
#include "Exhibition.h"

#include "Flight.h"
#include "StandardFlight.h"

int main()
{

    // QUESTION 1
    cout << "----------------QUESTION 1----------------" << endl << endl;
    Event* events[3]; // Array of pointers to Event objects
    events[0] = new Concert('B', "John", "1st Jan", "FAST UNIVERSITY");
    events[1] = new Conference("Speaker", "Jack", "2st Jan", "Yo moms house");  // Change first param to "Attendee" to check ticket price  // It will be 30
    events[2] = new Exhibition('A', "Jamal", "3st Jan", "NUST UNIVERSITY");

    for (int i = 0; i < 3; ++i)
    {
        events[i]->calculateTicketPrice();
        events[i]->displayInfo();
        delete events[i]; // Clean up dynamically allocated memory
        cout << endl;
    }

    cout << "----------------QUESTION 2----------------" << endl << endl;

    cout << "----------------QUESTION 3----------------" << endl << endl;

    Flight* flight;

    int option = -1;

    while (option != 1 && option != 2 && option != 3)  // Selecting the meal
    {
        cout << "Select your class: \n1)Standard \n2)Premium \n3)Luxury \n";
        cin >> option;
    }

    switch (option)
    {
    case(1):
        flight = new StandardFlight;
        break;

    case(2): 
        break;

    case(3):
        break;
    }

    return 0;
}
