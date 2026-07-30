#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsFindClientScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient& client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.firstName;
        cout << "\nLastName    : " << client.lastName;
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.email;
        cout << "\nPhone       : " << client.phone;
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.GetPinCode();
        cout << "\nBalance     : " << client.GetAccountBalance();
        cout << "\n___________________\n";
    }


public: 

    static void ShowFindClientScreen()
    {

        if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return; // this will exit the function and it will not continue
        }


        DrawScreenHeader("\t Find Client Screen");

        string accountNumber = "";

        cout << "\nPlease Enter Client Account Number: ";
        accountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::DoesClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(accountNumber);

        if (!client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(client1);

    }

};