#include <iostream>

using namespace std;

int RandomNumber(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;

	return randNum;
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%02d   ", arr[i][j]);
		}
		cout << endl;
	}
}

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}

}

int SumOfMatrix(int matrix[3][3], short rows, short cols)
{

	int sum = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}

int main()
{

	srand((unsigned)time(NULL));

	int matrix[3][3];

	FillMatrixWithRandomNumbers(matrix, 3, 3);
	cout << "The matrix:\n";
	PrintMatrix(matrix, 3, 3);

	cout << "\nThe sum of the matrix: " << SumOfMatrix(matrix, 3, 3) << endl;


	return 0;
}