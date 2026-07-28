#include <iostream>

using namespace std;

class clsPerson
{
	struct stAddress
	{
		string addressLine1;
		string addressLine2;
		string city;
		string country;
	};



public:

	string fullName;
	stAddress address;

	clsPerson()
	{
		fullName = "Mohammed Ali";
		address.addressLine1 = "Dummy Street";
		address.addressLine2 = "Building 10";
		address.country = "Norway";
		address.city = "Bergen";
	}


	void PrintAddress()
	{
		cout << "Address:\n";
		cout << address.addressLine1 << endl;
		cout << address.addressLine2 << endl;
		cout << address.city << endl;
		cout << address.country << endl;
	}

};

int main()
{

	clsPerson Person1;

	Person1.PrintAddress();

	return 0;
}