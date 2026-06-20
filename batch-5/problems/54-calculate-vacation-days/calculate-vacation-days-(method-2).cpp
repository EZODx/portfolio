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

int GetDiffeerceInDays(sDate date1, sDate date2, bool includeEndDay = false)
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

bool IsWeekEnd(sDate date)
{
	//Weekends are Fri and Sat
	short dayIndex = DayOfWeekOrder(date);
	return (dayIndex == 5 || dayIndex == 6);
}

short ActualVacationDays(sDate dateFrom, sDate dateTo)
{
	short allVacationDays = GetDiffeerceInDays(dateFrom, dateTo);

	short weekEndDays = 0;

	for (int i = 1; i <= allVacationDays; i++)
	{
		if (IsWeekEnd(dateFrom))
			weekEndDays++;

		dateFrom = IncreaseDateByOneDay(dateFrom);
	}

	return allVacationDays - weekEndDays;
}

int main()
{

	cout << "Vacation starts: \n";
	sDate dateFrom = ReadFullDate();

	cout << "\nVacation ends: \n";
	sDate dateTo = ReadFullDate();


	cout << "\nVecation from: " << DayName(DayOfWeekOrder(dateFrom)) << " , ";
	cout << dateFrom.day << "/" << dateFrom.month << "/" << dateFrom.year << endl;

	cout << "Vecation to: " << DayName(DayOfWeekOrder(dateTo)) << " , ";
	cout << dateTo.day << "/" << dateTo.month << "/" << dateTo.year << endl;

	cout << "\nActual vacation days is: " << ActualVacationDays(dateFrom, dateTo) << endl;

	return 0;
}