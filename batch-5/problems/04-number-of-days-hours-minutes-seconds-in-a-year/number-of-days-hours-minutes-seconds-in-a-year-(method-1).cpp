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

int CountSecondsInAYear(int minutes)
{
	return minutes * 60;
}

int CountMinutesInAYear(short hours)
{
	return hours * 60;
}

short CountHoursInAYear(short days)
{
	return days * 24;
}

void PrintLeapYearResult(short year)
{
	short days = 366;
	short hours = CountHoursInAYear(days);
	int minutes = CountMinutesInAYear(hours);
	int seconds = CountSecondsInAYear(minutes);

	cout << "\nNumbers of days    in year [" << year << "] is "
		<< days;
	cout << "\nNumbers of hours   in year [" << year << "] is "
		<< hours;
	cout << "\nNumbers of minutes in year [" << year << "] is "
		<< minutes;
	cout << "\nNumbers of seconds in year [" << year << "] is "
		<< seconds << endl;
}

void PrintNormalYearResult(short year)
{
	short days = 365;
	short hours = CountHoursInAYear(days);
	int minutes = CountMinutesInAYear(hours);
	int seconds = CountSecondsInAYear(minutes);

	cout << "\nNumbers of days    in year [" << year << "] is "
		<< days;
	cout << "\nNumbers of hours   in year [" << year << "] is "
		<< hours;
	cout << "\nNumbers of minutes in year [" << year << "] is "
		<< minutes;
	cout << "\nNumbers of seconds in year [" << year << "] is "
		<< seconds << endl;

}

void PrintResult(short year)
{

	if (IsLeapYear(year))
		PrintLeapYearResult(year);
	else
		PrintNormalYearResult(year);

}

int main()
{

	short year = ReadYear();

	PrintResult(year);

	return 0;
}