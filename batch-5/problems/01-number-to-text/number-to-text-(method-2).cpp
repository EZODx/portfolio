#include <iostream>

using namespace std;

long long ReadNumber()
{
	long long number;
	cout << "Please enter a number: ";
	cin >> number;

	return number;
}

string NumberToText(long long number)
{

	if (number == 0)
	{
		return "";
	}

	if (number >= 1 && number <= 19)
	{
		string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
		"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

		return arr[number];
	}

	if (number >= 20 && number <= 99)
	{
		string arr[] = { "", "", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		return arr[number / 10] + " " + NumberToText(number % 10);
	}

	if (number >= 100 && number <= 999)
	{
		return NumberToText(number / 100) + " " + "Hundred" + " " + NumberToText(number % 100);
	}

	if (number >= 1000 && number <= 999999)
	{
		return NumberToText(number / 1000) + " " + "Thousand" + " " + NumberToText(number % 1000);
	}

	if (number >= 1000000 && number <= 999999999)
	{
		return NumberToText(number / 1000000) + " " + "Million" + " " + NumberToText(number % 1000000);
	}
	else
	{
		return NumberToText(number / 1000000000) + " " + "Billion" + " " + NumberToText(number % 1000000000);
	}

}

int main()
{

	long long number = ReadNumber();

	cout << NumberToText(number);

	return 0;
}