#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& user)
    {
        cout << "\nEnter First Name: ";
        user.firstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        user.lastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        user.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        user.phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        user.password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        user.permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser& user)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << user.firstName;
        cout << "\nLastName    : " << user.lastName;
        cout << "\nFull Name   : " << user.FullName();
        cout << "\nEmail       : " << user.email;
        cout << "\nPhone       : " << user.phone;
        cout << "\nUser Name   : " << user.userName;
        cout << "\nPassword    : " << user.password;
        cout << "\nPermissions : " << user.permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int permissions = 0;
        char answer = 'n';


        cout << "\nDo you want to give full access? y/n: ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to: \n ";

        cout << "\nShow Client List? y/n: ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {


            permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nShow Login Register? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pShowLoginRegister;
        }

        return permissions;

    }


public:


    static void ShowAddNewUserScreen()
    {

        DrawScreenHeader("\t  Add New User Screen");

        string UserName = "";
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUsername is already used. Choose another one: ";

            UserName = clsInputValidate::ReadString();
        }

        clsUser newUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(newUser);

        clsUser::enSaveResults saveResult;

        saveResult = newUser.Save();


        switch (saveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Added Successfully :-)\n";
            _PrintUser(newUser);
            break;
        }
        case clsUser::enSaveResults::svFailedEmptyObject:
        {
            cout << "\nError! account was not saved because it's Empty";
            break;
        }
        case clsUser::enSaveResults::svFailedUserExists:
            cout << "\nError! account was not saved because account number is used!\n";
            break;

        }

    }


};