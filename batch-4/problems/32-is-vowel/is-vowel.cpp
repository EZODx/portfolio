#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char ReadChar()
{
	char theChar;
	cout << "Please enter a character: \n";
	cin >> theChar;

	return theChar;
}

bool IsVowel(char theChar)
{

	theChar = tolower(theChar);

	return ((theChar == 'a') || (theChar == 'e') || (theChar == 'i') || (theChar == 'o') || (theChar == 'u'));

}

int main()
{
	
	char theChar = ReadChar();

	if (IsVowel)
		cout << "Yes, the letter "<< theChar << "is a vowel\n";
	else
		cout << "No, the letter "<< theChar << "is NOT a vowel\n";


	return 0;
}