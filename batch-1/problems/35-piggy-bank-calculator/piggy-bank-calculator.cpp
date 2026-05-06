#include <iostream>

using namespace std;

struct stPiggyBankContent
{
	int Pennies, Nickels, Dimes, Quarter, Dollars;
};

stPiggyBankContent ReadPiggyBankContent()
{
	stPiggyBankContent PiggyBankContent;

	cout << "Please enter a total Pennies : " << endl;
	cin >> PiggyBankContent.Pennies;
	cout << "Please enter a total Nickels : " << endl;
	cin >> PiggyBankContent.Nickels;
	cout << "Please enter a total Dimes : " << endl;
	cin >> PiggyBankContent.Dimes;
	cout << "Please enter a total Quarter : " << endl;
	cin >> PiggyBankContent.Quarter;
	cout << "Please enter a total Dollars : " << endl;
	cin >> PiggyBankContent.Dollars;

	return PiggyBankContent;
}

float CalculateTotalpennies(stPiggyBankContent PiggyBankContent)
{
	float TotalPennies;

	TotalPennies = PiggyBankContent.Pennies * 1 + PiggyBankContent.Nickels * 5 +
		PiggyBankContent.Dimes * 10 + PiggyBankContent.Quarter * 25 +
		PiggyBankContent.Dollars * 100;
	return TotalPennies;
}

int main()
{
	float TotalPennies = CalculateTotalpennies(ReadPiggyBankContent());

	cout << "Total Pennies = " << TotalPennies << endl;
	cout << "Total Dollars = " << TotalPennies / 100 << endl;

	return 0;
}