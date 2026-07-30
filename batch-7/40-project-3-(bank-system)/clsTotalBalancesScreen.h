#pragma once

#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <vector>

class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void _PrintClientRecordBalanceLine(clsBankClient client)
	{
		cout << setw(25) << left << "" << "| " << setw(15) << left << client.AccountNumber();
		cout << "| " << setw(40) << left << client.FullName();
		cout << "| " << setw(12) << left << client.accountBalance;

	}


public:

	static void ShowTotalBalances()
	{

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string title = "\t  Balances List Screen";
		string subtitle = "\t     (" + to_string(vClients.size()) + ") Client(s)";

		DrawScreenHeader(title, subtitle);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		double totalBalances = clsBankClient::TotalBalances();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t     Total Balances = " << totalBalances << endl;
		cout << setw(8) << left << "" << "\t\t\t  ( " << clsUtil::NumberToText(totalBalances) << ")";
	}

};

