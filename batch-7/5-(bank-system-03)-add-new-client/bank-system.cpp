#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"

void ReadClientInfo(clsBankClient& client)
{
    cout << "\nEnter First Name: ";
    client.firstName = clsInputValidate::ReadString();

    cout << "\nEnter Last Name: ";
    client.lastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    client.email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    client.phone = clsInputValidate::ReadString();

    cout << "\nEnter PIN Code: ";
    client.pinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance: ";
    client.accountBalance = clsInputValidate::ReadFloatNumber();

}

int main()
{
    string accountNumber = "";
    cout << "Please enter account number: ";
    accountNumber = clsInputValidate::ReadString();

    while (clsBankClient::DoesClientExist(accountNumber))
    {
        cout << "\nAccount number already exists. Please enter another account number: ";
        accountNumber = clsInputValidate::ReadString();
    }

    clsBankClient newClient = clsBankClient::GetAddNewClient(accountNumber);

    ReadClientInfo(newClient);

    clsBankClient::enSaveResults saveResult;

    saveResult = newClient.Save();


    switch (saveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount added successfully :-)\n";
        newClient.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError! Account was not saved because it's empty.";
        break;
    }
    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        cout << "\nError! Account was not saved because the account number is already in use.\n";
        break;

    }

    return 0;
}