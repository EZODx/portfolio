#include <iostream>
#include <string>

using namespace std;

string ReplaceWordsInString(string str, string stringToReplace, string replaceTo)
{

	short pos = str.find(stringToReplace);

	while (pos != std::string::npos)
	{

		str = str.replace(pos, stringToReplace.length(), replaceTo);
		pos = str.find(stringToReplace);

	}


	return str;
}

int main()
{

	string str = "Welcome to Norway , Norway is a nice country";
	string stringToReplace = "Norway";
	string replaceTo = "Kurdistan";


	cout << "Original string:\n" << str << endl;
	cout << "\nThe string after replacing the words:\n";
	cout << ReplaceWordsInString(str, stringToReplace, replaceTo) << endl;


	return 0;
}