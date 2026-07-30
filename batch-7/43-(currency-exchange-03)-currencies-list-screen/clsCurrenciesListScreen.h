#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>


class clsCurrenciesListScreen : protected clsScreen
{

private:

	static void _PrintCurrencyRecordLine(clsCurrency currency)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << currency.Country();
		cout << "| " << setw(8) << left << currency.CurrencyCode();
		cout << "| " << setw(45) << left << currency.CurrencyName();
		cout << "| " << setw(10) << left << currency.Rate();

	}


public:

	static void ShowCurrenciesListScreen()
	{

		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t Currencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currencies";

		DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;


		for (clsCurrency& C : vCurrencies)
		{
			if (vCurrencies.size() == 0)
			{
				cout << "\t\t\t\tNo Currencies Available In the System!";
			}
			else
			{
				_PrintCurrencyRecordLine(C);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
	}

};

