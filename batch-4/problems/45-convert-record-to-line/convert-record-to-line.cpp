#include <iostream>
#include <string>

using namespace std;

struct sClient
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	double accountBalance;
};

sClient ReadData()
{

	sClient stClientData;

	cout << "Enter account number: ";
	getline(cin, stClientData.accountNumber);

	cout << "Enter pin code: ";
	getline(cin, stClientData.pinCode);

	cout << "Enter Name: ";
	getline(cin, stClientData.name);

	cout << "Enter phone number: ";
	getline(cin, stClientData.phoneNumber);

	cout << "Enter account balance: ";
	cin >> stClientData.accountBalance;

	return stClientData;

}

string ConvertRecordToLine(sClient stClientData, string separator = "#//#")
{

	string Client = "";

	Client += stClientData.accountNumber + separator;
	Client += stClientData.pinCode + separator;
	Client += stClientData.name + separator;
	Client += stClientData.phoneNumber + separator;
	Client += to_string(stClientData.accountBalance);


	return Client;
}


int main()
{

	cout << "Please enter a client data:\n\n";
	sClient Client = ReadData();

	cout << "\nClient record for saving is: " << endl;
	cout << ConvertRecordToLine(Client) << endl;



	return 0;
}