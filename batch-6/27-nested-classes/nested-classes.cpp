#include <iostream>

using namespace std;

class clsPerson
{

	class clsAddress
	{
	public:
		string addressLine1;
		string addressLine2;
		string city;
		string country;

		void Print()
		{
			cout << "Address:\n";
			cout << addressLine1 << endl;
			cout << addressLine2 << endl;
			cout << city << endl;
			cout << country << endl;
		}

	};

public:
	string fullName;
	clsAddress address;

	clsPerson()
	{
		fullName = "Mohammed Ali";
		address.addressLine1 = "Dummy Street";
		address.addressLine2 = "Building 10";
		address.country = "Norway";
		address.city = "Bergen";
	}


};

int main()
{
	clsPerson person1;

	person1.address.Print();

	return 0;
}