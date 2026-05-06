#include <iostream>

using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Please enter the number : " << endl;
	cin >> Number;

	return Number;
}

void PrintRangeFrom1ToN_UsingWhile(int N)
{
	cout << "Range printed using While statement : " << endl;

	int Counter = 1;

	while (Counter <= N)
	{
		cout << Counter << endl;
		Counter++;
	}
}

void PrintRangeFrom1ToN_UsingDoWhile(int N)
{
	cout << "Range printed using Do while statement : " << endl;

	int Counter = 1;

	do
	{
		cout << Counter << endl;
		Counter++;
	} while (Counter <= N);
}

void PrintRangeFrom1ToN_UsingFor(int N)
{
	cout << "Range printed using For statement : " << endl;

	for (int Counter = 1; Counter <= N; Counter++)
	{
		cout << Counter << endl;
	}
}
int main()
{
	int N = ReadNumber();

	PrintRangeFrom1ToN_UsingWhile(N);
	PrintRangeFrom1ToN_UsingDoWhile(N);
	PrintRangeFrom1ToN_UsingFor(N);

	return 0;
}