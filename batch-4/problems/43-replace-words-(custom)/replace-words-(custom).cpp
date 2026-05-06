#include <iostream>
#include <string>
#include <vector>

using namespace std;

string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

string JoinString(vector<string> vString, string Delim)
{
	string S1;
	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
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

string ReplaceWordsInString(string str, string stringToReplace, string replaceTo, bool matchCase = true)
{

	vector <string> vString;

	vString = SplitString(str, " ");


	for (string& s : vString)
	{

		if (matchCase)
		{
			if (s == stringToReplace)
				s = replaceTo;
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(stringToReplace))
			{
				s = replaceTo;
			}
		}

	}

	return JoinString(vString, " ");

}

int main()
{

	string str = "Welcome to Norway , Norway is a nice country";
	string stringToReplace = "Norway";
	string replaceTo = "Kurdistan";

	cout << "Original string:\n" << str << endl;

	cout << "\nReplace with match case:\n";
	cout << ReplaceWordsInString(str, stringToReplace, replaceTo) << endl;

	cout << "\nReplace without match case:\n";
	cout << ReplaceWordsInString(str, stringToReplace, replaceTo, false) << endl;


	return 0;
}