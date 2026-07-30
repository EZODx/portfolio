#include <iostream>
#include <vector>
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

void PrintClientRecordBalanceLine(clsBankClient& client)
{
    cout << "| " << left << setw(14) << client.AccountNumber();
    cout << "| " << left << setw(25) << client.FullName();
    cout << "| " << left << setw(10) << client.accountBalance << endl;
}

void ShowTotalBalances()
{
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\t\tClients List (" << vClients.size() << ") Client(s)\n";
    cout << "_________________________________________________________\n\n";
    cout << "| " << left << setw(14) << "Account Number";
    cout << "| " << left << setw(25) << "Client Name";
    cout << "| " << left << setw(10) << "Balance" << endl;
    cout << "_________________________________________________________\n\n";

    double totalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo clients available in the system!";
    else
    {
        for (clsBankClient& C : vClients)
        {
            PrintClientRecordBalanceLine(C);
        }
    }

    cout << "_________________________________________________________\n\n";
    cout << "\tTotal Balances = " << totalBalances << endl;
    cout << "\t(" << clsUtil::NumberToText(totalBalances) << ")\n";
}

int main()
{

    ShowTotalBalances();

    return 0;
}