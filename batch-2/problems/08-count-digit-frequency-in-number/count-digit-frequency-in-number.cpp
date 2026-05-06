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

int CountDigitFrequency(int Number, short DigitToCheck)
{
	int Reminder = 0, FreqCount = 0;

	while (Number > 0)
	{
		Reminder = Number % 10;
		Number = Number / 10;
		if (Reminder == DigitToCheck)
		{
			FreqCount++;
		}
	}
	return FreqCount;
}

int main()
{
	int MainNumber = ReadPositiveNumber("Please enter the main number : ");
	short DigitToCheck = ReadPositiveNumber("Please enter one digit to check : ");

	cout << "\nDigit \n" << DigitToCheck << " Frequency is "
		 << CountDigitFrequency(MainNumber, DigitToCheck)
	     << " Time(s)" << endl;

	return 0;
}