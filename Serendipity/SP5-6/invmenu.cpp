/* =====================================================================================

	Programmer:            Emaad Ilyas
	Course:                CS1A Intro to Compsci I w/ C++
	Assignment:            LAb SP4 - Serendipity Inventory Menu Screen
	Date Written:          2026-07-01
	Date Due:              2026-07-08
	Instructor:            Jeffery Barnett

	Purpose:               Display the Serendipity Booksellers Inventory Menu Database screen
	                       formatted with iomanip maniuplators. Calls for an input for the
								  user to input themselves which will send them to another menu
								  page using a switch source
======================================================================================== */

// basic inclusions
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// color variable
const string ORANGE = "\033[33m";
const string RESET = "\033[0m";
const string BOLD = "\033[1m";

// main function
int main() {

	// ASCII border box & menu top border
	cout << '+' << right << setfill('=') << setw(79) << '+' << setfill(' ') << endl;
	cout << '|' << left << setw(78) << "" << '|' << endl;
	// main title for the store
	cout << '|' << right << ORANGE << setw(50) << "Serendipity Booksellers" << RESET << setw(29) << '|' << endl;
	// subtitle showing what part the user is in
	cout << '|' << right << BOLD << setw(48) << "Inventory Database" << RESET << setw(31) << '|' << endl;

	cout << '|' << left << setw(78) << "" << '|' << endl;
	// Choice module text
	cout << '|' << left << left << setw(78) << "      1. Look Up a Book" << '|' << endl;
	cout << '|' << left << left << setw(78) << "      2. Add a Book" << '|' << endl;
	cout << '|' << left << left << setw(78) << "      3. Edit a Book's Record" << '|' << endl;
	cout << '|' << left << left << setw(78) << "      4. Delete a Book" << '|' << endl;
	cout << '|' << left << left << setw(78) << "      5. Return to the Main Menu" << '|' << endl;
	// border
	cout << '|' << left << setw(78) << "" << '|' << endl;
	// more choice
	cout << '|' << left << BOLD << setw(78) << "      Enter Your Choice: " << RESET << '|' << endl;
	// rest of the border
	cout << '|' << left << setw(78) << "" << '|' << endl;
	cout << '+' << right << setfill('=') << setw(79) << '+' << setfill(' ') << endl;

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;

	// ensuring to flush the buffer if the user inputs a bad input
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
	}

	switch (choice)
	{
		case 1:
			cout << ">> Look Up a Book selected [stub]." << endl;
			break;
		case 2:
			cout << ">> Add a Book selected [stub]." << endl;
			break;
		case 3:
			cout << ">> Edit a Book's Record selected [stub]." << endl;
			break;
		case 4:
			cout << ">> Delete a Book selected [stub]." << endl;
			break;
		case 5:
			cout << ">> Returning to Main Menu..." << endl;
			break;
		default:
			cout << "Invalid Option. Please enter a number 1-5." << endl;
	}

	return 0;
}
