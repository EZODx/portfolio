#pragma once

#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private: 

    static void _ReadClientInfo(clsBankClient& client)
    {
        cout << "\nEnter First Name: ";
        client.firstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        client.lastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        client.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        client.phone = clsInputValidate::ReadString();

        cout << "\nEnter PIN Code: ";
        client.pinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        client.accountBalance = clsInputValidate::ReadFloatNumber();

    }

    static void _PrintClient(clsBankClient& client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirst Name  : " << client.firstName;
        cout << "\nLast Name   : " << client.lastName;
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.email;
        cout << "\nPhone       : " << client.phone;
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.GetPinCode();
        cout << "\nBalance     : " << client.GetAccountBalance();
        cout << "\n___________________\n";
    }


public:


    static void ShowAddNewClientScreen()
    {

        if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return; // this will exit the function and it will not continue
        }


        DrawScreenHeader("\t  Add New Client Screen");

        string accountNumber = "";
        cout << "Please enter account number: ";
        accountNumber = clsInputValidate::ReadString();

        while (clsBankClient::DoesClientExist(accountNumber))
        {
            cout << "\nAccount number already exists. Please enter another account number: ";

            accountNumber = clsInputValidate::ReadString();
        }

        clsBankClient newClient = clsBankClient::GetAddNewClient(accountNumber);

        _ReadClientInfo(newClient);

        clsBankClient::enSaveResults saveResult;

        saveResult = newClient.Save();


        switch (saveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Added Successfully :-)\n";
            _PrintClient(newClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError! Account was not saved because it's empty.";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
            cout << "\nError! Account was not saved because the account number is already in use!\n";
            break;

        }

    }

};