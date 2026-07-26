/* =====================================================================================

	Programmer:            Emaad Ilyas
	Course:                CS1A Intro to Compsci I w/ C++
	Assignment:            LAb SP2 - Serendipity Main Menu Screen
	Date Written:          2026-07-01
	Date Due:              2026-07-08
	Instructor:            Jeffery Barnett

	Purpose:               Display the Serendipity Booksellers Book Cashier Menu screen
	                       formatted with iomanip maniuplators. Display only no input yet.
======================================================================================== */

// basic inclusions
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//color variables
const string GREEN = "\033[32m";
const string RESET = "\033[0m";
const string ORANGE = "\033[33m";
// main function
int main() {

cout << ORANGE << "Serendipity Book Sellers" << RESET << endl;
cout << endl;

cout << "Date:" << endl;
cout << endl;

cout << left << setw(4) << "Qty" << setw(14) << "ISBN" << setw(23) << "Title" << setw(9) << "Price" << "Total" << endl;
cout << setfill('-') << setw(59) << "" << setfill(' ') << endl;
cout << endl;

cout << setw(16) << "" << "Subtotal" << endl;
cout << setw(16) << "" << "Tax" << endl;
cout << setw(16) << "" << "Total" << endl;

cout << endl;
cout << GREEN << "Thank You for Shopping at Serendipity!" << RESET << endl;

return 0;
}
