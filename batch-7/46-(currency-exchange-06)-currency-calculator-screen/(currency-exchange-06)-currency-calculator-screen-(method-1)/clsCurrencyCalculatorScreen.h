#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

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


public:

	static void ShowCurrencyCalculatorScreen()
	{


		char answer = 'n';
		do
		{
			system("cls");
			DrawScreenHeader("\t  Currency Calculator Screen");

			string currencyCode1 = "";

			cout << "\nPlease choose a currency code 1: ";
			currencyCode1 = clsInputValidate::ReadString();
			while (!clsCurrency::DoesCurrencyExist(currencyCode1))
			{
				cout << "\nThe Currency was not found. Please choose another one: ";
				currencyCode1 = clsInputValidate::ReadString();
			}

			clsCurrency currency1 = clsCurrency::FindByCode(currencyCode1);

			////////////////////////////////

			string currencyCode2 = "";
			cout << "\nPlease enter a currency code 2: ";
			currencyCode2 = clsInputValidate::ReadString();
			while (!clsCurrency::DoesCurrencyExist(currencyCode2))
			{
				cout << "\nThe Currency was not found. Please choose another one: ";
				currencyCode2 = clsInputValidate::ReadString();
			}

			clsCurrency currency2 = clsCurrency::FindByCode(currencyCode2);

			double amount;
			cout << "\nPlease enter the amount to exchange: ";
			cin >> amount;



			if (currency2.CurrencyCode() == "USD")
			{

				_PrintCurrencyCard(currency1);
				cout << "\n";
				cout << amount << " " << currency1.CurrencyCode() <<
					" = " << amount / currency1.Rate() << " " << currency2.CurrencyCode() << endl;

			}
			else
			{

				_PrintCurrencyCard(currency1);
				cout << amount << " " << currency1.CurrencyCode() <<
					" = " << amount / currency1.Rate() << " " << currency2.CurrencyCode() << endl;


				cout << "\nConverting from USD to " << currency2.CurrencyCode() << ":" << endl;
				_PrintCurrencyCard(currency2);
				amount / currency1.Rate() * currency2.Rate();
				cout << amount << " " << currency1.CurrencyCode() << " = " << amount / currency1.Rate() * currency2.Rate() << " " << currency2.CurrencyCode() << endl;

			}

			cout << "\n\nDo you want to perform another currency exchange? (y/n): ";
			cin >> answer;

		} while (answer == 'y' || answer == 'Y');

	}
};