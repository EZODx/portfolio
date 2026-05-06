#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber()
{
	
	float Number;
	cout << "Please enter a number: ";
	cin >> Number;

	return Number;
}

float MyABS(float Number)
{
	if (Number > 0)
		return Number;
	else
		return Number * -1;
}

int main()
{
	float Number = ReadNumber();

	cout << "My abs result : " << MyABS(Number) << endl;
	cout << "C++ abs result: " << abs(Number) << endl;

	return 0;
}