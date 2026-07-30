#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"

class clsUsersListScreen : protected clsScreen
{

private:
    static void PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << User.userName;
        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(12) << left << User.phone;
        cout << "| " << setw(20) << left << User.email;
        cout << "| " << setw(10) << left << User.password;
        cout << "| " << setw(12) << left << User.permissions;

    }

public:


    static void ShowUsersList()
    {


        vector <clsUser> vUser = clsUser::GetUsersList();
        string Title = "\t  Users List Screen";
        string SubTitle = "\t    (" + to_string(vUser.size()) + ") User(s).";

        DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________\n" << endl;

        if (vUser.size() == 0)
            cout << "\t\t\t\tNo users available in the system!";
        else

            for (clsUser User : vUser)
            {

                PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________\n" << endl;

    }


};