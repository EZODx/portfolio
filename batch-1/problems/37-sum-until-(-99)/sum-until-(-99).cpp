#include <iostream>
#include <string>

using namespace std;

float ReadNumber(string Message)
{
	int Number;
	cout << Message << endl;
	cin >> Number;

	return Number;
}

float SumNumbers()
{
	int Sum = 0, Number = 0, Counter = 1;

	do
	{
		Number = ReadNumber("Please enter a number " + to_string(Counter) + " :");

		if (Number == -99)
			break;

		Sum += Number;
		Counter++;
	}
	while (Number != -99);

	return Sum;
}


int main()
{


	cout << "Result : " << SumNumbers() << endl;

	return 0;
}