#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsUpdateClientScreen : protected clsScreen
{

private:

    static void _ReadClientInfo(clsBankClient& client)
    {
        cout << "\nEnter FirstName: ";
        client.firstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        client.lastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        client.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        client.phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        client.pinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        client.accountBalance = clsInputValidate::ReadFloatNumber();
    }

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

    static void ShowUpdateClientScreen()
    {

        if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return; // this will exit the function and it will not continue
        }

        DrawScreenHeader("\t Update Client Screen");

        string accountNumber = "";

        cout << "\nPlease Enter Client Account Number: ";
        accountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(accountNumber))
        {
            cout << "\nAccount number not found, choose another one: ";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(accountNumber);
        _PrintClient(client1);

        cout << "\nAre you sure you want to update this client? y/n: ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            _ReadClientInfo(client1);

            clsBankClient::enSaveResults saveResult;

            saveResult = client1.Save();

            switch (saveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount updated successfully :-)\n";
                _PrintClient(client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError! Account was not saved because it's empty.";
                break;
            }

            }
        }
    }

};