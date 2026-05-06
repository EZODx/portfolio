#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string theString;
	cout << "Please enter your string : \n";
	getline(cin, theString);

	return theString;
}

vector <string> SplitString(string theString, string delime)
{


	vector <string> vString;

	string sWord;

	short pos = 0;

	while ((pos = theString.find(delime)) != std::string::npos)
	{

		sWord = theString.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		theString.erase(0, pos + delime.length());

	}

	if (theString != "")
	{
		vString.push_back(theString);
	}

	return vString;
}

int main()
{

	vector <string> vString;

	vString = SplitString(ReadString(), " ");


	cout << "\nTokens = " << vString.size() << endl;

	for (string& s : vString)
	{
		cout << s << endl;
	}


	return 0;
}