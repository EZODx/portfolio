#include <iostream>

using namespace std;

void PrintFibonacciUsingRecurssion(short number, int prev1, int prev2)
{

	int febNumber = 0;

	if (number > 0)
	{
		febNumber = prev1 + prev2;
		prev2 = prev1;
		prev1 = febNumber;
		cout << febNumber << "   ";
		PrintFibonacciUsingRecurssion(number - 1, prev1, prev2);
	}

}
int main()
{

	PrintFibonacciUsingRecurssion(10, 0, 1);

	return 0;
}