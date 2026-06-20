#include <iostream>

using namespace std;

short ReadYear()
{
	short year;
	cout << "Please enter a year to check: ";
	cin >> year;

	return year;
}

bool IsLeapYear(short year)
{

	if (year % 400 == 0)
		return true;

	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else
		return false;

}

int main()
{

	short year = ReadYear();

	if (IsLeapYear(year))
		cout << "\nYes, the year [" << year << "] is a leap year.\n";
	else
		cout << "\nNo, the year [" << year << "] is NOT a leap year.\n";

	return 0;
}