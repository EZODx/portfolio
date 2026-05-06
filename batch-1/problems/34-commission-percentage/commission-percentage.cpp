#include <iostream>

using namespace std;

int ReadTotalSales()
{
	int TotalSales;

	cout << "Please enter the totalsales : " << endl;
	cin >> TotalSales;

	return TotalSales;
}

float GetCommissionPersentage(float Number)
{
	if (Number >= 1000000)
		return 0.01;
	else if (Number >= 500000)
		return 0.02;
	else if (Number >= 100000)
		return 0.03;
	else if (Number >= 50000)
		return 0.05;
	else
		return 0.00;

}

float CalculateTotalCommission(float TotalSales)
{
	return GetCommissionPersentage(TotalSales) * TotalSales;
}

int main()
{
	float TotalSales = ReadTotalSales();

	cout << "Comission persentage = " << GetCommissionPersentage(TotalSales) << endl;
	cout << "Total comission = " << CalculateTotalCommission(TotalSales) << endl;

	return 0;
}