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

float CalculateRemainder(float TotalBill, float CashPaid)
{
	return TotalBill - CashPaid;
}

int main()
{
	float TotalBill = ReadPositiveNumber("Please enter total bill : ");
	float TotalCashPaid = ReadPositiveNumber("Please enter total cash paid");

	cout << endl;
	cout << "Total bill = " << TotalBill << endl;
	cout << "Total cash paid = " << TotalCashPaid << endl;

	cout << "***********************************" << endl;
	cout << "Remainder = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;

	return 0;
}