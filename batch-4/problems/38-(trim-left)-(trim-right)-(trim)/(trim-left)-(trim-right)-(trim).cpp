#include <iostream>
#include <string>

using namespace std;

string TrimLeft(string str)
{

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			return str.substr(i, str.length() - 1);
		}
	}
	return "";
}

string TrimRight(string str)
{

	for (int i = str.length() -1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			return str.substr(0, i + 1);
		}
	}
	return "";
}

string Trim(string str)
{

	return TrimLeft(TrimRight(str));

}

int main()
{

	string str = "    EZOD    ";

	cout << "\nstrign     = " << str;
	cout << "\n\nTrim left  = " << TrimLeft(str) << endl;
	cout << "\nTrim Right = " << TrimRight(str) << endl;
	cout << "\nTrim       = " << Trim(str) << endl;


	return 0;
}