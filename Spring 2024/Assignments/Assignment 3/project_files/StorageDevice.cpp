#include "StorageDevice.h"

// Constructors
StorageDevice::StorageDevice()
{
	Type = "N/A";
	Capacity = 0;
	Price = 0;
}

StorageDevice::StorageDevice(string p_Type = "N/A", int p_Capacity = 0, double p_Price = 0)
{
	Type = p_Type;
	Capacity = p_Capacity;
	Price = p_Price;
}

// Getters
string StorageDevice::getType() const
{
	return Type;
}

int StorageDevice::getCapacity() const
{
	return Capacity;
}

double StorageDevice::getPrice() const
{
	return Price;
}

// Setters
void StorageDevice::setType(string p_Type)
{
	Type = p_Type;
}

void StorageDevice::setCapacity(int p_Capacity)
{
	Capacity = p_Capacity;
}

void StorageDevice::setPrice(double p_Price)
{
	Price = p_Price;
}