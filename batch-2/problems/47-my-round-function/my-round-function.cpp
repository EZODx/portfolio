#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber()
{
	
	float Number;
	cout << "Please enter a float number: ";
	cin >> Number;

	return Number;
}

float GetFraction(float Number)
{
	return Number - (int)Number;
}

int MyRound(float Number)
{

	int IntPart;
	IntPart = (int)Number;

	float FractionPart = GetFraction(Number);

	if (abs(FractionPart) >= .5)
	{
		if (Number > 0)
		{
			return ++IntPart;
		}
		return --IntPart;
	}
	else
		return IntPart;

}

int main()
{
	float Number = ReadNumber();

	cout << "My round result : " << MyRound(Number) << endl;
	cout << "C++ round result: " << round(Number) << endl;

	return 0;
}