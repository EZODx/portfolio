#include <iostream>
#include <string>

using namespace std;

string ReadName()
{
	string name;

	cout << "Please enter your name: ";
	getline(cin, name);

	return name;
}

void PrintName(string Name)
{
	cout << "Your name is: " << Name << endl;
}

int main()
{
	PrintName(ReadName());

	return 0;
}