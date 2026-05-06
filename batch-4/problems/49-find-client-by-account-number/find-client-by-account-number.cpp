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
};

const string clientsFileName = "clients.txt";

string ReadClientAccountNumber()
{
	string accountNumber;

	cout << "Please enter the account number: ";
	cin >> accountNumber;

	return accountNumber;
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

vector <sClient> LoadDataFromFileToVector(string fileName)
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

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details: \n";
	cout << "\nAccount Number : " << Client.accountNumber;
	cout << "\nPinCode        : " << Client.pinCode;
	cout << "\nName           : " << Client.name;
	cout << "\nPhoneNumber    : " << Client.phoneNumber;
	cout << "\nAccountBalance : " << Client.accountBalance << endl;

}

bool FindClientByAccountNumber(string AccNumber, sClient& Client)
{

	vector <sClient> vClient = LoadDataFromFileToVector(clientsFileName);

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

int main()
{
	sClient Client;
	string accountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(accountNumber, Client))
		PrintClientCard(Client);
	else
		cout << "\nClient with account number (" << accountNumber << ") is not found." << endl;

	return 0;
}