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

short CountVowels(string theString)
{
	short counter = 0;

	for (int i = 0; i < theString.length(); i++)
	{
		if (IsVowel(theString[i]))
			counter++;
	}

	return counter;
}

int main()
{
	
	string theString = ReadString();

	cout << "\nThe number of vowels is : " << CountVowels(theString) << endl;


	return 0;
}