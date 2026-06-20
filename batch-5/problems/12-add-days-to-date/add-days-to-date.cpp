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

short addDays()
{
	short addDays;
	cout << "\nPlease enter an add days: ";
	cin >> addDays;

	return addDays;
}

sDate ReadDate()
{

	sDate date;

	date.year = ReadYear();
	date.month = ReadMonth();
	date.day = ReadDay();

	return date;
}

short ReadDaysToAdd()
{

	short daysToAdd;
	cout << "How many days to add: ";
	cin >> daysToAdd;

	return daysToAdd;
}

sDate DateAddDays(sDate date, short daysToAdd)
{

	short remainingDays = daysToAdd + NumberOfDaysFromBeginningOfTheYear(date.day, date.month, date.year);
	short monthDays = 0;

	date.month = 1;

	while (true)
	{

		monthDays = NumberOfDaysInAMonth(date.year, date.month);

		if (remainingDays > monthDays)
		{
			remainingDays -= monthDays;
			date.month++;

			if (date.month > 12)
			{
				date.month = 1;
				date.year++;
			}
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

	sDate date = ReadDate();
	short daysToAdd = ReadDaysToAdd();

	date = DateAddDays(date, daysToAdd);
	cout << "\nDate after adding [" << daysToAdd << "] days is: ";
	cout << date.day << "/" << date.month << "/" << date.year << endl;


	return 0;
}