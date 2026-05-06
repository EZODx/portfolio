#include <iostream>
#include <iomanip>

using namespace std;

int ReadNumber()
{
	int number;

	cout << "Please enter a number to search for in the matrix: " << endl;
	cin >> number;

	return number;
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << left << setw(3) << matrix[i][j] << "   ";
		}
		cout << endl;
	}
}

bool IsNumberInMatrix(int matrix[3][3], short rows, short cols, short num)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == num)
				return true;
		}
	}

	return false;
}

void PrintIntersectedNumbers(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((IsNumberInMatrix(matrix2, rows, cols, matrix1[i][j])))
			{
				cout << left << setw(3) << matrix1[i][j] << "   ";
			}
		}
	}

	cout << endl;
}

int main()
{

	int matrix1[3][3] = { {21,77,0}, {113,1,8}, {4,8,9} };
	int matrix2[3][3] = { {1,4,6}, {0,22,3}, {41,77,21} };


	cout << "Matrix 1:\n";
	PrintMatrix(matrix1, 3, 3);

	cout << "\nMatrix 2:\n";
	PrintMatrix(matrix2, 3, 3);

	cout << "\nIntersected Numbers are: ";
	PrintIntersectedNumbers(matrix1, matrix2, 3, 3);

	return 0;
}