#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"

void DeleteClient()
{

    string accountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    accountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::DoesClientExist(accountNumber))
    {
        cout << "\nAccount number not found, choose another one: ";
        accountNumber = clsInputValidate::ReadString();
    }

    clsBankClient client1 = clsBankClient::Find(accountNumber);
    client1.Print();

    char answer = 'n';

    cout << "\nAre you sure you want to delete this client? (y/n): ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {

        if (client1.DeleteClient())
        {
            cout << "\nClient deleted successfully :-)\n";
            client1.Print();
        }
        else
        {
            cout << "\nError! Client was not deleted.\n";
        }

    }

}

int main()
{

    DeleteClient();

    return 0;
}