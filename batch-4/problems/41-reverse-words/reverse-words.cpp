#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

string ReverseWordsInString(string str)
{


	vector <string> vString;
	string str2 = "";

	vString = SplitString(str, " ");

	vector <string>::iterator iter = vString.end();

	while (iter != vString.begin())
	{

		--iter;

		str2 += *iter + " ";

	}

	str2 = str2.substr(0, str2.length() - 1);


	return str2;
}

int main()
{

	string str = "Hi I'm EZOD";

	cout << "The string after reversing words:\n" << ReverseWordsInString(str) << endl;


	return 0;
}