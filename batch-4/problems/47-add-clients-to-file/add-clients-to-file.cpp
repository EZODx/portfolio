#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string clientsFileName = "clients.txt";

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
	getline(cin >> ws, stClientData.accountNumber);

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

void AddClientToFile(string FileName, string sDataLine)
{

	fstream myFile;

	myFile.open(FileName, ios::out | ios::app);

	if (myFile.is_open())
	{

		myFile << sDataLine << endl;

		myFile.close();
	}

}

void AddClient()
{

	sClient Client;
	Client = ReadData();
	string sDataLine = ConvertRecordToLine(Client);

	AddClientToFile(clientsFileName, sDataLine);

}


void AddClients()
{

	char addMore = 'Y';
	do
	{
		system("cls");
		cout << "Add a client: \n\n";

		AddClient();
		cout << "Do you want to add more clients? (Y/N): ";
		cin >> addMore;

	} while (toupper(addMore) == 'Y');

}

int main()
{

	AddClients();


	return 0;
}