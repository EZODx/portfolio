#include <iostream>

using namespace std;

void ReadNumbers(int& Num1, int& Num2, int& Num3)
{
	cout << "Please enter number 1 : ";
	cin >> Num1;
	cout << endl;

	cout << "Please enter number 2 : ";
	cin >> Num2;
	cout << endl;

	cout << "Please enter number 3 : ";
	cin >> Num3;
	cout << endl;

}

int SumOf3Numbers(int Num1,int Num2,int Num3)
{
	return Num1 + Num2 + Num3;
}

void PrintResult(int Total)
{
	cout << "The Total is : " << Total;
}

int main()
{
	int Num1, Num2, Num3;
	ReadNumbers(Num1, Num2, Num3);
	PrintResult(SumOf3Numbers(Num1, Num2, Num3));


	return 0;
}