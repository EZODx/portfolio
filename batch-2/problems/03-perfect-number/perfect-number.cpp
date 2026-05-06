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

void PrintResult(float Number)
{
	if (IsPerfectNumber(Number))
		cout << Number << " is a perfect number\n" << endl;
	else
		cout << Number << "is not a perfect number\n" << endl;
}

int main()
{
	PrintResult(ReadPositiveNumber("Please enter a positive number : "));

	return 0;
}