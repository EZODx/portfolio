#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsInputValidate.h"

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

    static string _ReadAccountNumber()
    {
        string accountNumber = "";

        accountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::DoesClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::ReadString();
        }
        return accountNumber;
    }

    static double _ReadAmount(clsBankClient client)
    {
        double transferAmount = 0;
        cout << "\nEnter transfer amount: ";
        transferAmount = clsInputValidate::ReadDblNumber();

        while (transferAmount > client.accountBalance)
        {
            cout << "\nAmount exceeds the available balance, enter another amount: ";
            transferAmount = clsInputValidate::ReadDblNumber();
        }
        return transferAmount;
    }

public:

    static void ShowTransferScreen()
    {
        DrawScreenHeader("\t  Transfer Screen");

       
        cout << "\nPlease enter account number to transfer from: ";
        clsBankClient sourceClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(sourceClient);

        cout << "\nPlease enter account number to transfer to: ";
        clsBankClient destinationClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(destinationClient);

        ////////////

        double transferAmount = _ReadAmount(sourceClient);

        char answer = 'n';
        cout << "\nAre you sure you want to perform this operation? y/n? ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            if (sourceClient.Transfer(transferAmount, destinationClient, currentUser.userName))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Failed\n";
            }
        }
        else
        {
            cout << "\nTransfer canceled\n";
        }

        _PrintClient(sourceClient);
        _PrintClient(destinationClient);

	}

};