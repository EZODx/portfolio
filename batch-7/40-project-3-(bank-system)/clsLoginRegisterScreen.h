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

		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
		{
			return; // this will exit the function and it will not continue
		}


		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string title = "\t  LoginRegisterScreen";
		string subtitle = "\t     (" + to_string(vLoginRegisterRecord.size()) + ") Record(s)";

		DrawScreenHeader(title, subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Available In The System!";
		else

			for (clsUser::stLoginRegisterRecord& record : vLoginRegisterRecord)
			{

				_PrintLoginRegisterRecordLine(record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};