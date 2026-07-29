/*==========================================================================

	Prorammer:      Emaad Ilyas
	Course:         CS 1A - Introduction to Computer Science
	Assignment:     SP5-6 header
	Date Written:   2026-07-28
	Date Due:       2026-07-29
	Instructor:     Dr. Jeffrey Barnett

	Purpose:        This file will have every single #include lines, global
						 constant, function prototypes, and with their own header
						 comment. It's basically the start of everything no func.
						 body in here.

===========================================================================*/
// all of the inclusions and gaurds
#ifndef SERENDIPITY_H
#define SERENDIPITY_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// named constants
const int NUM_COLS = 80;
const string CLEAR_SCREEN = "\033[2J\033[1;1H";
const string RESET = "\033[0m"; //resets the box
const string BOLD = "\033[1m";
const string ORANGE = "\033[33m";
const string EXIT_RED = "\033[31m";
const string GREEN = "\033[32m";
const double TAX_RATE = 0.06;

// -------------------------------Function Prototypes------------------------------ //

/* Function --  cashier
	Purpose  --  Reads one book sale from keyboard
					 computes the subtotal, sales tax,
					 total, and prints the formatted receipt.
	Parameters:  none
	Returns:     nothing (void)
	Side Effect: Prompts for and reads five sale inputs and writes
					 the completed receipt to the standard output area
*/
void cashier(); // prototype for cashier

/* Function -- invmenu
	Purpose:    Display serendipity bookseller's inventory menu screen
					calls for an input inside of a formatted box
					sends them to another page using a switch source
	Parameters: none
	Returns:    nothing (void)
	Side Effect: Prompts for an input and sends to another box after input read
*/
void invMenu(); // prototype for invmenu

	/* Function: lookUpBook
		Purpose:  Used for the look up a book feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Look up Book.
	*/
	void lookUpBook(); // prototype for lookUpBook

	/* Function: addBook
		Purpose:  Used for the add a book feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Add Book.
	*/
	void addBook(); // prototype for addbook

	/* Function: editBook
		Purpose:  Used for the edit book feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Edit Book.
	*/
	void editBook(); // prototype for edit book

	/* Function: deleteBook
		Purpose:  Used for the delete a book feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Delete a Book.
	*/
	void deleteBook(); // prototype for delete book

	/* Function: bookInfo
		Purpose:  Displays Book Information, with labelled feilds
					 filled in with add book or edit book.
		Parameters: none
		Returns:    nothing (void)
		Side Effect: Writes book information form to the standard output
	*/
	void bookInfo(); // prototype for book info


/* Function -- reports
	Purpose:    Display serendipity reports screen, formatted iomanip box, asks user
					to input a choice and then reads it. Uses a switch case to send to another
					menu screen
	Parameters: none
	Return:     nothing (void)
	Side Effects: Proimpts for an input and sends to another box after input read
*/
void reports(); // prototype for reports

	/* Function: repListing
		Purpose:  Used for the listing feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Inventory Listing.
	*/
	void repListing(); // prototype for report listing

	/* Function: repWholesale
		Purpose:  Used for the wholesale feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Inventory Wholesale Value.
	*/
	void repWholesale(); // prototype for rep wholesale

	/* Function: repRetail
		Purpose:  Used for the retail feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Inventory Retail Value.
	*/
	void repRetail(); // prototype for rep retail

	/* Function: repQty
		Purpose:  Used for the listing quantity feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Listing by Quantity.
	*/
	void repQty(); // prototype for rep quantity

	/* Function: repCost
		Purpose:  Used for the listing cost feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Listing by Cost.
	*/
	void repCost(); // prototype for rep costs

	/* Function: repAge
		Purpose:  Used for the listing age feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Listing by Age.
	*/
	void repAge(); // prototype for rep age


#endif // THE END GAURD
