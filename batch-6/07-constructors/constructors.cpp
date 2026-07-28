#include <iostream>

using namespace std;

class clsAddress
{
private:
    string _addressLine1;
    string _addressLine2;
    string _POBox;
    string  _zipCode;


public:

    clsAddress(string addressLine1, string addressLine2, string POBox, string zipCode)
    {
		_addressLine1 = addressLine1;
		_addressLine2 = addressLine2;
		_POBox = POBox;
		_zipCode = zipCode;
    }

    void SetAddressLine1(string address)
    {
        _addressLine1 = address;
    }

    // Getter
    string AddressLine1()
    {
        return _addressLine1;
    }

    void SetAddressLine2(string address)
    {
        _addressLine2 = address;
    }
    // Getter
    string AddressLine2()
    {
        return _addressLine2;
    }

    void SetPOBox(string POBox)
    {
        _POBox = POBox;
    }

    // Getter
    string POBox()
    {
        return _POBox;
    }

    void SetZipCode(string zipCode)
    {
        _zipCode = zipCode;
    }

    // Getter
    string ZipCode()
    {
        return _zipCode;
    }

    void Print()
    {
        cout << "Address Details:\n";
        cout << "----------------------------";
        cout << "\nAddressLine1: " << _addressLine1 << endl;
        cout << "AddressLine2: " << _addressLine2 << endl;
        cout << "POBox :       " << _POBox << endl;
        cout << "ZipCode :     " << _zipCode << endl;
    }

};

int main()
{
    clsAddress address1("50 West Pine Street", "Floor 6", "PO Box 309", "10001");

    address1.Print();

    return 0;
}
