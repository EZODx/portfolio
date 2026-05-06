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

short CountWords(string theString)
{

	string delime = " ";

	short counter = 0;
	string sWord;
	short pos = 0;

	while ((pos = theString.find(delime)) != std::string::npos)
	{

		sWord = theString.substr(0, pos);

		if (sWord != "")
		{
			counter++;
		}

		theString.erase(0, pos + delime.length());

	}

	if (theString != "")
	{
		counter++;
	}

	return counter;
}

int main()
{

	string theString = ReadString();

	cout << "\nThe number in your string is: " << CountWords(theString) << endl;


	return 0;
}