#include "ComputerAssembly.h"

// Constructors
ComputerAssembly::ComputerAssembly()
{
	totalPrice = 0;
	myPC = NULL;
	computerCase = NULL;
	GPU = NULL;
	PSU = NULL;
	internalBattery = NULL;
	NIC = NULL;
	storage = NULL;
	option = 0;
}

ComputerAssembly::ComputerAssembly(double p_totalPrice, Computer* p_myPC, Case* p_computerCase, GraphicsCard* p_GPU, PowerSupply* p_PSU, Battery* p_internal_battery, NetworkCard* p_NIC, StorageDevice* p_storage, int p_option)
{
	totalPrice = p_totalPrice;
	myPC = p_myPC;
	computerCase = p_computerCase;
	GPU = p_GPU;
	PSU = p_PSU;
	internalBattery = p_internal_battery;
	NIC = p_NIC;
	storage = p_storage;
	option = p_option;
}

// Getters
double ComputerAssembly::gettotalPrice()
{
	return totalPrice;
}

int ComputerAssembly::getoption()
{
	return option;
}

// Setters
void ComputerAssembly::settotalPrice(double p_totalPrice)
{
	totalPrice = p_totalPrice;
}

void ComputerAssembly::setoption(int p_option)
{
	option = p_option;
}

// Functions to create the PC part by part
void ComputerAssembly::createPC()
{
	myPC = new Computer;
	MotherBoard* motherboard = new MotherBoard();
	myPC->setMB(motherboard);
	computerCase = new Case;
	GPU = new GraphicsCard;
	PSU = new PowerSupply;
	NIC = new NetworkCard;
	storage = new StorageDevice;

	ALU* alu = new ALU(1, 1, 5, 32);
	ControlUnit* cu = new ControlUnit(2);
	IntelCPU* processor = new IntelCPU(alu, cu);
	MainMemory* mm = new MainMemory;

	myPC->setCPU(processor);
	myPC->getMotherboard()->setMainMemory(mm);

	Port* p = new Port[5];  // Array of ports
	p[1].setType("USB-A");
	p[2].setType("USB-A");
	p[3].setType("USB-C");
	p[4].setType("Headphone jack");

	option = 0;
	cout << "The price for your case is included in the base price \n";
	while (option != 1 && option != 2 && option != 3)  // Selecting the color of the case
	{
		cout << "Select your case color: \n 1)Black \n 2)White \n 3)Silver \n ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		computerCase->setColor("Black");
		break;
	case 2:
		computerCase->setColor("White");
		break;
	case 3:
		computerCase->setColor("Silver");
		break;
	}

	option = 0;

	while (option != 1 && option != 2 && option != 3 && option != 4)  // Selecting the memory capacity
	{
		cout << "Select your memory capacity: \n 1)8 GB $10 \n 2)16 GB $20 \n 3)32 Gb $40 \n 4)64 GB $80 \n ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		myPC->getMotherboard()->getMainMemory()->setCapacity(8);
		totalPrice += 10;
		settotalPrice(totalPrice);  // Updating the total price
		break;
	case 2:
		myPC->getMotherboard()->getMainMemory()->setCapacity(16);
		totalPrice += 20;
		settotalPrice(totalPrice);
		break;
	case 3:
		myPC->getMotherboard()->getMainMemory()->setCapacity(32);
		totalPrice += 40;
		settotalPrice(totalPrice);
		break;
	case 4:
		myPC->getMotherboard()->getMainMemory()->setCapacity(64);
		totalPrice += 80;
		settotalPrice(totalPrice);
		break;
	}
	myPC->getMotherboard()->getMainMemory()->setTechnologyType("Silicon");

	option = 0;

	while (option != 1 && option != 2)  // Selecting the display type
	{
		cout << "Select your display type: \n 1)Display Port \n 2)HDMI \n ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		p[0].setType("Display Port");
		break;
	case 2:
		p[0].setType("HDMI");
		break;
	}

	option = 0;

	while (option != 1 && option != 2)  // Selecting the network interface type
	{
		cout << "Select your network interface type: \n 1)Wi-Fi \n 2)Ethernet note: This will take the place of 1 USB-A port \n ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		NIC->setPrice(50);  // Included in Base Price
		NIC->setSpeed(1000);
		NIC->setType("Wi-Fi");
		break;
	case 2:
		p[1].setType("Ethernet");
		NIC->setPrice(50);  // Included in Base Price
		NIC->setSpeed(1000);
		NIC->setType("Ethernet");
		break;
	}

	myPC->getMotherboard()->setPorts(p, 5);  // Ports Array // Number of ports
	

	option = 0;

	while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)  // Selecting the GPU
	{
		cout << "Select your Graphics Card: \n 1)NVIDIA RTX 4090 24GB $1400 \n 2)NVIDIA RTX 4060ti 8GB $600 \n 3)AMD RX 7900XTX 16GB $1200 \n 4)AMD RX 7600XT 8GB $700 \n 5)Integrated GPU 2GB \n";
		cin >> option;
	}

	switch (option)
	{
	case 1:
		GPU->setBrand("NVIDIA RTX 4090 24GB");
		GPU->setmemorySize(24);
		GPU->setPrice(1400);
		totalPrice += 1400;
		settotalPrice(totalPrice);  // Updating the total price
		break;
	case 2:
		GPU->setBrand("NVIDIA RTX 4060ti 8GB");
		GPU->setmemorySize(8);
		GPU->setPrice(600);
		totalPrice += 600;
		settotalPrice(totalPrice);
		break;
	case 3:
		GPU->setBrand("AMD RX 7900XTX 16GB");
		GPU->setmemorySize(16);
		GPU->setPrice(1200);
		totalPrice += 1200;
		settotalPrice(totalPrice);
		break;
	case 4:
		GPU->setBrand("AMD RX 7600XT 8GB");
		GPU->setmemorySize(8);
		GPU->setPrice(700);
		totalPrice += 700;
		settotalPrice(totalPrice);
		break;
	case 5:
		GPU->setBrand("Intel iRIS Xe 2GB");
		GPU->setmemorySize(2);
		GPU->setPrice(0);  // Integrated
		break;
	}

	option = 0;

	while (option != 1 && option != 2 && option != 3 && option != 4)  // Selecting the storage
	{
		cout << "Select your storage: \n 1)500 GB HDD $30 \n 2)1000GB HDD $60 \n 3)500 GB SSD $50 \n 4)1000GB SSD $100 \n";
		cin >> option;
	}

	switch (option)
	{
	case 1:
		storage->setType("HDD");
		storage->setCapacity(500);
		storage->setPrice(30);
		totalPrice += 30;
		settotalPrice(totalPrice);
		break;
	case 2:
		storage->setType("HDD");
		storage->setCapacity(1000);
		storage->setPrice(60);
		totalPrice += 60;
		settotalPrice(totalPrice);
		break;
	case 3:
		storage->setType("SSD");
		storage->setCapacity(500);
		storage->setPrice(50);
		totalPrice += 50;
		settotalPrice(totalPrice);
		break;
	case 4:
		storage->setType("SSD");
		storage->setCapacity(1000);
		storage->setPrice(100);
		totalPrice += 100;
		settotalPrice(totalPrice);
		break;
	}

	option = 0;

	while (option != 1 && option != 2)  // Selecting the PSU
	{
		cout << "Select your Power Supply: \n 1)800W 80+ GOLD \n 2)1000W 80+ TITANIUM \n ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		PSU->setER("80+ GOLD");
		PSU->setPrice(80);
		PSU->setWattage(800);  // 800W
		totalPrice += 80;
		settotalPrice(totalPrice);
		break;
	case 2:
		PSU->setER("80+ TITANIUM");
		PSU->setPrice(160);
		PSU->setWattage(1000);  // 1000W
		totalPrice += 160;
		settotalPrice(totalPrice);
		break;
	}

	option = 1;  // Setting it back to PC

}

void ComputerAssembly::createMAC()
{
	myPC = new Computer;
	MotherBoard *motherboard = new MotherBoard();
	myPC->setMB(motherboard);
	computerCase = new Case;
	GPU = new GraphicsCard;
	PSU = new PowerSupply;
	internalBattery = new Battery;
	NIC = new NetworkCard;
	storage = new StorageDevice;

	ALU* alu = new ALU(1, 1, 5, 32);
	ControlUnit* cu = new ControlUnit(2);
	AppleCPU* processor = new AppleCPU(alu, cu);
	MainMemory* mm = new MainMemory;  // How much memory  // What kind

	myPC->setCPU(processor);
	myPC->getMotherboard()->setMainMemory(mm);

	Port* p = new Port[5];  // Array of ports
	p[1].setType("USB-A");
	p[2].setType("USB-A");
	p[3].setType("USB-C");
	p[4].setType("Headphone jack");

	option = 0;
	

	while (option != 1 && option != 2 && option != 3 && option != 4)
	{
		cout << "Select your laptop color: \n 1)Midnight \n 2)Starlight \n 3)Gold \n 4)Silver \n ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		computerCase->setColor("Midnight");
		break;
	case 2:
		computerCase->setColor("Starlight");
		break;
	case 3:
		computerCase->setColor("Gold");
		break;
	case 4:
		computerCase->setColor("Silver");
		break;
	}

	option = 0;

	while (option != 1 && option != 2 && option != 3 && option != 4)
	{
		cout << "Select your memory capacity: \n 1)8 GB Base Option \n 2)16 GB $20 \n 3)32 Gb $40 \n 4)64 GB $80 \n ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		myPC->getMotherboard()->getMainMemory()->setCapacity(8);
		break;
	case 2:
		myPC->getMotherboard()->getMainMemory()->setCapacity(16);
		totalPrice += 20;
		settotalPrice(totalPrice);
		break;
	case 3:
		myPC->getMotherboard()->getMainMemory()->setCapacity(32);
		totalPrice += 40;
		settotalPrice(totalPrice);
		break;
	case 4:
		myPC->getMotherboard()->getMainMemory()->setCapacity(64);
		totalPrice += 80;
		settotalPrice(totalPrice);
		break;
	}
	myPC->getMotherboard()->getMainMemory()->setTechnologyType("Silicon");

	option = 0;

	while (option != 1 && option != 2)
	{
		cout << "Select your display type: \n 1)Display Port \n 2)HDMI \n ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		p[0].setType("Display Port");
		break;
	case 2:
		p[0].setType("HDMI");
		break;
	}


	myPC->getMotherboard()->setPorts(p, 5);  // Ports Array // Number of ports

	option = 0;

	while (option != 1 && option != 2 && option != 3 && option != 4)
	{
		cout << "Select your Graphics memory: \n 1)8 GB Base Option \n 2)16 GB $80 \n 3)32 GB $200 \n 4)64 GB $500 \n";
		cin >> option;
	}

	switch (option)
	{
	case 1:
		myPC->getAppleCPU()->getiGPU().setmemorySize(8);
		myPC->getAppleCPU()->getiGPU().setPrice(40);  // Included in Base price
		break;
	case 2:
		myPC->getAppleCPU()->getiGPU().setmemorySize(16);
		myPC->getAppleCPU()->getiGPU().setPrice(80);
		totalPrice += 80;
		settotalPrice(totalPrice);
		break;
	case 3:
		myPC->getAppleCPU()->getiGPU().setmemorySize(32);
		myPC->getAppleCPU()->getiGPU().setPrice(200);
		totalPrice += 200;
		settotalPrice(totalPrice);
		break;
	case 4:
		myPC->getAppleCPU()->getiGPU().setmemorySize(64);
		myPC->getAppleCPU()->getiGPU().setPrice(500);
		totalPrice += 500;
		settotalPrice(totalPrice);
		break;
	}
	cout << myPC->getAppleCPU()->getiGPU().getmemorySize() << endl;
	option = 0;

	while (option != 1 && option != 2 && option != 3 && option != 4)
	{
		cout << "Select your storage: \n 1)500 GB HDD Base Option \n 2)1000GB HDD $60 \n 3)500 GB SSD $50 \n 4)1000GB SSD $100 \n";
		cin >> option;
	}

	switch (option)
	{
	case 1:
		storage->setType("HDD");
		storage->setCapacity(500);
		storage->setPrice(30);  // Included in Base price
		break;
	case 2:
		storage->setType("HDD");
		storage->setCapacity(1000);
		storage->setPrice(60);
		totalPrice += 60;
		settotalPrice(totalPrice);
		break;
	case 3:
		storage->setType("SSD");
		storage->setCapacity(500);
		storage->setPrice(50);
		totalPrice += 50;
		settotalPrice(totalPrice);
		break;
	case 4:
		storage->setType("SSD");
		storage->setCapacity(1000);
		storage->setPrice(100);
		totalPrice += 100;
		settotalPrice(totalPrice);
		break;
	}

	NIC->setPrice(50);  // Included in Base Price
	NIC->setSpeed(1000);
	NIC->setType("Wi-Fi");  // As its a laptop

	internalBattery->setCapacity(5000);  // 5000 mAh

	option = 2;  // Setting it back to MAC
}

// Function that will take the initial input from the user
void ComputerAssembly::selectOption()
{
	option = 0;
	while (option != 1 && option != 2)
	{
		cout << "Select a platform: \n 1)PC \n 2)MAC \n";
		cin >> option;
	}
	if (option == 1)
	{
		totalPrice += 300;  // Base price for a PC
		settotalPrice(totalPrice);
		cout << "Welcome to the PC master-race \n";
		createPC();
	}
	else if (option == 2)
	{
		totalPrice += 500;  // Base price for an apple laptop
		settotalPrice(totalPrice);
		cout << "Welcome to the Apple ecosystem \n";
		createMAC();
	}
}

// Function to display all the specifications
void ComputerAssembly::Display()
{
	if (option == 1)
	{
		cout << "SPECIFICATIONS:" << endl;
		cout << "Base Price: $300" << endl;
		cout << "Case color: " << computerCase->getColor() << endl;
		cout << "CPU: Intel i9-14900k" << endl;
		cout << "Graphics card: " << GPU->getBrand() << endl;
		cout << "Graphics memory: " << GPU->getmemorySize() << "GB" << endl;
		cout << "Main Memory type: DDR5" << endl;
		cout << "Main Memory Technology: " << myPC->getMotherboard()->getMainMemory()->getTechnologyType() << endl;
		cout << "Main Memory capacity: " << myPC->getMotherboard()->getMainMemory()->getCapacity() << "GB" << endl;
		for (int i = 0; i < 5; ++i)
		{
			cout << "Port " << (i + 1) << ": " << myPC->getMotherboard()->getPorts()[i].getType() << endl;
		}
		cout << "Storage type: " << storage->getType() << endl;
		cout << "Storage capacity: " << storage->getCapacity() << "GB" << endl;
		cout << "Network interface card type: " << NIC->getType() << endl;
		cout << "Network interface card speed: " << NIC->getSpeed() << "mB/s" << endl;
		cout << "PSU Efficiency rating: " << PSU->getER() << endl;
		cout << "PSU Wattage: " << PSU->getWattage() << "W" << endl;
		cout << endl << "Total Price: $" << gettotalPrice();
	}
	else if (option == 2)
	{
		cout << "SPECIFICATIONS:" << endl;
		cout << "Base Price: $500" << endl;
		cout << "Case color: " << computerCase->getColor() << endl;
		cout << "CPU: Apple M3 (ARM 64)" << endl;
		cout << "Graphics card: " << myPC->getAppleCPU()->getiGPU().getBrand() << endl;
		cout << "Graphics memory: " << myPC->getAppleCPU()->getiGPU().getmemorySize() << "GB" << endl;
		cout << "Main Memory type: LP-DDR5" << endl;
		cout << "Main Memory Technology: " << myPC->getMotherboard()->getMainMemory()->getTechnologyType() << endl;
		cout << "Main Memory capacity: " << myPC->getMotherboard()->getMainMemory()->getCapacity() << "GB" << endl;
		for (int i = 0; i < 5; ++i)
		{
			cout << "Port " << (i + 1) << ": " << myPC->getMotherboard()->getPorts()[i].getType() << endl;
		}
		cout << "Storage type: " << storage->getType() << endl;
		cout << "Storage capacity: " << storage->getCapacity() << "GB" << endl;
		cout << "Network interface card type: " << NIC->getType() << endl;
		cout << "Network interface card speed: " << NIC->getSpeed() << "mB/s" << endl;
		cout << "Battery capacity: " << internalBattery->getCapacity() << "mAh" << endl;
		cout << endl << "Total Price: $" << gettotalPrice();
	}
}