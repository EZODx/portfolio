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

float TotalBillAfterServicesAndTax(float TotalBill)
{
	TotalBill = TotalBill * 1.1;
	TotalBill = TotalBill * 1.16;

	return TotalBill;
}

int main()
{
	float TotalBill = ReadPositiveNumber("Please enter total bill : ");

	cout << endl;
	cout << "Total Bill = " << TotalBill << endl;

	cout << "Total bill after services fee and sales tax = "
		<< TotalBillAfterServicesAndTax(TotalBill) << endl;

	return 0;
}