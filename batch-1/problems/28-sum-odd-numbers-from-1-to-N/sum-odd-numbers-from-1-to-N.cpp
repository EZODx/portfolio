#include <iostream>

using namespace std;

enum enOddOrEven{Odd = 1, Even = 2};

int ReadNumber()
{
	int Number;
	cout << "Please enter the number : " << endl;
	cin >> Number;

	return Number;
}

enOddOrEven CheckOddorEven(int Number)
{
	if (Number % 2 != 0)
		return enOddOrEven::Odd;
	else
		return enOddOrEven::Even;
}

int SumOddNumbersFrom1ToN_UsingWhile(int N)
{
	cout << "Sum odd numbers using For statement : " << endl;

	int sum = 0;
	int Counter = 1;

	while (Counter <= N)
	{
		if (CheckOddorEven(Counter) == enOddOrEven::Odd)
		{
			sum += Counter;

		}

		Counter++;
	}

	return sum;
}

int SumOddNumbersFrom1ToN_UsingDoWhile(int N)
{
	cout << "Sum odd numbers using For statement : " << endl;

	int sum = 0;
	int Counter = 1;

	do
	{
		if (CheckOddorEven(Counter) == enOddOrEven::Odd)
		{
			sum += Counter;
		}

		Counter++;
	}
	while (Counter <= N);

	return sum;
}

int SumOddNumbersFrom1ToN_UsingFor(int N)
{
	cout << "Sum odd numbers using For statement : " << endl;
	int sum = 0;

	for (int Counter = 1; Counter <= N; Counter++)
	{
		if (CheckOddorEven(Counter) == enOddOrEven::Odd)
		sum += Counter;
	}

	return sum;
}
int main()
{
	int N = ReadNumber();

	cout << SumOddNumbersFrom1ToN_UsingWhile(N) << endl;
	cout << SumOddNumbersFrom1ToN_UsingDoWhile(N) << endl;
	cout << SumOddNumbersFrom1ToN_UsingFor(N) << endl;

	return 0;
}