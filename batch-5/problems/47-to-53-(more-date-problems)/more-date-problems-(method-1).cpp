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

short DayOfWeekOrder(short year, short month, short day)
{
	short a, y, m, d;

	a = ((14 - month) / 12);
	y = year - a;
	m = month + (12 * a) - 2;

	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

short DayOfWeekOrder(sDate date)
{
	return DayOfWeekOrder(date.year, date.month, date.day);
}

string DayName(short dayOrder)
{
	string arrDayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return arrDayName[dayOrder];
}

bool IsDate1BeforeDate2(sDate date1, sDate date2)
{

	if (date1.year != date2.year)
		return date1.year < date2.year;

	if (date1.month != date2.month)
		return date1.month < date2.month;

	return date1.day < date2.day;

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

void SwapDates(sDate& date1, sDate& date2)
{
	sDate tempDate;

	tempDate = date1;
	date1 = date2;
	date2 = tempDate;
}

int GetDifferenceInDays(sDate date1, sDate date2, bool includeEndDay = false)
{

	int day = 0;
	short swapFlagValue = 1;

	if (!IsDate1BeforeDate2(date1, date2))
	{
		SwapDates(date1, date2);
		swapFlagValue = -1;
	}

	while (IsDate1BeforeDate2(date1, date2))
	{
		day++;
		date1 = IncreaseDateByOneDay(date1);
	}

	return includeEndDay ? ((++day) * swapFlagValue) : (day * swapFlagValue);
}

bool IsEndOfWeek(sDate date)
{
	return DayOfWeekOrder(date) == 6;
}

bool IsWeekEnd(sDate date)
{
	//Weekends are Fri and Sat
	short dayIndex = DayOfWeekOrder(date);
	return (dayIndex == 5 || dayIndex == 6);
}

bool IsBusinessDay(sDate date)
{
	//Business days are Sun,Mon,Tue,Wed and Thu
	return !IsWeekEnd(date);
}

short DaysUntilTheEndOfWeek(sDate date)
{
	return 6 - DayOfWeekOrder(date);
}

short DaysUntilTheEndOfMonth(sDate date)
{
	sDate endOfMonthDate;
	endOfMonthDate.day = NumberOfDaysInAMonth(date.year, date.month);
	endOfMonthDate.month = date.month;
	endOfMonthDate.year = date.year;

	return GetDifferenceInDays(date, endOfMonthDate, true);
}

short DaysUntilTheEndOfYear(sDate date)
{
	sDate endOfYearDate;
	endOfYearDate.day = 31;
	endOfYearDate.month = 12;
	endOfYearDate.year = date.year;

	return GetDifferenceInDays(date, endOfYearDate, true);

}

int main()
{

	sDate date = GetSystemDate();

	cout << "\nToday is " << DayName(DayOfWeekOrder(date)) << " , ";
	cout << date.day << "/" << date.month << "/" << date.year << endl;


	cout << "\nIs it end of week?\n";
	if (IsEndOfWeek(date))
		cout << "Yes, it is Saturday, it's end of Week.\n\n";
	else
		cout << "No, it's Not end of week.\n\n";

	cout << "Is it weekend?\n";
	if (IsWeekEnd(date))
		cout << "Yes, it's a week end\n\n";
	else
		cout << "No, today is "<< DayName(DayOfWeekOrder(date))<<" it's not a week end\n\n";

	cout << "Is it business day?\n";
	if (IsBusinessDay(date))
		cout << "Yes, it's a business day\n\n";
	else
		cout << "No, it's not a business day\n\n";

	cout << "Days until end of week : ";
	cout << DaysUntilTheEndOfWeek(date) << " day(s)\n";

	cout << "Days until end of month : ";
	cout << DaysUntilTheEndOfMonth(date) << " day(s)\n";

	cout << "Days until end of year : ";
	cout << DaysUntilTheEndOfYear(date) << " day(s)\n";


	return 0;
}