#pragma once

#include "clsScreen.h"

class clsTransferLogScreen : protected clsScreen
{

private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferRecord transferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << transferLogRecord.dateTime;
        cout << "| " << setw(8) << left << transferLogRecord.sourceAccountNumber;
        cout << "| " << setw(8) << left << transferLogRecord.destinationAccountNumber;
        cout << "| " << setw(8) << left << transferLogRecord.amount;
        cout << "| " << setw(10) << left << transferLogRecord.srcBalanceAfter;
        cout << "| " << setw(10) << left << transferLogRecord.desBalanceAfter;
        cout << "| " << setw(8) << left << transferLogRecord.userName;

    }

public:

    static void ShowTransferLogScreen()
    {

        vector<clsBankClient::stTransferRecord> vTransferLog = clsBankClient::GetTransferLogList();

        string title = "\t  Transfer Log List Screen";
        string subtitle = "\t     (" + to_string(vTransferLog.size()) + ") Record(s)";

        DrawScreenHeader(title, subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLog.size() == 0)
            cout << "\t\t\t\tNo transfer records available in the system!";
        else

            for (clsBankClient::stTransferRecord& record : vTransferLog)
            {

                _PrintTransferLogRecordLine(record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};