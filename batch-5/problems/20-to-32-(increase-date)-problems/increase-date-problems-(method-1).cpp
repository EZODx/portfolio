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

sDate IncreaseDateByXDays(sDate date, int days)
{
	for (int i = 1; i <= days; i++)
	{
		date = IncreaseDateByOneDay(date);
	}

	return date;
}

sDate IncreaseDateByOneWeek(sDate date)
{
	for (int i = 1; i <= 7; i++)
	{
		date = IncreaseDateByOneDay(date);
	}

	return date;
}

sDate IncreaseDateByXWeeks(sDate date, int weeks)
{
	for (int i = 1; i <= weeks; i++)
	{
		date = IncreaseDateByOneWeek(date);
	}

	return date;
}

sDate IncreaseDateByOneMonth(sDate date)
{
	if (date.month == 12)
	{
		date.month = 1;
		date.year++;
	}
	else
	{
		date.month++;
	}

	//last check day in date should not exceed max days in thecurrent month
	// example if date is 31/1/2022 increasing one month shouldnot be 31 / 2 / 2022, it should
	// be 28/2/2022
	short daysInMonth = NumberOfDaysInAMonth(date.year, date.month);
	if (date.day > daysInMonth)
		date.day = daysInMonth;

	return date;
}

sDate IncreaseDateByXMonths(sDate date, int months)
{
	for (int i = 1; i <= months; i++)
	{
		date = IncreaseDateByOneMonth(date);
	}

	return date;
}

sDate IncreaseDateByOneYear(sDate date)
{
	date.year++;

	return date;
}

sDate IncreaseDateByXYears(sDate date, int years)
{
	for (int i = 1; i <= years; i++)
	{
		date = IncreaseDateByOneYear(date);
	}

	return date;
}

sDate IncreaseDateByXYearsFaster(sDate date, int years)
{
	date.year += years;

	return date;
}

sDate IncreaseDateByOneDecade(sDate date)
{
	//Period of 10 years
	date.year += 10;

	return date;
}

sDate IncreaseDateByXDecades(sDate date, int decades)
{
	for (int i = 1; i <= decades * 10; i++)
	{
		date = IncreaseDateByOneYear(date);
	}

	return date;
}

sDate IncreaseDateByXDecadesFaster(sDate date, int decades)
{
	date.year += decades * 10;

	return date;
}

sDate IncreaseDateByOneCentury(sDate date)
{
	//Period of 100 years
	date.year += 100;

	return date;
}

sDate IncreaseDateByOneMillennium(sDate date)
{
	//Period of 1000 years
	date.year += 1000;

	return date;
}

int main()
{

	sDate date = ReadFullDate();

	cout << "\nDate after:\n";

	date = IncreaseDateByOneDay(date);
	cout << "\n01-Adding one day is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByXDays(date, 10);
	cout << "\n02-Adding 10 days is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByOneWeek(date);
	cout << "\n03-Adding one week is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByXWeeks(date, 10);
	cout << "\n04-Adding 10 weeks is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByOneMonth(date);
	cout << "\n05-Adding one month is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByXMonths(date, 5);
	cout << "\n06-Adding 5 months is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByOneYear(date);
	cout << "\n07-Adding one year is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByXYears(date, 10);
	cout << "\n08-Adding 10 years is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByXYearsFaster(date, 10);
	cout << "\n09-Adding 10 years (faster) is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByOneDecade(date);
	cout << "\n10-Adding one decade is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByXDecades(date, 10);
	cout << "\n11-Adding 10 decades is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByXDecadesFaster(date, 10);
	cout << "\n12-Adding 10 decades (faster) is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByOneCentury(date);
	cout << "\n13-Adding one century is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = IncreaseDateByOneMillennium(date);
	cout << "\n14-Adding one millennium is: ";
	cout << date.day << "/" << date.month << "/" << date.year;
	cout << endl;

	return 0;
}