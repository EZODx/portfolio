#include <iostream>

using namespace std;

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

bool IsLeapYear(short year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short DayOfWeekOrder(short day, short month, short year)
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

short NumberOfDaysInAMonth(short year, short month)
{

	if (month < 1 || month > 12)
		return 0; // Invalid Input

	short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrDays[month - 1];

}

string MonthName(short month)
{
	string arrMonthName[12] = { "Jan", "Feb", "Mar",
								"Apr", "May", "Jun",
								"Jul", "Aug", "Sep",
								"Oct", "Nov", "Dec" };

	return arrMonthName[month - 1];
}

void PrintMonthCalendar(short month, short year)
{

	short numberOfDays;

	short order = DayOfWeekOrder(1, month, year);
	numberOfDays = NumberOfDaysInAMonth(year, month);

	printf("\n  _______________%s________________  \n\n", MonthName(month).c_str());

	printf("  San  Mon  Tue  Wed  Thu  Fri  Sat  \n");

	short i;
	for (i = 0; i < order; i++)
		printf("     ");

	for (short j = 1; j <= numberOfDays; j++)
	{
		printf("%5d",j);


		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}

	}

	printf("\n  __________________________________  \n");
}

int main()
{

	short year = ReadYear();
	short month = ReadMonth();

	PrintMonthCalendar(month, year);


	return 0;
}