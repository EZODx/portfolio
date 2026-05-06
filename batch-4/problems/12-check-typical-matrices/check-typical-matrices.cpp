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

bool AreTypicalMatrices(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			if (matrix1[i][j] != matrix2[i][j])
			{
				return false;
			}
		}
	}

	return true;
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


	if (AreTypicalMatrices(matrix1, matrix2, 3, 3))
		cout << "Yes, both matrices are typical\n";
	else
		cout << "No , the matrices are NOT typical\n";

	return 0;
}