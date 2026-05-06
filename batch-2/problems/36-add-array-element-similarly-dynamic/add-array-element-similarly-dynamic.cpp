#include <iostream>

using namespace std;

int ReadNumber()
{
	int Number;
	cout << "\nPlease enter a number:\n";
	cin >> Number;
	return Number;
}

void AddArrayElements(int Arr[100], int& ArrLength, int Number)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

void InputUserNumbersInArray(int Arr[100], int& ArrLength)
{

	bool AddMore = true;

	do
	{
		AddArrayElements(Arr, ArrLength, ReadNumber());

		cout << "Do you want to add more elements? [0]:No, [1]:Yes : ";
		cin >> AddMore;
	}
	while (AddMore == true);
	

}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

int main()
{

	int Arr[100], ArrLength = 0;
	InputUserNumbersInArray(Arr, ArrLength);


	cout << "\nArray length: " << ArrLength;
	cout << "\nArray elements: ";
	PrintArray(Arr, ArrLength);

	return 0;
}