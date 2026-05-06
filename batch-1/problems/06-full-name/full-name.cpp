#include <iostream>

using namespace std;

struct stInfo
{
	string FirstName;
	string LastName;
};

stInfo ReadName()
{
	stInfo Names;

	cout << "Please enter your first name" << endl;
	cin >> Names.FirstName;
	cout << "Please enter your last name" << endl;
	cin >> Names.LastName;

	return Names;
}

string GetFullName(stInfo Info, bool Reversed)
{
	string FullName ="";
	if (Reversed)
		FullName = Info.LastName + " " + Info.FirstName;
	else
		FullName = Info.FirstName + " " + Info.LastName;

	return FullName;
}

void PrintFullName(string FullName)
{
	cout << "Your Full name is: " << FullName << endl;
}

int main()
{
	PrintFullName(GetFullName(ReadName(),true));

	return 0;
}