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

bool AreEqualMatrices(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
	return (SumOfMatrix(matrix1, 3, 3) == SumOfMatrix(matrix2, 3, 3));
}

int main()
{

	srand((unsigned)time(NULL));

	int matrix1[3][3] ,matrix2[3][3];

	FillMatrixWithRandomNumbers(matrix1, 3, 3);
	cout << "Matrix 1:\n";
	PrintMatrix(matrix1, 3, 3);

	FillMatrixWithRandomNumbers(matrix2, 3, 3);
	cout << "Matrix 2:\n";
	PrintMatrix(matrix2, 3, 3);

	if (AreEqualMatrices(matrix1, matrix2, 3, 3))
		cout << "Yes, the matrices are equal" << endl;
	else
		cout << "No, the matrices are NOT equal" << endl;

	return 0;
}