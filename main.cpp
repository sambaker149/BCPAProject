// main.cpp
// An app to allow tickets to be purchased for shows
#include <iostream>
#include <iomanip>
#include <string>
#include "showSeat.h"
#include "person.h"
#include "customer.h"
#include "venueManager.h"
#include "show.h"
#include "ticket.h"
#include "pch.h"
using namespace std;

void main()
{
	// Initial variable declaration
	string a,
		b,
		c,
		f,
		g,
		h,
		o;
	int d,
		i,
		j,
		k,
		l,
		m,
		n;
	double e;
	char ch,
		terminator;

	// Objects
	showSeat SEAT;
	person PERSON;
	customer CUST;
	manager MANAGER;
	show SHOW;
	ticket* TICK;

	// Get login and user type
	PERSON.getLogin();
	PERSON.getUserType(o);

	if (o == "Customer")
	{
		// Get customer information
		CUST.getProfileInfo(f, g, h);

		// Display main menu and allow customer to choose option
		system("CLS");

		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

		cout << "1. Buy Tickets for Upcoming Shows" << endl;
		cout << "2. Log Out\n" << endl;
		cout << "Please Enter a Menu Choice Number: ";
		cin.get(ch);

		while (ch != '1' && ch != '2')
		{
			cin.clear();
			cin.ignore(100, '/n'); // Ensure buffer is completely clear
			cout << "Please Enter a Valid Menu Choice Number: ";
			cin.get(ch);
		}
		if (ch == '2')
		{
			return EXIT_SUCCESS;
		}

		// Select a show
		do
		{
			SHOW.selectShow(a, b);
			c = SHOW.selectTime();

			do
			{
				cout << "\nAre you happy with your choice? (Y = Yes, N = No)?: ";
				cin.get(ch);
			} while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
			cin.get(terminator); // Clear buffer
		} while (ch != 'N' || ch != 'n');

		// Select seat and calculate price
		SEAT.initialiseFloorPlan();
		d = SEAT.getNumSeats();
		e = SEAT.getSeatSelection(m, n);

		// Discounts, payment, and ticket generation
		SEAT.calculateDiscount(e);
		CUST.getPaymentInfo(i, j, k, l);
		TICK->printTicket(a, b, c, d, f, g, h);
	}
	else if (o == "Manager")
	{
		// Display main menu and allow manager to choose option
		system("CLS");

		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

		cout << "1. " << endl;
		cout << "2. " << endl;
		cout << "Please Enter a Menu Choice Number: ";
		cin.get(ch);

		while (ch != '1' && ch != '2')
		{
			cin.clear();
			cin.ignore(100, '/n'); // Ensure buffer is completely clear
			cout << "Please Enter a Valid Menu Choice Number: ";
			cin.get(ch);
		}
		if (ch == '2')
		{
			return EXIT_SUCCESS;
		}
	}
}