// person.h
// object of class person
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

class person
{
public:
	person();
	~person();
	void getUserType(string& type);
	void getLogin();
	void getName(string& fName, string& sName);
protected:
	char ch;
	string fName;
	string sName;
};

person::person()
{
	fName = "";
	sName = "";
}

person::~person()
{

}

void person::getUserType(string& type)
{
	system("CLS");

	cout << "\n~~~~~~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~~~~\n" <<
		endl;

	cout << "1. Customer Login" << endl;
	cout << "2. Manager Login" << endl;
	cout << "Please enter a menu choice number: ";
	cin.get(ch);

	while (ch != '1' && ch != '2' && ch != '3')
	{
		cin.clear();
		cin.ignore(100, '\n'); // Ensures buffer is completely clear
		cout << "Please select a valid menu choice number: ";
		cin.get(ch);
	}

	if (ch == '1')
	{
		type = "Customer";
	}
	else if (ch == '2')
	{
		type = "Manager";
	}
}

void person::getLogin()
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

void person::getName(string& fName, string& sName)
{
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
	}
}