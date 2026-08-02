/* =========================================================================================

	Programmer:			Emaad Ilyas
	Course:				CS1A - Introduction to Computer Science 1
	Assignment:			A19 - Strings 2: Finding the Seam
	Date Written:		2026-08-01
	Date Due:			2026-08-02
	Instructor:			Dr. Jeffrey Barnett

	Purpose:				Searches a single name for the index where the last name begins
							and returns as an seam index. If none is found returns string::npos.
							The user will enter their own input for this to work, but we'll using
							the guy in the wheel chair for this one.

	Parameters:			name --- the string to search
	Returns:				size_t --- integer index of the seam
							string::npos --- if the index is not found

	Side Effects:		none

===========================================================================================*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

size_t seamFinder(string name); // prototype for the function

int main()
{

	string fullName;
	string searchText;

	cout << "Enter a run-together name: ";
	getline(cin, fullName);

	cout << "Enter text to search for: ";
	getline(cin, searchText);

	int location = seamFinder(fullName);
	string firstName = fullName.substr(0, location);
	string lastName = fullName.substr(location, fullName.length());
	string formattedName = fullName;
	formattedName = formattedName.insert(location, " ");
	size_t searchResult = formattedName.find(searchText);





	cout << endl;
	cout << "Unformatted : " << fullName << "  (" << fullName.length() << " characters)" << endl;
	cout << "Seam index  : " << location << endl;
	cout << "First name  : " << firstName << endl;
	cout << "Last name   : " << lastName << endl;
	cout << "Formatted   : " << formattedName << "  (" << formattedName.length() << " characters)" << endl;

	if (searchResult != string::npos)
	{
		cout << "Search      : " << '"' << searchText << '"' << " found at index " << searchResult << endl;
	}
	else
	{
		cout << searchText << " not found" << endl;
	}

	return 0;
}

/* Function:	Seam Finder
	Purpose:		Takes name and returns index of first uppercase letter at or after index 1
	Parameters:	name - its well the name that will be comapred.
	Return:		returns the index of first uppercase letter.
					string::npos - no uppercase letter is found
	Side Effect:none
*/
size_t seamFinder(string name)
{
	int index = 1;
	int length = name.length();

	while (index < length)
	{
		if (isupper(name[index]))
		{
			return index;
		}
		else
		{
		index++;
		}
	}
	return string::npos;
}
