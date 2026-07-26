/* ======================================================================

	Programmer:       Emaad Ilyas
	Course:           CS1A - Introduction to Computer Science 1
	Assignment:       P1 - Change Maker
	Date Written:     2026-07-26
	Date Due:         2026-07-26
	Instructor:       Dr. Jeffery Barnett

	Purpose:          Program will read an input for money
							then will break it down into smaller
							currency using largest coins first approach system.
							It will used fixed set precision to show the change
							amount for the user.

========================================================================= */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// establishing the variable the user will input
	double amount;

	// asking the user for the input
	cout << "Enter Amount: ";
	cin >> amount;

	//converting the input into cents
	int totalCents = amount * 100;

	//getting the dollars first since it's the biggest denomination
	int dollars = totalCents / 100;
	int remainingCents = totalCents % 100; //used for next math quarters

	// getting the quarters using math
	int quarters = remainingCents / 25;
	remainingCents = remainingCents % 25; //used for dimes

	// getting the value for # of dimes
	int dimes = remainingCents / 10;
	remainingCents = remainingCents % 10; //used for nickles

	// getting the value for # of nickles
	int nickles = remainingCents / 5;
	remainingCents = remainingCents % 5; //used for pennies

	// getting the value for # of pennies
	int pennies = remainingCents; // doing remainingCents / 1 means literally nothing since cause its divided by 1...


	// Printing out the return
	cout << fixed << setprecision(2); //getting the setprecision ready for the printing
	cout << "Change Maker Amount Entered: $" << amount << " ----------------------- " << "Dollars: " << dollars << " Quarters: " << quarters << " Dimes: " << dimes << " Nickles: " << nickles << " Pennies: " << pennies << endl;


return 0;
}
