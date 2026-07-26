/* =====================================================
	Programmer:                       Ilyas, Emaad
	Course:                           CS 1A - Introduction to Computer Science
	Assignment:                       Lab A6 - Formatted Outputs and Strings
	Date Written:                     2026-06-29
	Date Due:                         2026-07-05
	Instructor:                       Dr. Jeffery Barnett
	Purpose:                          Read a quantity, a customer full name (getline)
	                                  and a unit price, then print a column-aligned
	                                  receipt with a currency total useing setw, fixed, and setprecision
======================================================*/

// basic inclusions I use for my code
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
// establishing variable(s)
int quantity;
string customerName;
double unitPrice;

// Input and output code
cout << endl;
cout << "Enter quantity: ";
cin >> quantity;

// clears out the buffer, and allows to write the full name
// otherwise the "enter" input would still be there in the code and would mess up the getline part.
// getline would include the enter and immediately think that it's action is done since it first reads the enter
cin.ignore(1000, '\n');
cout << "Enter customer full name: ";
getline(cin, customerName);

// Getting info for the receipt
cout << "Enter price per item: ";
cin >> unitPrice;
double total = unitPrice * quantity;
cout << fixed << setprecision(2);
cout << endl;

// printing receipt
cout << "========== RECEIPT ==========" << endl;
cout << "Customer: " << customerName << endl;
// setw only applies to 1 value, but left/right stays until changed
cout << left << setw(11) << "Qty"
	  << right << setw(11) << "Price"
	  << setw(11) << "Total" << endl;

cout << setw(11) << quantity
	  << setw(11) << unitPrice
	  << setw(11) << total << endl;

// ends it all
return 0;
}
