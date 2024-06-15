#pragma once
#include "Event.h"

class Conference : public Event
{
private:
	string personType;

public:
	Conference(string personType_p, string name_p, string date_p, string venue_p);
	virtual void calculateTicketPrice();
	virtual void displayInfo();
};

