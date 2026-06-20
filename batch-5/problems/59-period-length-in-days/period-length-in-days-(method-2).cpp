#include <iostream>

using namespace std;

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

int PeriodLengthInDays(sPeriod period, bool includEndDay = false)
{
	int periodInDays = 0;

	while (true)
	{
		periodInDays++;
		period.startDate = IncreaseDateByOneDay(period.startDate);
		if (
			period.startDate.day == period.endDate.day
			&& period.startDate.month == period.endDate.month
			&& period.startDate.year == period.endDate.year
			)
			break;
	}
	return includEndDay ? periodInDays + 1 : (periodInDays);
}

int main()
{
	cout << "Enter the period : \n\n";
	sPeriod period = ReadPeriod();

	cout << "\nPeriod length is: " << PeriodLengthInDays(period) << endl;
	cout << "Period length (including end day) is: " << PeriodLengthInDays(period, true) << endl;

	return 0;
}