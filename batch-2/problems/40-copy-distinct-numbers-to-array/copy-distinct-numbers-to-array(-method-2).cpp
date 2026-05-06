#include <iostream>

using namespace std;

void FillArray(int Arr[100], int& ArrLength)
{
	ArrLength = 10;
	Arr[0] = 10;
	Arr[1] = 10;
	Arr[2] = 10;
	Arr[3] = 50;
	Arr[4] = 50;
	Arr[5] = 70;
	Arr[6] = 70;
	Arr[7] = 70;
	Arr[8] = 70;
	Arr[9] = 90;

}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;
	}
	return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
	return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

void AddArrayElements(int Arr[100], int& ArrLength, int Number)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

void CopyDistinctNumbersToArray(int ArrSource[100], int ArrDestination[100], int SourceLength, int& DestinationLength)
{

	for (int i = 0; i < SourceLength; i++)
	{
		if (!IsNumberInArray(ArrSource[i], ArrDestination, DestinationLength))
		{
			AddArrayElements(ArrDestination, DestinationLength, ArrSource[i]);
		}
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
	int Arr[100], Arr2[100], ArrLength = 0, Arr2Length = 0;
	FillArray(Arr, ArrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(Arr, ArrLength);

	CopyDistinctNumbersToArray(Arr, Arr2, ArrLength, Arr2Length);

	cout << "\nArray 2 (Distinct numbers):\n";
	PrintArray(Arr2, Arr2Length);

	return 0;
}