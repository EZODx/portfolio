#include <iostream>

using namespace std;

float ReadCircumference()
{
	float L;

	cout << "Please enter circumference L : " << endl;
	cin >> L;

	return L;
}

float CircleAreaByCircumference(float L)
{
	const float PI = 3.141592653589793238;
	float Area = pow(L, 2) / (4 * PI);

	return Area;
}

void PrintResutl(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintResutl(CircleAreaByCircumference(ReadCircumference()));

	return 0;
}