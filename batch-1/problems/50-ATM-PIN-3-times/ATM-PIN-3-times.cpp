#include <iostream>

using namespace std;

string ReadPinCode()
{
	string PinCode;
	cout << "Please enter PIN code : " << endl;
	cin >> PinCode;
	return PinCode;
}

bool Login()
{
	string PINCode;
	int Counter = 3;
	do
	{
		Counter--;
		PINCode = ReadPinCode();

		if (PINCode == "1234")
		{
			return 1;
		}
		else
		{
			system("color 4F"); // turn screen to red
			cout << "Wrong PIN. You have " << Counter << " more tries" << endl;
		}
	}
	while (Counter >= 1 && PINCode != "1234");

	return 0;
}

int main()
{
	if (Login())
	{
		system("color 2F"); // turn screen to green
		cout << "\nYour balance = " << 7500 << endl;
	}
	else
	{
		cout << "\nYour card blocked, please call the bank for help." << endl;
	}
	return 0;
}