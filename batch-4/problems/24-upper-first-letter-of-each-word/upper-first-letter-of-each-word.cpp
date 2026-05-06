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

string UpperFirstLetterOfEachWord(string theString)
{

	bool isFirstLetter = true;

	for (int i = 0; i < theString.length(); i++)
	{
		if (theString[i] != ' ' && isFirstLetter)
		{
			theString[i] = toupper(theString[i]);
		}

		isFirstLetter = (theString[i] == ' ' ? true : false);
	}

	return theString;
}

int main()
{
	string theString = ReadString();
	cout << "\nString after conversion:\n";

	theString = UpperFirstLetterOfEachWord(theString);
	cout << theString << endl;

	return 0;
}