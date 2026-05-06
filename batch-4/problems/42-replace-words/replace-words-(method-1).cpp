#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> SplitString(string theString, string delim)
{


	vector <string> vString;

	string sWord;

	short pos = 0;

	while ((pos = theString.find(delim)) != std::string::npos)
	{

		sWord = theString.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		theString.erase(0, pos + delim.length());

	}

	if (theString != "")
	{
		vString.push_back(theString);
	}

	return vString;
}

string ReplaceWordsInString(string str, string word1, string word2)
{

	vector <string> vString;
	string str2 = "";

	vString = SplitString(str, " ");

	vector <string>::iterator iter = vString.begin();

	while (iter != vString.end())
	{

		if (*iter != word1)
			str2 += *iter + " ";
		else
			str2 += word2 + " ";

		iter++;

	}

	str2 = str2.substr(0, str2.length() - 1);


	return str2;

}

int main()
{

	string str = "Welcome to Norway , Norway is a nice country";

	cout << "Original string:\n" << str << endl;


	cout << "\nThe string after replace words:\n" << ReplaceWordsInString(str, "Norway", "Kurdistan") << endl;


	return 0;
}