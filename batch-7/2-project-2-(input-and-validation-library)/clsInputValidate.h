#pragma once

#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	static bool IsNumberBetween(short number, short from, short to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int number, int from, int to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;

	}

	static bool IsNumberBetween(float number, float from, float to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double number, double from, double to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate date, clsDate from, clsDate to)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(date, from) || clsDate::IsDate1EqualDate2(date, from))
			&&
			(clsDate::IsDate1BeforeDate2(date, to) || clsDate::IsDate1EqualDate2(date, to))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(date, to) || clsDate::IsDate1EqualDate2(date, to))
			&&
			(clsDate::IsDate1BeforeDate2(date, from) || clsDate::IsDate1EqualDate2(date, from))
			)
		{
			return true;
		}

		return false;
	}

	static int ReadIntNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		int number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return number;
	}

	static int ReadIntNumberBetween(int from, int to, string errorMessage = "Number is not within range, Enter again:\n")
	{
		int number = ReadIntNumber();

		while (!IsNumberBetween(number, from, to))
		{
			cout << errorMessage;
			number = ReadIntNumber();
		}
		return number;
	}

	static double ReadDblNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		double number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return number;
	}

	static double ReadDblNumberBetween(double from, double to, string errorMessage = "Number is not within range, Enter again:\n")
	{
		double number = ReadDblNumber();

		while (!IsNumberBetween(number, from, to)) {
			cout << errorMessage;
			number = ReadDblNumber();
		}
		return number;
	}

	static bool IsValidDate(clsDate date)
	{
		return	clsDate::IsValidDate(date);
	}

};