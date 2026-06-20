#include <iostream>

using namespace std;

enum enCompareDate { befor = -1, equal = 0, after = 1 };

struct sDate
{
	short year;
	short month;
	short day;
};

struct sPeriod
{
	sDate startDate;
	sDate endDate;
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

sPeriod ReadPeriod()
{
	sPeriod period;

	cout << "Enter start date :\n";
	period.startDate = ReadFullDate();

	cout << "\nEnter end date :\n";
	period.endDate = ReadFullDate();

	return period;
}

bool IsDate1EqualDate2(sDate date1, sDate date2)
{
	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day ? true : false)) : false) : false;
}

bool IsDate1BeforeDate2(sDate date1, sDate date2)
{
	return (date1.year < date2.year) ? true : (date1.year == date2.year ? (date1.month < date2.month ? true : (date1.month == date2.month ? (date1.day < date2.day) : false)) : false);
}

enCompareDate CompareDate(sDate date1, sDate date2)
{
	if (IsDate1BeforeDate2(date1, date2))
		return enCompareDate::befor;
	else if (IsDate1EqualDate2(date1, date2))
		return enCompareDate::equal;
	else
		return enCompareDate::after;
}

bool IsDateWithinPeriod(sPeriod period, sDate date)
{
	return !(CompareDate(date, period.startDate) == enCompareDate::befor

		||

		CompareDate(date, period.endDate) == enCompareDate::after
		);
}

int main()
{
	cout << "Enter the period: \n\n";
	sPeriod period = ReadPeriod();

	cout << "\nEnter the date: \n";
	sDate date = ReadFullDate();


	if (IsDateWithinPeriod(period, date))
		cout << "\nYes, the date is within the period.\n";
	else
		cout << "\nNo, the date is not within the period.\n";

	return 0;
}