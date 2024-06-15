#include "NetworkCard.h"

// Constructors
NetworkCard::NetworkCard()
{
	Type = "N/A";
	Speed = 0;
	Price = 0;
}

NetworkCard::NetworkCard(string p_Type = "N/A", int p_Speed = 0, double p_Price = 0)
{
	Type = p_Type;
	Speed = p_Speed;
	Price = p_Price;
}

// Getters
string NetworkCard::getType() const
{
	return Type;
}

int NetworkCard::getSpeed() const
{
	return Speed;
}

double NetworkCard::getPrice() const
{
	return Price;
}

// Setters
void NetworkCard::setType(string p_Type)
{
	Type = p_Type;
}

void NetworkCard::setSpeed(int p_Speed)
{
	Speed = p_Speed;
}

void NetworkCard::setPrice(double p_Price)
{
	Price = p_Price;
}