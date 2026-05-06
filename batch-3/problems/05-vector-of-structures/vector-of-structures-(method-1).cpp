#include <iostream>
#include <vector>

using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	int Salary;
};

void ReadEmployeesInfo(vector <stEmployee>& vEmployee)
{

	char AddMore = 'Y';
	stEmployee tempEmployee;

	while (AddMore == 'y' || AddMore == 'Y')
	{
		cout << "Please enter the first name : ";
		cin >> tempEmployee.FirstName;

		cout << "Please enter the last name : ";
		cin >> tempEmployee.LastName;

		cout << "Please enter the salary : ";
		cin >> tempEmployee.Salary;

		vEmployee.push_back(tempEmployee);

		cout << "\nDo you want to add more employee? (Y/N): ";
		cin >> AddMore;
		cout << endl;
	}

}

void PrintEmployeeInfo(vector <stEmployee>& vEmployee)
{

	cout << "\nEmployees Info : \n\n";

	int EmployeeNum = 1;

	for (stEmployee& employee : vEmployee)
	{

		cout << "Employee " << EmployeeNum << " :" << endl << endl;

		cout << "First name : " << employee.FirstName << endl;
		cout << "Last name : " << employee.LastName << endl;
		cout << "Salary : " << employee.Salary << endl;

		cout << endl;

		EmployeeNum++;
	}
	cout << endl;

}

int main()
{

	vector <stEmployee> vEmployee;

	ReadEmployeesInfo(vEmployee);
	PrintEmployeeInfo(vEmployee);


	return 0;
}