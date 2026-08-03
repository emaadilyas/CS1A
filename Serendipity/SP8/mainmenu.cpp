/* ==========================================================================================================

	Programmer:            Emaad Ilyas
	Course:                CS1A Intro to Compsci I w/ C++
	Assignment:            Final Exam Practical - Serendipity Main Menu Screen
	Date Written:          2026-07-01
	Date Due:              2026-07-08
	Instructor:            Jeffrey Barnett

	Purpose:               Merge the Serendipity Booksellers projects into one program. Displays
								  the Main Menu, Inventory Database Module menu, and the reports menu.
								  Each of which looping in an 80 column box. Reads the user for their input
								  and also checks for bad input from the user. Connected to include another
								  file which contains all of the functionheaders, named constants, inclusions,
								  and gaurds. Stores the store's inventory into eight arrays declared in main().
								  Tracked by a shared record count.

	Algorithm:             1: Displays Main Menu screen in an 80 column box.
								  2: Reads user's choice as a single character.
								  3: If choice is invalid it will show an error, then prompt the user again.
								  4: If the choice selected is 1, it will run the cashier, that reads input from
									  the user for information to generate the receipt.
								  5: If the choice selected is 2, it will change the menu to the Inventory
									  Database Module. Which loops the same way as mainmenu. From the IDM the user
									  is able to add a new book, look up an existing book, or return back to main menu
								  6: If the choice selected is 3, it will change the menu to the Reports Module
									  and it also looks the same as mainmenu. From there the user is able to view
									  all of the information for a book including the name, ISBN, author, etc...
								  7: The inventory itself is stored withing 8 arrays, all created in main()
									  and shared with the functions to add, look up, or list books. A tracker
									  exists to show how many books exist and where to store the next one.
								  8: If the choice selected is 4, the user will exit the program.
								  9: Repeat steps 1 through 7 until the user selects 4 on Main Menu to exit.

=========================================================================================================== */

// include serendipity.h which has all of the inclusions and constants
#include "serendipity.h"

// ---------------------------|Main Function: Mainmenu|--------------------------- //
int main()
{
	char choice; // variable user will input to chose where to move

	// array variables
	string bookTitle[DBSIZE];
	string isbn[DBSIZE];
	string author[DBSIZE];
	string publisher[DBSIZE];
	string dateAdded[DBSIZE];
	int qtyOnHand[DBSIZE];
	double wholesale[DBSIZE];
	double retail[DBSIZE];

	size_t numRecords = 0;

	do
	{
		cout << CLEAR_SCREEN;
		// ASCII border box & menu top border
		cout << CYAN << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		string title = "Serendipity Booksellers";
		string title2 = "Main Menu";
		string opt1 = "      1. Cashier Module";
		string opt2 = "      2. Inventory Database Module";
		string opt3 = "      3. Report Module";
		string opt4 = "      4. Exit";
		string chooseOption = "      Enter your choice: ";

		// title = Serendipity Booksellers
		int totalWidth = NUM_COLS - 2; // 80 columns, minus the two '|'. This is for the setw for the text
		int leftPad = (totalWidth - title.length()) / 2; // basically takes that 78 characters, subtracts title length and then splits that in two for padding
		int rightPad = totalWidth - leftPad - title.length(); // Takes total space, subtracts by half of it, then subtracts the rest by the length of the text
		cout << CYAN << '|' << RESET << setw(leftPad) << "" << ORANGE << title << RESET << setw(rightPad) << "" << CYAN << '|' << RESET << endl; // combines it all together

		// title2 = MainMenu
		int totalWidth2 = NUM_COLS - 2;
		int leftPad2 = (totalWidth2 - title2.length()) / 2;
		int rightPad2 = totalWidth2 - leftPad2 - title2.length();
		cout << CYAN << '|' << RESET << setw(leftPad2) << "" << BOLD << title2 << RESET << setw(rightPad2) << "" << CYAN << '|' << RESET << endl;

		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		// Choice module text
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt1 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt2 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt3 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << EXIT_RED << setw(NUM_COLS - 2) << opt4 << RESET << CYAN << '|' << RESET << endl;
		// border
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		// chooseOption = "      Enter your choice"
		int optionSetw = chooseOption.length();
		int closingSetw = totalWidth - chooseOption.length();
		cout << CYAN << '|' << RESET << left << GREEN << setw(optionSetw) << chooseOption << RESET << SAVE << right << setw(closingSetw) << "" << CYAN << '|' << RESET << endl; // the ansi saves user location

		// rest of the border
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;
		cout << CYAN << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << RESET << endl;

		// the user enter area
		cout << LOAD; // sets user location to previously saved ANSI text
		cin.get(choice); // this was here since of a bug where if you just typed enter when the program runs nothing would happen and you would go to a newline
		if (choice != '\n')
		{
			cin.ignore(1000, '\n');
		}

		switch (choice) // switch based on what the user responded
		{
			case '1': // calls for cashier
				cashier();
				break;
			case '2': // calls for invmenu
				invMenu(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, numRecords);
				break;
			case '3': // calls for reports
				reports(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, numRecords);
				break;
			case '4': // exits program
				cout << CLEAR_SCREEN;
				cout << ">> Exiting Serendipity. Goodbye." << endl;
				break;
			case '\n': // if they entered nothing (pressed enter twice)
				cout << CLEAR_SCREEN;
				cout << "You entered nothing" << endl;
				cout << "Press ENTER to continue ..." << endl;
				cin.ignore(1000, '\n');
				break;
			default: // default case for if they responded with a non useable input
				cout << CLEAR_SCREEN;
				cout << "Invalid choice ***" << EXIT_RED << choice << RESET << "***." << endl;
				cout << "Please enter 1-4." << endl;
				cout << "Press ENTER to continue ..." << endl;
				cin.ignore(1000, '\n');
		}
	}
	while (choice != '4'); // will keep doing this loop until they chose to exit
	return 0;
}

// ---------------------------|Function: Cashier|--------------------------- //
void cashier() {

	cout << CLEAR_SCREEN; // gets rid of old screen (mainmenu) and replaces it for this next part
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

	// checking in case cin fails we dont want that
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << CLEAR_SCREEN;
		cout << "Invalid option entered---Returning to Main Menu." << endl;
		cout << "Press ENTER to continue ..." << endl;
		cin.ignore(1000, '\n');
		return;
	}

	cout << "Enter Price: ";
	cin >> retailPrice;
	cin.ignore(1000, '\n');

	// checking in case cin fails we dont want that
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << CLEAR_SCREEN;
		cout << "Invalid option entered---Returning to Main Menu." << endl;
		cout << "Press ENTER to continue ..." << endl;
		cin.ignore(1000, '\n');
		return;
	}

	// doing the math for the receipt to print
	double lineTotal = quantity * retailPrice;
	double salesTax = lineTotal * TAX_RATE;
	double total = lineTotal + salesTax;

	// printing the receipt
	cout << CLEAR_SCREEN;
	cout << ORANGE << "Serendipity Booksellers" << RESET << endl;
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
void invMenu(string bookTitle[], string isbn[], string author[], string publisher[], string dateAdded[], int qtyOnHand[], double wholesale[], double retail[], size_t &numRecords)
{
	char choice;
	do
	{
		cout << CLEAR_SCREEN; // gets rid of old screen (mainmenu) and replaces it for this next part


		string title = "Serendipity Booksellers";
		string title2 = "Inventory Database";
		string opt1 = "      1. Look Up a Book";
		string opt2 = "      2. Add a Book";
		string opt3 = "      3. Edit a Book's Record";
		string opt4 = "      4. Delete a Book";
		string opt5 = "      5. Return to Main Menu";
		string chooseOption = "      Enter your choice: ";

		// ASCII border box & menu top border
		cout << CYAN << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		// title = Serendipity Booksellers
		int totalWidth = NUM_COLS - 2; // 80 columns, minus the two '|'. This is for the setw for the text
		int leftPad = (totalWidth - title.length()) / 2; // basically takes that 78 characters, subtracts title length and then splits that in two for padding
		int rightPad = totalWidth - leftPad - title.length(); // Takes total space, subtracts by half of it, then subtracts the rest by the length of the text
		cout << CYAN << '|' << RESET << setw(leftPad) << "" << ORANGE << title << RESET << setw(rightPad) << "" << CYAN << '|' << RESET << endl; // combines it all together

		// title2 = Inventory Database
		int totalWidth2 = NUM_COLS - 2;
		int leftPad2 = (totalWidth2 - title2.length()) / 2;
		int rightPad2 = totalWidth2 - leftPad2 - title2.length();
		cout << CYAN << '|' << RESET << setw(leftPad2) << "" << BOLD << title2 << RESET << setw(rightPad2) << "" << CYAN << '|' << RESET << endl;

		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		// Choice module text
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt1 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt2 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt3 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt4 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt5 << CYAN << '|' << RESET << endl;

		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		// chooseOption = "      Enter your choice"
		int optionSetw = chooseOption.length();
		int closingSetw = totalWidth - chooseOption.length();
		cout << CYAN << '|' << RESET << left << GREEN << setw(optionSetw) << chooseOption << RESET << SAVE << right << setw(closingSetw) << "" << CYAN << '|' << RESET << endl; // the ansi saves user location

		// rest of the border
		cout << CYAN << '|' << left << setw(NUM_COLS - 2) << "" << '|' << RESET << endl;
		cout << CYAN << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << RESET << endl;

		// stuff about their choice
		cout << LOAD;
		cin.get(choice);

		if (choice != '\n') // this is for the case where they type nothing used later down
		{
			cin.ignore(1000, '\n');
		}

		switch (choice)
		{
			case '1':
				lookUpBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, numRecords);
				break;
			case '2':
				addBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, numRecords);
				break;
			case '3':
				editBook();
				break;
			case '4':
				deleteBook();
				break;
			case '5': /*
				cout << CLEAR_SCREEN;
				cout << ">> Returning to Main Menu..." << endl;
				cout << "Press ENTER to continue..." << endl;
				cin.ignore(1000, '\n'); */
				break;
			case '\n': // if they entered nothing (pressed enter twice)
				cout << CLEAR_SCREEN;
				cout << "You entered nothing" << endl;
				cout << "Press ENTER to continue ..." << endl;
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
void reports(const string bookTitle[], const string isbn[], const string author[], const string publisher[], const string dateAdded[], const int qtyOnHand[], const double wholesale[], const double retail[], size_t numRecords)
{
	char choice;
	do
	{
		cout << CLEAR_SCREEN;

		string title = "Serendipity Booksellers";
		string title2 = "Reports";
		string opt1 = "      1. Inventory Listing";
		string opt2 = "      2. Inventory Wholesale Value";
		string opt3 = "      3. Inventory Retail Value";
		string opt4 = "      4. Listing by Quantity";
		string opt5 = "      5. Listing by Cost";
		string opt6 = "      6. Listing by Age";
		string opt7 = "      7. Return to Main Menu";
		string chooseOption = "      Enter your choice: ";

		// ASCII border box & menu top border
		cout << CYAN << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << RESET << endl;
		cout << CYAN << '|' << left << setw(NUM_COLS - 2) << "" << '|' << RESET << endl;

		// title = Serendipity Booksellers
		int totalWidth = NUM_COLS - 2; // 80 columns, minus the two '|'. This is for the setw for the text
		int leftPad = (totalWidth - title.length()) / 2; // basically takes that 78 characters, subtracts title length and then splits that in two for padding
		int rightPad = totalWidth - leftPad - title.length(); // Takes total space, subtracts by half of it, then subtracts the rest by the length of the text
		cout << CYAN << '|' << RESET << setw(leftPad) << "" << ORANGE << title << RESET << setw(rightPad) << "" << CYAN << '|' << RESET << endl; // combines it all together

		// title2 = MainMenu
		int totalWidth2 = NUM_COLS - 2;
		int leftPad2 = (totalWidth2 - title2.length()) / 2;
		int rightPad2 = totalWidth2 - leftPad2 - title2.length();
		cout << CYAN << '|' << RESET << setw(leftPad2) << "" << BOLD << title2 << RESET << setw(rightPad2) << "" << CYAN << '|' << RESET << endl;

		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		// Choice module text
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt1 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt2 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt3 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt4 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt5 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt6 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt7 << CYAN << '|' << RESET << endl;
		// border
		cout << CYAN << '|' << left << setw(NUM_COLS - 2) << "" << '|' << RESET << endl;

		// chooseOption = "      Enter your choice"
		int optionSetw = chooseOption.length();
		int closingSetw = totalWidth - chooseOption.length();
		cout << CYAN << '|' << RESET << left << GREEN << setw(optionSetw) << chooseOption << RESET << SAVE << right << setw(closingSetw) << "" << CYAN << '|' << RESET << endl; // the ansi saves user location

		// rest of the border
		cout << CYAN << '|' << left << setw(NUM_COLS - 2) << "" << '|' << RESET << endl;
		cout << CYAN << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << RESET << endl;

		cout << LOAD;
		cin.get(choice);

		if (choice != '\n')
		{
			cin.ignore(1000, '\n');
		}

		switch (choice)
		{
			case '1':
				repListing(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, numRecords);
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
			case '7': /*
				cout << CLEAR_SCREEN;
				cout << ">> Returning to Main Menu..." << endl;
				cout << "Press ENTER to continue..." << endl;
				cin.ignore(1000, '\n'); */
				break;
			case '\n': // if they entered nothing (pressed enter twice)
				cout << CLEAR_SCREEN;
				cout << "You entered nothing" << endl;
				cout << "Press ENTER to continue ..." << endl;
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
void bookInfo(const string bookTitle[], const string isbn[], const string author[], const string publisher[], const string dateAdded[], const int qtyOnHand[], const double wholesale[], const double retail[], size_t index)
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

size_t lookUpBook(const string bookTitle[], const string isbn[], const string author[], const string publisher[], const string dateAdded[], const int qtyOnHand[], const double wholesale[], const double retail[], size_t numRecords)
{
	cout << CLEAR_SCREEN;
	cout << "You selected Look Up Book" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');


	return string::npos;
}

void addBook(string bookTitle[], string isbn[], string author[], string publisher[], string dateAdded[], int qtyOnHand[], double wholesale[], double retail[], size_t &numRecords)
{
	// screen transition
	cout << CLEAR_SCREEN;
	cout << "You selected Add Book" << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore(1000, '\n');

	// more variables
	char choice;
	string pendingBookTitle = "EMPTY";
	string pendingISBN      = "EMPTY";
	string pendingAuthor    = "EMPTY";
	string pendingPublisher = "EMPTY";
	string pendingDateAdded = "EMPTY";
	int pendingQtyOnHand 	= 0;
	double pendingWholesale = 0.0;
	double pendingRetail    = 0.0;

	do
	{
	// literally like the only time <sstream> is used
	ostringstream ss7, ss8;
	ss7 << fixed << setprecision(2) << pendingWholesale;
	ss8 << fixed << setprecision(2) << pendingRetail;

	// variables for the screen
	string title = "Serendipity Booksellers";
	string title2 = "Add Book";
	string title3 = "Database Size: " + to_string(DBSIZE) + " Current Book Count: " + to_string(numRecords);
	string opt1 = " <1> Enter Book Title               >  --" + pendingBookTitle;
	string opt2 = " <2> Enter Book ISBN                >  --" + pendingISBN;
	string opt3 = " <3> Enter Author                   >  --" + pendingAuthor;
	string opt4 = " <4> Enter Publisher                >  --" + pendingPublisher;
	string opt5 = " <5> Enter Date Added (MM-DD-YYYY)  >  --" + pendingDateAdded;
	string opt6 = " <6> Enter Quantity on Hand         >  --" + to_string(pendingQtyOnHand);
	string opt7 = " <7> Enter Wholesale Cost           >  --$" + ss7.str();
	string opt8 = " <8> Enter Retail Price             >  --$" + ss8.str();
	string opt9 = " <9> Save Book to Database";
	string opt0 = " <0> Return to Inventory Menu";

		// actual screen
		cout << CLEAR_SCREEN;
		cout << CYAN << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		// title = Serendipity Booksellers
		int totalWidth = NUM_COLS - 2;
		int leftPad = (totalWidth - title.length()) / 2;
		int rightPad = totalWidth - leftPad - title.length();
		cout << CYAN << '|' << RESET << setw(leftPad) << "" << ORANGE << title << RESET << setw(rightPad) << "" << CYAN << '|' << RESET << endl;

		// title2 = Add Book
		int totalWidth2 = NUM_COLS - 2;
		int leftPad2 = (totalWidth2 - title2.length()) / 2;
		int rightPad2 = totalWidth2 - leftPad2 - title2.length();
		cout << CYAN << '|' << RESET << setw(leftPad2) << "" << BOLD << title2 << RESET << setw(rightPad2) << "" << CYAN << '|' << RESET << endl;

		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		// title2 = DB size and Numrecords
		int totalWidth3 = NUM_COLS - 2;
		int leftPad3 = (totalWidth3 - title3.length()) / 2;
		int rightPad3 = totalWidth3 - leftPad3 - title3.length();
		cout << CYAN << '|' << RESET << setw(leftPad3) << "" << BOLD << title3 << RESET << setw(rightPad3) << "" << CYAN << '|' << RESET << endl;

		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << "" << CYAN << '|' << RESET << endl;

		// Choice module text
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt1 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt2 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt3 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt4 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt5 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt6 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt7 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt8 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt9 << CYAN << '|' << RESET << endl;
		cout << CYAN << '|' << RESET << left << setw(NUM_COLS - 2) << opt0 << CYAN << '|' << RESET << endl;

		cout << CYAN << '+' << right << setfill('=') << setw(NUM_COLS - 1) << '+' << setfill(' ') << RESET << endl;

		cout << "      Choice (0-9): ";
		cin >> choice;
		cin.ignore(1000, '\n');

		if (numRecords >=DBSIZE)
		{
			cout << "The database is full (20 books)." << endl;
			cout << "No books can be added until a record is deleted." << endl;
			cout << "Press ENTER to continue ..." << endl;
			cin.ignore(1000, '\n');
		}
		else
		{
			cout << endl;
			switch (choice)
			{
				case '1': // booktitle
					cout << "Enter Book Title: ";
					getline(cin, pendingBookTitle);
					break;
				case '2': // ISBN
					cout << "Enter ISBN: ";
					getline(cin, pendingISBN);
					break;
				case '3': // Author
					cout << "Enter Author: ";
					getline(cin, pendingAuthor);
					break;
				case '4': // Publisher
					cout << "Enter Publisher: ";
					getline(cin, pendingPublisher);
					break;
				case '5': // Date Added
					cout << "Enter Date Added: ";
					getline(cin, pendingDateAdded);
					break;
				case '6': // QTY on Hand
					cout << "Enter Quantity on Hand: ";
					cin >> pendingQtyOnHand;
					break;
				case '7': // Wholesale
					cout << "Enter Wholesale Price: ";
					cin >> pendingWholesale;
					break;
				case '8': // retail
					cout << "Enter Retail Price: ";
					cin >> pendingRetail;
					break;
				case '9': // save book
					bookTitle[numRecords] = pendingBookTitle;
	            isbn[numRecords]      = pendingISBN;
	            author[numRecords]    = pendingAuthor;
	            publisher[numRecords] = pendingPublisher;
	            dateAdded[numRecords] = pendingDateAdded;
	            qtyOnHand[numRecords] = pendingQtyOnHand;
	            wholesale[numRecords] = pendingWholesale;
	            retail[numRecords]    = pendingRetail;
				case '\n': // inputted nothing
					cout << "You entered nothing" << endl;
					cout << "Press ENTER to continue ..." << endl;
					cin.ignore(1000, '\n');
				break;
				//case '0': // exit this menu checks if it saved or not
			}
		}

	//	cin.ignore(); // just temp for now
	}
	while (choice != 0);
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

void repListing(const string bookTitle[], const string isbn[], const string author[], const string publisher[], const string dateAdded[], const int qtyOnHand[], const double wholesale[], const double retail[], size_t numRecords)
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
