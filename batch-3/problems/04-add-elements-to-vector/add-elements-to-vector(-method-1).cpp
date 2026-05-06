#include <iostream>
#include <vector>

using namespace std;

vector <int> ReadNumbers(vector <int> &vNumber)
{

	int number;
	char addMore;
	do
	{
		cout << "Please enter a number : ";
		cin >> number;

		vNumber.push_back(number);

		cout << "Do you want to add more numbers ? (Y/N) : ";
		cin >> addMore;

	} while (addMore == 'Y' || addMore == 'y');

	return vNumber;

}

void PrintVectorNumbers(vector <int> &vNumbers)
{

	cout << "\nNumbers vector : ";

	for (int& number : vNumbers)
	{
		cout << number << " ";
	}
	cout << endl;
}

int main()
{

	vector <int> vNumbers;

	ReadNumbers(vNumbers);
	PrintVectorNumbers(vNumbers);


	return 0;
}