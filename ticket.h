// ticket.h
// Object of class ticket
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class ticket
{
public:
	ticket();
	~ticket();
	void setPrice(double price);
	void printTicket(string showName, string showDate, string showTime, int 
		numSeats, string fName, string sName, string address);
	virtual double cost() = 0; // Virtual function used by derived classes
protected:
	double totalCost;
};

// Constructor
ticket::ticket()
{
	totalCost = 0; // Initialise totalCost
}

// Destructor
ticket::~ticket()
{
}

// Calculate discount cost
void ticket::setPrice(double price)
{
	totalCost = price;
	cout << "\nThe total price of your tickets (including discounts) is "
		<< (char)156 << this->cost() << ".\n" << endl;
	system("PAUSE");
}

// Print out tickets using derived classes
void ticket::printTicket(string showName, string showDate, string showTime, int numSeats,
	string fName, string sName, string address)
{
	system("CLS");

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ YOUR TICKETS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

	cout << "===============================================================================" << endl;
	cout << "================== The Bucks Centre for the Performing Arts ===================" << endl;
	cout << "=============================== Enjoy the Show! ===============================" << endl;
	cout << "Show: " << showName << endl;
	cout << "Date: " << showDate << endl;
	cout << "Time: " << showTime << endl;
	cout << "===============================================================================" << endl;
	cout << "Number of seats: " << numSeats << endl;
	cout << "Total cost: " << (char)156 << this->cost() << endl;
	cout << "Ticket purchaser: " << fName << " " << sName << endl;
	cout << "Postal address: " << address << endl;
	cout << "===============================================================================" << endl;
	cout << "===============================================================================\n\n" << endl;
}