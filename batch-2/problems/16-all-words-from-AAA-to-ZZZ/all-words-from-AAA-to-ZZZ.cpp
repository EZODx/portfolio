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

void PrintLettersFromAAAToZZZ()
{
	cout << "\n";
	string word = "";

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);

				cout << word << endl;

				word = "";
			}
		}
		cout << "\n__________________________________\n";
	}
}

int main()
{
	PrintLettersFromAAAToZZZ();

	return 0;
}