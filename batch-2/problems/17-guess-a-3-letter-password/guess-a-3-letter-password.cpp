#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

string ReadPassword()
{
	string Password;

	cout << "Please enter a 3-Letter Password (all capital) : \n";
	cin >> Password;

	return Password;
}


bool GuessPassword(string OriginalPassword)
{
	cout << "\n";
	string word = "";
	int Counter = 0;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);

				Counter++;

				cout << "Trial [" << Counter << "] : " << word << endl;

				if (word == OriginalPassword)
				{
					cout << "\nPassword is (" << OriginalPassword << ")\n";
					cout << "found after (" << Counter << ") trial(s)." << endl;
					return true;
				}
				word = "";
			}
		}
		cout << "\n__________________________________\n";
	}
	return false;
}

int main()
{
	GuessPassword(ReadPassword());

	return 0;
}