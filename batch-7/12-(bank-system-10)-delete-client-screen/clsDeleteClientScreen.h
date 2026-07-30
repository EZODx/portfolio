#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"


class clsDeleteClientScreen : protected clsScreen
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

    static void DeleteClient()
    {

        DrawScreenHeader("\t  Delete Client Screen");

        string accountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        accountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(accountNumber);
        _PrintClient(client1);

        char answer = 'n';

        cout << "\nAre you sure you want to delete this client y/n? ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {

            if (client1.DeleteClient())
            {
                cout << "\nClient deleted successfully :-)\n";
                _PrintClient(client1);
            }
            else
            {
                cout << "\nError! Client was not deleted\n";
            }

        }

    }

};