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

void PrintArray(int arr[3][3], short rows, short cols)
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

void PrintEachRowSum(int arr[3][3], short rows, short cols)
{

	int sum = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += arr[i][j];
		}
		cout << "row " << i+1 << " = " << sum <<endl;
		sum = 0;
	}
}

int main()
{

	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "The following is a 3x3 random matrix:\n";
	PrintArray(arr, 3, 3);

	cout << "The following are the sum of each row in the matrix:\n";
	PrintEachRowSum(arr, 3, 3);

	return 0;
}