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

int ReadPositiveNumber(string message)
{
	int number;
	do
	{
		cout << message;
		cin >> number;
	} while (number <= 0);

	return number;
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

sDate VacationReturnDate(sDate dateFrom, short vacationDays)
{

	short vacationDaysCounter = 0;
	while (vacationDaysCounter != vacationDays)
	{
		if (IsBusinessDay(dateFrom))
			vacationDaysCounter++;

		dateFrom = IncreaseDateByOneDay(dateFrom);
	}

	// In case the return date is a weekend, keep adding one day until you reach a business day.
	while (IsWeekEnd(dateFrom))
	{
		dateFrom = IncreaseDateByOneDay(dateFrom);
	}

	return dateFrom;
}

int main()
{

	cout << "Vacation starts: \n";
	sDate dateFrom = ReadFullDate();

	short vacationDays = ReadPositiveNumber("\nPlease enter the vacation days: ");


	sDate returnDate = VacationReturnDate(dateFrom, vacationDays);

	cout << "\nReturn date: ";
	cout << returnDate.day << "/" << returnDate.month << "/" << returnDate.year << endl;

	return 0;
}