#include <iostream>

using namespace std;


int ReadAge()
{
	int Age;

	cout << "Please enter your age : " << endl;
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

int ReadUntilAgebetween(int From, int To)
{
	int Age = 0;

	do
	{
		Age = ReadAge();
	}
	while (!ValidateNumberInRange(Age, From, To));

	return Age;
}

void PrintResult(int Age)
{
	cout << "You are " << Age << " years old." << endl;
}

int main()
{
	PrintResult(ReadUntilAgebetween(18, 45));
	return 0;
}