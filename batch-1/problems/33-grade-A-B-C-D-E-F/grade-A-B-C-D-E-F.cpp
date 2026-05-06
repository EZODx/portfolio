#include <iostream>

using namespace std;

int ReadNumberInRange(int From, int To)
{
	int Number;
	do
	{
		cout << "Please enter a number : " << endl;
		cin >> Number;
	}
	while (Number < 0 || Number > 100);

	return Number;
}

char GetGradeLetter(int Number)
{
	if (Number >= 90)
		return 'A';
	else if (Number >= 80)
		return 'B';
	else if (Number >= 70)
		return 'C';
	else if (Number >= 60)
		return 'D';
	else if (Number >= 50)
		return 'E';
	else
		return 'F';


}

int main()
{
	cout << "Result = " << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;

	return 0;
}