#pragma once
#include <iostream>
using namespace std;

class Flight
{
protected:
	string airlineInfo;
	int flightNumber;
	string departureAiport;
	string arrivalAirport;
	int departureTime;
	int arrivalTime;

	int fare;
	
public:
	virtual void handleBooking() = 0;  // This will be used to ensure encapsulation
	virtual void display() = 0;  // Used to display the information and the ticket
};