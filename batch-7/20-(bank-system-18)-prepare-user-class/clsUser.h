#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsUser : public clsPerson
{
private:

    enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _markedForDelete = false;

    static clsUser _ConvertLineToUserObject(string line, string separator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(line, separator);

        return clsUser(enMode::updateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

    }

    static string _ConvertUserObjectToLine(clsUser user, string separator = "#//#")
    {

        string userRecord = "";
        userRecord += user.firstName + separator;
        userRecord += user.lastName + separator;
        userRecord += user.email + separator;
        userRecord += user.phone + separator;
        userRecord += user.userName + separator;
        userRecord += user.password + separator;
        userRecord += to_string(user.permissions);

        return userRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream myFile;
        myFile.open("Users.txt", ios::in);//read Mode

        if (myFile.is_open())
        {

            string line;


            while (getline(myFile, line))
            {

                clsUser user = _ConvertLineToUserObject(line);

                vUsers.push_back(user);
            }

            myFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream myFile;
        myFile.open("Users.txt", ios::out);//overwrite

        string dataLine;

        if (myFile.is_open())
        {

            for (clsUser u : vUsers)
            {
                if (u.MarkedForDelete() == false)
                {
                    //we only write records that are not marked for delete.  
                    dataLine = _ConvertUserObjectToLine(u);
                    myFile << dataLine << endl;

                }

            }

            myFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& u : _vUsers)
        {
            if (u.userName == userName)
            {
                u = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::out | ios::app);

        if (myFile.is_open())
        {

            myFile << stDataLine << endl;

            myFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::emptyMode, "", "", "", "", "", "", 0);
    }

public:

    clsUser(enMode mode, string firstName, string lastName,
        string email, string phone, string userName, string password,
        int permissions) :
        clsPerson(firstName, lastName, email, phone)

    {
        _Mode = mode;
        _UserName = userName;
        _Password = password;
        _Permissions = permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::emptyMode);
    }

    bool MarkedForDelete()
    {
        return _markedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string userName)
    {
        _UserName = userName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string userName;

    void SetPassword(string password)
    {
        _Password = password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string password;

    void SetPermissions(int permissions)
    {
        _Permissions = permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int permissions;

    static clsUser Find(string userName)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::in);//read Mode

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsUser user = _ConvertLineToUserObject(line);
                if (user.userName == userName)
                {
                    myFile.close();
                    return user;
                }
            }

            myFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string userName, string password)
    {

        fstream myFile;
        myFile.open("Users.txt", ios::in);//read Mode

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsUser user = _ConvertLineToUserObject(line);
                if (user.userName == userName && user.password == password)
                {
                    myFile.close();
                    return user;
                }

            }

            myFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::emptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFailedEmptyObject;
            }
        }

        case enMode::updateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::addNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFailedUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::updateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string userName)
    {

        clsUser user = clsUser::Find(userName);
        return (!user.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& u : _vUsers)
        {
            if (u.userName == _UserName)
            {
                u._markedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string userName)
    {
        return clsUser(enMode::addNewMode, "", "", "", "", userName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

};