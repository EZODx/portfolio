#include <iostream>

using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

enPrimNotPrime CheckPrime(int Number)
{

	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimNotPrime::NotPrime;
	}

	return enPrimNotPrime::Prime;
}

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

void CopyOnlyPrimeNumbersInArray(int ArrSource[100], int ArrDestination[100], int ArrLength, int& Arr2Length)
{
	int Counter = 0;

	for (int i = 0; i < ArrLength; i++)
	{
		if (CheckPrime(ArrSource[i]) == enPrimNotPrime::Prime)
		{
			ArrDestination[Counter] = ArrSource[i];

			Counter++;
		}
	}
	Arr2Length = Counter;
}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength;

	FillArrayWithRandomNumbers(Arr, ArrLength);

	int Arr2[100], Arr2Length = 0;

	CopyOnlyPrimeNumbersInArray(Arr, Arr2, ArrLength, Arr2Length);

	cout << "\nArray 1 elements : ";
	PrintArray(Arr, ArrLength);

	cout << "\nArray 2 (Prime numberes in array 1) : ";
	PrintArray(Arr2, Arr2Length);

	return 0;
}