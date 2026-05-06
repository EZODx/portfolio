#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char ReadChar()
{
	char theChar;
	cout << "Please enter a character:\n";
	cin >> theChar;

	return theChar;
}

char InvertLetterCase(char theChar)
{
	return isupper(theChar) ? tolower(theChar) : toupper(theChar);
}

int main()
{

	char theChar = ReadChar();

	theChar = InvertLetterCase(theChar);
	cout << "\nChar after inverting case:\n";
	cout << theChar << endl;

	return 0;
}