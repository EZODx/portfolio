#include <iostream>

using namespace std;

int RandomNumber(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;

	return randNum;
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%02d   ", matrix[i][j]);
		}
		cout << endl;
	}
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = RandomNumber(1, 10);
		}
	}

}

void MultiplyMatrix(int matrix1[3][3], int matrix2[3][3], int matrix3[3][3], short rows, short cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
		}
	}

}

int main()
{

	srand((unsigned)time(NULL));

	int matrix1[3][3], matrix2[3][3], matrixResults[3][3];

	FillMatrixWithRandomNumbers(matrix1, 3, 3);
	cout << "Matrix 1:\n";
	PrintMatrix(matrix1, 3, 3);

	FillMatrixWithRandomNumbers(matrix2, 3, 3);
	cout << "\nMatrix 2:\n";
	PrintMatrix(matrix2, 3, 3);

	MultiplyMatrix(matrix1, matrix2, matrixResults, 3, 3);

	cout << "\nResult :\n";
	PrintMatrix(matrixResults, 3, 3);

	return 0;
}