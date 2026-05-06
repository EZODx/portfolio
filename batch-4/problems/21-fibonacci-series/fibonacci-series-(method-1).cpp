#include <iostream>

using namespace std;

void PrintFibonacciSeriesUsingLoop(int num)
{

	int prev1 = 1, prev2 = 1;

	for (int i = 1; i <= num; i++)
	{

		cout << prev1 << "  ";

		prev2 = prev1 - prev2;

		prev1 = prev2 + prev1;

	}

	cout << endl;
}

int main()
{

	PrintFibonacciSeriesUsingLoop(10);


	return 0;
}