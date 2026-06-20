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
	cout << "\nPlease enter a month: ";
	cin >> month;

	return month;
}

short ReadDay()
{
	short day;
	cout << "\nPlease enter a day: ";
	cin >> day;

	return day;
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

short NumberOfDaysFromBeginningOfTheYear(short day, short month, short year)
{

	short totalDays = 0;

	for (short i = 1; i < month; i++)
	{
		totalDays += NumberOfDaysInAMonth(year, i);
	}

	totalDays += day;

	return totalDays;
}

sDate GetDateFromDayOrderInAYear(short daysOrderInAYear, short year)
{

	sDate date;
	short remainingDays = daysOrderInAYear;
	short monthDays = 0;

	date.year = year;
	date.month = 1;

	while (true)
	{

		monthDays = NumberOfDaysInAMonth(year, date.month);

		if (remainingDays > monthDays)
		{
			remainingDays -= monthDays;
			date.month++;
		}
		else
		{
			date.day = remainingDays;
			break;
		}

	}

	return date;
}

int main()
{

	short year = ReadYear();
	short month = ReadMonth();
	short day = ReadDay();
	short daysOrderInAYear = NumberOfDaysFromBeginningOfTheYear(day, month, year);


	cout << "\n";
	cout << "Number of days from the beginning of the year is: " << daysOrderInAYear;

	sDate date;
	date = GetDateFromDayOrderInAYear(daysOrderInAYear, year);
	cout << "\n\nDate for [" << daysOrderInAYear << "] is : ";
	cout << date.day << "/" << date.month << "/" << date.year << endl;

	return 0;
}