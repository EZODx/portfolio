#include <iostream>

using namespace std;

enum enNumberType { Odd = 1, Even = 2 };

int ReadNumber()
{
	int num;

	cout << "Please enter the number: ";
	cin >> num;

	return num;
}

enNumberType NumberType(int Num )
{
	int result = Num % 2;

	if (result == 0)
	{
		return enNumberType::Even;
	}
	else
	{
		return enNumberType::Odd;
	}
}

void PrintNumber(enNumberType Num)
{
	if (Num == enNumberType::Even)
	{
		cout << "The number is Even." << endl;
	}
	else
	{
		cout << "The number is Odd." << endl;
	}
}

int main()
{

	PrintNumber(NumberType(ReadNumber()));


	return 0;
}