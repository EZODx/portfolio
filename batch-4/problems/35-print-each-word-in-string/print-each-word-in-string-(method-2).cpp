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

	string delime = " ";

	short pos = 0;
	string sWord;

	cout << "\nYour string words are:\n";

	while ((pos = theString.find(delime)) != std::string::npos)
	{

		sWord = theString.substr(0, pos);

		if (sWord != "")
		{
			cout << sWord << endl;
		}

		theString.erase(0, pos + delime.length());
	}

	if (theString != "")
	{
		cout << theString << endl;
	}

}

int main()
{

	PrintEachWordInString(ReadString());


	return 0;
}