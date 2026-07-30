#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen

{
private:


    static void _ReadUserInfo(clsUser& user)
    {
        cout << "\nEnter first name: ";
        user.firstName = clsInputValidate::ReadString();

        cout << "\nEnter last name: ";
        user.lastName = clsInputValidate::ReadString();

        cout << "\nEnter email: ";
        user.email = clsInputValidate::ReadString();

        cout << "\nEnter phone: ";
        user.phone = clsInputValidate::ReadString();

        cout << "\nEnter password: ";
        user.password = clsInputValidate::ReadString();

        cout << "\nSet permissions: ";
        user.permissions = _ReadPermissionsToSet();
    }

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

    static int _ReadPermissionsToSet()
    {

        int permissions = 0;
        char answer = 'n';


        cout << "\nDo you want to grant full access? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            return -1;
        }

        cout << "\nSelect permissions:\n";

        cout << "\nShow Client List? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {


            permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pManageUsers;
        }


        return permissions;

    }

public:

    static void ShowUpdateUserScreen()
    {

        DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease enter a username: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser not found. Please choose another username: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this user? (y/n): ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Information:";
            cout << "\n____________________\n";


            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser updated successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFailedEmptyObject:
            {
                cout << "\nError! User was not saved because it is empty.";
                break;

            }

            }

        }

    }
};