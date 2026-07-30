#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency currency, string title)
	{
		cout << "\n" << title << "\n";
		cout << "_________________________\n";
		cout << "Country  : " << currency.Country() << endl;
		cout << "Code     : " << currency.CurrencyCode() << endl;
		cout << "Name     : " << currency.CurrencyName() << endl;
		cout << "Rate(1$) : " << currency.Rate() << endl;
		cout << "_________________________\n\n";
	}

	static clsCurrency _GetCurrency(string message)
	{
		string currencyCode;
		cout << message;

		currencyCode = clsInputValidate::ReadString();
		cout << "\n";

		while (!clsCurrency::DoesCurrencyExist(currencyCode))
		{
			cout << "The Currency was not found. Please choose another one: ";
			currencyCode = clsInputValidate::ReadString();
			cout << "\n";
		}

		clsCurrency currency = clsCurrency::FindByCode(currencyCode);

		return currency;
	}

	static double _ReadAmount()
	{

		double amount = 0;
		cout << "Please enter the amount to exchange: ";

		amount = clsInputValidate::ReadDblNumber();
		return amount;
	}

	static void _PrintCalculationResults(double amount, clsCurrency currency1, clsCurrency currency2)
	{
		_PrintCurrencyCard(currency1, "Currency Card :");

		double amountInUSD = currency1.ConvertToUSD(amount);

		cout << amount << " " << currency1.CurrencyCode() << " = "
			<< amountInUSD << " USD" << endl;

		if (currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to " << currency2.CurrencyCode() << ":\n";
		_PrintCurrencyCard(currency2, "Currency Card:");

		double amountInCurrency2 = currency1.ConvertToAnotherCurrency(amount, currency2);

		cout << amount << " " << currency1.CurrencyCode() << " = "
			<< amountInCurrency2 << " " << currency2.CurrencyCode() << endl;

	}

public:

	static void ShowCurrencyCalculatorScreen()
	{


		char answer = 'y';
		while (answer == 'y' || answer == 'Y')
		{
			system("cls");
			DrawScreenHeader("\t  Currency Calculator Screen");

			clsCurrency currencyFrom = _GetCurrency("Please enter a currency code 1: ");
			clsCurrency currencyTo = _GetCurrency("Please enter a currency code 2: ");
			double amount = _ReadAmount();

			_PrintCalculationResults(amount, currencyFrom, currencyTo);

			cout << "\n\nDo you want to perform another currency exchange? (y/n): ";
			cin >> answer;

		}

	}
};