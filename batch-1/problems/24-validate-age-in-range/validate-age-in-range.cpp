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

void PrintResult(int Age)
{
	if (ValidateNumberInRange(Age, 18, 45))
	cout << Age << " is a valid Age";
	else
	cout << Age << " is an Invalid Age";
}

int main()
{
	PrintResult(ReadAge());
	return 0;
}