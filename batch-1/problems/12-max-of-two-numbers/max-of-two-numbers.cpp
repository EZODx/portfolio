#include <iostream>

using namespace std;

void ReadNumbers(int& Num1, int& Num2)
{
	cout << "Please enter number 1 : " << endl;
	cin >> Num1;
	cout << "Please enter number 2 : " << endl;
	cin >> Num2;
}

int MaxOf2Nums(int num1, int num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;
}

void PrintMaxOf2Nums(int MaxNumber)
{
	cout << "The maximum of the numbers is : " << MaxNumber;
}

int main()
{
	int Num1, Num2;
	ReadNumbers(Num1, Num2);
	PrintMaxOf2Nums(MaxOf2Nums(Num1, Num2));

	return 0;
}