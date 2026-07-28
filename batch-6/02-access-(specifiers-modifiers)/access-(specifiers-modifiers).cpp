#include iostream

using namespace std;

class clsPerson
{
private

	int v1 = 10;

	int function1()
	{
		return 0;
	}

protected

	int v2 = 20;

	int function2()
	{
		return 0;
	}

public

	string firstName;
	string lastName;

	string PrintFullName()
	{
		return firstName +   + lastName;
	}

};

int main()
{

	clsPerson person1;

	person1.firstName = John;
	person1.lastName = Zirak;

	cout  person1.PrintFullName()  endl;


	return 0;
}
