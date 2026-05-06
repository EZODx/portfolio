#include <iostream>

using namespace std;

void PrintFibonacciUsingLoop(short number)
{

	int febNumber = 1;
	int prev2 = 0, prev1 = 1;
	
	for (int i = 1; i <= number; i++)
	{
		cout << febNumber << "  ";

		febNumber = prev1 + prev2;

		prev2 = prev1;
		prev1 = febNumber;
	}

}
int main()
{
	PrintFibonacciUsingLoop(10);

	return 0;
}