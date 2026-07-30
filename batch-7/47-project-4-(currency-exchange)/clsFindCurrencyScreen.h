#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{

private:

	static short _ReadFindCurrencyMethod()
	{
		short findMethod = 0;
		cout << "Find by: [1] Currency Code\n";
		cout << "         [2] Currency Name\n";
		findMethod = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter a number from 1 to 2: ");
		
		return findMethod;
	}

	static void _PrintCurrencyCard(clsCurrency currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_________________________\n";
		cout << "Country  : " << currency.Country() << endl;
		cout << "Code     : " << currency.CurrencyCode() << endl;
		cout << "Name     : " << currency.CurrencyName() << endl;
		cout << "Rate(1$) : " << currency.Rate() << endl;
		cout << "_________________________\n\n";
	}

	static void _ShowResult(clsCurrency currency)
	{

		if (!currency.IsEmpty())
		{
			_PrintCurrencyCard(currency);
		}
		else
		{
			cout << "\nCurrency not found!\n";
		}

	}

public:

	static void ShowFindCurrencyScreen()
	{

		DrawScreenHeader("\t Find Currency Screen");

		short findMethod = _ReadFindCurrencyMethod();

		if (findMethod == 1)
		{
			string currencyCode = "";
			cout << "\nPlease enter a currency code: ";
			currencyCode = clsInputValidate::ReadString();
			clsCurrency currency = clsCurrency::FindByCode(currencyCode);
			_ShowResult(currency);
		}
		else
		{
			string countryName = "";
			cout << "\nPlease enter a country name: ";
			countryName = clsInputValidate::ReadString();
			clsCurrency currency = clsCurrency::FindByCountry(countryName);
			_ShowResult(currency);
		}

	}

};