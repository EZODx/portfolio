#include <iostream>

using namespace std;

class clsEmployee
{

public:
	int ID;
	string name;
	float salary;

	clsEmployee(int ID, string name, float salary)
	{
		this->ID = ID;
		this->name = name;
		this->salary = salary;
	}


	static void Fun1(clsEmployee employee)
	{
		employee.Print();
	}

	void Fun2()
	{
		Fun1(*this);
	}

	void Print()
	{
		cout << ID << " " << name << " " << salary << endl;
	 // cout << this->ID << "  " << this->name << "  " << this->salary << endl;

	}

};

int main()
{
	clsEmployee employee1(444, "EZOD", 5000);
	employee1.Print();

	employee1.Fun2();

	return 0;
}