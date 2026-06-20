#include <iostream>

using namespace std;

enum enCompareDate { befor = -1, equal = 0, after = 1 };

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

bool IsDate1EqualDate2(sDate date1, sDate date2)
{
	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day ? true : false)) : false) : false;
}

bool IsDate1BeforeDate2(sDate date1, sDate date2)
{
	return (date1.year < date2.year) ? true : (date1.year == date2.year ? (date1.month < date2.month ? true : (date1.month == date2.month ? (date1.day < date2.day) : false)) : false);
}

bool IsDate1AfterDate2(sDate date1, sDate date2)
{
	return (!IsDate1BeforeDate2(date1, date2) && (!IsDate1EqualDate2(date1, date2)));
}

bool IsDateWithinPeriod(sPeriod period, sDate date)
{
	if (
		(IsDate1AfterDate2(date, period.startDate) || IsDate1EqualDate2(date, period.startDate))
		&& (IsDate1BeforeDate2(date, period.endDate) || IsDate1EqualDate2(date, period.endDate))
		)
		return true;

	return false;

}

int main()
{
	cout << "Enter the period: \n\n";
	sPeriod period = ReadPeriod();

	cout << "\nEnter the date: \n";
	sDate date = ReadFullDate();


	if (IsDateWithinPeriod(period, date))
		cout << "\nYes, the date is within the period.\n";
	else
		cout << "\nNo, the date is not within the period.\n";

	return 0;
}