#pragma once
#include "Event.h"

class Exhibition : public Event
{
private:
	char Tier;

public:
	Exhibition(char Tier_p, string name_p, string date_p, string venue_p);
	virtual void calculateTicketPrice();
	virtual void displayInfo();
};

