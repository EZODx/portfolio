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

bool IsDate1BeforeDate2(sDate date1, sDate date2)
{

	if (date1.year > date2.year)
	{
		return false;
	}
	else if (date1.year == date2.year)
	{
		if (date1.month > date2.month)
			return false;
		else if (date1.month == date2.month)
		{
			if (date1.day > date2.day)
				return false;
			else if (date1.day == date2.day)
				return false;
		}

	}
	else
	{
		return true;
	}
}

int main()
{

	sDate date1 = ReadFullDate();
	cout << "\n";
	sDate date2 = ReadFullDate();

	if (IsDate1BeforeDate2(date1, date2))
		cout << "\nYes, date 1 is less than date 2.\n";
	else
		cout << "\nNo, date 1 is not less than date 2.\n";

	return 0;
}