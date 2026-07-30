#pragma once

#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
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

    static string _ReadAccountNumber()
    {
        string accountNumber = "";
        cout << "\nPlease enter the account number: ";
        cin >> accountNumber;
        return accountNumber;
    }

    static double _ReadAmount()
    {
        double amount = 0;
        do
        {
            cout << "Please enter the withdraw amount: ";
            amount = clsInputValidate::ReadDblNumber();
        } while (amount <= 0);
        return amount;
    }

public:

    static void ShowWithdrawScreen()
    {

        DrawScreenHeader("\t  Withdraw Screen");

        string accountNumber = "";
        accountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = _ReadAccountNumber();
        }

        clsBankClient client1 = clsBankClient::Find(accountNumber);
        _PrintClient(client1);

        double amount = _ReadAmount();

        char answer = 'n';
        cout << "\nAre you sure you want to perform this transaction? y/n: ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            if (client1.WithDraw(amount))
            {
                cout << "\nAmount Withdrawn Successfully.\n";
                cout << "\nThe New Balance Is: " << client1.accountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, insufficient balance!\n";
                cout << "\nAmount to withdraw is: " << amount;
                cout << "\nYour Balance is: " << client1.accountBalance;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};