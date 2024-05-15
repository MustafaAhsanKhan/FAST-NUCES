#include <iostream>
using namespace std;

int main()
{	
	int num1,num2;
	char op;
	
	cout<<"Enter first number: "<<endl;
	cin>>num1;
	cout<<"Enter second number: "<<endl;
	cin>>num2;
	cout<<"Enter operator: "<<endl;
	cin>>op;
	
	switch(op)
	{	case '+':
			cout << num1 + num2 << endl;
			break;
		case '-':
			cout << num1 - num2 << endl;
			break;
		case '*':
			cout << num1 * num2 << endl;
			break;
		case '/':
			cout << num1 / num2 << endl;
			break;
	}
		
	return 0;
}
	