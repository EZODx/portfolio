#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

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

vector <string> SplitString(string theString, string delim)
{


	vector <string> vString;

	string sWord;

	short pos = 0;

	while ((pos = theString.find(delim)) != std::string::npos)
	{

		sWord = theString.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		theString.erase(0, pos + delim.length());

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

		string line;
		sClient Client;

		while (getline(myFile, line))
		{
			Client = ConvertLineToRecord(line);
			vClients.push_back(Client);

		}

		myFile.close();

	}

	return vClients;

}

string ReadClientAccountNumber()
{
	string accountNumber;

	cout << "Please enter the account number: ";
	cin >> accountNumber;

	return accountNumber;
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

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details: \n";
	cout << "\nAccount Number : " << Client.accountNumber;
	cout << "\nPinCode        : " << Client.pinCode;
	cout << "\nName           : " << Client.name;
	cout << "\nPhoneNumber    : " << Client.phoneNumber;
	cout << "\nAccountBalance : " << Client.accountBalance << endl;

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

			vClient = LoadClientsDataFromFile(clientsFileName);

			cout << "\nClient Deleted Successfully." << endl;
			return true;
		}

	}
	else
	{
		cout << "\nClient with account number (" << accountNumber << ") is not found" << endl;
		return false;
	}

}

int main()
{

	vector <sClient> vClient = LoadClientsDataFromFile(clientsFileName);
	string accountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(accountNumber, vClient);

	return 0;
}