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

int MySqrt(float Number)
{
	return pow(Number, 0.5);
}

int main()
{
	float Number = ReadNumber();

	cout << "My sqrt result : " << MySqrt(Number) << endl;
	cout << "C++ sqrt result: " << sqrt(Number) << endl;

	return 0;
}