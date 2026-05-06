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

char ReadChar()
{
	char theChar;
	cout << "\nPlease enter a character: \n";
	cin >> theChar;

	return theChar;
}

char InvertLetterCase(char theChar)
{
	return isupper(theChar) ? tolower(theChar) : toupper(theChar);
}

short CountLetter(string theString, char theChar, bool matchCase = true)
{

	short counter = 0;

	for (int i = 0; i < theString.length(); i++)
	{

		if (matchCase)
		{
			if (theString[i] == theChar)
				counter++;
		}
		else
		{
			if (tolower(theString[i]) == tolower(theChar))
			{
				counter++;
			}
		}

	}

	return counter;
}

int main()
{
	
	string theString = ReadString();
	char theChar = ReadChar();

	cout << "\nThe letter '" << theChar << "' count = "
		<< CountLetter(theString, theChar) << endl;

	cout << "\nThe letter '" << theChar << "' or '" << InvertLetterCase(theChar)
		<< "' count = " << CountLetter(theString, theChar, false) << endl;


	return 0;
}