#include <iostream>

using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

bool IsPerfectNumber(int Number)
{
	int sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
			sum += i;
	}

	return sum == Number;
}

void PrintPerfectNumbersFrom1ToN(float Number)
{
	for (int i = 1; i <= Number; i++)
	{
		if (IsPerfectNumber(i))
			cout << i << endl;
	}
}

int main()
{
	PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number : "));

	return 0;
}