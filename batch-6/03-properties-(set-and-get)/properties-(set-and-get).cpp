#include <iostream>

using namespace std;

class clsPerson
{
private:
	string _firstName;
	string _lastName;


public:
	
	void setFirstName(string firstName)
	{
		_firstName = firstName;
	}

	string getFirstName()
	{
		return _firstName;
	}

	void setLastName(string lastName)
	{
		_lastName = lastName;
	}

	string getLastName()
	{
		return _lastName;
	}

	string getFullName()
	{
		return _firstName + " " + _lastName;
	}

};

int main()
{

	clsPerson person1;

	person1.setFirstName("Essam");
	person1.setLastName("Issa");

	cout << "The first name is: " << person1.getFirstName() << endl;
	cout << "The last name is: " << person1.getLastName() << endl;
	cout << "The full name is: " << person1.getFullName() << endl;

	return 0;
}