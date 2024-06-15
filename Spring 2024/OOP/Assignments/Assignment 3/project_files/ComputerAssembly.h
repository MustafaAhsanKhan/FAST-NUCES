#pragma once
#include "../assignment3_project/Computer.h"
#include "../assignment3_project/GraphicsCard.h"
#include "../assignment3_project/StorageDevice.h"
#include "../assignment3_project/NetworkCard.h"
#include "../assignment3_project/PowerSupply.h"
#include "../assignment3_project/Battery.h"
#include "../assignment3_project/Case.h"

class ComputerAssembly
{
private:
	double totalPrice;
	Computer* myPC;
	Case* computerCase;
	GraphicsCard* GPU;
	PowerSupply* PSU;
	Battery* internalBattery;
	NetworkCard* NIC;
	StorageDevice* storage;
	int option;

public:
	// Constructors
	ComputerAssembly();

	ComputerAssembly(double p_totalPrice, Computer* p_myPC, Case* p_computerCase, GraphicsCard* p_GPU, PowerSupply* p_PSU, Battery* p_internal_battery, NetworkCard* p_NIC, StorageDevice* p_storage, int p_option);

	// Getters
	double gettotalPrice();

	int getoption();

	// Setters
	void settotalPrice(double p_totalPrice);

	void setoption(int);

	// Function to create the PC part by part
	void createPC();

	// Function to create the MAC part by part
	void createMAC();

	// Function that will take the initial input from the user
	void selectOption();

	// Function to display all the specifications
	void Display();

};