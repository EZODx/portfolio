#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string theString;
	cout << "Please enter your string : \n";
	getline(cin, theString);

	return theString;
}

void PrintEachWordInString(string theString)
{

	bool isLetter = true;


	cout << "\nYour string words are:\n";

	for (int i = 0; i < theString.length(); i++)
	{
		isLetter = (theString[i] != ' ' ? true : false);

		if (isLetter)
		{
			cout << theString[i];
		}
		else
			cout << endl;

	}

	cout << endl;
}

int main()
{

	PrintEachWordInString(ReadString());


	return 0;
}