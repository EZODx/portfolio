#include <iostream>

using namespace std;

int ReadValidNumber()
{
	int number;
	cout << "Please enter a number: " << endl;
	cin >> number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Number, please enter a valid one:" << endl;
		cin >> number;
	}

	return number;
}

int main()
{
	
	cout << "Your number is : " << ReadValidNumber() << endl;

	return 0;
}