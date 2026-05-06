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

float TotalMonths(int LoanAmount, int MonthlyInstallment)
{
	return (float)LoanAmount / MonthlyInstallment;
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please enter the Loan Amount : ");
	float MonthlyInstallment = ReadPositiveNumber("Please enter the monthly installment : ");

	cout << "Total month to pay = " << TotalMonths(LoanAmount, MonthlyInstallment) << endl;


	return 0;
}