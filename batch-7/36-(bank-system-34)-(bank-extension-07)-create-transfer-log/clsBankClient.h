#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
#include <vector>
#include "clsDate.h"

using namespace std;

class clsBankClient :public clsPerson
{

private:
	enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2 };
	enMode _mode;
	string _accountNumber;
	string _pinCode;
	float _accountBalance;
	bool _markedForDelete = false;


	string _ConvertClientObjectToLine(clsBankClient client, string separator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += client.firstName + separator;
		stClientRecord += client.lastName + separator;
		stClientRecord += client.email + separator;
		stClientRecord += client.phone + separator;
		stClientRecord += client.AccountNumber() + separator;
		stClientRecord += client.pinCode + separator;
		stClientRecord += to_string(client.accountBalance);

		return stClientRecord;


	}

	void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{

		fstream myFile;
		myFile.open("Clients.txt", ios::out);

		string dataLine;

		for (clsBankClient& C : vClients)
		{

			if (C._markedForDelete == false)
			{
				dataLine = _ConvertClientObjectToLine(C);
				myFile << dataLine << endl;
			}
		}

		myFile.close();
	}

	static clsBankClient _ConvertLineToClientObject(string line, string separator = "#//#")
	{

		vector <string> vClient;
		vClient = clsString::Split(line, separator);

		return clsBankClient(enMode::updateMode, vClient[0], vClient[1], vClient[2], vClient[3],
			vClient[4], vClient[5], stod(vClient[6]));
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{

		vector <clsBankClient> vClinets;

		fstream myFile;
		myFile.open("Clients.txt", ios::in);


		if (myFile.is_open())
		{

			string line;
			while (getline(myFile, line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);
				vClinets.push_back(client);

			}

			myFile.close();

		}

		return vClinets;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream myFile;
		myFile.open("Clients.txt", ios::out | ios::app);

		if (myFile.is_open())
		{

			myFile << stDataLine << endl;

			myFile.close();
		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
			}
		}

		_SaveClientsDataToFile(_vClient);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _PrepareTransferLogRecord(double amount, clsBankClient destinationClient,
		string userName, string separator = "#//#")
	{
		string transferLogRecord = "";

		transferLogRecord += clsDate::GetSystemDateTimeString() + separator;
		transferLogRecord += AccountNumber() + separator;
		transferLogRecord += destinationClient.AccountNumber() + separator;
		transferLogRecord += to_string(amount) + separator;
		transferLogRecord += to_string(accountBalance) + separator;
		transferLogRecord += to_string(destinationClient.accountBalance) + separator;
		transferLogRecord += userName;

		return transferLogRecord;
	}

	void _RegisterTransferLog(double amount, clsBankClient destinationClient, string userName)
	{
		string stDateLine = _PrepareTransferLogRecord(amount, destinationClient, userName);

		fstream myFile;
		myFile.open("TransferLog.txt", ios::out | ios::app);

		if (myFile.is_open())
		{
			myFile << stDateLine << endl;
			myFile.close();

		}
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

	bool MarkedForDelete()
	{
		return _markedForDelete;
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


	// No UI-related code inside the object.
	/*void Print()
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
	}*/

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
		return (_mode == enMode::emptyMode);
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists};

	static clsBankClient GetAddNewClient(string accountNumber)
	{
		return clsBankClient(enMode::addNewMode, "", "", "", "", accountNumber, "", 0);
	}

	enSaveResults Save()
	{

		switch (_mode)
		{
		case enMode::emptyMode:
		{
			return enSaveResults::svFailedEmptyObject;
			break;
		}
		case enMode::updateMode:
		{

			_Update();

			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::addNewMode:
			if (clsBankClient::IsClientExist(_accountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
			}

			_AddNew();
			_mode = enMode::updateMode;
			return enSaveResults::svSucceeded;

		}


	}

	bool Delete()
	{
		vector <clsBankClient> vClient;
		vClient = _LoadClientsDataFromFile();

		
		for (clsBankClient & C: vClient)
		{
			if (C.AccountNumber() == _accountNumber)
			{
				C._markedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(vClient);

		*this = _GetEmptyClientObject();

		return true;


	}

	static bool IsClientExist(string accountNumber)
	{

		clsBankClient client = Find(accountNumber);

		return (!client.IsEmpty());
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{

		vector <clsBankClient> vClient = clsBankClient::GetClientsList();

		double totalBalances = 0;

		for (clsBankClient& C : vClient)
		{
			totalBalances += C.accountBalance;
		}

		return totalBalances;

	}

	void Deposit(double amount)
	{
		_accountBalance += amount;
		Save();
	}

	bool Withdraw(double amount)
	{
		if (amount > accountBalance)
		{
			return false;
		}
		else
		{
			_accountBalance -= amount;
			Save();
			return true;
		}

	}

	static double TotalBalances()
	{

		double totalBalances = 0;

		vector <clsBankClient> vClient = clsBankClient::GetClientsList();

		for (clsBankClient& C : vClient)
		{
			totalBalances += C.accountBalance;
		}

		return totalBalances;
	}

	bool Transfer(double amount, clsBankClient & destinationClient, string userName)
	{

		if (amount > accountBalance)
		{
			return false;
		}
		else
		{
			Withdraw(amount);
			destinationClient.Deposit(amount);
			_RegisterTransferLog(amount, destinationClient, userName);
			return true;
		}

	}

};