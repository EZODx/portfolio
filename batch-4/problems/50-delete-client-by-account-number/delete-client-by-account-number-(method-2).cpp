#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string clientsFileName = "clients.txt";

struct sClient
{
	string accountNumber;
	string pinCode;
	string name;
	string phone;
	double accountBalance;
	bool markForDelete = false;
};

vector<string> SplitString(string S1, string delim)
{

	vector<string> vString;
	short pos = 0;

	string sWord;

	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

sClient ConvertLinetoRecord(string line, string separator ="#//#")
{
	sClient Client;
	vector<string> vClientData;

	vClientData = SplitString(line, separator);

	Client.accountNumber = vClientData[0];
	Client.pinCode = vClientData[1];
	Client.name = vClientData[2];
	Client.phone = vClientData[3];
	Client.accountBalance = stod(vClientData[4]);

	return Client;
}

string ConvertRecordToLine(sClient client, string separator ="#//#")
{
	string stClientRecord = "";

	stClientRecord += client.accountNumber + separator;
	stClientRecord += client.pinCode + separator;
	stClientRecord += client.name + separator;
	stClientRecord += client.phone + separator;
	stClientRecord += to_string(client.accountBalance);

	return stClientRecord;
}

vector <sClient> LoadCleintsDataFromFile(string fileName)
{
	vector <sClient> vClients;

	fstream MyFile;
	MyFile.open(fileName, ios::in);//read Mode

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

void PrintClientCard(sClient client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccount Number: " << client.accountNumber;
	cout << "\nPin Code : " << client.pinCode;
	cout << "\nName : " << client.name;
	cout << "\nPhone : " << client.phone;
	cout << "\nAccount Balance: " << client.accountBalance;
}

bool FindClientByAccountNumber(string accountNumber, vector<sClient> vClients, sClient& client)
{
	for (sClient C : vClients)
	{
		if (C.accountNumber == accountNumber)
		{
			client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string accountNumber,vector <sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.accountNumber == accountNumber)
		{
			C.markForDelete = true;
			return true;
		}
	}
	return false;
}

vector <sClient> SaveCleintsDataToFile(string fileName, vector<sClient> vClients)
{
	fstream MyFile;
	MyFile.open(fileName, ios::out);//overwrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (C.markForDelete == false)
			{
				//we only write records that are not marked for delete.
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}

	return vClients;
}

bool DeleteClientByAccountNumber(string accountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(accountNumber, vClients,Client))
	{

		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			MarkClientForDeleteByAccountNumber(accountNumber,vClients);
			SaveCleintsDataToFile(clientsFileName, vClients);

			//Refresh Clients
			vClients = LoadCleintsDataFromFile(clientsFileName);
			cout << "\n\nClient Deleted Successfully.";

			return true;
		}
		return false;
	}
	else
	{
		cout << "\nClient with Account Number (" <<accountNumber<< ") is Not Found!";
		return false;
	}
}

string ReadClientAccountNumber()
{
	string accountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> accountNumber;

	return accountNumber;
}

int main()
{
	vector <sClient> vClients = LoadCleintsDataFromFile(clientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClients);

	return 0;
}