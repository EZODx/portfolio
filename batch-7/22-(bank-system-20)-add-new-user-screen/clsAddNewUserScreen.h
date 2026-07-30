#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter First Name: ";
        User.firstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        User.lastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser& User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.firstName;
        cout << "\nLastName    : " << User.lastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.email;
        cout << "\nPhone       : " << User.phone;
        cout << "\nUser Name   : " << User.userName;
        cout << "\nPassword    : " << User.password;
        cout << "\nPermissions : " << User.permissions;
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
            permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pManageUsers;
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