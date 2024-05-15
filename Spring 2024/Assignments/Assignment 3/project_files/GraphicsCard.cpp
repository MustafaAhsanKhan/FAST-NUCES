#include "GraphicsCard.h"

// Constructors
GraphicsCard::GraphicsCard()
{
	Brand = "N/A";
	memorySize = 0;
	Price = 0;
}

GraphicsCard::GraphicsCard(string p_Brand = "N/A", int p_memorySize = 0, double p_Price = 0)
{
	Brand = p_Brand;
	memorySize = p_memorySize;
	Price = p_Price;
}

// Getters
string GraphicsCard::getBrand() const
{
	return Brand;
}

int GraphicsCard::getmemorySize() const
{
	return memorySize;
}

double GraphicsCard::getPrice() const
{
	return Price;
}

// Setters
void GraphicsCard::setBrand(string p_Brand)
{
	Brand = p_Brand;
}

void GraphicsCard::setmemorySize(int p_memorySize)
{
	memorySize = p_memorySize;
}

void GraphicsCard::setPrice(double p_Price)
{
	Price = p_Price;
}