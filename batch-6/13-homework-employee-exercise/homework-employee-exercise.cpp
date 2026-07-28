#include <iostream>

using namespace std;

class clsEmployee
{

private:
	int _ID;
	string _firstName;
	string _lastName;
	string _title;
	string _email;
	string _phone;
	int _salary;
	string _department;



public:

	clsEmployee(int ID, string firstName, string lastName, string title, string email, string phone, int salary, string Department)
	{
		_ID = ID;
		_firstName = firstName;
		_lastName = lastName;
		_title = title;
		_email = email;
		_phone = phone;
		_salary = salary;
		_department = Department;

	}

	//read only properties
	int ID()
	{
		return _ID;
	}

	void SetFirstName(string firstName)
	{
		_firstName = firstName;
	}

	string FirstName()
	{
		return _firstName;
	}

	///
	void SetLastName(string lastName)
	{
		_lastName = lastName;
	}

	string LastName()
	{
		return _lastName;
	}

	///
	void SetTitle(string title)
	{
		_title = title;
	}

	string Title()
	{
		return _title;
	}

	///
	void SetEmail(string email)
	{
		_email = email;
	}

	string Email()
	{
		return _email;
	}

	///
	void SetPhone(string phone)
	{
		_phone = phone;
	}

	string Phone()
	{
		return _phone;
	}

	///
	void SetSalary(int salary)
	{
		_salary = salary;
	}

	int Salary()
	{
		return _salary;
	}

	///
	void SetDepartment(string department)
	{
		_department = department;
	}

	string Department()
	{
		return _department;
	}

	string FullName()
	{
		return FirstName() + " " + LastName();
	}

	void Print()
	{
		cout << "Employee Information:" << endl;
		cout << "_________________________" << endl;
		cout << "ID        : " << ID() << endl;
		cout << "First Name: " << FirstName() << endl;
		cout << "Last Name : " << LastName() << endl;
		cout << "Full Name : " << FullName() << endl;
		cout << "Title     : " << Title() << endl;
		cout << "Email     : " << Email() << endl;
		cout << "Phone     : " << Phone() << endl;
		cout << "Salary    : " << Salary() << endl;
		cout << "Department: " << Department() << endl;
		cout << "_________________________" << endl;
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
		cout << "Message: " << message << endl;
	}


};

int main()
{

	clsEmployee employee1(1024, "Zirak", "Dildar", "Senior Software Engineer", "zirak@gmail.com", "9000200", 8000, "Engineering");
	employee1.Print();

	employee1.SendEmail("Hi", "How are you");
	employee1.SendSMS("How are you ");

	employee1.SetSalary(9000);
	cout << "\nSalary after update: " << employee1.Salary() << endl;

	return 0;
}