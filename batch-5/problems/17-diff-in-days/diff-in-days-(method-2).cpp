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

short DayOfYear(short day, short month, short year)
{

	short totalDays = 0;

	for (short i = 1; i < month; i++)
	{
		totalDays += NumberOfDaysInAMonth(year, i);
	}

	totalDays += day;

	return totalDays;
}

int DaysRemainingInYear(sDate date1)
{
	int totalDyas;

	if (IsLeapYear(date1.year))
		totalDyas = 366;
	else
		totalDyas = 365;

	int daysFromBeginning = DayOfYear(date1.day, date1.month, date1.year);


	int result = totalDyas - daysFromBeginning;

	return result;
}

int DaysPassedInYear(sDate date2)
{
	return DayOfYear(date2.day, date2.month, date2.year);
}

int DaysBetweenYears(sDate date1, sDate date2)
{

	int totalDays = 0;

	for (int currentYear = date1.year + 1; currentYear < date2.year; currentYear++)
	{
		if (IsLeapYear(currentYear))
			totalDays += 366;
		else
			totalDays += 365;
	}

	return totalDays;
}

int GetDifferenceInDays(sDate date1, sDate date2)
{
	int daysFromStartYear = DaysRemainingInYear(date1);
	int daysFromEndYear = DaysPassedInYear(date2);
	int daysBetweenYears = DaysBetweenYears(date1, date2);

	if (date1.year != date2.year)
	{
		return (daysFromStartYear + daysFromEndYear + daysBetweenYears);
	}
	else
	{
		return (daysFromEndYear - DayOfYear(date1.day, date1.month, date1.year));
	}
}

int main()
{

	sDate date1 = ReadFullDate();
	cout << "\n";
	sDate date2 = ReadFullDate();

	int differenceInDays = GetDifferenceInDays(date1, date2);

	cout << "\nThe differece is: " << differenceInDays << "day(s)" << endl;
	cout << "\nThe differece (Including end day) is: " << differenceInDays + 1 << "day(s)" << endl;

	return 0;
}