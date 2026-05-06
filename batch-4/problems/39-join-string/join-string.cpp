#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(vector <string> vString, string delim)
{

	string str = "";

	for (string& s : vString)
	{
		str += s + delim;
	}

	return str.substr(0, str.length() - delim.length());
}

int main()
{

	vector <string> vString = { "EZOD", "Sara", "Jude", "Finn" };


	cout << "Vector after join:\n";
	cout << JoinString(vString, " ") << endl;


	return 0;
}