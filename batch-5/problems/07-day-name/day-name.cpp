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

short ReadDay()
{
	short day;
	cout << "\nPlease enter a day: ";
	cin >> day;

	return day;
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

string DayName(short dayOrder)
{
	string arrDayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return arrDayName[dayOrder];
}

int main()
{

	short year = ReadYear();
	short month = ReadMonth();
	short day = ReadDay();

	short dayOrder = DayOfWeekOrder(year, month, day);
	string dayName = DayName(dayOrder);

	cout << "\nDate     : " << day << "/" << month << "/" << year;
	cout << "\nDay Order: " << dayOrder;
	cout << "\nDay Name : " << dayName << endl;

	return 0;
}