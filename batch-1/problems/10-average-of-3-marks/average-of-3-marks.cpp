#include <iostream>

using namespace std;

void ReadNumbers(int& Mark1, int& Mark2, int& Mark3)
{
	cout << "Please enter number 1 : ";
	cin >> Mark1;
	cout << endl;

	cout << "Please enter number 2 : ";
	cin >> Mark2;
	cout << endl;

	cout << "Please enter number 3 : ";
	cin >> Mark3;
	cout << endl;

}

int SumOf3Numbers(int Mark1,int Mark2,int Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
	return (float)SumOf3Numbers(Mark1, Mark2, Mark3) / 3;
}

void PrintResult(float Total)
{
	cout << "The Average is : " << Total;
}

int main()
{
	int Mark1, Mark2, Mark3;
	ReadNumbers(Mark1, Mark2, Mark3);
	PrintResult(CalculateAverage(Mark1, Mark2, Mark3));


	return 0;
}