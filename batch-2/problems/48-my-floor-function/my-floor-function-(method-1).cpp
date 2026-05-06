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

int MyFloor(float Number)
{
	if (abs(GetFraction(Number)) > 0)
	{
		if (Number > 0)
			return (int)Number;
		else
			return (int)Number - 1;
	}
	else
		return int(Number);


}

int main()
{
	float Number = ReadNumber();

	cout << "My floor result : " << MyFloor(Number) << endl;
	cout << "C++ floor result: " << floor(Number) << endl;

	return 0;
}