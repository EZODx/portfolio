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

	if (month == 2)
		return IsLeapYear(year) ? 29 : 28;

	short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };

	for (int i = 1; i <= 7; i++)
	{
		if (month == arr31Days[i - 1])
			return 31;
	}

	// Otherwise, the month has 30 days
	return 30;
}

short NumberOfHoursInAMonth(short year, short month)
{
	return NumberOfDaysInAMonth(year, month) * 24;
}

int NumberOfMinutesInAMonth(short year, short month)
{
	return NumberOfHoursInAMonth(year, month) * 60;
}

int NumberOfSecondsInAMonth(short year, short month)
{
	return NumberOfMinutesInAMonth(year, month) * 60;
}

int main()
{

	short year = ReadYear();
	short month = ReadMonth();

	cout << "\nNumbers of days    in month [" << month << "] is "
		<< NumberOfDaysInAMonth(year, month);
	cout << "\nNumbers of hours   in month [" << month << "] is "
		<< NumberOfHoursInAMonth(year, month);
	cout << "\nNumbers of minutes in month [" << month << "] is "
		<< NumberOfMinutesInAMonth(year, month);
	cout << "\nNumbers of seconds in month [" << month << "] is "
		<< NumberOfSecondsInAMonth(year, month) << endl;

	return 0;
}