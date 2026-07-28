#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include "clsString.h"

using namespace std;

class clsDate
{

private:

	short _day = 1;
	short _month = 1;
	short _year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_day = now->tm_mday;
		_month = now->tm_mon + 1;
		_year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{

		vector <string> vDate;
		vDate = clsString::Split(sDate, "/");

		_day = stoi(vDate[0]);
		_month = stoi(vDate[1]);
		_year = stoi(vDate[2]);

	}

	clsDate(short day, short month, short year)
	{

		_day = day;
		_month = month;
		_year = year;

	}

	clsDate(short dateOrderInYear, short year)
	{
		//This will construct a date by date order in year
		clsDate date1 = GetDateFromDayOrderInYear(dateOrderInYear, year);
		_day = date1.GetDay();
		_month = date1.GetMonth();
		_year = date1.GetYear();
	}

	void SetDay(short day)
	{
		_day = day;
	}

	short GetDay()
	{
		return _day;
	}

	void SetMonth(short month)
	{
		_month = month;
	}

	short GetMonth()
	{
		return _month;
	}

	void SetYear(short year)
	{
		_year = year;
	}

	short GetYear()
	{
		return _year;
	}

	/////////////////////////////////////

	void Print()
	{
		cout << DateToString() << endl;
	}

	static clsDate GetSystemDate()
	{
		//system date
		time_t t = time(0);
		tm* now = localtime(&t);

		short day, month, year;

		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;

		return clsDate(day, month, year);
	}

	static	bool IsValidDate(clsDate date)
	{

		if (date._day < 1 || date._day>31)
			return false;

		if (date._month < 1 || date._month>12)
			return false;

		if (date._month == 2)
		{
			if (isLeapYear(date._year))
			{
				if (date._day > 29)
					return false;
			}
			else
			{
				if (date._day > 28)
					return false;
			}
		}

		short daysInMonth = NumberOfDaysInAMonth(date._month, date._year);

		if (date._day > daysInMonth)
			return false;

		return true;

	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static string DateToString(clsDate date)
	{
		return  to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);
	}

	string DateToString()
	{
		return  DateToString(*this);
	}

	static bool isLeapYear(short year)
	{

		// if year is divisible by 4 AND not divisible by 100
	  // OR if year is divisible by 400
	  // then it is a leap year
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	bool isLeapYear()
	{
		return isLeapYear(_year);
	}

	static short NumberOfDaysInAYear(short year)
	{
		return  isLeapYear(year) ? 366 : 365;
	}

	short NumberOfDaysInAYear()
	{
		return  NumberOfDaysInAYear(_year);
	}

	static short NumberOfHoursInAYear(short year)
	{
		return  NumberOfDaysInAYear(year) * 24;
	}

	short NumberOfHoursInAYear()
	{
		return  NumberOfHoursInAYear(_year);
	}

	static int NumberOfMinutesInAYear(short year)
	{
		return  NumberOfHoursInAYear(year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return  NumberOfMinutesInAYear(_year);
	}

	static int NumberOfSecondsInAYear(short year)
	{
		return  NumberOfMinutesInAYear(year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return  NumberOfSecondsInAYear(_year);
	}

	static short NumberOfDaysInAMonth(short month, short year)
	{

		if (month < 1 || month>12)
			return  0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];

	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_month, _year);
	}

	static short NumberOfHoursInAMonth(short month, short year)
	{
		return  NumberOfDaysInAMonth(month, year) * 24;
	}

	short NumberOfHoursInAMonth()
	{
		return  NumberOfDaysInAMonth(_month, _year) * 24;
	}

	static int NumberOfMinutesInAMonth(short month, short year)
	{
		return  NumberOfHoursInAMonth(month, year) * 60;
	}

	int NumberOfMinutesInAMonth()
	{
		return  NumberOfHoursInAMonth(_month, _year) * 60;
	}

	static int NumberOfSecondsInAMonth(short month, short year)
	{
		return  NumberOfMinutesInAMonth(month, year) * 60;
	}

	int NumberOfSecondsInAMonth()
	{
		return  NumberOfMinutesInAMonth(_month, _year) * 60;
	}

	static short DayOfWeekOrder(short day, short month, short year)
	{
		short a, y, m;
		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_day, _month, _year);
	}

	static string DayShortName(short dayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[dayOfWeekOrder];

	}

	static string DayShortName(short day, short month, short year)
	{

		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder(day, month, year)];

	}

	string DayShortName()
	{

		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder(_day, _month, _year)];

	}

	static string MonthShortName(short monthNumber)
	{
		string months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};

		return (months[monthNumber - 1]);
	}

	string MonthShortName()
	{

		return MonthShortName(_month);
	}

	static void PrintMonthCalendar(short month, short year)
	{
		int numberOfDays;

		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, month, year);

		numberOfDays = NumberOfDaysInAMonth(month, year);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= numberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");

	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_month, _year);
	}

	static void PrintYearCalendar(int year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, year);
		}

		return;
	}

	void PrintYearCalendar()
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", _year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, _year);
		}

		return;
	}

	static short DaysFromTheBeginingOfTheYear(short day, short month, short year)
	{


		short totalDays = 0;

		for (int i = 1; i <= month - 1; i++)
		{
			totalDays += NumberOfDaysInAMonth(i, year);
		}

		totalDays += day;

		return totalDays;
	}

	short DaysFromTheBeginingOfTheYear()
	{


		short totalDays = 0;

		for (int i = 1; i <= _month - 1; i++)
		{
			totalDays += NumberOfDaysInAMonth(i, _year);
		}

		totalDays += _day;

		return totalDays;
	}

	static clsDate GetDateFromDayOrderInYear(short dateOrderInYear, short year)
	{

		clsDate date;
		short remainingDays = dateOrderInYear;
		short monthDays = 0;

		date._year = year;
		date._month = 1;

		while (true)
		{
			monthDays = NumberOfDaysInAMonth(date._month, year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				date._month++;
			}
			else
			{
				date._day = remainingDays;
				break;
			}

		}

		return date;
	}

	void AddDays(short days)
	{


		short remainingDays = days + DaysFromTheBeginingOfTheYear(_day, _month, _year);
		short monthDays = 0;

		_month = 1;

		while (true)
		{
			monthDays = NumberOfDaysInAMonth(_month, _year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				_month++;

				if (_month > 12)
				{
					_month = 1;
					_year++;

				}
			}
			else
			{
				_day = remainingDays;
				break;
			}

		}


	}

	static bool IsDate1BeforeDate2(clsDate date1, clsDate date2)
	{
		return  (date1._year < date2._year) ? true : ((date1._year == date2._year) ? (date1._month < date2._month ? true : (date1._month == date2._month ? date1._day < date2._day : false)) : false);
	}

	bool IsDateBeforeDate2(clsDate date2)
	{
		//note: *this sends the current object :-) 
		return  IsDate1BeforeDate2(*this, date2);

	}

	static bool IsDate1EqualDate2(clsDate date1, clsDate date2)
	{
		return  (date1._year == date2._year) ? ((date1._month == date2._month) ? ((date1._day == date2._day) ? true : false) : false) : false;
	}

	bool IsDateEqualDate2(clsDate date2)
	{
		return  IsDate1EqualDate2(*this, date2);
	}

	static bool IsLastDayInMonth(clsDate date)
	{

		return (date._day == NumberOfDaysInAMonth(date._month, date._year));

	}

	bool IsLastDayInMonth()
	{

		return IsLastDayInMonth(*this);

	}

	static bool IsLastMonthInYear(short month)
	{
		return (month == 12);
	}

	static clsDate AddOneDay(clsDate date)
	{
		if (IsLastDayInMonth(date))
		{
			if (IsLastMonthInYear(date._month))
			{
				date._month = 1;
				date._day = 1;
				date._year++;
			}
			else
			{
				date._day = 1;
				date._month++;
			}
		}
		else
		{
			date._day++;
		}

		return date;
	}

	void AddOneDay()

	{
		*this = AddOneDay(*this);
	}

	static void  SwapDates(clsDate& date1, clsDate& date2)
	{

		clsDate tempDate;
		tempDate = date1;
		date1 = date2;
		date2 = tempDate;

	}

	static int GetDifferenceInDays(clsDate date1, clsDate date2, bool includeEndDay = false)
	{
		//this will take care of negative diff
		int days = 0;
		short sawpFlagValue = 1;

		if (!IsDate1BeforeDate2(date1, date2))
		{
			//Swap Dates 
			SwapDates(date1, date2);
			sawpFlagValue = -1;

		}

		while (IsDate1BeforeDate2(date1, date2))
		{
			days++;
			date1 = AddOneDay(date1);
		}

		return includeEndDay ? ++days * sawpFlagValue : days * sawpFlagValue;
	}

	int GetDifferenceInDays(clsDate date2, bool includeEndDay = false)
	{
		return GetDifferenceInDays(*this, date2, includeEndDay);
	}

	static int CalculateMyAgeInDays(clsDate dateOfBirth)
	{
		return GetDifferenceInDays(dateOfBirth, clsDate::GetSystemDate(), true);
	}
	//above no need to have nonstatic function for the object because it doesn't depend on any data from it.

	static clsDate IncreaseDateByOneWeek(clsDate& date)
	{

		for (int i = 1; i <= 7; i++)
		{
			date = AddOneDay(date);
		}

		return date;
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short weeks, clsDate& date)
	{

		for (short i = 1; i <= weeks; i++)
		{
			date = IncreaseDateByOneWeek(date);
		}
		return date;
	}

	void IncreaseDateByXWeeks(short weeks)
	{
		IncreaseDateByXWeeks(weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& date)
	{

		if (date._month == 12)
		{
			date._month = 1;
			date._year++;
		}
		else
		{
			date._month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date._month, date._year);
		if (date._day > numberOfDaysInCurrentMonth)
		{
			date._day = numberOfDaysInCurrentMonth;
		}

		return date;
	}

	void IncreaseDateByOneMonth()
	{

		IncreaseDateByOneMonth(*this);

	}

	static clsDate IncreaseDateByXDays(short days, clsDate& date)
	{

		for (short i = 1; i <= days; i++)
		{
			date = AddOneDay(date);
		}
		return date;
	}

	void IncreaseDateByXDays(short days)
	{

		IncreaseDateByXDays(days, *this);
	}

	static clsDate IncreaseDateByXMonths(short months, clsDate& date)
	{

		for (short i = 1; i <= months; i++)
		{
			date = IncreaseDateByOneMonth(date);
		}
		return date;
	}

	void IncreaseDateByXMonths(short months)
	{
		IncreaseDateByXMonths(months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& date)
	{
		date._year++;
		return date;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short years, clsDate& date)
	{
		date._year += years;
		return date;

	}

	void IncreaseDateByXYears(short years)
	{
		IncreaseDateByXYears(years, *this);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& date)
	{
		//Period of 10 years
		date._year += 10;
		return date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short decade, clsDate& date)
	{
		date._year += decade * 10;
		return date;
	}

	void IncreaseDateByXDecades(short decade)
	{
		IncreaseDateByXDecades(decade, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& date)
	{
		//Period of 100 years
		date._year += 100;
		return date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& date)
	{
		//Period of 1000 years
		date._year += 1000;
		return date;
	}

	void IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& date)
	{
		if (date._day == 1)
		{
			if (date._month == 1)
			{
				date._month = 12;
				date._day = 31;
				date._year--;
			}
			else
			{

				date._month--;
				date._day = NumberOfDaysInAMonth(date._month, date._year);
			}
		}
		else
		{
			date._day--;
		}

		return date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& date)
	{

		for (int i = 1; i <= 7; i++)
		{
			date = DecreaseDateByOneDay(date);
		}

		return date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short weeks, clsDate& date)
	{

		for (short i = 1; i <= weeks; i++)
		{
			date = DecreaseDateByOneWeek(date);
		}
		return date;
	}

	void DecreaseDateByXWeeks(short weeks)
	{
		DecreaseDateByXWeeks(weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& date)
	{

		if (date._month == 1)
		{
			date._month = 12;
			date._year--;
		}
		else
			date._month--;


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date._month, date._year);
		if (date._day > numberOfDaysInCurrentMonth)
		{
			date._day = numberOfDaysInCurrentMonth;
		}


		return date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short days, clsDate& date)
	{

		for (short i = 1; i <= days; i++)
		{
			date = DecreaseDateByOneDay(date);
		}
		return date;
	}

	void DecreaseDateByXDays(short days)
	{
		DecreaseDateByXDays(days, *this);
	}

	static clsDate DecreaseDateByXMonths(short months, clsDate& date)
	{

		for (short i = 1; i <= months; i++)
		{
			date = DecreaseDateByOneMonth(date);
		}
		return date;
	}

	void DecreaseDateByXMonths(short months)
	{
		DecreaseDateByXMonths(months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& date)
	{

		date._year--;
		return date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short years, clsDate& date)
	{

		date._year -= years;
		return date;
	}

	void DecreaseDateByXYears(short years)
	{
		DecreaseDateByXYears(years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& date)
	{
		//Period of 10 years
		date._year -= 10;
		return date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short decades, clsDate& date)
	{

		date._year -= decades * 10;
		return date;
	}

	void DecreaseDateByXDecades(short decades)
	{
		DecreaseDateByXDecades(decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& date)
	{
		//Period of 100 years
		date._year -= 100;
		return date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& date)
	{
		//Period of 1000 years
		date._year -= 1000;
		return date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(clsDate date)
	{
		return  DayOfWeekOrder(date._day, date._month, date._year) == 6;
	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate date)
	{
		//Weekends are Fri and Sat
		short dayIndex = DayOfWeekOrder(date._day, date._month, date._year);
		return  (dayIndex == 5 || dayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate date)
	{
		//Weekends are Sun,Mon,Tue,Wed and Thur

	   /*
		short dayIndex = DayOfWeekOrder(date.Day, date.Month, date.Year);
		return  (dayIndex >= 5 && dayIndex <= 4);
	   */

	   //shorter method is to invert the IsWeekEnd: this will save updating code.
		return !IsWeekEnd(date);

	}

	bool IsBusinessDay()
	{
		return  IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate date)
	{
		return 6 - DayOfWeekOrder(date._day, date._month, date._year);
	}

	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate date1)
	{

		clsDate endOfMontDate;
		endOfMontDate._day = NumberOfDaysInAMonth(date1._month, date1._year);
		endOfMontDate._month = date1._month;
		endOfMontDate._year = date1._year;

		return GetDifferenceInDays(date1, endOfMontDate, true);

	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate date1)
	{

		clsDate endOfYearDate;
		endOfYearDate._day = 31;
		endOfYearDate._month = 12;
		endOfYearDate._year = date1._year;

		return GetDifferenceInDays(date1, endOfYearDate, true);

	}

	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	// Counts business days in the range [dateFrom, dateTo)
	static short CalculateBusinessDays(clsDate dateFrom, clsDate dateTo)
	{

		short days = 0;
		while (IsDate1BeforeDate2(dateFrom, dateTo))
		{
			if (IsBusinessDay(dateFrom))
				days++;

			dateFrom = AddOneDay(dateFrom);
		}

		return days;

	}

	static short CalculateVacationDays(clsDate dateFrom, clsDate dateTo)
	{
		/*short days = 0;
		while (IsDate1BeforeDate2(dateFrom, dateTo))
		{
			if (IsBusinessDay(dateFrom))
				days++;

			dateFrom = AddOneDay(dateFrom);
		}*/

		return CalculateBusinessDays(dateFrom, dateTo);

	}
	// Above, a static method is enough; there is no need to have a method for the object.

	static clsDate CalculateVacationReturnDate(clsDate dateFrom, short vacationDays)
	{

		short weekEndCounter = 0;

		for (short i = 1; i <= vacationDays; i++)
		{

			if (IsWeekEnd(dateFrom))
				weekEndCounter++;

			dateFrom = AddOneDay(dateFrom);
		}
		//to add weekends 
		for (short i = 1; i <= weekEndCounter; i++)
			dateFrom = AddOneDay(dateFrom);

		return dateFrom;
	}

	static bool IsDate1AfterDate2(clsDate date1, clsDate date2)
	{
		return (!IsDate1BeforeDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));

	}

	bool IsDateAfterDate2(clsDate date2)
	{
		return IsDate1AfterDate2(*this, date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate date1, clsDate date2)
	{
		if (IsDate1BeforeDate2(date1, date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(date1, date2))
			return enDateCompare::Equal;

		/* if (IsDate1AfterDate2(date1,date2))
			 return enDateCompare::After;*/

			 //this is faster
		return enDateCompare::After;

	}

	enDateCompare CompareDates(clsDate date2)
	{
		return CompareDates(*this, date2);
	}

};