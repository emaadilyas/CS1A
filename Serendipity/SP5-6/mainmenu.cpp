/* ===============================================================================================

	Programmer:            Emaad Ilyas
	Course:                CS1A Intro to Compsci I w/ C++
	Assignment:            LAb SP5 - Serendipity Main Menu Screen
	Date Written:          2026-07-01
	Date Due:              2026-07-08
	Instructor:            Jeffrey Barnett

	Purpose:               Display the Serendipity Booksellers Main Menu screen
	                       formatted with iomanip maniuplators. Includes a switch with a
								  case to give an output depending on the input that the user puts
								  either changing their location or presenting with an error message.

=============================================================================================== */

// include serendipity.h which has all of the inclusions and constants
#include "serendipity.h"

// ---------------------------|Main Function: Mainmenu|--------------------------- //
int main()
{
	char choice; // variable user will input to chose where to move

	do
	{
		cout << CLEAR_SCREEN;
		// ASCII border box & menu top border
		cout << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << endl;
		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		// main title for the store
		cout << '|' << right << ORANGE << setw(NUM_COLS - 30) << "Serendipity Booksellers" << RESET << setw(NUM_COLS - 51) << '|' << endl;
		// subtitle showing what part the user is in
		cout << '|' << right << BOLD << setw(NUM_COLS - 37) << "Main Menu" << RESET << setw(NUM_COLS - 44) << '|' << endl;

		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		// Choice module text
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      1. Cashier Module" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      2. Inventory Database Module" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      3. Report Module" << '|' << endl;
		cout << '|' << left << left << EXIT_RED << setw(NUM_COLS - 2) << "      4. Exit" << RESET << '|' << endl;
		// border
		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		// more choice
		cout << '|' << left << setw(NUM_COLS - 74) << "      Enter your choice: "<< "\033[s" << right << setw(NUM_COLS - 26) << '|' << endl;
		// rest of the border
		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		cout << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << endl;

		// the user enter area
		cout << "\033[u";
		cin.get(choice); // this was here since of a bug where if you just typed enter when the program runs nothing would happen and you would go to a newline
		if (choice != '\n')
		{
			cin.ignore(1000, '\n');
		}
		cout << "\033[2B";

		switch (choice) // switch based on what the user responded
		{
			case '1':
				cashier();
				break;
			case '2':
				invMenu();
				break;
			case '3':
				reports();
				break;
			case '4':
				cout << CLEAR_SCREEN;
				cout << ">> Exiting Serendipity." << endl;
				break;
			case '\n':
				cout << CLEAR_SCREEN;
				cout << "You entered nothing" << endl;
				cout << "Press ENTER to continue ..." << endl;
				cin.ignore();
				break;
			default: // default case for if they responded with a non useable input
				cout << CLEAR_SCREEN;
				cout << "Invalid choice ***" << EXIT_RED << choice << RESET << "***." << endl;
				cout << "Please enter 1-4." << endl;
				cout << "Press ENTER to continue ..." << endl;
				cin.ignore(1000, '\n');
		}
	}
	while (choice != '4');
	return 0;
}

// ---------------------------|Function: Cashier|--------------------------- //
void cashier() {

	cout << CLEAR_SCREEN;
	cout << endl;
	// declaring constants and variables the user will input
	string saleDate;                 // the date of the sale (MM-DD-YYYY)
	int quantity;                    // the number of quantities sold (integer becuase it's a whole num)
	string isbn;                     // International Standard Book Number (no spaces)
	string bookTitle;                // Title of the book (Ex: The Hobbit)
	double retailPrice;              // The retail price of the book (the money cost)

	// requesting the variables
	cout << "Date (MM-DD-YYYY): ";
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
	cin.ignore(1000, '\n');

	// doing the math for the receipt to print
	double lineTotal = quantity * retailPrice;
	double salesTax = lineTotal * TAX_RATE;
	double total = lineTotal + salesTax;

	// printing the receipt
	cout << CLEAR_SCREEN;
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
	cout << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

// ---------------------------|Function: Inventory Menu|--------------------------- //
void invMenu()
{
	char choice;
	do
	{
		cout << CLEAR_SCREEN;
		// ASCII border box & menu top border
		cout << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << endl;
		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		// main title for the store
		cout << '|' << right << ORANGE << setw(NUM_COLS - 30) << "Serendipity Booksellers" << RESET << setw(NUM_COLS - 51) << '|' << endl;
		// subtitle showing what part the user is in
		cout << '|' << right << BOLD << setw(NUM_COLS - 32) << "Inventory Database" << RESET << setw(NUM_COLS - 49) << '|' << endl;

		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		// Choice module text
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      1. Look Up a Book" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      2. Add a Book" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      3. Edit a Book's Record" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      4. Delete a Book" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      5. Return to the Main Menu" << '|' << endl;
		// border
		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		// more choice
		cout << '|' << left << setw(NUM_COLS - 74) << "      Enter Your Choice: " << "\033[s" << right << setw(NUM_COLS - 26) << '|' << endl;
		// rest of the border
		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		cout << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << endl;

		cout << "\033[u";
		cin.get(choice);

		if (choice != '\n')
		{
			cin.ignore(1000, '\n');
		}

		cout << "\033[2B";

		switch (choice)
		{
			case '1':
				lookUpBook();
				break;
			case '2':
				addBook();
				break;
			case '3':
				editBook();
				break;
			case '4':
				deleteBook();
				break;
			case '5':
				cout << CLEAR_SCREEN;
				cout << ">> Returning to Main Menu..." << endl;
				cout << "Press ENTER to continue..." << endl;
				cin.ignore(1000, '\n');
				break;
			default:
				cout << CLEAR_SCREEN;
				cout << "Invalid choice ***" << EXIT_RED << choice << RESET << "***." << endl;
				cout << "Please enter 1-5." << endl;
				cout << "Press ENTER to continue ..." << endl;
				cin.ignore(1000, '\n');
		}
	}
	while (choice != '5');
}

// ---------------------------|Function: Reports|--------------------------- //
void reports()
{
	char choice;
	do
	{
		cout << CLEAR_SCREEN;
		// ASCII border box & menu top border
		cout << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << endl;
		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		// main title for the store
		cout << '|' << right << ORANGE << setw(NUM_COLS - 30) << "Serendipity Booksellers" << RESET << setw(NUM_COLS - 51) << '|' << endl;
		// subtitle showing what part the user is in
		cout << '|' << right << BOLD << setw(NUM_COLS - 38) << "Reports" << RESET << setw(NUM_COLS - 43) << '|' << endl;

		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		// Choice module text
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      1. Inventory Listing" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      2. Inventory Wholesale Value" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      3. Inventory Retail Value" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      4. Listing by Quantity" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      5. Listing by Cost" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      6. Listing by Age" << '|' << endl;
		cout << '|' << left << left << setw(NUM_COLS - 2) << "      7. Return to the Main Menu" << '|' << endl;
		// border
		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		// more choice
		cout << '|' << left << setw(NUM_COLS - 74) << "      Enter Your Choice: " << "\033[s" << right << setw(NUM_COLS - 26) << '|' << endl;
		// rest of the border
		cout << '|' << left << setw(NUM_COLS - 2) << "" << '|' << endl;
		cout << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << endl;

		cout << "\033[u";
		cin.get(choice);

		if (choice != '\n')
		{
			cin.ignore(1000, '\n');
		}

		cout << "\033[2B";

		switch (choice)
		{
			case '1':
				repListing();
				break;
			case '2':
				repWholesale();
				break;
			case '3':
				repRetail();
				break;
			case '4':
				repQty();
				break;
			case '5':
				repCost();
				break;
			case '6':
				repAge();
				break;
			case '7':
				cout << CLEAR_SCREEN;
				cout << ">> Returning to Main Menu..." << endl;
				cout << "Press ENTER to continue..." << endl;
				cin.ignore(1000, '\n');
				break;
			default:
				cout << CLEAR_SCREEN;
				cout << "Invalid choice ***" << EXIT_RED << choice << RESET << "***." << endl;
				cout << "Please enter 1-7." << endl;
				cout << "Press ENTER to continue ..." << endl;
				cin.ignore(1000, '\n');
		}
	}
	while (choice != '7');
}

// ---------------------------|Function: Bookinfo|--------------------------- //
void bookInfo()
{
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
}

// ---------------------------|Function: invmenu() Stubs|--------------------------- //

void lookUpBook()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Look Up Book" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

void addBook()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Add Book" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

void editBook()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Edit Book" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

void deleteBook()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Delete Book" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

// ---------------------------|Function: reports() Stubs|--------------------------- //

void repListing()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Inventory Listing" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

void repWholesale()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Inventory Wholesale Value" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

void repRetail()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Inventory Retail Value" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

void repQty()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Listing By Quantity" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

void repCost()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Listing By Cost" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}

void repAge()
{
	cout << CLEAR_SCREEN;
	cout << "You selected Listing By Age" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');
}
