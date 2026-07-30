#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
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

	static float _RaedNewRate()
	{
		float newRate = 0;
		cout << "\nUpdate Currency Rate";
		cout << "\n______________________________\n";
		cout << "Enter the new currency rate: ";
		newRate = clsInputValidate::ReadFloatNumber();
		return newRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{

		DrawScreenHeader("\t  Update Rate Screen");

		string currencyCode = "";

		cout << "\nPlease enter a currency code: ";
		currencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::DoesCurrencyExist(currencyCode))
		{
            cout << "\nThe Currency was not found. Please choose another one: ";
			currencyCode = clsInputValidate::ReadString();
		}

		clsCurrency currency = clsCurrency::FindByCode(currencyCode);
		_PrintCurrencyCard(currency);

		char answer = 'n';
		cout << "\nAre you sure you want to update the rate of this Currency y/n: ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{

			currency.UpdateRate(_RaedNewRate());
			cout << "\nCurrency rate updated successfully :-)\n";

			_PrintCurrencyCard(currency);
		}
		else
		{
			cout << "\nUpdate currency rate canceled.\n";
		}

	}

};