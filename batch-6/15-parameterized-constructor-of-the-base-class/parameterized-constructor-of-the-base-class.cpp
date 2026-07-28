#include <iostream>

using namespace std;

class clsPerson
{

private:
	int _ID;
	string _firstName;
	string _lastName;
	string _email;
	string _phone;


public:

	clsPerson(int ID, string firstName, string lastName, string email, string phone)
	{
		_ID = ID;
		_firstName = firstName;
		_lastName = lastName;
		_email = email;
		_phone = phone;
	}

	// read only property
	int ID()
	{
		return _ID;
	}

	////
	void SetFirstName(string firstName)
	{
		_firstName = firstName;
	}

	string FirstName()
	{
		return _firstName;
	}

	////
	void SetLastName(string lastName)
	{
		_lastName = lastName;
	}

	string LastName()
	{
		return _lastName;
	}

	////
	string FullName()
	{
		return FirstName() + " " + LastName();
		return _firstName + " " + _lastName; // This is also correct but it is better to use the properties instead of the private data members because if we have any logic in the properties it will be executed when we call the properties and it's better for reusability and maintainability of the code.
	}
	////
	void SetEmail(string email)
	{
		_email = email;
	}

	string Email()
	{
		return _email;
	}

	////
	void SetPhone(string phone)
	{
		_phone = phone;
	}

	string Phone()
	{
		return _phone;
	}


	void PrintInfo()
	{
		cout << "Info:\n";
		cout << "______________________________" << endl;
		cout << "ID        : " << ID() << endl;
		cout << "First Name: " << FirstName() << endl;
		cout << "Last Name : " << LastName() << endl;
		cout << "Full Name : " << FullName() << endl;
		cout << "Email     : " << Email() << endl;
		cout << "Phone     : " << Phone() << endl;
		cout << "______________________________" << endl;

	}

	void SendEmail(string subject, string body)
	{
		cout << "\nThe following email has been sent successfully to: " << _email << endl;
		cout << "Subject: " << subject << endl;
		cout << "Body: " << body << endl;
	}

	void SendSMS(string message)
	{
		cout << "\nThe following SMS has been sent successfully to: " << _phone << endl;
		cout << "SMS: " << message << endl;
	}

};

class clsEmployee : public clsPerson
{
	string _title;
	string _department;
	float _salary;

public:

	clsEmployee(int ID, string firstName, string lastName, string email, string phone, string title, string department, float salary) :
		clsPerson (ID, firstName, lastName, email, phone)
	{
		_title = title;
		_department = department;
		_salary = salary;
	}

	//Property Set
	void SetTitle(string Title)
	{
		_title = Title;
	}
	//Property Get
	string Title()
	{
		return _title;
	}
	//Property Set
	void SetDepartment(string Department)
	{
		_department = Department;
	}
	//Property Get
	string Department()
	{
		return _department;
	}
	//Property Set
	void SetSalary(float Salary)
	{
		_salary = Salary;
	}
	//Property Get
	float Salary()
	{
		return _salary;
	}
};

int main()
{

	clsEmployee employee1(10, "Mohammed", "Noah", "a@gmail.com", "8298982", "CEO", "Engineering", 5000);

	employee1.PrintInfo();
	
	cout << "\n" << employee1.Title() << endl;
	cout << employee1.Department() << endl;
	cout << employee1.Salary() << endl;

	return 0;
}