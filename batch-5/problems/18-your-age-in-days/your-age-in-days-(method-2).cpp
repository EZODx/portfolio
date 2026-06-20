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

sDate GetSystemDate()
{
	sDate date;

	time_t t = time(0);
	tm* now = localtime(&t);

	date.year = now->tm_year + 1900;
	date.month = now->tm_mon + 1;
	date.day = now->tm_mday;

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

bool IsDate1BeforeDate2(sDate date1, sDate date2)
{

	if (date1.year != date2.year)
		return date1.year < date2.year;

	if (date1.month != date2.month)
		return date1.month < date2.month;

	return date1.day < date2.day;

}

sDate IncreaseDateByOneDay(sDate date)
{

	if (IsLastDayInMonth(date))
	{
		if (IsLastMonthInYear(date.month))
		{
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else
		{
			date.day = 1;
			date.month++;
		}
	}
	else
	{
		date.day++;
	}

	return date;
}

int AgeInDays(sDate date1, sDate date2)
{

	int day = 0;
	while (IsDate1BeforeDate2(date1, date2))
	{
		day++;
		date1 = IncreaseDateByOneDay(date1);
	}

	return day;
}

int main()
{

	cout << "Please enter your date of birth: \n\n";

	sDate date1 = ReadFullDate();
	sDate date2 = GetSystemDate();

	cout << "\nYour age is: ";
	cout << AgeInDays(date1, date2) << " day(s)" << endl;


	return 0;
}