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

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumbers(int Array[100], int ArrLength)
{

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

void SumOf2Arrays(int Arr1[100], int Arr2[100],int Arr3[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		Arr3[i] = Arr1[i] + Arr2[i];
	}
}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Arr[100], Arr2[100], Arr3[100];

	int ArrLength = ReadPositiveNumber("Please enter the number of elements : ");

	FillArrayWithRandomNumbers(Arr, ArrLength);
	FillArrayWithRandomNumbers(Arr2, ArrLength);


	SumOf2Arrays(Arr, Arr2, Arr3, ArrLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(Arr, ArrLength);

	cout << "\nArray 2 elements : \n";
	PrintArray(Arr2, ArrLength);

	cout << "\nSum of array 1 and array 2 elements : \n";
	PrintArray(Arr3, ArrLength);

	return 0;
}