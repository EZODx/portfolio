#include <iostream>

using namespace std;

int RandomNumber(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;

	return randNum;
}

void FillMatrixWithRandomNumbers(int array[3][3])
{

	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			array[i][j] = RandomNumber(1, 100);
		}

	}
}

void PrintMatrix(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%*d   ", 2, arr[i][j]);
		}
		cout << endl;
	}
	cout << "\n";
}

int main()
{

	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr);

	cout << "The following is a 3x3 random matrix:\n";
	PrintMatrix(arr);

	return 0;
}