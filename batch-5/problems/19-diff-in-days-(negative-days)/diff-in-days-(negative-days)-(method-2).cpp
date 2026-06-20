#pragma warning(disable : 4996)

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

void SwapDates(sDate& date1, sDate& date2)
{
	sDate tempDate;

	tempDate = date1;
	date1 = date2;
	date2 = tempDate;
}

int GetDifferenceInDays(sDate date1, sDate date2, bool includeEndDay = false)
{

	sDate temp;
	bool isDate1BeforDate2 = false;

	int day = 0;
	while (IsDate1BeforeDate2(date1, date2))
	{
		day++;
		date1 = IncreaseDateByOneDay(date1);
		isDate1BeforDate2 = true;
	}

	if (!IsDate1BeforeDate2(date1, date2))
	{
		SwapDates(date1, date2);

		while (IsDate1BeforeDate2(date1, date2))
		{
			day++;
			date1 = IncreaseDateByOneDay(date1);
		}
	}

	if (isDate1BeforDate2)
		return includeEndDay ? (++day) : (day);
	else
		return includeEndDay ? ((++day) * -1) : (day * -1);
}

int main()
{

	sDate date1 = ReadFullDate();
	sDate date2 = ReadFullDate();


	cout << "\nThe difference is: ";
	cout << GetDifferenceInDays(date1, date2) << " day(s)";

	cout << "\nThe difference(Including end day) is: ";
	cout << GetDifferenceInDays(date1, date2, true) << " day(s)" << endl;

	return 0;
}