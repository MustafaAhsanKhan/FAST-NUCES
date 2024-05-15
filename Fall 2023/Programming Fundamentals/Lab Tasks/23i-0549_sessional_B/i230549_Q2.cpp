#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int option, payment_choice;
    float price1, price2, price3, price4;
    float total, amount;
    price1 = 0.50;
    price2 = 0.20;
    price3 = 1.00;
    price4 = 0.80;
    total = 0;
    
    cout << "Vending machine menu" << endl;
    cout << "1. Lays        -  " << price1 << endl;
    cout << "2. Cookies     -  " << price2 << endl;
    cout << "3. Chocolate   -  " << price3 << endl;
    cout << "4. Soft Drink  -  " << price4 << endl;
    
    cout << "Enter -1 to procede to checkout" << endl;
    do
    {
        cout << "Select a product (1,2,3,4): ";
        cin >> option;
    	while(option != 1 && option != 2 && option != 3 && option != 4)
    	{
    	    if(option == -1)
    	    {
    	        break;
    	    }
            cout << "Select a product (1,2,3,4): ";
            cin >> option;
        }
        if(option == -1)
        {
            break;
        }
        
        switch(option)
        {
            case 1: total = total + price1;
            	    break;
            case 2: total = total + price2;
            	    break;
            case 3: total = total + price3;
            	    break;
            case 4: total = total + price4;
            	    break;
        }
        
    }
    while(option != -1);
    cout << "The total is: " << total << endl << "How would you like to pay? (1. cash/2. card): ";
    cin >> payment_choice;
    
    if(payment_choice == 1)
    {
        cout << "Enter your amount: ";
        cin >> amount;
        if(amount < total)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            cout << "The change is: " << amount - total;
	}
    }
    else
    {
        cout << "Card payment successfull";
    }
    return 0;
}
