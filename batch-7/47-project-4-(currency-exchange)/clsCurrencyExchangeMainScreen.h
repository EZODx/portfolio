#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:

	enum enCurrenciesMainMenuOptions {
		eCurrenciesList = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
		eCurrencyCalculator = 4, eMainMenu = 5
	};

    
    static void _GoBackToCurrenciesMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to the Currency menu...\n";
        system("pause > 0");
        ShowCurrenciesMenu();
    }

    static short _ReadCurrencyExchangeOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]: ";
        short option = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter a number from 1 to 5: ");
        return option;
    }

    static void _ShowCurrenciesListScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }


    static void _PerformCurrencyExchangeMenuOption(enCurrenciesMainMenuOptions option)
    {

        switch (option)
        {
        case enCurrenciesMainMenuOptions::eCurrenciesList:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenu();
        }

        case enCurrenciesMainMenuOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenu();
        }
        case enCurrenciesMainMenuOptions::eUpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenu();
        }
        case enCurrenciesMainMenuOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenu();
        }
        case enCurrenciesMainMenuOptions::eMainMenu:
        {
			// no action needed, it will go back to the main menu in the main function
        }

        }

    }


public:

	static void ShowCurrenciesMenu()
	{

        system("cls");

        DrawScreenHeader("   Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Currencies List.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenuOption((enCurrenciesMainMenuOptions)_ReadCurrencyExchangeOption());

	}


};