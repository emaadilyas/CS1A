/* =====================================================================================

	Programmer:            Emaad Ilyas
	Course:                CS1A Intro to Compsci I w/ C++
	Assignment:            LAb SP3 - Serendipity Cashier Screen
	Date Written:          2026-07-14
	Date Due:              2026-07-15
	Instructor:            Jeffery Barnett

	Purpose:               Display the Serendipity cashier screen reads one book sale
								  the date, isbn, quantity, price, and uses that to compute
								  the subtotal apply the sales tax, and then print the full
								  receipt.

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

	// declaring constants and variables the user will input

	const double TAX_RATE = 0.06;    // this is the 6% tax fee
	string saleDate;                 // the date of the sale (MM-DD-YYYY)
	int quantity;                    // the number of quantities sold (integer becuase it's a whole num)
	string isbn;                     // International Standard Book Number (no spaces)
	string bookTitle;                // Title of the book (Ex: The Hobbit)
	double retailPrice;              // The retail price of the book (the money cost)

	// requesting the variables
	cout << "Date (DD-MM-YYYY): ";
	getline(cin, saleDate);

	cout << "Book Title: ";
	getline(cin, bookTitle);

	cout << "Enter the ISBN: ";
	cin >> isbn;
	cin.ignore(1000, '\n'); // flushes the buffer left by the cin

	cout << "Enter Quantity: ";
	cin >> quantity;

	cout << "Enter Price: ";
	cin >> retailPrice;

	// doing the math for the receipt to print
	double lineTotal = quantity * retailPrice;
	double salesTax = lineTotal * TAX_RATE;
	double total = lineTotal + salesTax;

	// printing the receipt
	cout << ORANGE << "Serendipity Book Sellers" << RESET << endl;
	cout << endl;

	cout << "Date: " << saleDate << endl;
	cout << endl;

	// printing the main receipt
	cout << left << setw(4) << "Qty" << setw(15) << "ISBN" << setw(23) << "Title" << setw(9) << "Price" << "Total" << endl;
	cout << setfill('_') << setw(59) << "" << setfill(' ') << endl;
	cout << fixed << setprecision(2);
	cout << left << setw(4) << quantity << setw(15) << isbn << setw(23) << bookTitle << "$" << setw(8) << retailPrice << "$" << lineTotal << endl;
	cout << endl;

	cout << "	" << left << setw(11) << "Subtotal" << "$" << setw(6) << right << lineTotal << endl;
	cout << "	" << left << setw(11) << "Tax" << "$" << setw(6) << right << salesTax << endl;
	cout << "	" << left << setw(11) << "Total" << "$" << setw(6) << right << total << endl;

	cout << endl;
	cout << GREEN << "Thank You for Shopping at Serendipity!" << RESET << endl;

	return 0;
}


/* Reflection: Theoretically since the instructions solved the issue itself by changing the order
if there was a cin >> input before a cin.getline input it would have required a cin.ingore() to reset
the buffer that was left from the whitespace of the cin >> input. Since the instructions changed the order
around so that didn't happen, the cin.ignore is not neccessary and is there becuase the instructions say it should
be there. In the case where the cin.ignore was needed and was skipped, the \n from the cin input would be left in
the buffer and immediately clear up the getline request basically making that variable empty */
