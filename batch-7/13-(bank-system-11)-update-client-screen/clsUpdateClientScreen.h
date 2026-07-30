DrawScreenHeader("\t  Update Client Screen");

string accountNumber = "";

cout << "\nPlease enter client account number: ";
accountNumber = clsInputValidate::ReadString();

while (!clsBankClient::IsClientExist(accountNumber))
{
    cout << "\nAccount number not found, choose another one: ";
    accountNumber = clsInputValidate::ReadString();
}

clsBankClient client = clsBankClient::Find(accountNumber);
_PrintClient(client);

cout << "\nAre you sure you want to update this client? (y/n): ";

char answer = 'n';
cin >> answer;

if (answer == 'y' || answer == 'Y')
{
    cout << "\n\nUpdate Client Information:";
    cout << "\n__________________________\n";

    _ReadClientInfo(client);

    clsBankClient::enSaveResults saveResult = client.Save();

    switch (saveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nClient updated successfully :-)\n";
        _PrintClient(client);
        break;
    }

    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError! Client was not updated because it is empty.\n";
        break;
    }
    }
}