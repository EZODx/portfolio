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

void PrintClientRecord(sClient client)
{


	cout << "| " << left << setw(14) << client.accountNumber;
	cout << "| " << left << setw(14) << client.pinCode;
	cout << "| " << left << setw(40) << client.name;
	cout << "| " << left << setw(12) << client.phoneNumber;
	cout << "| " << left << setw(12) << client.accountBalance;
	cout << "\n";


}

void PrintAllClientsData(vector <sClient> vClient)
{

	cout << "\t\t\t\t\t Client List (" << vClient.size() << ") Client(s).\t\t\t\t\t\t\n";
	cout << "_________________________________________________";
	cout << "_________________________________________________\n\n";
	cout << "| " << left << setw(14) << "Accoutn Number";
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

int main()
{

	vector <sClient> vClient = LoadClientsDataFromFile(clientsFileName);

	PrintAllClientsData(vClient);

	return 0;
}