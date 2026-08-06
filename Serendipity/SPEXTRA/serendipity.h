/*==========================================================================

	Prorammer:      Emaad Ilyas
	Course:         CS 1A - Introduction to Computer Science
	Assignment:     Final Exam Lab Practical - SP8 Header File
	Date Written:   2026-08-03
	Date Due:       2026-08-05
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
#include <cctype>
#include <sstream> // this is literally used for like one thing
using namespace std;

// named constants
const int NUM_COLS = 80; // for the columns
const string CLEAR_SCREEN = "\033[2J\033[1;1H"; // clears the screen
const string RESET = "\033[0m"; //resets the box
const string BOLD = "\033[1m"; // bold text
const string ORANGE = "\033[33m"; // orange color
const string EXIT_RED = "\033[31m"; // red color use in the exit button
const string GREEN = "\033[32m"; // green color
const string CYAN = "\033[36m"; // cyan color
const string SAVE = "\033[s"; // save for the ansi commands
const string LOAD = "\033[u"; // load the save position
const double TAX_RATE = 0.06; // constant for cashier
const size_t DBSIZE = 20; // constant for database

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
					sends them to another page using a switch source.
					Forwards the inventory arrays to the subpages down below it.
	Parameters: The 8 parallel arrays - used to send down to the other functions
					size_t &numRecords - pass by reference so the sub functions can update
					the counter when they're in use and are supposed to.
					this is used to send it down to the other functions like add book
	Returns:    nothing (void)
	Side Effect: Prompts for an input and sends to another box after input read
*/
void invMenu(string bookTitle[], string isbn[], string author[], string publisher[], string dateAdded[], int qtyOnHand[], double wholesale[], double retail[], size_t &numRecords); // prototype for invmenu

	/* Function: lookUpBook
		Purpose:  Used for the look up a book feature. Searches for a book
					 via ISBN and bookTitle. Offers matches one-by-one calls.
					 calls bookInfo if it is accepted so it can display the
					 full information of a book. Gated if the inventory is empty.
		Parameters: 8 parallel arrays and size_t numRecords. Used to search for book.
		Returns: size_t depending if there is a match, no match, or empty inventory
		Side Effects: clears screen and prints you selected Look up Book.
	*/
	size_t lookUpBook(const string bookTitle[], const string isbn[], const string author[], const string publisher[], const string dateAdded[], const int qtyOnHand[], const double wholesale[], const double retail[], size_t numRecords); // prototype for lookUpBook

	/* Function: addBook
		Purpose:  Used for the add a book feature. Presents the pending-values
					 entry menu. Stores all fields in subscript numRecords only on
					 <9>. save then increment and clear pending values. Refuses entry
					 when the databse if full. Ejects when last slot is filled. Warns
					 if field is unsaved.
		Parameters: 8 parallel arrays and a pass by reference for size_t numRecords.
						since it edits some of the numbers for the total numRecords
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Add Book.
	*/
	void addBook(string bookTitle[], string isbn[], string author[], string publisher[], string dateAdded[], int qtyOnHand[], double wholesale[], double retail[], size_t &numRecords); // prototype for addbook

	/* Function: editBook
		Purpose:  Used for the edit book feature
		Parameters: none
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Edit Book.
	*/
	void editBook(string[], string[], string[], string[], string[], int[], double[], double[], size_t &numRecords); // prototype for edit book

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
		Parameters: 8 parallel arrays as the actual book information
						size_t index to show which book info to actually show.
		Returns:    nothing (void)
		Side Effect: Writes book information form to the standard output
	*/
	void bookInfo(const string bookTitle[], const string isbn[], const string author[], const string publisher[], const string dateAdded[], const int qtyOnHand[], const double wholesale[], const double retail[], size_t index); // prototype for book info


/* Function -- reports
	Purpose:    Display serendipity reports screen, formatted iomanip box, asks user
					to input a choice and then reads it. Uses a switch case to send to another
					menu screen. Will also send the variables for the lower functions down to them.
	Parameters: The 8 parallel arrays - used to send down to the other functions
					size_t &numRecords - pass by reference so the sub functions can update
					the counter when they're in use and are supposed to.
					this is used to send it down to the other functions.
	Return:     nothing (void)
	Side Effects: Proimpts for an input and sends to another box after input read
*/
void reports(const string bookTitle[], const string isbn[], const string author[], const string publisher[], const string dateAdded[], const int qtyOnHand[], const double wholesale[], const double retail[], size_t numRecords); // prototype for reports

	/* Function: repListing
		Purpose:  Used for the listing feature. Will print a single line summary
					 summary of the stored books that are listed.
		Parameters: 8 parallel arrays and numRecord by it's value
		Returns: nothing (void)
		Side Effects: clears screen and prints you selected Inventory Listing.
	*/
	void repListing(const string bookTitle[], const string isbn[], const string author[], const string publisher[], const string dateAdded[], const int qtyOnHand[], const double wholesale[], const double retail[], size_t numRecords); // prototype for report listing

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