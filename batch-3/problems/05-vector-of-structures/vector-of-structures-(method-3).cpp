#include <iostream>
#include <vector>

using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	int Salary;
};

int main()
{

	vector <stEmployee> vEmployee;

	stEmployee tempEmployee;

	tempEmployee.FirstName = "Ivan";
	tempEmployee.LastName = "Stone";
	tempEmployee.Salary = 10000;
	vEmployee.push_back(tempEmployee);

	tempEmployee.FirstName = "Lena";
	tempEmployee.LastName = "Hart";
	tempEmployee.Salary = 5000;
	vEmployee.push_back(tempEmployee);

	tempEmployee.FirstName = "Zara";
	tempEmployee.LastName = "Lee";
	tempEmployee.Salary = 7500;
	vEmployee.push_back(tempEmployee);

	cout << "Employees vector : \n\n";

	for (stEmployee& employee : vEmployee)
	{
		cout << "First name : " << employee.FirstName << endl;
		cout << "Last name : " << employee.LastName << endl;
		cout << "Salary : " << employee.Salary << endl;

		cout << endl;
	}
	cout << endl;

	return 0;
}