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
	char ch,
		terminator;
};

person::person()
{

}

person::~person()
{

}

void person::getUserType(string& type)
{
	system("CLS");

	cout << "\n~~~~~~~~~~~~~~~~~ SELECT USER TYPE ~~~~~~~~~~~~~~~~\n" <<
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

	switch (ch)
	{
	case '1': type = "Customer";
		break;
	case '2': type = "Manager";
		break;
	}

	cin.get(terminator);
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