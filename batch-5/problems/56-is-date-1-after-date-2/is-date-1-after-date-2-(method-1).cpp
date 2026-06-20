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

bool IsDate1EqualDate2(sDate date1, sDate date2)
{
	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day ? true : false)) : false) : false;
}

bool IsDate1BeforeDate2(sDate date1, sDate date2)
{
	return (date1.year < date2.year) ? true : (date1.year == date2.year ? (date1.month < date2.month ? true : (date1.month == date2.month ? (date1.day < date2.day) : false)) : false);
}

bool IsDate1AfterDate2(sDate date1, sDate date2)
{
	return (!IsDate1BeforeDate2(date1, date2) && (!IsDate1EqualDate2(date1, date2)));
}

int main()
{
	
	cout << "Enter date 1: \n";
	sDate date1 = ReadFullDate();

	cout << "\nEnter date 2: \n";
	sDate date2 = ReadFullDate();

	if (IsDate1AfterDate2(date1, date2))
		cout << "\nYes, date 1 is after date 2.\n";
	else
		cout << "\nNo, date 1 is not after date 2.\n";

	return 0;
}