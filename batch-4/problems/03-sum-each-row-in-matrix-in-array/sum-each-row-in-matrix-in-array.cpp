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

int RowSum(int arr[3][3], short rowNumber, short cols)
{

	int sum = 0;

	for (int j = 0; j <= cols - 1; j++)
	{
		sum += arr[rowNumber][j];
	}

	return sum;
}

void SumMatrixRosInArray(int arr[3][3],int arrSum[3], short rows, short cols)
{

	for (int i = 0; i < rows; i++)
	{
		arrSum[i] = RowSum(arr, i, cols);
	}

}

void PrintRowsSumArray(int arrSum[3], short rows)
{

	cout << "The following are the sum of each row in the matrix:\n";

	for (int i = 0; i < rows; i++)
	{
		cout << "Sum of row " << i + 1  << ": " << arrSum[i] << endl;
	}

}

int main()
{

	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "The following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	SumMatrixRosInArray(arr, arrSum, 3, 3);

	PrintRowsSumArray(arrSum, 3);

	return 0;
}