#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct sClient
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	double accountBalance;

	bool MarkForDelete = false;

};

const string clientsFileName = "clients.txt";

enum eMainMenuOptions
{
	quickWithdraw = 1, normalWithdraw, deposit, checkBalance, logout
};

sClient currentClient;

void ShowMainMenuScreen();
void ShowQuickWithdrawScreen();
void Login();

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

bool FindClientByAccountNumberAndPINCode(string accNumber, string PINCode, sClient& Client)
{

	vector <sClient> vClient = LoadClientsDataFromFile(clientsFileName);

	for (sClient& C : vClient)
	{

		if (C.accountNumber == accNumber && C.pinCode == PINCode)
		{
			Client = C;
			return true;
		}
	}

	return false;

}

bool LoadUserInfo(string accountNumber, string PINCode)
{

	if (FindClientByAccountNumberAndPINCode(accountNumber,PINCode, currentClient))
		return true;
	else
		return false;

}

short ReadMainMenuOption()
{

	short option;
	cout << "Choose what do you want to do? [1 to 5]: ";
	cin >> option;

	return option;

}

void GoBackToMainMenu()
{

	cout << "\nPress any key to go back to the Main Menu...";
	system("pause>0");
	ShowMainMenuScreen();

}

short ReadQuickWithdrawMenuOption()
{

	short option = 0;
	while (option < 1 || option > 9)
	{
		cout << "Choose what do you want to do? [1 to 9]: ";
		cin >> option;
	}

	return option;
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

short GetWithdrawAmount(short quickWithdrawOption)
{
	switch (quickWithdrawOption)
	{
	case 1:
		return 20;
	case 2:
		return 50;
	case 3:
		return 100;
	case 4:
		return 200;
	case 5:
		return 400;
	case 6:
		return 600;
	case 7:
		return 800;
	case 8:
		return 1000;
	}
}

void PerformQuickWithdrawOption(short quickWithdrawOption)
{
	if (quickWithdrawOption == 9)//Exit
	{
		ShowMainMenuScreen();
		return;
	}

	short withdrawAmount = GetWithdrawAmount(quickWithdrawOption);

	if (withdrawAmount > currentClient.accountBalance)
	{
		cout << "\nThe amount exceeds your balance, make another choice.\n";
		cout << "Press Any key to continue...";
		system("pause>0");
		ShowQuickWithdrawScreen();
		return;
	}

	vector <sClient> vClinet = LoadClientsDataFromFile(clientsFileName);
	if (DeopsitBalanceToClientByAccountNumber(currentClient.accountNumber, withdrawAmount * (-1), vClinet))
		currentClient.accountBalance -= withdrawAmount;

}

void ShowQuickWithdrawScreen()
{
	system("cls");
	cout << "===================================\n";
	cout << "\tQuick Withdraw Screen\n";
	cout << "===================================\n";
	cout << "\t[1] 20    [2] 50\n";
	cout << "\t[3] 100   [4] 200\n";
	cout << "\t[5] 400   [6] 600\n";
	cout << "\t[7] 800   [8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "===================================\n";
	cout << "      Your balance is [" << currentClient.accountBalance << "]\n";
	cout << "===================================\n";
	PerformQuickWithdrawOption(ReadQuickWithdrawMenuOption());

}

int ReadNormalWithdrawAmount()
{
	int option;
	do
	{
		cout << "Enter an amount multiple of 5's: ";
		cin >> option;

	} while (option % 5 != 0);

	return option;
}

void PerformNormalWithdrawOption(int withdrawAmount)
{

	if (withdrawAmount > currentClient.accountBalance)
	{
		cout << "\nThe amount exceeds your balance, make another choice.\n";
		cout << "Press Any key to continue...";
		system("pause>0");
		ShowQuickWithdrawScreen();
		return;
	}


	vector <sClient> vClinet = LoadClientsDataFromFile(clientsFileName);
	if (DeopsitBalanceToClientByAccountNumber(currentClient.accountNumber, withdrawAmount * (-1), vClinet))
		currentClient.accountBalance -= withdrawAmount;

}

void ShowNormalWithdrawScreen()
{

	cout << "===================================\n";
	cout << "\tNormal Withdraw Screen\n";
	cout << "===================================\n";

	PerformNormalWithdrawOption(ReadNormalWithdrawAmount());

}

void Depostie(double depositAmount)
{

	vector <sClient> vClients = LoadClientsDataFromFile(clientsFileName);

	if (DeopsitBalanceToClientByAccountNumber(currentClient.accountNumber, depositAmount, vClients))
		currentClient.accountBalance += depositAmount;
}

double ReadDepositAmount()
{

	double option;
	cout << "Enter a positive deposit amount: ";
	cin >> option;

	return option;
}

void ShowDepositScreen()
{

	cout << "===================================\n";
	cout << "\tDeposit Screen\n";
	cout << "===================================\n";

	Depostie(ReadDepositAmount());

}

void CheckBalance()
{
	cout << "\nYour balance is [" << currentClient.accountBalance << "].\n";
}

void ShowCheckBalanceScreen()
{

	cout << "===================================\n";
	cout << "\tCheck Balance Screen\n";
	cout << "===================================\n";

	CheckBalance();

}

void PerformMainMenuOption(eMainMenuOptions mainMenuOption)
{

	switch (mainMenuOption)
	{
	case eMainMenuOptions::quickWithdraw:
	{
		system("cls");
		ShowQuickWithdrawScreen();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::normalWithdraw:
	{
		system("cls");
		ShowNormalWithdrawScreen();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::deposit:
	{
		system("cls");
		ShowDepositScreen();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::checkBalance:
	{
		system("cls");
		ShowCheckBalanceScreen();
		GoBackToMainMenu();
		break;
	}
	case eMainMenuOptions::logout:
	{
		system("cls");
		Login();
		break;
	}

	}

}

void ShowMainMenuScreen()
{

	system("cls");
	cout << "=======================================================\n";
	cout << "                  Main Menu Screen                     \n";
	cout << "=======================================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "=======================================================\n";

	PerformMainMenuOption((eMainMenuOptions)ReadMainMenuOption());

}

void Login()
{

	bool loginFailed = false;

	string accountNumber, PINCode;

	do
	{

		system("cls");
		cout << "================================\n";
		cout << "\t  Login Screen        \n";
		cout << "================================\n";

		if (loginFailed)
		{
			cout << "\nInvalid Account Number/PIN Code!\n";
		}

		cout << "\nEnter the account number: ";
		cin >> accountNumber;

		cout << "Enter the PIN Code: ";
		cin >> PINCode;

		loginFailed = !LoadUserInfo(accountNumber, PINCode);

	} while (loginFailed);

	ShowMainMenuScreen();

}

int main()
{
	Login();

	return 0;
}