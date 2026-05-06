#include <iostream>

using namespace std;

void ReadNumbers(int& Num1, int& Num2, int& Num3)
{
	cout << "Please enter number 1 : " << endl;
	cin >> Num1;
	cout << "Please enter number 2 : " << endl;
	cin >> Num2;
	cout << "Please enter number 3 : " << endl;
	cin >> Num3;
}

int MaxOf3Nums(int num1, int num2, int num3)
{
	if (num1 > num2)
		if (num1 > num3)
			return num1;
		else
			return num3;

	else
		if (num2 > num3)
			return num2;
		else
			return num3;
}

void PrintMaxOf3Nums(int MaxNumber)
{
	cout << "The maximum of the numbers is : " << MaxNumber;
}

int main()
{
	int Num1, Num2, Num3;
	ReadNumbers(Num1, Num2, Num3);
	PrintMaxOf3Nums(MaxOf3Nums(Num1, Num2 , Num3));

	return 0;
}