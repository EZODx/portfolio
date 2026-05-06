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

void AddArrayElements(int Arr[100], int& ArrLength, int Number)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

bool IsDistinct(int Arr[10], int Arr2[10], int ArrLength, int Number)
{

	int Counter = 0;

	for (int i = 0; i < ArrLength; i++)
	{
		if (Arr[Number] == Arr2[Counter])
		{
			return false;
		}
		Counter++;
	}
	return true;
}

void CopyDistinctNumbers(int Arr[10], int Arr2[10], int ArrLength, int& Arr2Length)
{
	int Counter = 0;

	for (int i = 0; i < ArrLength; i++)
	{
		if (IsDistinct(Arr, Arr2, ArrLength, i))
		{
			AddArrayElements(Arr2, Arr2Length, Arr[i]);
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
	int Arr[10], ArrLength = 0;
	FillArray(Arr, ArrLength);

	int Arr2[100], Arr2Length = 0;
	CopyDistinctNumbers(Arr, Arr2, ArrLength, Arr2Length);

	cout << "\nArray 1 elements:\n";
	PrintArray(Arr, ArrLength);

	cout << "\nArray 2 (Distinct numbers):\n";
	PrintArray(Arr2, Arr2Length);

	return 0;
}