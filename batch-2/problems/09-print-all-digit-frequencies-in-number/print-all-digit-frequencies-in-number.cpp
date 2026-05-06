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

int CountDigitFrequency(short DigitToCheck, int Number)
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

void PrintAllDigitsFrequencey(int Number)
{
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		short DigitFrequency;
		DigitFrequency = CountDigitFrequency(i, Number);

		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequency is : "
			     << DigitFrequency << " Time(s).\n";
		}
	}

}

int main()
{
	int Number = ReadPositiveNumber("Please enter a number : ");

	PrintAllDigitsFrequencey(Number);

	return 0;
}