#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string theString;
	cout << "Please enter your string:\n";
	getline(cin, theString);

	return theString;
}

string UpperAllString(string theString)
{

	for (int i = 0; i < theString.length(); i++)
	{
		theString[i] = tolower(theString[i]);
	}
	return theString;
}

string LowerAllString(string theString)
{

	for (int i = 0; i < theString.length(); i++)
	{
		theString[i] = toupper(theString[i]);
	}
	return theString;
}

int main()
{
	string theString = ReadString();


	theString = LowerAllString(theString);
	cout << "\nString after upper:\n";
	cout << theString << endl;

	theString = UpperAllString(theString);
	cout << "\nString after lower:\n";
	cout << theString << endl;

	return 0;
}