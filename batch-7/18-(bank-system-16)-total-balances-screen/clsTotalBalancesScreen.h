#pragma once

#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:

    static void _PrintClientRecordBalanceLine(clsBankClient client)
    {
        cout << setw(25) << left << client.AccountNumber();
        cout << setw(40) << left << client.FullName();
        cout << setw(12) << left << client.accountBalance;
    }

public:

    static void ShowTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string title = "Balances List Screen";
        string subtitle = "\t(" + to_string(vClients.size()) + ") Client(s)";

        DrawScreenHeader(title, subtitle);

        cout << setw(25) << left << "Account Number";
        cout << setw(40) << left << "Client Name";
        cout << setw(12) << left << "Balance";
        cout << "\n____________________________________________________________\n";

        double totalBalances = clsBankClient::GetTotalBalances();

        if (vClients.empty())
        {
            cout << "\t\tNo Clients Available In the System!\n";
        }
        else
        {
            for (clsBankClient& client : vClients)
            {
                _PrintClientRecordBalanceLine(client);
                cout << endl;
            }
        }

        cout << "\n____________________________________________________________\n";

        cout << "\t\tTotal Balances = " << totalBalances << endl;
        cout << "\t\t(" << clsUtil::NumberToText(totalBalances) << ")\n";
    }

};