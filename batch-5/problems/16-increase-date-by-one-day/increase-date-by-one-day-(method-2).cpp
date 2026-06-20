#include <iostream>

using namespace std;

struct sDate
{
	short year;
	short month;
	short day;
};

short ReadYear()
{
	short year;
	cout << "Please enter a year: ";
	cin >> year;

	return year;
}

short ReadMonth()
{
	short month;
	cout << "Please enter a month: ";
	cin >> month;

	return month;
}

short ReadDay()
{
	short day;
	cout << "Please enter a day: ";
	cin >> day;

	return day;
}

sDate ReadFullDate()
{

	sDate date;

	date.year = ReadYear();
	date.month = ReadMonth();
	date.day = ReadDay();

	return date;
}

bool IsLeapYear(short year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short NumberOfDaysInAMonth(short year, short month)
{

	if (month < 1 || month > 12)
		return 0; // Invalid Input

	short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrDays[month - 1];

}

bool IsLastDayInMonth(sDate date)
{
	return (date.day == NumberOfDaysInAMonth(date.year, date.month));
}

bool IsLastMonthInYear(short month)
{
	return (month == 12);
}

sDate IncreaseDateByOneDay(sDate date)
{
	(IsLastDayInMonth(date)) ? (IsLastMonthInYear(date.month) ? (date.year++ , date.month =1, date.day =1) : date.month++) : date.day++;
	return date;
}

int main()
{

	sDate date = ReadFullDate();

	date = IncreaseDateByOneDay(date);

	cout << "\nThe date after adding one day is : ";
	cout << date.day << "/" << date.month << "/" << date.year << endl;


	return 0;
}