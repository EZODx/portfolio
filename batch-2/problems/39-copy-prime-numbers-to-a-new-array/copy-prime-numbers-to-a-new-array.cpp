#include <iostream>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrim = 2 };

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimeNotPrime::NotPrim;
	}
	return enPrimeNotPrime::Prime;
}

void FillArrayWithRandomNumbers(int Array[100], int& ArrLength)
{

	cout << "Please enter the number of array elements : ";
	cin >> ArrLength;

	for (int i = 0; i < ArrLength; i++)
		Array[i] = RandomNumber(1, 100);

}

void AddArrayElements(int Arr[100], int& ArrLength, int Number)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int ArrLength, int& arrDestinationLength)
{

	for (int i = 0; i < ArrLength; i++)
		if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
		{
			AddArrayElements(arrDestination, arrDestinationLength, arrSource[i]);
		}
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

	int Arr[100], ArrLength = 0;
	FillArrayWithRandomNumbers(Arr, ArrLength);

	int Arr2[100], Arr2Length = 0;
	CopyPrimeNumbers(Arr, Arr2, ArrLength, Arr2Length);

	cout << "\nArray 1 elements:\n";
	PrintArray(Arr, ArrLength);

	cout << "\nArray 2 (Prime numbers):\n";
	PrintArray(Arr2, Arr2Length);

	return 0;
}