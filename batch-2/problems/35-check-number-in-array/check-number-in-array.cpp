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

	cout << "Please enter the nubmer of array elements:";
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

short FindNumberPositionInArray(int Arr[100], int ArrLength, int Number)
{
	for (int i = 0; i < ArrLength; i++)
	{
		if (Number == Arr[i])
			return i;
	}
	return -1;
}

int ReadNumber()
{
	int Number;
	cout << "\nPlease enter a number to search for?\n";
	cin >> Number;
	return Number;
}

bool IsNumberInArray(int Arr[100], int ArrLength, int Number)
{

	return(FindNumberPositionInArray(Arr, ArrLength, Number) != -1);

}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength;
	FillArrayWithRandomNumbers(Arr, ArrLength);

	cout << "\nArray elements:\n";
	PrintArray(Arr, ArrLength);

	int Number = ReadNumber();
	cout << "The number you are looking for is: " << Number << endl;


	if (!IsNumberInArray(Arr, ArrLength, Number))
		cout << "No, The number is not found :-(\n";
	else
	{
		cout << "Yes, The number is found :-)\n";
	}


	return 0;
}