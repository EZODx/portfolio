#include <iostream>

using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

void ReadNumbers(int& Mark1, int& Mark2, int& Mark3)
{
	cout << "Please enter Mark 1 : ";
	cin >> Mark1;
	cout << endl;

	cout << "Please enter Mark 2 : ";
	cin >> Mark2;
	cout << endl;

	cout << "Please enter Mark 3 : ";
	cin >> Mark3;
	cout << endl;

}

int SumOf3Numbers(int Mark1, int Mark2, int Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
	return (float)SumOf3Numbers(Mark1, Mark2, Mark3) / 3;
}

enPassFail CheckIfPass(float Average)
{
	if (Average >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResult(float Average)
{
	cout << "The Average is : " << Average << endl;

	if (CheckIfPass(Average) == enPassFail::Pass)
		cout << "\nYou passed\n";
	else
		cout << "\nYou failed\n";
}

int main()
{
	int Mark1, Mark2, Mark3;
	ReadNumbers(Mark1, Mark2, Mark3);
	PrintResult(CalculateAverage(Mark1, Mark2, Mark3));


	return 0;
}