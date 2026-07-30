#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

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

void UpdateClient()
{
    string accountNumber = "";

    cout << "\nPlease Enter Client Account Number: ";
    accountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::DoesClientExist(accountNumber))
    {
        cout << "\nAccount number not found, choose another one: ";
        accountNumber = clsInputValidate::ReadString();
    }

    clsBankClient client1 = clsBankClient::Find(accountNumber);
    client1.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";

    ReadClientInfo(client1);

    clsBankClient::enSaveResults saveResult;

    saveResult = client1.Save();

    switch (saveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount updated successfully :-)\n";
        client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError! Account was not saved because it's empty.";
        break;
    }

    }
}

int main()
{
    UpdateClient();
    return 0;
}