#include <iostream>
#include <vector>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"

void PrintClientRecordLine(clsBankClient& client)
{
    cout << "| " << left << setw(14) << client.AccountNumber();
    cout << "| " << left << setw(25) << client.FullName();
    cout << "| " << left << setw(10) << client.phone;
    cout << "| " << left << setw(20) << client.email;
    cout << "| " << left << setw(10) << client.pinCode;
    cout << "| " << left << setw(10) << client.accountBalance << endl;
}

void ShowClientsList()
{
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\t\t\t\tClients List (" << vClients.size() << ") Client(s)\n";
    cout << "___________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(14) << "Account Number";
    cout << "| " << left << setw(25) << "Client Name";
    cout << "| " << left << setw(10) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "PIN Code";
    cout << "| " << left << setw(10) << "Balance" << endl;
    cout << "___________________________________________________________________________________________________\n";

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo clients available in the system!";
    else
    {
        for (clsBankClient& C : vClients)
        {
            PrintClientRecordLine(C);
        }
    }

    cout << "___________________________________________________________________________________________________\n";
}

int main()
{

    ShowClientsList();

    return 0;
}