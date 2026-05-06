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

void PrintFirstLetterOfEachWord(string theString)
{

	bool IsFirstLetter = true;

	cout << "\nFirst letters of this string:\n";

	for (int i = 0; i < theString.length(); i++)
	{

		if (theString[i] != ' ' && IsFirstLetter)
		{
			cout << theString[i] << endl;
		}

		IsFirstLetter = (theString[i] == ' ' ? true : false);
	}

}

int main()
{

	PrintFirstLetterOfEachWord(ReadString());

	return 0;
}