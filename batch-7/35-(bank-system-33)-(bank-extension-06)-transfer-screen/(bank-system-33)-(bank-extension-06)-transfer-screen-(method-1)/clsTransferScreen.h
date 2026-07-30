#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nBalance     : " << client.GetAccountBalance();
        cout << "\n___________________\n";
    }

public:

    static void ShowTransferScreen()
    {
        DrawScreenHeader("\t  Transfer Screen");

        string accountNumber = "";

        cout << "\nPlease enter the account number to transfer from: ";
        accountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(accountNumber))
        {
            cout << "\nAccount number not found. Choose another one: ";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(accountNumber);
        _PrintClient(client1);

        cout << "\nPlease enter the account number to transfer to: ";
        accountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(accountNumber))
        {
            cout << "\nAccount number not found. Choose another one: ";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client2 = clsBankClient::Find(accountNumber);
        _PrintClient(client2);

        double transferAmount = 0;
        cout << "\nEnter the amount: ";
        cin >> transferAmount;

        while (transferAmount > client1.accountBalance)
        {
            cout << "\nError! Please enter another amount: ";
            cin >> transferAmount;
        }

        char answer = 'n';
        cout << "\nAre you sure? (y/n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            client1.accountBalance -= transferAmount;
            client2.accountBalance += transferAmount;
        }

        clsBankClient::enSaveResults saveResult;
        saveResult = client1.Save();

        clsBankClient::enSaveResults saveResult2;
        saveResult2 = client2.Save();

        if (saveResult == clsBankClient::enSaveResults::svSucceeded &&
            saveResult2 == clsBankClient::enSaveResults::svSucceeded)
        {
            cout << "\nTransfer completed successfully.\n";
        }
        else
        {
            cout << "\nTransfer failed.\n";
        }

        _PrintClient(client1);
        cout << "\n\n";
        _PrintClient(client2);
    }

};