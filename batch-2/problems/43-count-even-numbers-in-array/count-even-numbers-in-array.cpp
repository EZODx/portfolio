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

	cout << "Please enter the number of array elements: ";
	cin >> ArrLength;

	for (int i = 0; i < ArrLength; i++)
		Array[i] = RandomNumber(1, 100);
}

int EvenCount(int Arr[100], int ArrLength)
{

	int Counter = 0;

	for (int i = 0; i < ArrLength; i++)
	{
		if (Arr[i] % 2 == 0)
		{
			Counter++;
		}
	}

	return Counter;
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

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength;
	FillArrayWithRandomNumbers(Arr, ArrLength);


	cout << "\nArray elements:\n";
	PrintArray(Arr, ArrLength);

	cout << "Even numbers count is: ";
	cout << EvenCount(Arr, ArrLength) << endl;

	return 0;
}