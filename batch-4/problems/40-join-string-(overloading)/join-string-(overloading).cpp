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

string JoinString(string arrString[], int arrLength, string delim)
{

	string str = "";

	for (int i = 0; i < arrLength; i++)
	{
		str += arrString[i] + delim;
	}

	return str.substr(0, str.length() - delim.length());
}

int main()
{

	vector <string> vString = { "EZOD", "Sara", "Jude", "Finn" };
	string arrString[] = { "EZOD", "Sara", "Jude", "Finn" };

	cout << "Vector after join:\n";
	cout << JoinString(vString, " ") << endl;

	cout << "\nArray after join:\n";
	cout << JoinString(arrString, 4, " ") << endl;

	return 0;
}