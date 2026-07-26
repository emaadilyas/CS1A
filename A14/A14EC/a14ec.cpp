/* ===========================================================================

	Programmer:        Emaad Ilyas
	Course:            CS 1A - Introduction to Computer Science I
	Assignment:        Lab A14 - Functions 1: Intro (Temperature Converter)
	Date Written:      2026-07-26
	Date Due:          2026-07-26
	Instructor:        Dr. Jeffery Barnett

	Purpose:           Create a function that will convert a celcius temp
							 into a Fahrenheit one. Value in and getting value back.
							 will also provide the option of going both ways F to C
							 and C to F.

=============================================================================*/
#include <iostream>
#include <iomanip>
using namespace std;

double celsiusToFahrenheit(double celsius); // prototype above the main()
double fahrenheitToCelsius(double fahrenheit); // prototype above the main()

int main ()
{
	int converterChoice;
	cout << "Select which converter you would like to use (C to F select 1 | F to C select 2): ";
	cin >> converterChoice;

	switch(converterChoice)
	{
		case(1):
		{
			double celsiusTemp; // establishing variable user will enter
			cout << "Enter a temperature in Celsius: "; // prompts user to enter
			cin >> celsiusTemp; // user enters here

			// sets temp for F equal to user input as double celsius for the function
			double fahrenheitTemp = celsiusToFahrenheit(celsiusTemp);

			cout << fixed << setprecision(1);
			cout << celsiusTemp << " C = " << fahrenheitTemp << " F" << endl;
			break;
		}
		case(2):
		{
			double fahrenheitTemp;// establishing variable user will enter
			cout << "Enter a temperature in Fahrenheit: "; // promts user to enter
			cin >> fahrenheitTemp; // user enters here

			// sets temp for C equal to user input as double fahrenheit for the function
			double celsiusTemp = fahrenheitToCelsius(fahrenheitTemp);

			cout << fixed << setprecision(1);
			cout << fahrenheitTemp << " F = " << celsiusTemp << " C" << endl;
			break;
		}
		default:
			cout << "Invalid option detected... Try Again." << endl;
	}

	return 0;
}


/* Function:          C to F Calculator
	Purpose:           Calculate the celsius number, and then does math to return it as Fahrenheit
	Parameters:        celsius - temperature user entered
	Return:				 fahrenheit - temperature computer will return
	Side Effect:       none */
double celsiusToFahrenheit(double celsius)
{
	double fahrenheit = celsius * 9.0 / 5.0 + 32; // converts the celsius into fahrenheit
	return fahrenheit; // returns the value to main
}


/* Function:        F to C calculator
	Purpose:   		  Calcualte the fahrenheit number, then does math to return as celsius
	Parameters: 	  fahreinheit - temperature user entered
	Return:          celsius - temperature computer will return
	Side Effect:     none */
double fahrenheitToCelsius(double fahrenheit)
{
	double celsius = (fahrenheit - 32) * 5.0 / 9.0; // converst the F into C
	return celsius; // returns the value to main
}
