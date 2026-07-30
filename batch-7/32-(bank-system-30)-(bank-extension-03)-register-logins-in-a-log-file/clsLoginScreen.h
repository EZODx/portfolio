#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login()
	{

		string userName, password;
		short failedLoginCount = 0;

		bool loginFailed = false;
		do
		{

			if (loginFailed)
			{
				failedLoginCount += 1;

				cout << "\nInvalid Username/Password!\n\n";
				cout << "\nYou have " << (3 - failedLoginCount) << " attempt(s) left to log in.\n\n";
			}

			if (failedLoginCount == 3)
			{
				cout << "\nYour account has been locked after 3 failed login attempts.\n\n";
				return false;
			}

			cout << "Enter Username: ";
			cin >> userName;
			cout << "Enter Password: ";
			cin >> password;

			currentUser = clsUser::Find(userName, password);

			loginFailed = currentUser.clsUser::IsEmpty();

		} while (loginFailed);

		currentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		DrawScreenHeader("\t    Login Screen");
		return _Login();
	}

};