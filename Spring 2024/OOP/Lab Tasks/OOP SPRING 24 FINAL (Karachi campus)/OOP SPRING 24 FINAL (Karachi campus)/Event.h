#pragma once
#include <iostream>
using namespace std;
class Event
{
protected:
	string name;
	string date;
	string venue;
	int ticketPrice;

public:
	virtual void calculateTicketPrice() = 0;
	virtual void displayInfo() = 0;
};