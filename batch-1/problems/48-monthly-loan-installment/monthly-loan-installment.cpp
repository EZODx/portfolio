#include <iostream>

using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number;

	do
	{
		cout << Message << endl;
		cin >> Number;
	}
	while (Number <= 0);

	return Number;
}

float MonthlyInstallment(int LoanAmount, int HowManyMonths)
{
	return (float)LoanAmount / HowManyMonths;
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please enter the Loan Amount : ");
	float HowManyMonths = ReadPositiveNumber("How many months : ");

	cout << "The monthly installment = " << MonthlyInstallment(LoanAmount, HowManyMonths) << endl;


	return 0;
}