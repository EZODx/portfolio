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

sDate DecreaseDateByOneDay(sDate date)
{

	if (date.day == 1)
	{
		if (date.month == 1)
		{
			date.day = 31;
			date.month = 12;
			date.year--;
		}
		else
		{
			date.month--;
			date.day = NumberOfDaysInAMonth(date.year, date.month);
		}
	}
	else
	{
		date.day--;
	}

	return date;
}

sDate DecreaseDateByXDays(sDate date, int days)
{
	for (int i = 1; i <= days; i++)
	{
		date = DecreaseDateByOneDay(date);
	}

	return date;
}

sDate DecreaseDateByOneWeek(sDate date)
{
	for (int i = 1; i <= 7; i++)
	{
		date = DecreaseDateByOneDay(date);
	}

	return date;
}

sDate DecreaseDateByXWeeks(sDate date, int weeks)
{
	for (int i = 1; i <= weeks; i++)
	{
		date = DecreaseDateByOneWeek(date);
	}

	return date;
}

sDate DecreaseDateByOneMonth(sDate date)
{
	if (date.month == 1)
	{
		date.month = 12;
		date.year--;
	}
	else
	{
		date.month--;
	}

	//last check day in date should not exceed max days in thecurrent month
	// example if date is 31/3/2022 decreasing one month should notbe 31 / 2 / 2022, it should
	// be 28/2/2022
	short daysInMonth = NumberOfDaysInAMonth(date.year, date.month);
	if (date.day > daysInMonth)
		date.day = daysInMonth;

	return date;
}

sDate DecreaseDateByXMonths(sDate date, int months)
{
	for (int i = 1; i <= months; i++)
	{
		date = DecreaseDateByOneMonth(date);
	}

	return date;
}

sDate DecreaseDateByOneYear(sDate date)
{
	date.year--;

	return date;
}

sDate DecreaseDateByXYears(sDate date, int years)
{
	for (int i = 1; i <= years; i++)
	{
		date = DecreaseDateByOneYear(date);
	}

	return date;
}

sDate DecreaseDateByXYearsFaster(sDate date, int years)
{
	date.year -= years;

	return date;
}

sDate DecreaseDateByOneDecade(sDate date)
{
	//Period of 10 years
	date.year -= 10;

	return date;
}

sDate DecreaseDateByXDecades(sDate date, int decades)
{
	for (int i = 1; i <= decades; i++)
	{
		date = DecreaseDateByOneDecade(date);
	}

	return date;
}

sDate DecreaseDateByXDecadesFaster(sDate date, int decades)
{
	date.year -= decades * 10;

	return date;
}

sDate DecreaseDateByOneCentury(sDate date)
{
	//Period of 100 years
	date.year -= 100;

	return date;
}

sDate DecreaseDateByOneMillennium(sDate date)
{
	//Period of 1000 years
	date.year -= 1000;

	return date;
}

int main()
{

	sDate date = ReadFullDate();

	cout << "\nDate after:\n";

	date = DecreaseDateByOneDay(date);
	cout << "\n01-Subtracting one day is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByXDays(date, 10);
	cout << "\n02-Subtracting 10 days is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByOneWeek(date);
	cout << "\n03-Subtracting one week is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByXWeeks(date, 10);
	cout << "\n04-Subtracting 10 weeks is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByOneMonth(date);
	cout << "\n05-Subtracting one month is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByXMonths(date, 5);
	cout << "\n06-Subtracting 5 months is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByOneYear(date);
	cout << "\n07-Subtracting one year is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByXYears(date, 10);
	cout << "\n08-Subtracting 10 years is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByXYearsFaster(date, 10);
	cout << "\n09-Subtracting 10 years (faster) is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByOneDecade(date);
	cout << "\n10-Subtracting one decade is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByXDecades(date, 10);
	cout << "\n11-Subtracting 10 decades is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByXDecadesFaster(date, 10);
	cout << "\n12-Subtracting 10 decades (faster) is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByOneCentury(date);
	cout << "\n13-Subtracting one century is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	date = DecreaseDateByOneMillennium(date);
	cout << "\n14-Subtracting one millennium is: ";
	cout << date.day << "/" << date.month << "/" << date.year;
	cout << endl;

	return 0;
}