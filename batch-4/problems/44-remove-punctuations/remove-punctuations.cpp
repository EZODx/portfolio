#include <iostream>
#include <string>

using namespace std;

string RemovePunctuationsFromString(string str)
{

	string str2 = "";

	for (int i = 0; i < str.length(); i++)
	{
		if (!ispunct(str[i]))
		{
			str2 += str[i];
		}
	}

	return str2;
}

int main()
{

	string str = "Welcome to Kurdistan , Kurdistan is a nice country.";

	cout << "The original string:\n" << str << endl;

	cout << "\nThe string after removing punctuations:\n";
	cout << RemovePunctuationsFromString(str) << endl;

	return 0;
}