// showSeat.h
// Object of class showSeat
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class showSeat
{
public:
	showSeat();
	~showSeat();
	void initialiseFloorPlan();
	int getNumSeats();
	double getSeatSelection();
private:
	void displayFloorPlan(int r, int c);
	void selectTicketType(string type);
	void calculatePrice(double &price); // Only accessed by class showSeat
protected:
	string type;
	char floorPlan[7][6];
	int numSeats;
	char ch,
		terminator;
	int rNum; // Used to calculate price
	double price;
};

// Constructor
showSeat::showSeat()
{
	for (int r = 0; r < 7; r++)
		for (int c = 0; c < 6; c++)
			floorPlan[r][c] = '0'; // Allocates memory slots for floor plan array

	numSeats = 0;
	rNum = 0;
	price = 0; // Initialise remaining variables
}

// Destructor
showSeat::~showSeat()
{
}

// Initialise theatre floor plan
void showSeat::initialiseFloorPlan()
{
	for (int r = 0; r < 7; r++) // Prepares rows
		for (int c = 0; c < 6; c++) // Prepares columns
			floorPlan[r][c] = 'A'; // Populates array with 'A' character (available)
}

// Get user's number of seats
int showSeat::getNumSeats()
{
	system("CLS");

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SEATS INTERACTIVELY ~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	do
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "How many tickets would you like to purchase (max 8)?:"; // Prompts customer to enter number of tickets
		cin >> numSeats;
		cout << endl;
	} while (numSeats != 1 && numSeats != 2 && numSeats != 3 && numSeats != 4 && numSeats
		!= 5 && numSeats != 6 && numSeats != 7 && numSeats != 8);

	return numSeats;
}

double showSeat::getSeatSelection()
{

}

void showSeat::displayFloorPlan(int r, int c)
{

}

void showSeat::selectTicketType(string type)
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT TICKET ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

	cout << "1. Infant" << endl;
	cout << "2. Child" << endl;
	cout << "3.Adult" << endl;
	cout << "4. Senior" << endl;
	cin.get(ch);

	while (ch != '1' && ch != '2' && ch != '3' && ch != '4')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please select a valid menu choice number";
		cin.get(ch);
	}

	switch (ch)
	{
	case '1': type = "Infant";
		break;
	case '2': type = "Child";
		break;
	case '3': type = "Adult";
		break;
	case '4': type = "Senior";
		break;
	}

	this->type = type;

	cin.get(terminator);
}

void showSeat::calculatePrice(double& price)
{
	if (type == "Infant")
	{
		price = 5.00;
	}
	else if (type == "Child")
	{
		price = 7.50;
	}
	else if (type == "Adult")
	{
		price = 15.00;
	}
	else if (type == "Senior")
	{
		price = 10.00;
	}
}