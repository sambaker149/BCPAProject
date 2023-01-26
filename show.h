// show.h
// Object of class show
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class show
{
public:
	show();
	~show();
	void selectShow(string& showName, string& showDate);
	string selectTime();
protected:
	string showName;
	string showDate;
	string showTime;
	char ch,
		terminator;
};

// Constructor
show::show()
{
	showName = "";
	showDate = "";
	showTime = "";
}

// Destructor
show::~show()
{
}

// Select upcoming show
void show::selectShow(string& showName, string& showDate)
{
	char ch;
	char terminator;

	system("CLS");

	cout << "=============== SELECT AN UPCOMING SHOW ===============" << endl;

	cout << "1. Harry Potter (30/01/2023)" << endl;
	cout << "2. Star Wars Musical (03/02/2023)" << endl;
	cout << "3. Hairspray (07/02/2023)" << endl;

	cin.clear();
	cin.ignore(100, '\n'); // Ensures buffer is completely clear
	cout << "Please select a show number: ";
	cin.get(ch);

	while (ch != '1' && ch != '2' && ch != '3')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please select a valid show number: ";
		cin.get(ch);
	}

	switch (ch)
	{
	case '1': showName = "Harry Potter", showDate = "30/01/2023";
		break;
	case '2': showName = "Star Wars Musical", showDate = "03/02/2023";
		break;
	case '3': showName = "Hairspray", showDate = "07/02/2023";
		break;
	}

	this->showName = showName;
	this->showDate = showDate; // Enter reference variable into class variable

	cin.get(terminator); // Clears buffer
}

// Select time
string show::selectTime()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT TIME ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

	cout << "1. 11AM" << endl;
	cout << "2. 6PM" << endl;
	cout << "Please Enter a Menu Choice Number: ";
	cin.get(ch);

	while (ch != '1' && ch != '2')
	{
		cin.clear();
		cin.ignore(100, '/n');
		cout << "Please Enter a Valid Menu Choice Number: ";
		cin.get(ch);
	}
	if (ch == '1')
	{
		showTime = "11:00";
	}
	if (ch)
	{
		showTime = "18:00";
	}
}