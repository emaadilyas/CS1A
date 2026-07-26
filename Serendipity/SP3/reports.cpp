/* =====================================================================================

	Programmer:            Emaad Ilyas
	Course:                CS1A Intro to Compsci I w/ C++
	Assignment:            LAb SP2 - Serendipity Reports Screen
	Date Written:          2026-07-01
	Date Due:              2026-07-08
	Instructor:            Jeffery Barnett

	Purpose:               Display the Serendipity Booksellers Reports menu screen
	                       formatted with iomanip maniuplators. Display only no input yet.
======================================================================================== */

// basic inclusions
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// color variables
const string ORANGE = "\033[33m";
const string BOLD = "\033[1m";
const string RESET = "\033[0m";

// main function
int main() {

// ASCII border box & menu top border
cout << '+' << right << setfill('=') << setw(79) << '+' << setfill(' ') << endl;
cout << '|' << left << setw(78) << "" << '|' << endl;
// main title for the store
cout << '|' << right << ORANGE << setw(50) << "Serendipity Booksellers" << RESET << setw(29) << '|' << endl;
// subtitle showing what part the user is in
cout << '|' << right << BOLD << setw(42) << "Reports" << RESET << setw(37) << '|' << endl;

cout << '|' << left << setw(78) << "" << '|' << endl;
// Choice module text
cout << '|' << left << left << setw(78) << "      1. Inventory Listing" << '|' << endl;
cout << '|' << left << left << setw(78) << "      2. Inventory Wholesale Value" << '|' << endl;
cout << '|' << left << left << setw(78) << "      3. Inventory Retail Value" << '|' << endl;
cout << '|' << left << left << setw(78) << "      4. Listing by Quantity" << '|' << endl;
cout << '|' << left << left << setw(78) << "      5. Listing by Cost" << '|' << endl;
cout << '|' << left << left << setw(78) << "      6. Listing by Age" << '|' << endl;
cout << '|' << left << left << setw(78) << "      7. Return to the Main Menu" << '|' << endl;
// border
cout << '|' << left << setw(78) << "" << '|' << endl;
// more choice
cout << '|' << left << BOLD << setw(78) << "      Enter Your Choice: " << RESET << '|' << endl;
// rest of the border
cout << '|' << left << setw(78) << "" << '|' << endl;
cout << '+' << right << setfill('=') << setw(79) << '+' << setfill(' ') << endl;


return 0;
}
