#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
#include <vector>

using namespace std;

class clsBankClient : public clsPerson
{

private:
	enum enMode { enEmpty = 0, enUpdate = 1 };
	enMode _mode;
	string _accountNumber;
	string _pinCode;
	float _accountBalance;


	static clsBankClient _ConvertLineToClientObject(string line, string separator = "#//#")
	{

		vector<string> vClient;
		vClient = clsString::Split(line, separator);

		return clsBankClient(enMode::enUpdate, vClient[0], vClient[1], vClient[2], vClient[3],
			vClient[4], vClient[5], stod(vClient[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::enEmpty, "", "", "", "", "", "", 0);
	}

public:

	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone,
		string accountNumber, string pinCode, float accountBalance) :
		clsPerson(firstName, lastName, email, phone)
	{
		_mode = mode;
		_accountNumber = accountNumber;
		_pinCode = pinCode;
		_accountBalance = accountBalance;
	}

	string AccountNumber()
	{
		return _accountNumber;
	}

	void SetPinCode(string pinCode)
	{
		_pinCode = pinCode;
	}

	string GetPinCode()
	{
		return _pinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string pinCode;

	void SetAccountBalance(float accountBalance)
	{
		_accountBalance = accountBalance;
	}

	float GetAccountBalance()
	{
		return _accountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float accountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << firstName;
		cout << "\nLastName    : " << lastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << email;
		cout << "\nPhone       : " << phone;
		cout << "\nAcc. Number : " << AccountNumber();
		cout << "\nPassword    : " << GetPinCode();
		cout << "\nBalance     : " << GetAccountBalance();
		cout << "\n___________________\n";
	}

	static clsBankClient Find(string accountNumber)
	{

		fstream myFile;
		myFile.open("Clients.txt", ios::in);

		while (myFile.is_open())
		{

			string line;

			while (getline(myFile, line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);
				if (client.AccountNumber() == accountNumber)
				{
					myFile.close();
					return client;
				}
			}

			myFile.close();

		}

		return _GetEmptyClientObject();
	}


	static clsBankClient Find(string accountNumber, string pinCode)
	{

		fstream myFile;
		myFile.open("Clients.txt", ios::in);

		while (myFile.is_open())
		{

			string line;

			while (getline(myFile, line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);
				if (client.AccountNumber() == accountNumber && client.GetPinCode() == pinCode)
				{
					myFile.close();
					return client;
				}
			}

			myFile.close();
		}

		return _GetEmptyClientObject();
	}

	bool IsEmpty()
	{
		return (_mode == enMode::enEmpty);
	}

	static bool DoesClientExist(string accountNumber)
	{

		clsBankClient client = Find(accountNumber);

		return (!client.IsEmpty());
	}

};