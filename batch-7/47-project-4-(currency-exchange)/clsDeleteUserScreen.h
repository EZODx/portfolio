#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"

class clsDeleteUserScreen : protected clsScreen
{

private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirst Name  : " << User.firstName;
        cout << "\nLast Name   : " << User.lastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.email;
        cout << "\nPhone       : " << User.phone;
        cout << "\nUser Name   : " << User.userName;
        cout << "\nPassword    : " << User.password;
        cout << "\nPermissions : " << User.permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowDeleteUserScreen()
    {

        DrawScreenHeader("\t  Delete User Screen");

        string userName = "";

        cout << "\nPlease Enter UserName: ";
        userName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(userName))
        {
            cout << "\nUser is not found, choose another one: ";
            userName = clsInputValidate::ReadString();
        }

        clsUser user1 = clsUser::Find(userName);
        _PrintUser(user1);

        char answer = 'n';

        cout << "\nAre you sure you want to delete this user y/n: ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {

            if (user1.Delete())
            {
                cout << "\nUser deleted successfully :-)\n";
                _PrintUser(user1);
            }
            else
            {
                cout << "\nError! User Was not Deleted\n";
            }

        }

    }

};