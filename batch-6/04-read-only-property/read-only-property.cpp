#include iostream

using namespace std;

class clsEmployee
{

private
	string _firstName;
	string _lastName;

	short _age = 28;
	string _phoneNumber = 9008000;
	int _salary = 5500;

public
	void SetFirstName(string firstName)
	{
		_firstName = firstName;
	}

	string GetFirstName()
	{
		return _firstName;
	}

	void SetLastName(string lastName)
	{
		_lastName = lastName;
	}

	string GetLastName()
	{
		return _lastName;
	}

	short GetAge()
	{
		return _age;
	}

	string GetPhoneNumber()
	{
		return _phoneNumber;
	}

	int GetSalary()
	{
		return _salary;
	}

};

void PrintEmployee1Info(clsEmployee& employee1)
{

	employee1.SetFirstName(Zirak);
	employee1.SetLastName(Dildar);


	cout  The first name   employee1.GetFirstName()  endl;
	cout  The last name   employee1.GetLastName()  endl;
	cout  The age   employee1.GetAge()  endl;
	cout  The phone number   employee1.GetPhoneNumber()  endl;
	cout  The salary   employee1.GetSalary()  endl;

}

int main()
{
	clsEmployee employee1;
	PrintEmployee1Info(employee1);

	return 0;
}