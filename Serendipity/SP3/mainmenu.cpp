/* =====================================================================================

	Programmer:            Emaad Ilyas
	Course:                CS1A Intro to Compsci I w/ C++
	Assignment:            LAb SP2 - Serendipity Main Menu Screen
	Date Written:          2026-07-01
	Date Due:              2026-07-08
	Instructor:            Jeffery Barnett

	Purpose:               Display the Serendipity Booksellers Main Menu screen
	                       formatted with iomanip maniuplators. Display only no input yet.
======================================================================================== */

// basic inclusions
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//color constant variables
const string BOX_COLOR = "\033[1;32m"; // bold green
const string RESET = "\033[0m"; //resets the box
const string BOLD = "\033[1m";
const string ORANGE = "\033[33m";
const string EXIT_RED = "\033[31m";

// main function
int main() {

// ASCII border box & menu top border
cout << '+' << right << setfill('=') << setw(79) << '+' << setfill(' ') << endl;
cout << '|' << left << setw(78) << "" << '|' << endl;
// main title for the store
cout << '|' << right << ORANGE << setw(50) << "Serendipity Booksellers" << RESET << setw(29) << '|' << endl;
// subtitle showing what part the user is in
cout << '|' << right << BOLD << setw(43) << "Main Menu" << RESET << setw(36) << '|' << endl;

cout << '|' << left << setw(78) << "" << '|' << endl;
// Choice module text
cout << '|' << left << left << setw(78) << "      1. Cashier Module" << '|' << endl;
cout << '|' << left << left << setw(78) << "      2. Inventory Database Module" << '|' << endl;
cout << '|' << left << left << setw(78) << "      3. Report Module" << '|' << endl;
cout << '|' << left << left << EXIT_RED << setw(78) << "      4. Exit" << RESET << '|' << endl;
// border
cout << '|' << left << setw(78) << "" << '|' << endl;
// more choice
cout << '|' << left << left << setw(78) << "      Enter Your Choice: "<< '|' << endl;
// rest of the border
cout << '|' << left << setw(78) << "" << '|' << endl;
cout << '+' << right << setfill('=') << setw(79) << '+' << setfill(' ') << endl;


return 0;
}
