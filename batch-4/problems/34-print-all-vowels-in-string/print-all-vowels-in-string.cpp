#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string theString;
	cout << "Please enter your string : \n";
	getline(cin, theString);

	return theString;
}

bool IsVowel(char theChar)
{

	theChar = tolower(theChar);

	return ((theChar == 'a') || (theChar == 'e') || (theChar == 'i') || (theChar == 'o') || (theChar == 'u'));

}

void PrintVowels(string theString)
{

	cout << "\nThe Vowels in the string are: ";

	for (int i = 0; i < theString.length(); i++)
	{

		if (IsVowel(theString[i]))
			cout << theString[i] << "  ";

	}

	cout << endl;
}

int main()
{
	
	string theString = ReadString();

	PrintVowels(theString);


	return 0;
}