#include <iostream>
#include <string>

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

int SumOfDigits(int Number)
{
	int Reminder = 0, sum = 0;

	while (Number > 0)
	{
		Reminder = Number % 10;
		Number = Number / 10;
		sum += Reminder;
	}
	return sum;
}

int main()
{
	cout << "Sum of digits = "
		<< SumOfDigits(ReadPositiveNumber("Please enter a positive number : "))
		<< endl;

	return 0;
}