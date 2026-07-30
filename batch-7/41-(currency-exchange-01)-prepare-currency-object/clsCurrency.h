#pragma once

#include <iostream>
#include "clsUtil.h"
#include "clsString.h"
#include <fstream>


using namespace std;

class clsCurrency
{

private:

	enum enMode { emptyMode = 0, updateMode = 1 };
	enMode _mode;

	string _country;
	string _currencyCode;
	string _currencyName;
	float _rate;

	static string _ConvertCurrencyObjectToLine(clsCurrency currency, string seperator = "#//#")
	{
		string currencyRecord = "";

		currencyRecord += currency.Country() + seperator;
		currencyRecord += currency.CurrencyCode() + seperator;
		currencyRecord += currency.CurrencyName() + seperator;
		currencyRecord += to_string(currency.Rate()) + seperator;

		return currencyRecord;

	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
	{
		
		string dataLine = "";

		fstream myFile;
		myFile.open("Currencies.txt", ios::out);

		if (myFile.is_open())
		{
			for (clsCurrency& C : vCurrencies)
			{
				dataLine = _ConvertCurrencyObjectToLine(C);
				myFile << dataLine << endl;
			}

			myFile.close();
		}
	}

	static clsCurrency _ConvertLineToCurrencyObject(string line, string seperator = "#//#")
	{
		
		vector <string> vCurrencyData = clsString::Split(line, seperator);

		return clsCurrency(enMode::updateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}

	static vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{

		vector <clsCurrency> vCurrencies;

		fstream myFile;
		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open())
		{

			string line;

			while (getline(myFile, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				vCurrencies.push_back(currency);
			}

			myFile.close();
		}

		return vCurrencies;
	}

	void _Update()
	{
		vector <clsCurrency> _vCurrency = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : _vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(_vCurrency);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::emptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate)
	{
		_mode = mode;
		_country = country;
		_currencyCode = currencyCode;
		_currencyName = currencyName;
		_rate = rate;
	}

	bool IsEmpty()
	{
		return (_mode == enMode::emptyMode);
	}

	string Country()
	{
		return _country;
	}

	string CurrencyCode()
	{
		return _currencyCode;
	}

	string CurrencyName()
	{
		return _currencyName;
	}

	float Rate()
	{
		return _rate;
	}

	void UpdateRate(float newRate)
	{
		_rate = newRate;
		_Update();
	}

	static clsCurrency FindByCode(string currencyCode)
	{
		currencyCode = clsString::UpperAllString(currencyCode);

		fstream myFile;
		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open())
		{
			
			string line;
			while (getline(myFile, line))
			{

				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				if (currency.CurrencyCode() == currencyCode)
				{
					myFile.close();
					return currency;
				}

			}

			myFile.close();
		}


		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string country)
	{
		country = clsString::UpperAllString(country);

		fstream myFile;
		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open())
		{

			string line;
			while (getline(myFile, line))
			{

				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				if (clsString::UpperAllString(currency.Country()) == country)
				{
					myFile.close();
					return currency;
				}

			}

			myFile.close();
		}


		return _GetEmptyCurrencyObject();
	}

	static bool DoesCurrencyExist(string currencyCode)
	{
		clsCurrency c = clsCurrency::FindByCode(currencyCode);
		return (!c.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

};

