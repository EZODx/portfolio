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

void PrintMiddleRowOfMatrix(int arr[3][3], short rows, short cols)
{

	short middleRow = rows / 2;

	for (int i = 0; i < cols; i++)
	{
		printf("%0*d   ", 2, arr[middleRow][i]);
	}

}

void PrintMiddleColOfMatrix(int arr[3][3], short rows, short cols)
{

	short middleCol = cols / 2;

	for (int j = 0; j < rows; j++)
	{
		printf("%0*d   ", 2, arr[j][middleCol]);
	}

}

int main()
{

	srand((unsigned)time(NULL));

	int matrix[3][3];

	FillMatrixWithRandomNumbers(matrix, 3, 3);
	cout << "Matrix 1:\n";
	PrintMatrix(matrix, 3, 3);


	cout << "\nMeddle row of Matrix is:\n";
	PrintMiddleRowOfMatrix(matrix, 3, 3);

	cout << "\nMeddle col of Matrix is:\n";
	PrintMiddleColOfMatrix(matrix, 3, 3);


	return 0;
}