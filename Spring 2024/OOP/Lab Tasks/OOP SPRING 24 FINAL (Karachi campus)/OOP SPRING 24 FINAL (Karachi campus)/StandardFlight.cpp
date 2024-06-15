#include "StandardFlight.h"

StandardFlight::StandardFlight()
{
	handleBooking();
}
void StandardFlight::handleBooking()  // This will be used to ensure encapsulation
{
	int option = -1;
	airlineInfo = "PIA";
	flightNumber = 1691;
	fare = 100;
	option = 0;

	cout << "You have chosen the STANDARD class" << endl;

	cout << "Enter your departure city: ";
	cin >> departureAiport;

	cout << "Enter your arrival city: ";
	cin >> arrivalAirport;

	cout << "Enter your departure time(HOURS): ";
	cin >> departureTime;

	arrivalTime = departureTime + 600;

	while (option < 1 || option > 50)  // Selecting the seat
	{
		cout << "Select your seat \n";
		cin >> option;
	}

	seatNumber = option;
	
	option = 0;

	while (option != 1 && option != 2)  // Selecting the meal
	{
		cout << "Select your meal: \n1)Biryani \n2)Lentil with white rice\n";
		cin >> option;
	}

	switch (option)
	{
	case(1): meal = "Biryani";
		break;

	case(2): meal = "Lentil with white rice";
		break;
	}

	display();

}
void StandardFlight::display()  // Used to display the information and the ticket
{
	cout << "STANDARD CLASS" << endl;
	cout << "~~~~~~~~~~~~~~~~" << endl;
	cout << "Airline: " << airlineInfo << endl;
	cout << "Flight number: " << flightNumber << endl;
	cout << "Seat number: " << seatNumber << endl;
	cout << "Choice of meal: " << meal << endl;
	cout << "Departure city: " << departureAiport << endl;
	cout << "Arrival city: " << arrivalAirport << endl;
	cout << "Departure time: " << departureTime << "Hours" << endl;
	cout << "Arrival time: " << arrivalTime << "Hours" << endl;
}