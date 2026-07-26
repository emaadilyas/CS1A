/* ==============================================================

	Programmer:    Ilyas Emaad
	Course:        CS 1A - Introduction to Computer Science I
	Assignment:    Lab A5 - Interactive Input (Carpet Calculator)
	Date written:  2026-06-29
	Date Due:      2026-07-5
	Instructor:    Dr. Jeffery Bernett

	Purpose:       Read a room's length, width, and price per square foot from the user,
	               then computer and display the carpet area and total cost in formatted currency.
===================================================================================================*/

// normal inclusions for code that I want to use
#include <iostream>
#include <iomanip>
using namespace std;


int main() {

// declaring variables that will get user input later
double length;
double width;
double pricePerSqFt;

// printable outputs that tell user what to input
// inputs spaces for the user to input
cout << "Enter the length (feet):" << endl;
cin >> length;
cout << "Enter the width (feet):" << endl;
cin >> width;
cout << "Enter Price Per Square Foot (Dollars):" << endl;
cin >> pricePerSqFt;

// math to calculate the totals for the user
double area = length * width;
double cost = area * pricePerSqFt;

// prints the users output area and cost, also sets a percision
cout << fixed << setprecision(2);
cout << "The total area is: " << area << " sq ft." << endl;
cout << "The total cost in USD is: $" <<  cost << endl;

// more variables talking about waste
const double WASTE_FACTOR = 1.10;
double costWithWaste = cost * WASTE_FACTOR;

// printing cost with waste
cout << "The total cost including waste is: $" << costWithWaste << endl;

/* Having a constant is good for maintainability incase the WASTE_FACTOR changes in the future
you just need to change 1 variable instead of a lot of numbers.
Also having a variable makes it easier to read than a bunch of numbers */

return 0;

}
