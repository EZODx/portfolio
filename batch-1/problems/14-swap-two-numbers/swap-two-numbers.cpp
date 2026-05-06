#include <iostream>

using namespace std;

void ReadNumbers(int& Num1, int& Num2)
{
	cout << "Please enter number 1 : " << endl;
	cin >> Num1;
	cout << "Please enter number 2 : " << endl;
	cin >> Num2;

}

void SwapNumbers(int& num1, int& num2)
{
	int Temp;

	Temp = num1;
	num1 = num2;
	num2 = Temp;
}

void PrintNumbers(int& num1, int& num2)
{
	cout << "\nNumber1 = " << num1 << endl;
	cout << "Number2 = " << num2 << endl;
}

int main()
{
	int Num1, Num2;
	ReadNumbers(Num1, Num2);
	PrintNumbers(Num1, Num2);
	SwapNumbers(Num1, Num2);
	PrintNumbers(Num1, Num2);

	return 0;
}