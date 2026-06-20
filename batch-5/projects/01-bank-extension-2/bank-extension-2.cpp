#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string clientsFileName = "clients.txt";
const string usersFileName = "users.txt";

struct sClient
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	double accountBalance;

	bool MarkForDelete = false;

};

struct sUsers
{
	string userName;
	string password;
	int permission;

	bool markForDelete = false;

};

enum eMainMenuOptions
{
	eShowClientList = 1, eAddNewClient,
	eDeleteClient, eUpdateClientInfo,
	eFindClient, eTransactions, eManageUsers, eExit
};

enum eManageUsersMenuOptions
{
	eListUsers = 1, eAddNewUser,
	eDeleteUser, eUpdateUser,
	eFindUser, eMainMenuFromUsers
};

enum eTransactionsMenuOptions
{
	eDeposit = 1, eWithdraw,
	eTotalBalances, eMainMenu
};

enum eMainMenuPermissions {
	all = -1, showClientList = 1, addNewClient = 2, deleteClient = 4,
	updateClientInfo = 8, findClient = 16, transactions = 32, manageUsers = 64
};

sUsers currentUser;

void ShowMainMenuList();
void ShowTransactionsMenu();
void ShowManageUsersMenu();
vector <sUsers> LoadUsersDataFromFile(string fileName);
void Login();

short ReadMainMenuOption()
{

	short option;
	cout << "Choose what do you want to do? [1 to 8]: ";
	cin >> option;

	return option;

}

bool CheckAccessPermission(eMainMenuPermissions permission)
{

	if (currentUser.permission == eMainMenuPermissions::all)
		return true;

	if ((permission & currentUser.permission) == permission)
		return true;
	else
		return false;

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

void PrintClientRecord(sClient client)
{

	cout << "| " << left << setw(14) << client.accountNumber;
	cout << "| " << left << setw(14) << client.pinCode;
	cout << "| " << left << setw(40) << client.name;
	cout << "| " << left << setw(12) << client.phoneNumber;
	cout << "| " << left << setw(12) << client.accountBalance;
	cout << "\n";

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

sUsers ConvertUserLineToRecord(string Line, string separator = "#//#")
{

	sUsers users;

	vector <string> vUserData;

	vUserData = SplitString(Line, separator);


	users.userName = vUserData[0];
	users.password = (vUserData[1]);
	users.permission = stoi(vUserData[2]);

	return users;
}

void PrintClientsBalances(sClient client)
{

	cout << "| " << left << setw(14) << client.accountNumber;
	cout << "| " << left << setw(40) << client.name;
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

void ShowAccessDeniedMessage()
{
	cout << "------------------------------------\n";
	cout << "Access Denied, \nYou don't have permission to do this,\nPlease contact your admin.";
	cout << "\n------------------------------------\n";
}

void ShowAllClientsScreen()
{

	if (!CheckAccessPermission(eMainMenuPermissions::showClientList))
	{
		ShowAccessDeniedMessage();
		return;
	}

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

	cout << "\nPress any key to go back to the Main Menu...";
	system("pause>0");
	ShowMainMenuList();

}

void ShowEndScreen()
{

	cout << "___________________________________\n";
	cout << "\tProgram Ends\n";
	cout << "___________________________________\n";

}

void AddDataToFile(string FileName, string sDataLine)
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

	AddDataToFile(clientsFileName, sDataLine);

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

	if (!CheckAccessPermission(eMainMenuPermissions::addNewClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

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

bool FindClientByAccountNumber(string accNumber, vector <sClient> vClient, sClient& Client)
{

	for (sClient& C : vClient)
	{

		if (C.accountNumber == accNumber)
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
	cout << "\nPlease enter the account number : ";
	cin >> accountNumber;

	return accountNumber;
}

void ShowDeleteClientScreen()
{

	if (!CheckAccessPermission(eMainMenuPermissions::deleteClient))
	{
		ShowAccessDeniedMessage();
		return;
	}


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

	if (!CheckAccessPermission(eMainMenuPermissions::updateClientInfo))
	{
		ShowAccessDeniedMessage();
		return;
	}


	cout << "___________________________________\n";
	cout << "\tUpdate Client Screen\n";
	cout << "___________________________________\n";

	vector <sClient> vClient = LoadClientsDataFromFile(clientsFileName);
	string accountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(accountNumber, vClient);

}

void ShowFindClientScreen()
{

	if (!CheckAccessPermission(eMainMenuPermissions::findClient))
	{
		ShowAccessDeniedMessage();
		return;
	}


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

void GoBackTransactionsMenu()
{

	cout << "\nPress any key to go back to the transactions menu...";
	system("pause>0");
	ShowTransactionsMenu();

}

void ShowTotalBalances()
{
	vector <sClient> vClient = LoadClientsDataFromFile(clientsFileName);

	cout << "\t\t\t\t\t Client List (" << vClient.size() << ") Client(s).\t\t\t\t\t\t\n";
	cout << "_________________________________________________";
	cout << "_________________________________________________\n\n";
	cout << "| " << left << setw(14) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_________________________________________________";
	cout << "_________________________________________________\n\n";

	double totalBalances = 0;

	for (sClient& client : vClient)
	{
		PrintClientsBalances(client);
		totalBalances += client.accountBalance;
	}

	cout << "_________________________________________________";
	cout << "_________________________________________________\n";

	cout << "\t\t\t\t\t Total Balances (" << totalBalances << ")\t\t\t\t\t\t\n";
}

void ShowTotalBalancesScreen()
{
	ShowTotalBalances();
}

bool DeopsitBalanceToClientByAccountNumber(string accountNumber, double depositAmount, vector <sClient>& vClient)
{

	char answer = 'n';

	cout << "\nAre you sure you want to perform this transaction? y/n : ";
	cin >> answer;

	if (answer == 'y' || answer == 'Y')
	{

		for (sClient& C : vClient)
		{
			if (C.accountNumber == accountNumber)
			{
				C.accountBalance += depositAmount;
				SaveClientsDataToFile(vClient);
				cout << "\nDone successfully. New balance is : " << C.accountBalance << endl;

				return true;
			}
		}

	}

	return false;
}

double ReadDepositAmount()
{

	double DepositAmount;
	cout << "\nPlease enter the deposit amount: ";
	cin >> DepositAmount;

	return DepositAmount;
}

void ShowDepositScreen()
{

	cout << "___________________________________\n";
	cout << "\tDeposit Screen\n";
	cout << "___________________________________\n";

	sClient client;
	string accountNumber = ReadClientAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(clientsFileName);


	while (!FindClientByAccountNumber(accountNumber, vClients, client))
	{
		cout << "\nClient with account number (" << accountNumber << ") does not exist.\n";
		accountNumber = ReadClientAccountNumber();
	}


	PrintClientCard(client);

	double depositAmount = ReadDepositAmount();

	DeopsitBalanceToClientByAccountNumber(accountNumber, depositAmount, vClients);

}

double ReadWithdrawAmount()
{

	double withdrawAmount;
	cout << "\nPlease enter the withdraw amount: ";
	cin >> withdrawAmount;

	return withdrawAmount;
}

void ShowWithdrawScreen()
{

	cout << "___________________________________\n";
	cout << "\tWithdraw Screen\n";
	cout << "___________________________________\n";


	sClient client;
	string accountNumber = ReadClientAccountNumber();
	vector <sClient> vClients = LoadClientsDataFromFile(clientsFileName);


	while (!FindClientByAccountNumber(accountNumber, vClients, client))
	{
		cout << "\nClient with account number (" << accountNumber << ") does not exist.\n";
		accountNumber = ReadClientAccountNumber();
	}


	PrintClientCard(client);

	double withdrawAmount = ReadWithdrawAmount();

	while (withdrawAmount > client.accountBalance)
	{
		cout << "Amount exceeds the balance, you can withdraw up to [" << client.accountBalance << "]\n";
		cout << "Please enter another amount : ";
		cin >> withdrawAmount;
	}


	DeopsitBalanceToClientByAccountNumber(accountNumber, withdrawAmount * (-1), vClients);
}

void PerformTransactionsMenuOption(eTransactionsMenuOptions transactionsMenuOption)
{

	switch (transactionsMenuOption)
	{
	case eTransactionsMenuOptions::eDeposit:
	{
		system("cls");
		ShowDepositScreen();
		GoBackTransactionsMenu();
		break;
	}
	case eTransactionsMenuOptions::eWithdraw:
	{
		system("cls");
		ShowWithdrawScreen();
		GoBackTransactionsMenu();
		break;
	}
	case eTransactionsMenuOptions::eTotalBalances:
	{
		system("cls");
		ShowTotalBalancesScreen();
		GoBackTransactionsMenu();
		break;
	}
	case eTransactionsMenuOptions::eMainMenu:
	{
		system("cls");
		ShowMainMenuList();
		break;
	}

	}

}

short ReadTransactionsMenuOption()
{

	short option;
	cout << "Choose what do you want to do? [1 to 4]: ";
	cin >> option;

	return option;
}

void ShowTransactionsMenu()
{

	if (!CheckAccessPermission(eMainMenuPermissions::transactions))
	{
		ShowAccessDeniedMessage();
		return;
	}


	system("cls");
	cout << "=======================================================\n";
	cout << "                Transactions Screen                    \n";
	cout << "=======================================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menu.\n";
	cout << "=======================================================\n";

	PerformTransactionsMenuOption((eTransactionsMenuOptions)ReadTransactionsMenuOption());
}

short ReadManageUsersMenuOption()
{

	short choice;
	cout << "Choose what do you want to do? [1 to 6]: ";
	cin >> choice;

	return choice;

}

void PrintUsersRecord(sUsers users)
{

	cout << "| " << left << setw(14) << users.userName;
	cout << "| " << left << setw(14) << users.password;
	cout << "| " << left << setw(40) << users.permission;
	cout << "\n";

}

vector <sUsers> LoadUsersDataFromFile(string fileName)
{

	vector <sUsers> vUsers;

	fstream myFile;
	myFile.open(fileName, ios::in);

	if (myFile.is_open())
	{
		sUsers user;
		string line;

		while (getline(myFile, line))
		{


			user = ConvertUserLineToRecord(line);
			vUsers.push_back(user);

		}

		myFile.close();

	}

	return vUsers;
}

void ShowAllUsersScreen()
{

	vector <sUsers> vUsers = LoadUsersDataFromFile(usersFileName);

	cout << "\t\t\t\t\t Client List (" << vUsers.size() << ") Client(s).\t\t\t\t\t\t\n";
	cout << "_________________________________________________";
	cout << "_________________________________________________\n\n";
	cout << "| " << left << setw(14) << "User Name";
	cout << "| " << left << setw(14) << "Password";
	cout << "| " << left << setw(40) << "Permission";
	cout << "\n_________________________________________________";
	cout << "_________________________________________________\n\n";


	for (sUsers user : vUsers)
	{
		PrintUsersRecord(user);
	}

	cout << "_________________________________________________";
	cout << "_________________________________________________\n";

}

void ShowListUsersScreen()
{
	ShowAllUsersScreen();
}

void GoBackToManageUsersMenu()
{

	cout << "\nPress any key to go back to the Manage Users Menu...";
	system("pause>0");
	ShowManageUsersMenu();

}

bool UserExistByUserName(string userName, string fileName)
{

	fstream myFile;
	myFile.open(fileName, ios::in);

	if (myFile.is_open())
	{

		string line;
		sUsers user;

		while (getline(myFile, line))
		{
			user = ConvertUserLineToRecord(line);
			if (user.userName == userName)
			{
				myFile.close();
				return true;
			}
		}

		myFile.close();

	}
	return false;
}

int ReadPermissions()
{

	int permissions = 0;

	char answer = 'N';
	cout << "\nDo you want to gave full access to List Users? y/n: ";
	cin >> answer;

	if (toupper(answer) == 'Y')
	{
		return eMainMenuPermissions::all;
	}

	cout << "\nDo you want to gave access to: \n";

	cout << "\nShow Client List y/n?: ";
	cin >> answer;
	if (toupper(answer) == 'Y')
		permissions += eMainMenuPermissions::showClientList;
	////

	cout << "Add New Client y/n?: ";
	cin >> answer;
	if (toupper(answer) == 'Y')
		permissions += eMainMenuPermissions::addNewClient;
	////

	cout << "Delete Client y/n?: ";
	cin >> answer;
	if (toupper(answer) == 'Y')
		permissions += eMainMenuPermissions::deleteClient;
	////

	cout << "Update Client y/n?: ";
	cin >> answer;
	if (toupper(answer) == 'Y')
		permissions += eMainMenuPermissions::updateClientInfo;
	////

	cout << "Find Client y/n?: ";
	cin >> answer;
	if (toupper(answer) == 'Y')
		permissions += eMainMenuPermissions::findClient;
	////

	cout << "Transactions y/n?: ";
	cin >> answer;
	if (toupper(answer) == 'Y')
		permissions += eMainMenuPermissions::transactions;
	////

	cout << "Manage Users y/n?: ";
	cin >> answer;
	if (toupper(answer) == 'Y')
		permissions += eMainMenuPermissions::manageUsers;

	return permissions;
}

sUsers ReadNewUser()
{

	sUsers sUser;

	cout << "Enter User Name: ";
	getline(cin >> ws, sUser.userName);

	while (UserExistByUserName(sUser.userName, usersFileName))
	{
		cout << "User with [" << sUser.userName << "] is already exists, please enter another username\n";
		getline(cin >> ws, sUser.userName);
	}

	cout << "Enter Password: ";
	getline(cin >> ws, sUser.password);

	sUser.permission = ReadPermissions();

	return sUser;
}

string ConvertUsersRecordToLine(sUsers stUserData, string separator = "#//#")
{

	string user = "";

	user += stUserData.userName + separator;
	user += (stUserData.password) + separator;
	user += to_string(stUserData.permission);


	return user;
}

void AddNewUser()
{
	sUsers user;
	user = ReadNewUser();
	string sDataLine = ConvertUsersRecordToLine(user);

	AddDataToFile(usersFileName, sDataLine);
}

void AddNewUsers()
{

	char addMore = 'Y';
	do
	{
		cout << "\nAdding a new user: \n\n";

		AddNewUser();
		cout << "\nUser added successfully, do you want to add more users? (Y/N): ";
		cin >> addMore;

	} while (toupper(addMore) == 'Y');
}

void ShowAddNewUserScreen()
{

	cout << "___________________________________\n";
	cout << "\tAdd New User Screen\n";
	cout << "___________________________________\n";

	AddNewUsers();

}

string ReadUserName()
{
	string userName;
	cout << "\nPlease enter the username: ";
	cin >> userName;

	return userName;
}

void PrintUserCard(sUsers user)
{
	cout << "\nThe following are the user details: \n";
	cout << "\nUser Name : " << user.userName;
	cout << "\nPassword  : " << user.password;
	cout << "\nPermission : " << user.permission << endl;

}

void SaveUsersDataToFile(string fileName, vector <sUsers>& vUser)
{

	string UUser;

	fstream myFile;
	myFile.open(fileName, ios::out);

	if (myFile.is_open())
	{

		for (sUsers& U : vUser)
		{
			if (U.markForDelete == false)
			{
				UUser = ConvertUsersRecordToLine(U);
				myFile << UUser << endl;
			}
		}

		myFile.close();

	}

}

bool MarkUserForDeleteByUserName(string userName, vector <sUsers>& vUser)
{

	for (sUsers& U : vUser)
	{

		if (U.userName == userName)
		{
			U.markForDelete = true;
			return true;
		}

	}

	return false;
}

bool FindUserByUsernameAndPassword(string username, string password, sUsers& user)
{

	vector <sUsers> vUser = LoadUsersDataFromFile(usersFileName);

	for (sUsers& U : vUser)
	{

		if (U.userName == username && U.password == password)
		{
			user = U;
			return true;
		}
	}

	return false;
}

bool FindUserByUsername(string username, vector <sUsers> vUser, sUsers& user)
{

	for (sUsers& U : vUser)
	{

		if (U.userName == username)
		{
			user = U;
			return true;
		}
	}

	return false;
}

bool DeleteUserByUserName(string username, vector <sUsers>& vUser)
{

	if (username == "Admin")
		return false;

	sUsers user;
	char answer = 'n';

	if (FindUserByUsername(username, vUser, user))
	{

		PrintUserCard(user);

		cout << "\nAre you sure you want to delete this user? y/n : ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{

			MarkUserForDeleteByUserName(username, vUser);
			SaveUsersDataToFile(usersFileName ,vUser);

			vUser = LoadUsersDataFromFile(usersFileName);

			cout << "\nUser Deleted Successfully." << endl;
			return true;
		}
		return false;

	}
	else
	{
		cout << "\nUser with username (" << username << ") is not found!" << endl;
		return false;
	}
}

void ShowDeleteUserScreen()
{

	cout << "___________________________________\n";
	cout << "\tDelete User Screen\n";
	cout << "___________________________________\n";

	vector <sUsers> vUser = LoadUsersDataFromFile(usersFileName);
	string username = ReadUserName();

	DeleteUserByUserName(username, vUser);

}

sUsers ChangeUserRecord(string userName)
{

	sUsers user;

	user.userName = userName;

	cout << "\nEnter password: ";
	getline(cin >> ws, user.password);

	user.permission = ReadPermissions();

	return user;
}

bool UpdateUserByUserName(string username, vector <sUsers>& vUser)
{

	sUsers user;
	char answer = 'n';

	if (FindUserByUsername(username, vUser, user))
	{

		PrintUserCard(user);

		cout << "\nAre you sure you want to update this user? y/n : ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{

			for (sUsers& U : vUser)
			{

				if (U.userName == username)
				{
					U = ChangeUserRecord(username);
					break;
				}

			}

			SaveUsersDataToFile(usersFileName, vUser);
			cout << "\nUser updated successfully." << endl;
			return true;
		}
		return false;

	}
	else
	{
		cout << "\nUser with username (" << username << ") is not found!" << endl;
		return false;
	}
}

void ShowUpdateUserScreen()
{

	cout << "___________________________________\n";
	cout << "\tUpdate User Screen\n";
	cout << "___________________________________\n";

	vector <sUsers> vUser = LoadUsersDataFromFile(usersFileName);
	string username = ReadUserName();

	UpdateUserByUserName(username, vUser);

}

void ShowFindUserScreen()
{

	cout << "___________________________________\n";
	cout << "\tFind User Screen\n";
	cout << "___________________________________\n";

	sUsers user;
	string userName = ReadUserName();
	vector <sUsers> vUsers = LoadUsersDataFromFile(usersFileName);

	if (FindUserByUsername(userName, vUsers, user))
		PrintUserCard(user);
	else
		cout << "\nUser with username (" << userName << ") is not found!" << endl;

}

void GoBackToMainMenuFromUsers()
{
	ShowMainMenuList();
}

void PerforManageUsersMuneOption(eManageUsersMenuOptions manageUsersOption)
{

	switch (manageUsersOption)
	{
	case eManageUsersMenuOptions::eListUsers:
	{
		system("cls");
		ShowListUsersScreen();
		GoBackToManageUsersMenu();
		break;
	}
	case eManageUsersMenuOptions::eAddNewUser:
	{
		system("cls");

		ShowAddNewUserScreen();
		GoBackToManageUsersMenu();
		break;
	}
	case eManageUsersMenuOptions::eDeleteUser:
	{
		system("cls");

		ShowDeleteUserScreen();
		GoBackToManageUsersMenu();
		break;
	}
	case eManageUsersMenuOptions::eUpdateUser:
	{
		system("cls");
		ShowUpdateUserScreen();
		GoBackToManageUsersMenu();
		break;
	}
	case eManageUsersMenuOptions::eFindUser:
	{
		system("cls");
		ShowFindUserScreen();
		GoBackToManageUsersMenu();
		break;
	}
	case eManageUsersMenuOptions::eMainMenuFromUsers:
	{
		GoBackToMainMenuFromUsers();
		break;
	}
	}

}

void ShowManageUsersMenu()
{

	if (!CheckAccessPermission(eMainMenuPermissions::manageUsers))
	{
		ShowAccessDeniedMessage();
		return;
	}


	system("cls");
	cout << "=======================================================\n";
	cout << "              Manage Users Menu Screen                 \n";
	cout << "=======================================================\n";
	cout << "\t[1] List Users.\n";
	cout << "\t[2] Add New User.\n";
	cout << "\t[3] Delete User.\n";
	cout << "\t[4] Update User.\n";
	cout << "\t[5] Find User.\n";
	cout << "\t[6] Main Menu.\n";
	cout << "=======================================================\n";

	PerforManageUsersMuneOption((eManageUsersMenuOptions)ReadManageUsersMenuOption());

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
	case eMainMenuOptions::eTransactions:
	{
		system("cls");
		ShowTransactionsMenu();
		GoBackToMainMenu();
		break;
	}

	case eMainMenuOptions::eManageUsers:
	{
		system("cls");
		ShowManageUsersMenu();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::eExit:
	{
		system("cls");
		//ShowEndScreen();
		Login();
		break;
	}

	}

}

bool LoadUserInfo(string username, string password)
{

	if (FindUserByUsernameAndPassword(username, password, currentUser))
		return true;
	else
		return false;

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
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
	cout << "=======================================================\n";

	PerformMainMenuOption((eMainMenuOptions)ReadMainMenuOption());

}

void Login()
{

	bool loginFailed = false;

	string username, password;

	do
	{

		system("cls");
		cout << "================================\n";
		cout << "\t  Login Screen        \n";
		cout << "================================\n";

		if (loginFailed)
		{
			cout << "\nInvalid Username/Password!\n";
		}

		cout << "\nEnter the name: ";
		cin >> username;

		cout << "Enter the password: ";
		cin >> password;

		loginFailed = !LoadUserInfo(username, password);

	} while (loginFailed);


	ShowMainMenuList();

}

int main()
{
	Login();

	return 0;
}