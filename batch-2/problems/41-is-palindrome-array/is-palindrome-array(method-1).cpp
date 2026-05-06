#include <iostream>

using namespace std;

void FillArray(int Arr[100], int& ArrLength)
{
	ArrLength = 6;
	Arr[0] = 10;
	Arr[1] = 20;
	Arr[2] = 30;
	Arr[3] = 30;
	Arr[4] = 20;
	Arr[5] = 10;

}

bool IsPalindromeArray(int Arr[100], int ArrLength)
{
	string ArrayElements = "";
	string ReversedArrayElements = "";

	for (int i = 0; i < ArrLength; i++)
	{
		ArrayElements += to_string(Arr[i]);
	}

	for (int i = ArrLength -1 ; i >= 0; i--)
	{
		ReversedArrayElements += to_string(Arr[i]);
	}

	if (ArrayElements == ReversedArrayElements)
		return true;
	else
		return false;

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
	int Arr[100], ArrLength = 0;
	FillArray(Arr, ArrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(Arr, ArrLength);

	if (IsPalindromeArray(Arr, ArrLength))
		cout << "Yes, array is palindrome\n";
	else
		cout << "No, array is not palindrome\n";

	return 0;
}