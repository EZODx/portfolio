#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

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

void SwapNumbers(int& A, int& B)
{
	int Temp;
	Temp = A;
	A = B;
	B = Temp;
}

void FillArrayWith1ToN(int Array[100], int& ArrLength)
{

	for (int i = 0; i < ArrLength; i++)
		Array[i] = i + 1;

}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

void ShuffleArrayElements(int Arr[100], int ArrLength)
{

	for (int i = 0; i < ArrLength; i++)
	{
		SwapNumbers(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
	}
}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength = ReadPositiveNumber("Enter number of elements : ");

	FillArrayWith1ToN(Arr, ArrLength);

	cout << "\nArray elements before shuffling: \n";
	PrintArray(Arr, ArrLength);

	ShuffleArrayElements(Arr, ArrLength);

	cout << "\nArray elements after shuffling: \n";
	PrintArray(Arr, ArrLength);

	return 0;
}