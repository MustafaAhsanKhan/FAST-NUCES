#pragma once
#include "Event.h"

class Concert : public Event
{
private:
	char Tier;

public:
	Concert(char Tier_p, string name_p, string date_p, string venue_p);
	virtual void calculateTicketPrice();
	virtual void displayInfo();
};

