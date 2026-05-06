#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sClient
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	double accountBalance;
};

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
	 Client.pinCode	= vClientData[1];
	 Client.name = vClientData[2];
	 Client.phoneNumber = vClientData[3];
	 Client.accountBalance = stod(vClientData[4]);

	return Client;
}

void PrintClientRecord(sClient Client)
{
	cout << "\n\nThe following is the extracted client record: \n";
	cout << "\nAccount Number : " << Client.accountNumber;
	cout << "\npinCode        : " << Client.pinCode;
	cout << "\nname           : " << Client.name;
	cout << "\nphoneNumber    : " << Client.phoneNumber;
	cout << "\naccountBalance : " << Client.accountBalance << endl;

}

int main()
{

	string sLine = "A300#//#1234#//#EZOD#//#4007000#//#6000";

	cout << "Line record is:\n";
	cout << sLine;

	sClient Client = ConvertLineToRecord(sLine);
	
	PrintClientRecord(Client);


	return 0;
}