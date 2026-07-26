/* =====================================================================================

	Programmer:            Emaad Ilyas
	Course:                CS1A Intro to Compsci I w/ C++
	Assignment:            LAb SP2 - Serendipity Main Menu Screen
	Date Written:          2026-07-01
	Date Due:              2026-07-08
	Instructor:            Jeffery Barnett

	Purpose:               Display the Serendipity Booksellers Book Info Menu screen
	                       formatted with iomanip maniuplators. Display only no input yet.
======================================================================================== */

// basic inclusions
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// variable for color
const string RESET = "\033[0m"; //resets the box
const string BOLD = "\033[1m";
const string ORANGE = "\033[33m";
// main function
int main() {

cout << " " << ORANGE << setw(36) << "Serendipity Booksellers" << RESET << endl;
cout << " " << BOLD << setw(31) << "Book Information" << RESET << endl;
cout << endl;
cout << " " << left << setw(20) << "ISBN:" << endl;
cout << " " << left << setw(20) << "Title:" << endl;
cout << " " << left << setw(20) << "Author:" << endl;
cout << " " << left << setw(20) << "Publisher:" << endl;
cout << " " << left << setw(20) << "Date Added:" << endl;
cout << " " << left << setw(20) << "Quantity-On-Hand:" << endl;
cout << " " << left << setw(20) << "Wholesale Cost:" << endl;
cout << " " << left << setw(20) << "Retail Price:" << endl;



return 0;
}
