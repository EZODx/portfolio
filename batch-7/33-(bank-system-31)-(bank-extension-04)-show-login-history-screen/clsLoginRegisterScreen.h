#pragma once

#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsDate.h"
#include "Global.h"

class clsLoginRegisterScreen : protected clsScreen
{

private:

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord loginRegisterRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(25) << left << loginRegisterRecord.dateTime;
		cout << "| " << setw(20) << left << loginRegisterRecord.userName;
		cout << "| " << setw(12) << left << loginRegisterRecord.password;
		cout << "| " << setw(20) << left << loginRegisterRecord.permissions;

	}

public:

	static void ShowLoginRegisterScreen()
	{

		vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::GetLoginRegisterList();

		string title = "Login Register Screen";
		string subtitle = "(" + to_string(vLoginRegisterRecords.size()) + ") Record(s)";

		DrawScreenHeader(title, subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisterRecords.size() == 0)
			cout << "\t\t\t\tNo Login Records Available in the System!";
		else

			for (clsUser::stLoginRegisterRecord& record : vLoginRegisterRecords)
			{

				_PrintLoginRegisterRecordLine(record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};