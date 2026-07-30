#pragma once

#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:


	template <typename T>
	static bool IsNumberBetween(T number, T from, T to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	// The functions below kept for backward compatibility with existing codebase.
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

	//////


	template <typename T>
	static T ReadNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		T number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return number;
	}

	// The functions below kept for backward compatibility with existing codebase.
	static short ReadShortNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		short number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return number;
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

	static double ReadFloatNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return Number;
	}

	//////


	template <typename T>
	static T ReadNumberBetween(T from, T to,
		string errorMessage = "Number is not within range, Enter again:\n")
	{
		T number = ReadNumber<T>();

		while (!IsNumberBetween(number, from, to))
		{
			cout << errorMessage;
			number = ReadNumber<T>();
		}
		return number;
	}

	// The functions below kept for backward compatibility with existing codebase.
	static short ReadShortNumberBetween(short from, short to, string errorMessage = "Number is not within range, Enter again:\n")
	{
		short number = ReadShortNumber();

		while (!IsNumberBetween(number, from, to))
		{
			cout << errorMessage;
			number = ReadShortNumber();
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

	static double ReadDblNumberBetween(double from, double to, string errorMessage = "Number is not within range, Enter again:\n")
	{
		double number = ReadDblNumber();

		while (!IsNumberBetween(number, from, to)) {
			cout << errorMessage;
			number = ReadDblNumber();
		}
		return number;
	}

	static float ReadFloatNumberBetween(float from, float to, string errorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, from, to)) {
			cout << errorMessage;
			Number = ReadFloatNumber();
		}
		return Number;
	}

	//////


	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
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

	static bool IsValidDate(clsDate date)
	{
		return	clsDate::IsValidDate(date);
	}


};