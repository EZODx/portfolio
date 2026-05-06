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

void ReadArray(int Arr[100], int& ArrLength)
{
	cout << "Please enter the number of array : ";
	cin >> ArrLength;

	cout << "\nPlease enter the array's elements : " << endl;

	for (int i = 0; i < ArrLength; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> Arr[i];
	}
	cout << endl;
}

void PrintArray(int Arr[100], int ArrLength, int)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

int TimesRepeated(int Arr[100], int ArrLength, int NumberToCheck)
{
	int Counter = 0;
	for (int i = 0; i < ArrLength; i++)
	{
		if (NumberToCheck == Arr[i])
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	int Arr[100], ArrLength, NumberToCheck;

	ReadArray(Arr, ArrLength);


	NumberToCheck = ReadPositiveNumber("Enter the number you want to check : ");

	cout << "\nThe Original array : ";
	PrintArray(Arr, ArrLength, NumberToCheck);

	cout << "The Number " << NumberToCheck;
	cout << " is repeated ";
	cout << TimesRepeated(Arr, ArrLength, NumberToCheck) << " time(s)." << endl;

	return 0;
}