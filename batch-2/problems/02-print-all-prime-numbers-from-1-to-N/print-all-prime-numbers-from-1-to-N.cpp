#include <iostream>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrim = 2 };

float ReadPositiveNumber(string Message)
{
	float Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);

	return Number;
}

enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimeNotPrime::NotPrim;
	}
	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumbersFrom1ToN(float Number)
{

	cout << "\nPrime numbers from " << 1 << " to " << Number;
	cout << " are : " << endl;

	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
			cout << i << endl;
	}
}

int main()
{
	PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number : "));

	return 0;
}