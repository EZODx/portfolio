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

bool IsValidDate(sDate date)
{

	if (date.day < 1 || date.day > 31)
		return false;

	if (date.month < 1 || date.month > 12)
		return false;

	if (date.month == 2)
	{
		if (IsLeapYear(date.year))
		{
			if (date.day > 29)
				return false;
		}
		else
		{
			if (date.day > 28)
				return false;
		}
	}


	short daysInMonth = NumberOfDaysInAMonth(date.year, date.month);
	if (date.day > daysInMonth)
		return false;

	return true;
}

int main()
{
	cout << "Please enter the date: \n";
	sDate date = ReadFullDate();


	if (IsValidDate(date))
		cout << "\nYes, the date is a valid date.\n";
	else
		cout << "\nNo, the date is not a valid date.\n";

	return 0;
}