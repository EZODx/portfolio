#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumbers(int Array[100], int& ArrLength)
{

	cout << "Please enter the nubmer of array elements:";
	cin >> ArrLength;

	for (int i = 0; i < ArrLength; i++)
		Array[i] = RandomNumber(1, 100);
}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

short FindNumberPositionInArray(int Arr[100], int ArrLength, int Number)
{
	for (int i = 0; i < ArrLength; i++)
	{
		if (Number == Arr[i])
			return i;
	}
	return -1;
}

int ReadNumber()
{
	int Number;
	cout << "\nPlease enter a number to search for?\n";
	cin >> Number;
	return Number;
}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength;
	FillArrayWithRandomNumbers(Arr, ArrLength);

	cout << "\nArray elements:\n";
	PrintArray(Arr, ArrLength);

	int Number = ReadNumber();
	cout << "The number you are looking for is: " << Number << endl;

	short NumberPosition = FindNumberPositionInArray(Arr, ArrLength, Number);

	if (NumberPosition == -1)
		cout << "The number you are looking for is not found :-(\n";
	else
	{
		cout << "The number found at position: " << NumberPosition << endl;
		cout << "The number found its order: " << NumberPosition + 1 << endl;
	}


	return 0;
}