#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter the number: " << endl;
	cin >> Number;
	return Number;
}

float CalculateHalf(int Number)
{
	return (float)Number / 2;
}

void PrintHalfOfNumber(int Number)
{
	string Result = "The half of: " + to_string(Number) + " is : " + to_string(CalculateHalf(Number));
	cout << Result << endl;
}

int main()
{

	PrintHalfOfNumber(ReadNumber());

	return 0;
}