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
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short NumberOfDaysInAYear(short year)
{
	return IsLeapYear(year) ? 366 : 365;
}

short NumberOfHoursInAYear(short year)
{
	return NumberOfDaysInAYear(year) * 24;
}

int NumberOfMinutesInAYear(short year)
{
	return NumberOfHoursInAYear(year) * 60;
}

int NumberOfSecondsInAYear(short year)
{
	return NumberOfMinutesInAYear(year) * 60;
}

int main()
{

	short year = ReadYear();

	cout << "\nNumbers of days    in year [" << year << "] is "
		<< NumberOfDaysInAYear(year);
	cout << "\nNumbers of hours   in year [" << year << "] is "
		<< NumberOfHoursInAYear(year);
	cout << "\nNumbers of minutes in year [" << year << "] is "
		<< NumberOfMinutesInAYear(year);
	cout << "\nNumbers of seconds in year [" << year << "] is "
		<< NumberOfSecondsInAYear(year) << endl;

	return 0;
}