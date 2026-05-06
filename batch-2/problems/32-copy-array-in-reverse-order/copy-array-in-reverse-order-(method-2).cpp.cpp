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

	cout << "Please enter the number of array elements : ";
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

void CopyArrayInReverseOrder(int ArrSource[100],int ArrDestination[100], int ArrLength)
{

	for (int i = 0; i < ArrLength; i++)
		ArrDestination[i] = ArrSource[ArrLength - 1 - i];

}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Arr[100], Arr2[100], ArrLength;

	FillArrayWithRandomNumbers(Arr, ArrLength);


	CopyArrayInReverseOrder(Arr, Arr2, ArrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(Arr, ArrLength);

	cout << "\nArray 2 elements after copy:\n";
	PrintArray(Arr2, ArrLength);

	return 0;
}