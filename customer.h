// customer.h
// Object of class customer
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

class customer
{
public:
	customer();
	~customer();
	void getLogin();
	void getProfileInfo(string& fName, string& sName, string& address);
	void getPaymentInfo(int& cardNo, int& cvvNo, int& expMonth, int& expYear);
protected:
	string fName;
	string sName;
	string address;
	int cardNo;
	int cvvNo;
	int expMonth;
	int expYear;
};

// Constructor
customer::customer()
{
	fName = "";
	sName = "";
	address = ""; // Initialises variables
}

// Destructor
customer::~customer()
{
}

// Enter customer login
void customer::getLogin()
{
	string username; // Usernames would be stored in a database file in a real system
	string password; // Any username/password accepted in this example

	cout << "================ Welcome to the BCPA ticket purchasing system ================" << endl;
	cout << "================================ Please log in ===============================" << endl;

	cout << "Enter username:";
	getline(cin, username);

	while (username.length() > 10)
	{
		cout << "Your username should be no longer than 10 characters long." << endl;
		cout << "Please re-enter your username: ";
		getline(cin, username);
	}

	cout << "Enter password";
	getline(cin, password);

	while (password.length() > 10)
	{
		cout << "Your password should be no longer than 10 characters long." << endl;
		cout << "Please re-enter your password: ";
		getline(cin, password);
	}
}

// Enter customer profile information
void customer::getProfileInfo(string& fName, string& sName, string& address)
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER PROFILE INFORMATION ~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	char terminator;

	cout << "Enter First Name: " << endl;
	getline(cin, fName);

	while (fName.length() > 25)
	{
		cout << "Your first name should be no more than 25 characters long." << endl;
		cout << "Please re-enter your first name: ";
		getline(cin, fName);
	}

	cout << "Enter Surname: " << endl;
	getline(cin, sName);

	while (fName.length() > 25)
	{
		cout << "Your surname should be no more than 25 characters long." << endl;
		cout << "Please re-enter your first name: ";
		getline(cin, sName);
	}

	cin.get(terminator);

	char terminator;

	cout << "Enter Address: " << endl;
	getline(cin, address);

	while (address.length() < 20)
	{
		cout << "Your address should be no less than 20 characters long." << endl;
		cout << "Please enter a valid email: ";
		getline(cin, address);
	}

	cin.get(terminator);
}

// Enter payment information
void customer::getPaymentInfo(int& cardNo, int& cvvNo, int& expMonth, int& expYear)
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER PAYMENT INFORMATION ~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	char terminator;
	cout << "Enter Card Number: " << endl;
	cin >> cardNo;

	while (sizeof(cardNo) != 16)
	{
		cout << "Your card number should be 16 characters long." << endl;
		cout << "Please enter a valid card number: ";
		cin >> cardNo;
	}

	cout << "Enter CVV Number: " << endl;
	cin >> cvvNo;

	while (sizeof(cvvNo) != 3)
	{
		cout << "Your CVV number should only be 3 characters long." << endl;
		cout << "Please enter a valid CVV number: ";
		cin >> cvvNo;
	}

	cout << "Enter Expiry Month: " << endl;
	cin >> expYear;

	while (sizeof(expMonth) != 2)
	{
		cout << "The expiry month should be no more than 2 characters long." << endl;
		cout << "Please enter a valid expiry month: ";
		cin >> expMonth;
	}

	cout << "Enter Expiry Year: " << endl;
	cin >> expYear;

	while (sizeof(expYear) != 4)
	{
		cout << "The expiry year should only be 4 characters long." << endl;
		cout << "Please enter a valid expiry year: ";
		cin >> expYear;
	}

	cin.get(terminator);

	cout << "*** PAYMENT ACCEPTED ***" << endl;
}