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

char InvertLettersCase(char theChar)
{
	return isupper(theChar) ? tolower(theChar) : toupper(theChar);
}

string InvertAllStringLettersCase(string theString)
{
	for (int i = 0; i < theString.length(); i++)
	{
		theString[i] = InvertLettersCase(theString[i]);
	}
	return theString;
}

int main()
{

	string theString = ReadString();

	theString = InvertAllStringLettersCase(theString);
	cout << "\nString after inverting all letters case:\n";
	cout << theString << endl;

	return 0;
}