#include "Exhibition.h"

Exhibition::Exhibition(char Tier_p, string name_p, string date_p, string venue_p)
{
	Tier = Tier_p;
	name = name_p;
	date = date_p;
	venue = venue_p;
}
void Exhibition::calculateTicketPrice()
{
	switch (Tier)
	{
	case('A'):
	case('a'):
		ticketPrice = 100;
		break;

	case('B'):
	case('b'):
		ticketPrice = 80;
		break;

	case('C'):
	case('c'):
		ticketPrice = 50;
		break;
	}
}
void Exhibition::displayInfo()
{
	cout << name << " ";
	cout << "your tier is: " << Tier << endl;
	cout << "The date of the Exhibition is: " << date << endl;
	cout << "The venue of the Exhibition is: " << venue << endl;
	cout << "Your ticket price is <$" << ticketPrice << ">" << endl;
}