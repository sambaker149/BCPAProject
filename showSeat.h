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
	double getSeatSelection(int r, int c);
	void calculateDiscount(double& price);
private:
	void displayFloorPlan(int r, int c);
	void calculatePrice(int r, int c, double &price); // Only accessed by class showSeat
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

double showSeat::getSeatSelection(int r, int c)
{
	cout << "Enter Row Number: " << endl;
	cin >> r;

	while (sizeof(r) > 7)
	{
		cout << "There are only 7 rows." << endl;
		cout << "Please enter a valid row number: ";
		cin >> r;
	}

	cout << "Enter Column Number: " << endl;
	cin >> r;

	while (sizeof(c) > 6)
	{
		cout << "There are only 6 columns." << endl;
		cout << "Please enter a valid column number: ";
		cin >> c;
	}

	cin.get(terminator);
}

void showSeat::displayFloorPlan(int r, int c)
{

}

void showSeat::calculatePrice(int r, int c, double& price)
{
	price = 15;

	if (r <= 3)
	{
		price = price + 5;
	}
	else if (r >= 4)
	{
		price = price + 2.50;
	}
}

void showSeat::calculateDiscount(double& price)
{
	while (numSeats >= 5)
	{
		price = price - (0.25 * price);
	}
}