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
	}
	while (Number <= 0);

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

void PrintNumberType(int Number)
{
	switch (CheckPrime(Number))
	{
	case enPrimeNotPrime::Prime:
		cout << "Prime number";
		break;
	case enPrimeNotPrime::NotPrim:
		cout << "Not prime number";
		break;
	}

}

int main()
{

	PrintNumberType(ReadPositiveNumber("Please enter a positive number : "));
	return 0;
}