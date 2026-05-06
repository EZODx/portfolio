#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string clientsFileName = "clients.txt";

struct sClient
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	double accountBalance;

	bool MarkForDelete = false;

};

void ShowMainMenuList();

enum eMainMenuOptions
{
	eShowClientList = 1, eAddNewClient,
	eDeleteClient, eUpdateClientInfo,
	eFindClient, eExit
};

short ReadMainMenuOption()
{

	short option;
	cout << "Choose what do you want to do? [1 to 6]: ";
	cin >> option;

	return option;

}

vector <string> SplitString(string theString, string delime)
{


	vector <string> vString;

	string sWord;

	short pos = 0;

	while ((pos = theString.find(delime)) != std::string::npos)
	{

		sWord = theString.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		theString.erase(0, pos + delime.length());

	}

	if (theString != "")
	{
		vString.push_back(theString);
	}

	return vString;
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

sClient ConvertLineToRecord(string Line, string separator = "#//#")
{

	sClient Client;

	vector <string> vClientData;

	vClientData = SplitString(Line, separator);


	Client.accountNumber = vClientData[0];
	Client.pinCode = vClientData[1];
	Client.name = vClientData[2];
	Client.phoneNumber = vClientData[3];
	Client.accountBalance = stod(vClientData[4]);

	return Client;
}

void PrintClientRecord(sClient client)
{

	cout << "| " << left << setw(14) << client.accountNumber;
	cout << "| " << left << setw(14) << client.pinCode;
	cout << "| " << left << setw(40) << client.name;
	cout << "| " << left << setw(12) << client.phoneNumber;
	cout << "| " << left << setw(12) << client.accountBalance;
	cout << "\n";

}

vector <sClient> LoadClientsDataFromFile(string fileName)
{

	vector <sClient> vClients;

	fstream myFile;
	myFile.open(fileName, ios::in);

	if (myFile.is_open())
	{
		sClient Client;
		string line;

		while (getline(myFile, line))
		{


			Client = ConvertLineToRecord(line);
			vClients.push_back(Client);

		}

		myFile.close();

	}

	return vClients;
}

void ShowAllClientsScreen()
{

	vector <sClient> vClient = LoadClientsDataFromFile(clientsFileName);

	cout << "\t\t\t\t\t Client List (" << vClient.size() << ") Client(s).\t\t\t\t\t\t\n";
	cout << "_________________________________________________";
	cout << "_________________________________________________\n\n";
	cout << "| " << left << setw(14) << "Account Number";
	cout << "| " << left << setw(14) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone Number";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_________________________________________________";
	cout << "_________________________________________________\n\n";


	for (sClient client : vClient)
	{
		PrintClientRecord(client);
	}

	cout << "_________________________________________________";
	cout << "_________________________________________________\n";


}

void GoBackToMainMenu()
{

	cout << "\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenuList();

}

void ShowEndScreen()
{

	cout << "___________________________________\n";
	cout << "\tProgram Ends\n";
	cout << "___________________________________\n";

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

bool ClientExistByAccountNumber(string accountNumber, string fileName)
{

	fstream myFile;
	myFile.open(fileName, ios::in);

	if (myFile.is_open())
	{

		string line;
		sClient Client;

		while (getline(myFile, line))
		{
			Client = ConvertLineToRecord(line);
			if (Client.accountNumber == accountNumber)
			{
				myFile.close();
				return true;
			}
		}

		myFile.close();

	}
	return false;
}

sClient ReadNewClient()
{

	sClient stClientData;

	cout << "Enter account number: ";
	getline(cin >> ws, stClientData.accountNumber);

	while (ClientExistByAccountNumber(stClientData.accountNumber, clientsFileName))
	{
		cout << "Client with [" << stClientData.accountNumber << "] already exists, please enter account number\n";
		getline(cin >> ws, stClientData.accountNumber);
	}

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

void AddNewClient()
{

	sClient Client;
	Client = ReadNewClient();
	string sDataLine = ConvertRecordToLine(Client);

	AddClientToFile(clientsFileName, sDataLine);

}

void AddNewClients()
{

	char addMore = 'Y';
	do
	{
		system("cls");
		cout << "Add a client: \n\n";

		AddNewClient();
		cout << "Do you want to add more clients? (Y/N): ";
		cin >> addMore;

	} while (toupper(addMore) == 'Y');

}

void ShowAddNewClientScreen()
{

	cout << "___________________________________\n";
	cout << "\tAdd New Client Screen\n";
	cout << "___________________________________\n";

	AddNewClients();


}

bool MarkClientForDeleteByAccountNumber(string accountNumber, vector <sClient>& vClient)
{

	for (sClient& C : vClient)
	{

		if (C.accountNumber == accountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}

	}

	return false;
}

void SaveClientsDataToFile(vector <sClient>& vClient)
{

	string CClient;

	fstream myFile;
	myFile.open(clientsFileName, ios::out);

	if (myFile.is_open())
	{

		for (sClient& C : vClient)
		{
			if (C.MarkForDelete == false)
			{
				CClient = ConvertRecordToLine(C);
				myFile << CClient << endl;
			}
		}

		myFile.close();

	}

}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details: \n";
	cout << "\nAccount Number : " << Client.accountNumber;
	cout << "\nPinCode        : " << Client.pinCode;
	cout << "\nName           : " << Client.name;
	cout << "\nPhoneNumber    : " << Client.phoneNumber;
	cout << "\nAccountBalance : " << Client.accountBalance << endl;

}

bool FindClientByAccountNumber(string AccNumber, vector <sClient> vClient, sClient& Client)
{

	for (sClient& C : vClient)
	{

		if (C.accountNumber == AccNumber)
		{
			Client = C;
			return true;
		}
	}

	return false;

}

bool DeleteClientByAccountNumber(string accountNumber, vector <sClient>& vClient)
{

	sClient Client;
	char answer = 'n';

	if (FindClientByAccountNumber(accountNumber, vClient, Client))
	{

		PrintClientCard(Client);

		cout << "\nAre you sure you want to delete this client? y/n : ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{

			MarkClientForDeleteByAccountNumber(accountNumber, vClient);
			SaveClientsDataToFile(vClient);

			cout << "\nClient Deleted Successfully." << endl;
			return true;
		}
		return false;

	}
	else
	{
		cout << "\nClient with account number (" << accountNumber << ") is not found" << endl;
		return false;
	}
}

string ReadClientAccountNumber()
{
	string accountNumber;
	cout << "Please enter the account number : ";
	cin >> accountNumber;

	return accountNumber;
}

void ShowDeleteClientScreen()
{

	cout << "___________________________________\n";
	cout << "\tDelete Client Screen\n";
	cout << "___________________________________\n";

	vector <sClient> vClient = LoadClientsDataFromFile(clientsFileName);
	string accountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(accountNumber, vClient);

}

sClient ChangeClientRecord(string accountNumber)
{

	sClient Client;

	Client.accountNumber = accountNumber;

	cout << "\nEnter pin code: ";
	getline(cin >> ws, Client.pinCode);

	cout << "Enter Name: ";
	getline(cin, Client.name);

	cout << "Enter phone number: ";
	getline(cin, Client.phoneNumber);

	cout << "Enter account balance: ";
	cin >> Client.accountBalance;

	return Client;

}

bool UpdateClientByAccountNumber(string accountNumber, vector <sClient>& vClient)
{

	sClient Client;
	char answer = 'n';

	if (FindClientByAccountNumber(accountNumber, vClient, Client))
	{

		PrintClientCard(Client);

		cout << "\nAre you sure you want to update this client? y/n : ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{

			for (sClient& C : vClient)
			{

				if (C.accountNumber == accountNumber)
				{
					C = ChangeClientRecord(accountNumber);
					break;
				}

			}

			SaveClientsDataToFile(vClient);
			cout << "\nClient updated successfully." << endl;
			return true;
		}
		return false;

	}
	else
	{
		cout << "\nClient with account number (" << accountNumber << ") is not found" << endl;
		return false;
	}
}

void ShowUpdateClientScreen()
{

	cout << "___________________________________\n";
	cout << "\tUpdate Client Screen\n";
	cout << "___________________________________\n";

	vector <sClient> vClient = LoadClientsDataFromFile(clientsFileName);
	string accountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(accountNumber, vClient);

}

void ShowFindClientScreen()
{

	cout << "___________________________________\n";
	cout << "\tFind Client Screen\n";
	cout << "___________________________________\n";

	sClient client;
	string accountNumber = ReadClientAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(clientsFileName);

	if (FindClientByAccountNumber(accountNumber, vClients, client))
		PrintClientCard(client);
	else
		cout << "\nClient with account number (" << accountNumber << ") is not found." << endl;

}

void PerformMainMenuOption(eMainMenuOptions mainMenuOption)
{

	switch (mainMenuOption)
	{
	case eMainMenuOptions::eShowClientList:
	{
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::eAddNewClient:
	{
		system("cls");
		ShowAddNewClientScreen();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::eDeleteClient:
	{
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::eUpdateClientInfo:
	{
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::eFindClient:
	{
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::eExit:
	{
		system("cls");
		ShowEndScreen();
		break;
	}

	}

}

void ShowMainMenuList()
{

	system("cls");
	cout << "=======================================================\n";
	cout << "                  Main Menu Screen                     \n";
	cout << "=======================================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "=======================================================\n";

	PerformMainMenuOption((eMainMenuOptions)ReadMainMenuOption());

}

int main()
{

	ShowMainMenuList();

	return 0;
}