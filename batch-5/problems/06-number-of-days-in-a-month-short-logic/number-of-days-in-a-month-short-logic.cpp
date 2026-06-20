#include <iostream>

using namespace std;

short ReadYear()
{
	short year;
	cout << "Please enter a year to check: ";
	cin >> year;

	return year;
}

short ReadMonth()
{
	short month;
	cout << "\nPlease enter a month to check: ";
	cin >> month;

	return month;
}

bool IsLeapYear(short year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short NumberOfDaysInAMonth(short year, short month)
{

	if (month < 1 || month > 12)
		return 0; // Invalid Input

	short arrDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrDays[month - 1];

}

int main()
{

	short year = ReadYear();
	short month = ReadMonth();

	cout << "\nNumbers of days in month [" << month << "] is "
		<< NumberOfDaysInAMonth(year, month);

	return 0;
}