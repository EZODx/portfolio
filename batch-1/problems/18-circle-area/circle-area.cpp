#include <iostream>

using namespace std;

float ReadRadious()
{
	float R;

	cout << "Please enter radious R : " << endl;
	cin >> R;

	return R;
}

float CircleArea(float R)
{
	const float PI = 3.141592653589793238;
	float Area = PI * pow(R, 2);

	return Area;
}

void PrintResutl(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintResutl(CircleArea(ReadRadious()));

	return 0;
}