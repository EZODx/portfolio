#pragma once

#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientsScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsers.h"

void ShowMainMenu();

class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenuOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do [1 to 8] ";
        short choice = clsInputValidateReadShortNumberBetween(1, 8, "Enter a number from 1 to 8 ");
        return choice;
    }

    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\nPress any key to go back to Main Menu...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreenShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreenShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreenDeleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreenShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreenShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreenShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreenShowManageUsersMenue();
    }

    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";
    }


    static void _PerfromMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case eFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case eShowTransactionsMenue:
        {
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        }
        case eManageUsers:
        {
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        }
        case eExit:
        {
            system("cls");
            _ShowEndScreen();
            Login();
            break;
        }
        }
    }


public:

    static void ShowMainMenu()
    {
        system("cls");

        DrawScreenHeader("Main Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "[1] Show Client List.\n";
        cout << setw(37) << left << "" << "[2] Add New Client.\n";
        cout << setw(37) << left << "" << "[3] Delete Client.\n";
        cout << setw(37) << left << "" << "[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "[5] Find Client.\n";
        cout << setw(37) << left << "" << "[6] Transactions.\n";
        cout << setw(37) << left << "" << "[7] Manage Users.\n";
        cout << setw(37) << left << "" << "[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }

};