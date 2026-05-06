#include <iostream>

using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Please enter the number : " << endl;
	cin >> Number;

	return Number;
}

void PrintRangeFromNTo1_UsingWhile(int N)
{
	cout << "Range printed using While statement : " << endl;

	int Counter = N;

	while (Counter >= 1)
	{
		cout << Counter << endl;
		Counter--;
	}
}

void PrintRangeFromNTo1_UsingDoWhile(int N)
{
	cout << "Range printed using Do while statement : " << endl;

	int Counter = N;

	do
	{
		cout << Counter << endl;
		Counter--;
	} while (Counter >= 1);
}

void PrintRangeFromNTo1_UsingFor(int N)
{
	cout << "Range printed using For statement : " << endl;

	for (int Counter = N; Counter >= 1; Counter--)
	{
		cout << Counter << endl;
	}
}
int main()
{
	int N = ReadNumber();

	PrintRangeFromNTo1_UsingWhile(N);
	PrintRangeFromNTo1_UsingDoWhile(N);
	PrintRangeFromNTo1_UsingFor(N);

	return 0;
}