#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum enWhatToCount { CapitalLetters = 0, SmallLetters = 1, All = 2 };

string ReadString()
{
	string theString;
	cout << "Please enter your string:\n";
	getline(cin, theString);

	return theString;
}

short CountLetters(string theString, enWhatToCount whatToCount = enWhatToCount::All)
{

	if (whatToCount == enWhatToCount::All)
	{
		return theString.length();
	}

	short counter = 0;

	for (int i = 0; i < theString.length(); i++)
	{

		if (islower(theString[i]) && whatToCount == enWhatToCount::SmallLetters)
			counter++;
		else if (isupper(theString[i]) && whatToCount == enWhatToCount::CapitalLetters)
			counter++;

	}

	return counter;
}

short SmallLettersCoutn(string theString)
{
	short counter = 0;

	for (int i = 0; i < theString.length(); i++)
	{
		if (islower(theString[i]))
			counter++;
	}
	return counter;
}

short CapitalLettersCount(string theString)
{
	short counter = 0;

	for (int i = 0; i < theString.length(); i++)
	{
		if (isupper(theString[i]))
			counter++;
	}
	return counter;
}

int main()
{
	
	string theString = ReadString();

	cout << "\nMethod 1:\n";
	cout << "\nString length : " << theString.length();
	cout << "\nCapital letters cout " << CapitalLettersCount(theString);
	cout << "\nSmall letters cout " << SmallLettersCoutn(theString);

	cout << "\n\nMethod 2:\n";
	cout << "\nString length : " << CountLetters(theString);
	cout << "\nCapital letters cout " << CountLetters(theString, enWhatToCount::CapitalLetters);
	cout << "\nSmall letters cout " << CountLetters(theString, enWhatToCount::SmallLetters) << endl;


	return 0;
}