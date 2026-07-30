#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{

private:

	static void _Login()
	{

		string userName, password;

		bool loginFailed = false;
		do
		{

			if (loginFailed)
			{
				cout << "\nInvalid Username/Password!\n\n";
			}

			cout << "Enter username: ";
			cin >> userName;
			cout << "Enter password: ";
			cin >> password;

			currentUser = clsUser::Find(userName, password);

			loginFailed = currentUser.clsUser::IsEmpty();

		} while (loginFailed);

		clsMainScreen::ShowMainMenu();
	}

public:

	static void ShowLoginScreen()
	{
		system("cls");
		DrawScreenHeader("\t    Login Screen");
		_Login();
	}

};