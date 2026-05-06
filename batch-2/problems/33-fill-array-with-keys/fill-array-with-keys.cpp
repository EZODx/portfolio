#include <iostream>

using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
	{
		return char(RandomNumber(97, 122));
		break;
	}
	case enCharType::CapitalLetter:
	{
		return char(RandomNumber(65, 90));
		break;
	}
	case enCharType::SpecialCharacter:
	{
		return char(RandomNumber(33, 47));
		break;
	}
	case enCharType::Digit:
	{
		return char(RandomNumber(48, 57));
		break;
	}
	}
}

string GenerateWord(enCharType CharType, short Length)
{
	string Word = "";

	for (int i = 1; i <= Length; i++)
	{
		Word += GetRandomCharacter(CharType);
	}
	return Word;
}

string GenerateKey()
{
	string Key;

	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4);

	return Key;
}

void PrintStringArray(string Arr[100], int ArrLength)
{

	cout << "\nArray elements:\n\n";

	for (int i = 0; i < ArrLength; i++)
	{
		cout << "Arr[" << i << "] : ";
		cout << Arr[i] << "\n";
	}
	cout << "\n";
}

void FillArrayWithKeys(string Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		Arr[i] = GenerateKey();
	}
}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	string Arr[100];
	int ArrLength = 0;

	int ArrLength = ReadPositiveNumber("How many keys do you want to generate?:");

	FillArrayWithKeys(Arr, ArrLength);

	PrintStringArray(Arr, ArrLength);

	return 0;
}