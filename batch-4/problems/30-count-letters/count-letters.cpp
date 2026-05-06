#include <iostream>
#include <string>

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

short CountLetter(string theString, char theChar)
{

	short counter = 0;

	for (int i = 0; i < theString.length(); i++)
	{
		if (theString[i] == theChar)
			counter++;
	}

	return counter;
}

int main()
{
	
	string theString = ReadString();
	char theChar = ReadChar();

	cout << "\nThe letter '" << theChar << "' count = "
		<< CountLetter(theString, theChar) << endl;


	return 0;
}