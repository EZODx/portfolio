#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;

	return randNum;
}

void FillMatrixWithRandomNumbers(int array[3][3], short rows, short cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = RandomNumber(1, 100);
		}
	}

}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << left << setw(3) << arr[i][j] << "   ";
		}
		cout << endl;
	}
	cout << "\n";
}

int ColSum(int arr[3][3], short rows, short ColNumber)
{
	int sum = 0;

	for (int i = 0; i <= rows - 1; i++)
	{
		sum += arr[i][ColNumber];
	}

	return sum;
}

void PrintEachColSum(int arr[3][3], short rows, short cols)
{

	cout << "The following are a sum of the matrix cols\n";

	for (int i = 0; i < cols; i++)
	{
		cout << "Row " << i + 1 << ": " << ColSum(arr, rows, i) << endl;
	}

}

int main()
{

	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "The following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	PrintEachColSum(arr, 3, 3);


	return 0;
}