#pragma once
#include "Flight.h"

class StandardFlight : public Flight
{
private:
	string meal;
	int seatNumber;

public:
	StandardFlight();
	virtual void handleBooking();  // This will be used to ensure encapsulation
	virtual void display();  // Used to display the information and the ticket
};