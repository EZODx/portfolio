#include <iostream>

using namespace std;

class clsPerson
{

	string _fullName;

	class clsAddress
	{
	private:
		string _addressLine1;
		string _addressLine2;
		string _city;
		string _country;

	public:

		clsAddress(string addressLine1, string addressLine2, string city, string country)
		{
			_addressLine1 = addressLine1;
			_addressLine2 = addressLine2;
			_city = city;
			_country = country;
		}

		void Print()
		{
			cout << "Address:\n";
			cout << AddressLine1() << endl;
			cout << AddressLine2() << endl;
			cout << City() << endl;
			cout << Country() << endl;
		}

		string SetAddressLine1(string addressLine1)
		{
			_addressLine1 = addressLine1;
		}

		string AddressLine1()
		{
			return _addressLine1;
		}

		string SetAddressLine2(string addressLine2)
		{
			_addressLine2 = addressLine2;
		}

		string AddressLine2()
		{
			return _addressLine2;
		}

		string SetCity(string city)
		{
			_city = city;
		}

		string City()
		{
			return _city;
		}

		string SetCountry(string country)
		{
			_country = country;
		}

		string Country()
		{
			return _country;
		}

	};

public:

	void SetFullName(string fullName)
	{
		_fullName = fullName;
	}

	string FullName()
	{
		return _fullName;
	}

	clsAddress address = clsAddress("", "", "", "");

	clsPerson(string name, string addressLine1, string addressLine2, string city, string country)
	{
		_fullName = name;
		address = clsAddress(addressLine1, addressLine2, city, country);
	}


};

int main()
{

	clsPerson person1("Mohammed Ali", "Building 10", "B20 Street", "Bergen", "Norway");

	cout << "\nFull name: ";
	cout << person1.FullName() << "\n\n";

	person1.address.Print();

	return 0;
}