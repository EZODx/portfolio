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

	cout << "Please enter the number of array : ";
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

int MinNumberInArray(int Arr[100], int ArrLength)
{

	int Min = 0;
	Min = Arr[0];

	for (int i = 0; i < ArrLength; i++)
	{
		if (Arr[i] < Min)
		{
			Min = Arr[i];
		}
	}
	return Min;
}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength;

	FillArrayWithRandomNumbers(Arr, ArrLength);

	cout << "\nArray elements : ";
	PrintArray(Arr, ArrLength);

	cout << "\nThe min number in array is : ";
	cout << MinNumberInArray(Arr, ArrLength) << endl;


	return 0;
}