#pragma once

#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientsScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"

class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenuOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenu = 6,
        eManageUsers = 7,
        eExit = 8
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << ""
             << "Choose what do you want to do? [1 to 8]: ";

        return clsInputValidate::ReadShortNumberBetween(
            1, 8, "Enter a number from 1 to 8: ");
    }

    static void _GoBackToMainMenu()
    {
        cout << setw(37) << left << ""
             << "\n\tPress any key to go back to Main Menu...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        cout << "\nUpdate Client Screen Will be here...\n";
    }

    static void _ShowFindClientScreen()
    {
        cout << "\nFind Client Screen Will be here...\n";
    }

    static void _ShowTransactionsMenu()
    {
        cout << "\nTransactions Menu Will be here...\n";
    }

    static void _ShowManageUsersMenu()
    {
        cout << "\nUsers Menu Will be here...\n";
    }

    static void _ShowEndScreen()
   {
        cout << "\nEnd Screen Will be here...\n";
    }

    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;

        case eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;

        case eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;

        case eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;

        case eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;

        case eShowTransactionsMenu:
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;

        case eManageUsers:
            system("cls");
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;

        case eExit:
            system("cls");
            _ShowEndScreen();
            // Login();
            break;
        }
    }

public:

    static void ShowMainMenu()
    {
        system("cls");

        DrawScreenHeader("\t\tMain Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption(
            (enMainMenuOptions)_ReadMainMenuOption());
    }
};