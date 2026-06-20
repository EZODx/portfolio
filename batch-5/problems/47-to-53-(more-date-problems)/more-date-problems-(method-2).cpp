#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

struct sDate
{
	short year;
	short month;
	short day;
};

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

short NumberOfDaysInAYear(short year)
{
	return IsLeapYear(year) ? 366 : 365;
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

short DayOfWeekOrder(sDate date)
{
	short a, y, m, d;

	a = ((14 - date.month) / 12);
	y = date.year - a;
	m = date.month + (12 * a) - 2;

	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	d = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayName(short dayOrder)
{
	string arrDayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return arrDayName[dayOrder];
}

bool IsEndOfWeek(string dayName)
{
	return (dayName == "Sat") ? true : false;
}

bool IsWeekEnd(string dayName)
{
	return (dayName == "Fri") ? true : false;
}

bool IsBusinessDay(string dayName)
{
	return (dayName == "Fri" || dayName == "Sat") ? false : true;
}

short DaysUntilTheEndOfWeek(short dayOrder)
{
	short arr[] = { 6,5,4,3,2,1,0 };
	return arr[dayOrder];
}

short DaysUntilTheEndOfMonth(sDate date)
{
	short daysInMonth = NumberOfDaysInAMonth(date.year, date.month);
	return (daysInMonth - (date.day - 1));
}

short DaysUntilTheEndOfYear(sDate date)
{
	short daysInYear = NumberOfDaysInAYear(date.year);
	short daysFromBeginningOfTheYear = NumberOfDaysFromBeginningOfTheYear(date.day, date.month, date.year);

	return (daysInYear - (daysFromBeginningOfTheYear - 1));
}

int main()
{

	sDate date = GetSystemDate();
	short dayOrder = DayOfWeekOrder(date);
	string dayName = DayName(dayOrder);

	cout << "\nToday is " << dayName << " , ";
	cout << date.day << "/" << date.month << "/" << date.year << endl;


	cout << "\nIs it end of week?\n";
	if (IsEndOfWeek(dayName))
		cout << "Yes, It's end of week\n\n";
	else
		cout << "No, It's not end of week\n\n";

	cout << "Is it weekend?\n";
	if (IsWeekEnd(dayName))
		cout << "Yes, it's a week end\n\n";
	else
		cout << "No, it's not a week end\n\n";

	cout << "Is it business day?\n";
	if (IsBusinessDay(dayName))
		cout << "Yes, it's a business day\n\n";
	else
		cout << "No, it's not a business day\n\n";

	cout << "Days until end of week : ";
	cout << DaysUntilTheEndOfWeek(dayOrder) << " day(s)\n";

	cout << "Days until end of month : ";
	cout << DaysUntilTheEndOfMonth(date) << " day(s)\n";

	cout << "Days until end of year : ";
	cout << DaysUntilTheEndOfYear(date) << " day(s)\n";

	return 0;
}