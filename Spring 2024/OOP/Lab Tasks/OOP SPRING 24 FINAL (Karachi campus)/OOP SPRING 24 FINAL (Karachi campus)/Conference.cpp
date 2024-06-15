#include "Conference.h"

Conference::Conference(string personType_p, string name_p, string date_p, string venue_p)
{
	personType = personType_p;
	name = name_p;
	date = date_p;
	venue = venue_p;
}

void Conference::calculateTicketPrice()
{
	if (personType == "Attendee")
	{
		ticketPrice = 30;
	}
	else if(personType == "Speaker")
	{
		ticketPrice = 0;
	}
}

void Conference::displayInfo()
{
	cout << name << " ";
	cout << "you are a " << personType << endl;
	cout << "The date of the conference is: " << date << endl;
	cout << "The venue of the conference is: " << venue << endl;
	cout << "Your ticket price is <$" << ticketPrice << ">" << endl;
}