#include <iostream>

using namespace std;

enum enCompareDate { before = -1, equal = 0, after = 1 };

struct sDate
{
	short year;
	short month;
	short day;
};

struct sPeriod
{
	sDate startDate;
	sDate endDate;
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

sPeriod ReadPeriod()
{
	sPeriod period;

	cout << "Enter start date :\n";
	period.startDate = ReadFullDate();

	cout << "\nEnter end date :\n";
	period.endDate = ReadFullDate();

	return period;
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

sDate IncreaseDateByOneDay(sDate date)
{

	if (IsLastDayInMonth(date))
	{
		if (date.month == 12)
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

bool IsDate1BeforeDate2(sDate date1, sDate date2)
{

	if (date1.year != date2.year)
		return date1.year < date2.year;

	if (date1.month != date2.month)
		return date1.month < date2.month;

	return date1.day < date2.day;

}

int GetDifferenceInDays(sDate date1, sDate date2, bool includeEndDay = false)
{

	int day = 0;
	while (IsDate1BeforeDate2(date1, date2))
	{
		day++;
		date1 = IncreaseDateByOneDay(date1);
	}

	return includeEndDay ? (++day) : (day);
}

int PeriodLengthInDays(sPeriod period, bool includEndDay = false)
{
	return GetDifferenceInDays(period.startDate, period.endDate, includEndDay);
}

bool IsDate1EqualDate2(sDate date1, sDate date2)
{
	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day ? true : false)) : false) : false;
}

enCompareDate CompareDate(sDate date1, sDate date2)
{
	if (IsDate1BeforeDate2(date1, date2))
		return enCompareDate::before;
	else if (IsDate1EqualDate2(date1, date2))
		return enCompareDate::equal;
	else
		return enCompareDate::after;
}

bool IsPeriodsOverlap(sPeriod period1, sPeriod period2)
{

	if (
		CompareDate(period2.endDate, period1.startDate) == enCompareDate::before
		||
		CompareDate(period2.startDate, period1.endDate) == enCompareDate::after
		)
		return false;
	else
		return true;

}

bool IsDateWithinPeriod(sPeriod period, sDate date)
{
	return !(CompareDate(date, period.startDate) == enCompareDate::before

		||

		CompareDate(date, period.endDate) == enCompareDate::after
		);
}

int OverlapDays(sPeriod period1, sPeriod period2)
{

	int period1Length = PeriodLengthInDays(period1, true);
	int period2Length = PeriodLengthInDays(period2, true);

	int overlapDays = 0;


	if (!IsPeriodsOverlap(period1, period2))
		return 0;


	if (period1Length < period2Length)
	{
		while (IsDate1BeforeDate2(period1.startDate, period1.endDate))
		{

			if (IsDateWithinPeriod(period2, period1.startDate))
				overlapDays++;

			period1.startDate = IncreaseDateByOneDay(period1.startDate);
		}
	}
	else
	{
		while (IsDate1BeforeDate2(period2.startDate, period2.endDate))
		{
			if (IsDateWithinPeriod(period1, period2.startDate))
				overlapDays++;

			period2.startDate = IncreaseDateByOneDay(period2.startDate);
		}
	}

	return overlapDays;
}

int main()
{
	cout << "Enter the period 1: \n\n";
	sPeriod period1 = ReadPeriod();

	cout << "Enter the period 2: \n\n";
	sPeriod period2 = ReadPeriod();

	cout << "\nThe number of overlapping days is : " << OverlapDays(period1, period2) << endl;

	return 0;
}