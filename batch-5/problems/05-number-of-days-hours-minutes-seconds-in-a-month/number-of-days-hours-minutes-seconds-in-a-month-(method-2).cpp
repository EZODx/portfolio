#include <iostream>

using namespace std;

enum monthsInLeapYear { ljan = 1, lfeb, lmar, lapr, lmay, ljun, ljul, laug, lsep, loct, lnov, ldec };

enum monthsInYear { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };


short ReadYear()
{
	short year;
	cout << "Please enter a year to check: ";
	cin >> year;

	return year;
}

short ReadMonth()
{
	short month;
	cout << "\nPlease enter a month to check: ";
	cin >> month;

	return month;
}

bool IsLeapYear(short year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short NumberOfDaysInAMonth(short year, short month)
{

	short Month;

	if (IsLeapYear(year))
	{
		switch (month)
		{

		case monthsInLeapYear::ljan:
			Month = 31;
			break;

		case monthsInLeapYear::lfeb:
			Month = 29;
			break;

		case monthsInLeapYear::lmar:
			Month = 31;
			break;

		case monthsInLeapYear::lapr:
			Month = 30;
			break;

		case monthsInLeapYear::lmay:
			Month = 31;
			break;

		case monthsInLeapYear::ljun:
			Month = 30;
			break;

		case monthsInLeapYear::ljul:
			Month = 31;
			break;

		case monthsInLeapYear::laug:
			Month = 30;
			break;

		case monthsInLeapYear::lsep:
			Month = 31;
			break;

		case monthsInLeapYear::loct:
			Month = 30;
			break;

		case monthsInLeapYear::lnov:
			Month = 31;
			break;

		case monthsInLeapYear::ldec:
			Month = 30;
			break;

		default:
			Month = 0;
			break;
		}


	}
	else
	{
		switch (month)
		{

		case monthsInYear::jan:
			Month = 31;
			break;

		case monthsInYear::feb:
			Month = 28;
			break;

		case monthsInYear::mar:
			Month = 31;
			break;

		case monthsInYear::apr:
			Month = 30;
			break;

		case monthsInYear::may:
			Month = 31;
			break;

		case monthsInYear::jun:
			Month = 30;
			break;

		case monthsInYear::jul:
			Month = 31;
			break;

		case monthsInYear::aug:
			Month = 30;
			break;

		case monthsInYear::sep:
			Month = 31;
			break;

		case monthsInYear::oct:
			Month = 30;
			break;

		case monthsInYear::nov:
			Month = 31;
			break;

		case monthsInYear::dec:
			Month = 30;
			break;

		default:
			Month = 0;
			break;
		}
	}

	return Month;
}

short NumberOfHoursInAMonth(short year, short month)
{
	return NumberOfDaysInAMonth(year, month) * 24;
}

int NumberOfMinutesInAMonth(short year, short month)
{
	return NumberOfHoursInAMonth(year, month) * 60;
}

int NumberOfSecondsInAMonth(short year, short month)
{
	return NumberOfMinutesInAMonth(year, month) * 60;
}

int main()
{

	short year = ReadYear();
	short month = ReadMonth();

	cout << "\nNumbers of days    in month [" << month << "] is "
		<< NumberOfDaysInAMonth(year, month);
	cout << "\nNumbers of hours   in month [" << month << "] is "
		<< NumberOfHoursInAMonth(year, month);
	cout << "\nNumbers of minutes in month [" << month << "] is "
		<< NumberOfMinutesInAMonth(year, month);
	cout << "\nNumbers of seconds in month [" << month << "] is "
		<< NumberOfSecondsInAMonth(year, month) << endl;

	return 0;
}