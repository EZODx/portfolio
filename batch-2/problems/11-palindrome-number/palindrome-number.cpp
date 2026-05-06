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

int ReverseNumber(int Number)
{
	int Reminder = 0, Number2 = 0;

	while (Number > 0)
	{
		Reminder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Reminder;
	}
	return Number2;
}

bool IsPalindromeNumber(int Number)
{
	return Number == ReverseNumber(Number);
}

int main()
{
	if (IsPalindromeNumber(ReadPositiveNumber("Please enter a number : ")))
		cout << "Yes, It's a palindrome number" << endl;
	else
		cout << "No, It's not a palindrome number" << endl;


	return 0;
}