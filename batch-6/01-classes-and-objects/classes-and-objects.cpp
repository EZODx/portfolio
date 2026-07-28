#include <iostream>

using namespace std;

class clsPerson
{

	int age;

public:

	string firstName;
	string lastName;

	string PrintFullName()
	{
		return firstName + " " + lastName;
	}

};

int main()
{

	clsPerson person1;

	person1.firstName = "Zirak";
	person1.lastName = "Dildar";

	cout << person1.PrintFullName() << endl;


	// string is a class in C++ and S1 is an object of that class

	string S1; 
	S1.length();

	return 0;
}
