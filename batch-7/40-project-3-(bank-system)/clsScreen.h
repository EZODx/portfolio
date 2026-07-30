#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:

    static void DrawScreenHeader(string title, string subTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t " << title;
        if (subTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << subTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser: " << currentUser.FullName() << endl;
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
    }


    static bool CheckAccessRights(clsUser::enPermissions permissions)
    {
        if (currentUser.CheckAccessPermissions(permissions))
        {
            return true;
        }
        else
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
    }

};
