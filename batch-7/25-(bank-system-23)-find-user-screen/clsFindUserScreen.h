#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{

private:

    static void _PrintUser(clsUser user)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirst Name  : " << user.firstName;
        cout << "\nLast Name   : " << user.lastName;
        cout << "\nFull Name   : " << user.FullName();
        cout << "\nEmail       : " << user.email;
        cout << "\nPhone       : " << user.phone;
        cout << "\nUsername    : " << user.userName;
        cout << "\nPassword    : " << user.password;
        cout << "\nPermissions : " << user.permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {

        DrawScreenHeader("\t  Find User Screen");

        string userName;
        cout << "\nPlease enter a username: ";
        userName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(userName))
        {
            cout << "\nUser not found. Please choose another username: ";
            userName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(userName);

        if (!User1.IsEmpty())
        {
            cout << "\nUser found :-)\n";
        }
        else
        {
            cout << "\nUser not found :-(\n";
        }

        _PrintUser(User1);

    }

};